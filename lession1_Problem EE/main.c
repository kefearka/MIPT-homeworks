/*
        Problem EE* — Расширенный алгоритм Евклида.

    Решил сам
*/

#include <stdio.h>

int gcd_ext(int a, int b, int *x, int *y)
{
	if (a == 0)
	{
		#if 0
		printf("\t!\t\n");
		#endif
		*x = 0; *y = 1;
		return b;
	}

	int x1, y1;
	
	int d = gcd_ext(b % a, a, &x1, &y1);
	
	*x = y1 - (b / a) * x1;
	*y = x1;

	#if 0
	printf("\tx=%d,y=%d\n", *x, *y);
	#endif

	return d;
}

int main()
{
    int a;
    int b;
    int x, y;
    
    printf("Введите числа a и b через пробел:\n");
    if (scanf("%d%d", &a, &b) == 2 && b != 0)
    	printf("Для чисел %d и %d уравнение Эвклида выглядит так:\n(%d * %d) + (%d * %d) = %d\n", a, b, a, x, b, y, gcd_ext(a, b, &x, &y));
    else
    	printf("Введены некорректные данные, либо b = 0.\nРассчет невозможен.\nВыход...\n");

    return 0;
}
