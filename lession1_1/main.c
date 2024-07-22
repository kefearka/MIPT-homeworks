/*
        Наибольший общий делитель x и y. Евклидово деление!
    Два числа (x и y) можно связать через уравнение:
        x = y * p + q (0),
    отсюда:
        q = x - y * p (1),
    Пусть x и y делятся на k, тогда из (1) очевидно,
    что q тоже должна делиться на k.
    Тогда верно утверждение 
        НОД(x, y) = НОД(y, q), 
    что и реализовано в коде:
*/

#include <stdio.h>

// Поставил под сомнение единственность выражения НОД(y, q),
// моя проверка на выражение x через y - наоборот тоже работает
int igcd(int x, int y)
{
    if (!y) return 0;
    int q;
    q = y % x;
    if (q == 0) return x; // найдено
    return igcd(q, x);
}

int gcd(int x, int y)
{
    if (!y) return 0;
    int q;
    q = x % y;
    if (q == 0) return y; // найдено
    return gcd(y, q);
}

// Используемый, в методах gcd/igcd Сишный метод взятия модуля,
// не учитывет работы с отрицательными числами, что искажает результат.
// Для решения бага при вводе отрицательных чисел,
// следует заменить % на самописную функцию:

int iabs(int x)
{
    return (x < 0) ? -x : x;
}

int signed_mod(int x, int y)
{
    if (!y) return 0;
    int r;
    r = x % y;
    if (r < 0) r += iabs(y);
    return r;
}

int signed_gcd(int x, int y)
{
    int q = signed_mod(x, y);
    return (q == 0) ? iabs(y) : signed_gcd(y, q);
}

// BTW! очень интересная статья об остатке и модуле:
// https://habr.com/ru/articles/421071/

int main()
{
    int x = 698917;
    int y = 102089;
    printf("беззнаковый НОД(%d, %d) = %d\n", x, y, gcd(x, y));
    
    int a = 14;
    int b = -8;
    
    printf("беззнаковый НОД(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("знаковый НОД(%d, %d) = %d\n", a, b, signed_gcd(a, b));
    
    return 0;
}
