/*
        Problem CF — цепные дроби
    Полностью сам (прочитал только вики о непрерывной дроби)
*/

#define FLOAT_LENGHT 10

#include <stdio.h>

int iabs(int x)
{
    return (x < 0) ? -x : x;
}

void continued_fraction(int a, int b)
{
    if (iabs(a) < iabs(b))
        printf("Дробь %d/%d не может быть разложена!((\n", a, b);
    else
    {
        printf("Дробь %d/%d раскладывается на цепь: \n[%d; ", a, b, a / b);
        
        int i = 0;
        a = a % b;
        
        while (i < FLOAT_LENGHT)
        {
            // Переворот дроби
            a = a + b;
            b = a - b;  // b = a
            a = a - b;
            
            printf("%d", iabs(a / b));
            
            // Новый числитель
            a = a % b;
            
            // Вставляю разделитель 
            if (a != 0) printf(", ");
            else break; // - конец дроби похоже, на выход!)
            
            ++i;
        }
        printf("]\n");
    }
    return;
}

int main()
{
    int a = 101;
    int b = 60;
    continued_fraction(a, b);

    return 0;
}