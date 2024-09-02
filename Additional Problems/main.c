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
    
    Тогда сдвинутый ряд относительно 0 и домноженный на целое, выглядит так:
    1С + 0а, 1С + 1а, 2С + 1а, 3С + 2а, 5С + 3а, 8С + 5а, 13C + 8a... где С - целое, а - "основание".
    
    Тогда для элемента n будет справедлива запись:
    TODO...

    Пример:
    a5 = 100, a422 = 67. Найти a22.
    
    Решил сам
*/

#include <stdio.h>

void fibonacchi(long element_number, 
                long long *element_val, 
                long long *element_prev_val)
{
    long long result = 1ll;
    long long prev = 0ll;
    for(long i = 0l;; ++i)
    {
        if(element_number - i == 1ll)
            *element_prev_val = result;
        if(element_number - i == 0ll)
        {
            *element_val = result;
            break;
        }
        result += prev;
        prev = result;
    }
}



int main()
{
    unsigned i, j, k, i_num, j_num, k_num;

    if(scanf("Введите номер известного элемента:%u", &i) == 1)
        if(scanf("Введите значение этого элемента:%u", &i_num) == 1)
            if(scanf("Введите номер другого известного элемента:%u", &j) == 1)
                if(scanf("Введите значение этого элемента:%u", &j_num) == 1)
                    if(scanf("Введите номер элемента который необходимо найти:%u", &k_num) == 1)
    	printf("Результат вычисления = %u\n", 90);
    else
    {
        printf("Ошибка ввода.\nРассчет невозможен.\nВыход...\n");
        return -1;
    }
    return 0;
}
#endif
