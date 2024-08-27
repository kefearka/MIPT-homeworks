#include <stdio.h>

#define MAX_LENGHT 32

int print_converted(unsigned n, unsigned base)
{
    int mass[MAX_LENGHT] = {0};
    if (base > 10)
    {
        printf("База = %d, а должна быть положительной и не превышать 10!\nВыход...", base);
        return -1;
    }
    
    for(int i = 31; i != 0; n /= base)
        mass[i--]=(n % base);
        
    #if 0    
    for(int i = 0; i != MAX_LENGHT; printf("%d", mass[i++]));
    #endif
    
    for(int i = 0; i != MAX_LENGHT; i++)
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
