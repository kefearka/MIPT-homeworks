/*
        Problem NS — Системы счисления

    Можно использовать деление с остатком, чтобы напечатать число в системе по основанию base.
    Предполагается, что base <=10.
    Требуется написать функцию, печатающую число по основанию base на экран.

    Решил сам
*/

#include <stdio.h>

#define MAX_LENGHT 32
#define MAX_BASE 10

int print_converted(unsigned n, unsigned base)
{
    int mass[MAX_LENGHT] = {0};
    if (base > MAX_BASE)
    {
        printf("База = %d, а должна быть положительной и не превышать 10!\nВыход...", base);
        return -1;
    }
    
    int i;
    for(i = MAX_LENGHT - 1; i >= 0; n /= base)
    {
        if(!n) break;
        mass[--i] = (n % base);
    }

    for(int j = MAX_LENGHT - 1; i < j; ++i)
        printf("%d", mass[i]);
    
    return 0;
}

int main()
{
    unsigned a, b;
    
    printf("Введите десятичное число и основание системы через пробел:\n");
    if(scanf("%d%d", &a, &b) == 2)
        print_converted(a, b);
    else
        printf("Ошибка ввода\nВыход...");

    return 0;
}
