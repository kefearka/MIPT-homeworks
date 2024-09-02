#define AP 1

#if AP == 1
/*
        Problem_from_Oleg
    
    Ряды Фибоначчи.
    Даны значения двух элементов (i, j) ряда Фибоначчи.
    Найти любой (k) элемент ряда.
    
    Мысль такая(думал на бумажке):
    Ряд Фибоначчи(классический) можно записать так:
    0, 1, 1, 2, 3, 5, 8, 13 ...

    Если принять:
    x0 = x;
    x1 = y;
    x2 = x + y;
    x3 = x + 2y;
    x4 = 2x + 3y;
    x5 = 3x + 5y, то
    x(n) = Fx(n) * x + Fy(n) * y.
    Очевидно, что коэффициенты при x и y, являются классическим рядом Фибоначчи,
    тогда:
    | n | F | Fx | Fy |
    | 0 | 0 | 1  | 0  |
    | 1 | 1 | 0  | 1  |
    | 2 | 1 | 1  | 1  |
    | 3 | 2 | 1  | 2  |
    | 4 | 3 | 2  | 3  |
    | 5 | 5 | 3  | 5  |
    Не трудно заметить, что Fx(n) = Fy(n - 1), а Fy(n) = F, тогда n-член запишется в виде:
    x(n) = F(n - 1) * x + F(n) * y, отсюда
         x(n) - F(n - 1)
    y = ----------------- , тогда
              F(n)
             F(m) * x(n) - F(n) * x(m)
    x = ----------------------------------- , где n и m - номера известных элементов, а x(n) и x(m) - их значения.
         F(n - 1) * F(m) - F(m - 1) * F(n)

    Т.к. задача в целых числах, x и y должны быть целыми. Если числитель = 0, решений нет (такое ощущение).
    Решил почти сам (зациклился на том, что в произвольном ряду по Фибоначчи, 
    обязательно должен быть элемент принимающий значение = 0. На этом и застопорился.
*/

#include <stdio.h>

#define NO_REASON -2147483648

void fibonacchi(long element_number, 
                long *element_val, 
                long *element_prev_val)
{
    long result = 1l;
    long prev = 0l;
    for(long i = 0l;; ++i)
    {
        if(element_number - i == 1l)
            *element_prev_val = result;
        if(element_number - i == 0l)
        {
            *element_val = result;
            break;
        }
        result += prev;
        prev = result;
    }
}

long find_val(int i, int i_num, int j, int j_num, int k_num)
{
    long fn, fn_prev, fm, fm_prev, top, bot, x, y;
    
    fibonacchi(i_num, &fn, &fn_prev);
    fibonacchi(j_num, &fm, &fm_prev);
    
    top = fm * i - fn * j;
    
    if(!top) return NO_REASON;
    
    bot = fn_prev * fm - fm_prev * fn;
    
    if(!bot || top % bot) return NO_REASON;
    
    x = top / bot;
    
    y = !((i - fn_prev * x) % fn) ? (i - fn_prev * x) / fn : NO_REASON;
    
    return ((fn_prev * x) + (fn * y));
}

int main()
{
    int i, j, k, i_num, j_num, k_num;
    
    printf("Введите номер известного элемента:");
    if(scanf("%d", &i) == 1)
    {
        printf("Введите значение этого элемента:");
        if(scanf("%d", &i_num) == 1)
        {
            printf("Введите номер другого известного элемента:");
            if(scanf("%d", &j) == 1)
            {
                printf("Введите значение этого элемента:");
                if(scanf("%d", &j_num) == 1)
                {
                    printf("Введите номер элемента который необходимо найти:");
                    if(scanf("%d", &k_num) == 1)
                    {
                        k = find_val(i, i_num, j, j_num, k_num);
                        if(k != NO_REASON)
                            printf("Для данного ряда элемент под номером %d равен %d", k_num, k);
                        else
                            printf("Для данного ряда решения нет");
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
