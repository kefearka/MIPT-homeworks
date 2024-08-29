/*
        Problem RPS
    Возведение в сверхстепень.
    Сверхстепенью a⬆️⬆️b называется итерация возведения a,
    в степень a, в степени а, в степени а... и так b раз.
        
    Например, 2⬆️⬆️4 = 2 ^ (2 ^ (2 ^ 2)) = 2 ^ 16 = 65536.
    (2⬆️⬆️4) mod 10 = 6
    (3⬆️⬆️3) mod 6 = 3
    (6⬆️⬆️2) mod 5 = 1
    Задача посчитать (a⬆️⬆️b) mod m.

    Решил сам
*/

#include <stdio.h>

unsigned spow_mod(unsigned n, unsigned k, unsigned m)
{
    unsigned result = 1;
	for(;k > 0; --k)
	    result *= n % m;
	    
	return result % m;
}

int main()
{
    unsigned a, b, c;

    printf("Введите целые положительные - число, степень и основание модуля, через пробел\n");

    if(scanf("%u%u%u", &a, &b, &c) == 3 && a >= 0 && b >= 0)
    	printf("Результат вычисления = %u\n", spow_mod(a, b, c));
    else
    {
        printf("Ошибка ввода.\nРассчет невозможен.\nВыход...\n");
        return -1;
    }
    return 0;
}
