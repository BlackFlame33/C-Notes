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
}

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

//读入一组文本，并把最长的文本行打印出来。
#include <stdio.h>
#define MAXLINE 1000 //允许的输入行的最大长度

int getlines(char line[], int maxline);
void copy(char to[], char from[]);
//打印最长的输入行
int main()
{
    int len;               //当前行长度
    int max;               //目前为止发现的最长行的长度
    char line[MAXLINE];    //当前的输入行
    char longest[MAXLINE]; //用于保存最长的行

    max = 0;
    while ((len = getlines(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) //存在这样的行
        printf("%s", longest);

    return 0;
}

//getlines函数：将一行读入s中并返回其长度
int getlines(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

//copy函数：将from复制到to；假定to足够大
void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
    /*为什么要用while，不用for？
    因为在这个循环操作中，from的下标是未知的，也就是说不清楚循环的步数。
    使用while可以设定为当复制的当前字符为EOF的时候便可结束函数。
    
        ++i;
}*/

//练习1-16  打印任意长度的输入行的长度，并尽可能地打印文本
//实在是没懂，这个程序功能上依旧是打印最长行
#include <stdio.h>
#define MAXLENGTH 20
int getlines(char[], int);
void copy(char[], char[]);
int main()
{
    int len, max = 0;
    char line[MAXLENGTH], longest[MAXLENGTH];
    while ((len = getlines(line, MAXLENGTH)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
    {
        if (max > MAXLENGTH)
        {
            printf("\n\nStorage limit exceeded by : %d", max - MAXLENGTH);
            printf("\nString length : %d", max);
            printf("\n%s", longest);
        }
        else
            printf("%s", longest);
    }
    printf("\n");
    return 0;
}

int getlines(char line[], int limit)
{
    int i, c;
    for (i = 0; i < limit - 1 && (((c = getchar()) != EOF) && (c != '\n')); i++)
        line[i] = c;
    if (i == (limit - 1))
    {
        while ((c = getchar()) != '\n')
        {
            ++i;
        }
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}