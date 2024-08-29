/*
        Problem FS*
    Система факториалов.
    Число может быть представлено
    единственным образом в факториальной системе счисления.
    У каждого n! может быть коэффициент 0 <= k <= n.
    Задача написать программу, которая принимает на вход положительное десятичное число
    и печатает его в факториальной системе счисления. 
    
    Вход:
    463
    Выход:
    3.4.1.0.1.
    
    Например:
    463 = 3 * 5! + 4 * 4! + 1 * 3! + 0 * 2! + 1 * 1! = (34101)ф
    
    Решил сам
*/

#include <stdio.h>
#define DBG 0

#if DBG
unsigned find_major_degree(unsigned number, unsigned *degree)
{
    unsigned result = 1;
    
    for(unsigned i = *degree; i > 0; --i) result *= i;
    
    if(result < number)
    {
        (*degree)++;
        return find_major_degree(number, degree);
    }
    else
    {
        (*degree)--;
        return result / (*degree);
    }
}
#endif

unsigned factorial(unsigned degree)
{
    unsigned result = 1;
    for(unsigned i = degree; i > 0; --i) result *= i;
    return result;
}

// unsigned find_major_degree(unsigned *n, unsigned d = 1) BUT, unfortunately, C has no default parameters
unsigned find_major_degree(unsigned number, unsigned degree)
{
    unsigned result = 1;

    result = factorial(degree);
        
    return (result < number) ? find_major_degree(number, degree + 1) : --degree;
}

unsigned find_major_coeff(unsigned number, unsigned degree)
{
    unsigned result = 0;
    for(unsigned i = 0; number >= factorial(degree) * i; ++i)
        result++;
        
    return result;
}

int factorial_representation(unsigned number)
{
    printf("Число %u в факториальном представлении:\n", number);
    
    unsigned coeff = 0; 
    unsigned dgr = 1;
    for(;number >= 0;)
    {
        dgr = find_major_degree(number, dgr);
        coeff = find_major_coeff(number, dgr);
        number = number - dgr - coeff;
        dgr--;
        printf("%u.", coeff);
    }
     printf("\n");
}

int main()
{
    unsigned number;

    printf("Введите целое неотрицательное число\n");

    if(scanf("%u", &number) == 1)
    	factorial_representation(number);
    else
    {
        printf("Ошибка ввода.\nРассчет невозможен.\nВыход...\n");
        return -1;
    }
    return 0;
}
