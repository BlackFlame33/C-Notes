/*//定义一个power函数用于计算整数的n次幂
#include <stdio.h>
int power(int m, int n);
int main()
{
    int i;
    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));

    return 0;
}
int power(int base, int n)
{
    int i, p;
    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;

    return p;
}*/

//练习1-15  使用函数实现温度转换计算
#include <stdio.h>
double temperature(int F);
int main()
{
    printf("华氏度——>摄氏度\n");
    for (int F; F <= 300; F += 20)
        printf("%3d\t%6.2f\n\n", F, temperature(F));

    return 0;
}
double temperature(int F)
{
    double C;
    C = (5 / 9.0) * (F - 32);

    return C;
}