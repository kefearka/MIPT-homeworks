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
    int x = 698917;
    int y = 102089;
    printf("Итеративный беззнаковый НОД(%d, %d) = %d\n", x, y, iter_gcd(x, y));
    
    int a = 14;
    int b = -8;
    printf("Итеративный беззнаковый НОД(%d, %d) = %d\n", a, b, iter_gcd(a, b));
    printf("Итеративный знаковый НОД(%d, %d) = %d\n", a, b, signed_iter_gcd(a, b));
    
    return 0;
}