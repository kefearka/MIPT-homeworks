#define AP 1

#if AP == 1
/*
        Problem_from_Oleg
    
    Ряды Фибоначчи.
    Даны значения двух элементов (i, j) ряда Фибоначчи.
    Найти любой (k) элемент ряда, по его номеру.
    
    Мысль такая(думал на бумажке):
    Ряд Фибоначчи(классический) можно записать так:
    0, 1, 1, 2, 3, 5, 8, 13 ...

    Если принять:
    x0 = a;
    x1 = b;
    x2 = a + b;
    x3 = a + 2b;
    x4 = 2a + 3b;
    x5 = 3a + 5b, то
    x(n) = Fa(n) * a + Fb(n) * b.
    Очевидно, что коэффициенты при x и y, являются классическим рядом Фибоначчи,
    тогда:
    
    | n | F | Fa | Fb |
    | 0 | 0 | 1  | 0  |
    | 1 | 1 | 0  | 1  |
    | 2 | 1 | 1  | 1  |
    | 3 | 2 | 1  | 2  |
    | 4 | 3 | 2  | 3  |
    | 5 | 5 | 3  | 5  |
    Не трудно заметить, что Fa(n) = Fb(n - 1), а Fa(n) = F, тогда n-член запишется в виде:
    
    x(n) = F(n - 1) * a + F(n) * b, отсюда
    
         x(n) - F(n - 1) * b
    a = -------------------- , тогда
                F(n)
                
          x(j) * F(i - 1) - x(i) * F(j - 1) 
    b = ------------------------------------ , где i и j - номера известных элементов, а x(i) и x(j) - их значения.
         F(j) * F(i - 1) -  F(i) * F(j - 1)

    Т.к. задача в целых числах a / b должно быть целым.
    Решил почти сам (зациклился на том, что в произвольном ряду по Фибоначчи, 
    обязательно должен быть элемент принимающий значение = 0. На этом и застопорился.)
*/

#include <stdio.h>

#define NO_REASON -2147483648

void fibonacchi(long element_number, 
                long *element_val, 
                long *element_prev_val)
{
    if(element_number == 0l)
    {
        *element_val = 0l;
        *element_prev_val = 1l;
        return;
    }
    
    if(element_number == 1l)
    {
        *element_val = 1l;
        *element_prev_val = 0l;
        return;
    }
    
    long prev_prev_n = 0l;
    long prev_n = 1l;
    long n = 1l;
    
    for(long i = 3; i <= element_number; ++i)
    {
        prev_prev_n = prev_n;
        prev_n = n;
        n = prev_n + prev_prev_n;
    }
    
    *element_val = n;
    *element_prev_val = prev_n;
    return;
}

long find_val(int i, int i_num, int j, int j_num, int k_num)
{
    long fi, fi_prev; 
    long fj, fj_prev;
    long fk, fk_prev;
    long top_b, bot_b, a, b;
    
    fibonacchi(i_num, &fi, &fi_prev);
    fibonacchi(j_num, &fj, &fj_prev);
    fibonacchi(k_num, &fk, &fk_prev);
    
    // x(j) * F(i - 1) - x(i) * F(j - 1) 
    top_b = (j * fi_prev) - (i * fj_prev);
    
    // F(j) * F(i - 1) -  F(i) * F(j - 1)
    bot_b = (fj * fi_prev) - (fi * fj_prev);
    
    if(top_b % bot_b) return NO_REASON;
    
    b = (top_b / bot_b);
    a = ((i - (fi * b)) / fi_prev);

    return ((a * fk_prev) + (b * fk));
}

int main()
{
    int i, j, k;
    int i_num, j_num, k_num;
    
    printf("Введите номер известного элемента:");
    if(scanf("%d", &i_num) == 1)
    {
        printf("Введите значение этого элемента:");
        if(scanf("%d", &i) == 1)
        {
            printf("Введите номер другого известного элемента:");
            if(scanf("%d", &j_num) == 1)
            {
                printf("Введите значение этого элемента:");
                if(scanf("%d", &j) == 1)
                {
                    printf("Введите номер элемента который необходимо найти:");
                    if(scanf("%d", &k_num) == 1)
                    {
                        k = find_val(i, i_num, j, j_num, k_num);
                        if(k != NO_REASON)
                            printf("Для данного ряда элемент под номером %d равен %d", k_num, k);
                        else
                            printf("Для данного ряда целочисленного решения нет");
                    }
                }
            }
        }
    }
    else
    {
        printf("Ошибка ввода.\nРассчет невозможен.\nВыход...\n");
        return -1;
    }
    return 0;
}
#endif

#if AP == 2
/*
        Problem_the_Queen
    Комбинаторика
    Расставить на стандартной 64-клеточной шахматной доске 8 ферзей так, 
    чтобы ни один из них не находился под боем другого.
*/

#include <stdio.h>

#define DECK_SIZE 8
#define FREE 0
#define QUEEN 5
#define NONFREE 1
// #define NO_REASON -2147483648

struct crd
{
    int x;
    int y;
};

struct crd queens[8] = {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}};

// unsigned field[DECK_SIZE][DECK_SIZE] = {FREE};

unsigned uabs(int a) { return a > 0 ? a : -a; }

int has_cross(int new_x, int new_y, int current_queen)
{
    // if (!current_queen) return -1;
    
	for(int i = 0; i < current_queen; ++i)
	{
        if((new_y == queens[i].y) || ((uabs(new_x - queens[i].x) == 1) && (uabs(new_y - queens[i].y) == 1)))
            return i;
	}
	return -1;
}

int find_y(unsigned q_num)
{
    int cross = has_cross(queens[q_num].x, queens[q_num].y, q_num);
    if(cross != -1)
    {
        ++queens[q_num].y;
        
        if(queens[q_num].y > DECK_SIZE - 1)
        {
            for(int i = 0; i < q_num; ++i)
            {
                queens[i].y++;
                if(queens[i].y > DECK_SIZE - 1)
                    queens[i].y = 0;
            }
            queens[q_num].y = 0;
        }
        return find_y(q_num);
    }
    else return -1;
}


void show_queens_coords()
{
    for(int i = 0; i < DECK_SIZE; ++i)
    {
        printf("x = %d, y = %d\n", queens[i].x + 1, queens[i].y + 1);
    }
}

void show_deck()
{
    printf("\n   A  B  C  D  E  F  G  H\n");
    for(int x = 0; x < DECK_SIZE; ++x)
    {
        printf("%d ", DECK_SIZE - x);
        for(int y = 0; y < DECK_SIZE; ++y)
        {
            // for(int q = 0; q < DECK_SIZE; ++q)
            if((x == queens[x].x) && (y == queens[x].y))
                printf(" ♛ ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

void f1()
{
    for(unsigned q_num = 0; q_num < DECK_SIZE; ++q_num)
    {
        printf("-----------q = %d----------\n", q_num);
        find_y(q_num);
        show_deck();
        printf("---------------------------\n\n");
    }
}


int main()
{
    // show_deck();
    f1();
    show_queens_coords();
    // show_deck();
    return 0;
}
#endif
