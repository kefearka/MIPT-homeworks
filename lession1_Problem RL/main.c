/*
        Problem RL — рекурсия в цикл (алгоритм Евклида)
    Полностью сам
*/

#include <stdio.h>

// для беззнаковых чисел
int iter_gcd(int x, int y)
{
    #if 0
    // данная проверка избыточна
    if(x == y)
        return x;
    #endif
    
    int result;
    // выбросить своп (((
    for(result = (x < y) ? x : y; result > 0; --result)
        if (!(x % result) && !(y % result))
            return result;
}

// абсолютные
int iabs(int x)
{
    return (x < 0) ? -x : x;
}

// для знаковых чисел
int signed_iter_gcd(int x, int y)
{
    iter_gcd(iabs(x), iabs(y));
    
    #if 0
    // проще надо быть, золотые мои... (с)Mr.Freeman
    x = iabs(x);
    y = iabs(y);
    
    // данная проверка избыточна
    if(x == y)
        return x;
    
    // повторение кода iter_gcd(int x, int y)
    int result;
    for(result = (x < y) ? x : y; result > 0; --result)
        if (!(x % result) && !(y % result))
            return result;
    #endif
}

int main()
{
    int a;
    int b;
    
    printf("Введите числа a и b через пробел:\n");
    if (scanf("%d%d", &a, &b) == 2)
    	if (b != 0)
    	{
    		printf("беззнаковый НОД(%d, %d) = %d\n", a, b, iter_gcd(a, b));
    		printf("знаковый НОД(%d, %d) = %d\n", a, b, signed_iter_gcd(a, b));
    	}
    else
    	printf("Введены некорректные данные, либо b = 0.\nРассчет невозможен.\nВыход...\n");
    	
    return 0;
}
