/*#define 名字 替换文本
#include <stdio.h>
int main()
{
    int c;
    c = getchar();
    putchar(c);

    return 0;
}

#include <stdio.h>
int main()
{
    int c;

    while ((c = getchar()) != EOF) //  EOF: end of file, 文件结束
        putchar(c);
}

练习1 - 6 验证表达式getchar() != EOF的值时0还是1
#include <stdio.h>
    int main()
{
    int c;

    if ((c = getchar()) != EOF)
    {
        printf("0\n");
    }
    else
    {
        printf("1\n");
    }
}
//  标准答案
//  需要考虑到表达式的结果无非就0或1，所以可用%来直接在printf语句中调用表达式的值
#include <stdio.h>
int main()
{
    printf("请键入后按回车键：\n");
    printf("表达式getchar()!=EOF的值是：%d\n", getchar() != EOF);
}

//   练习1-7 编写一个打印EOF值的程序
#include <stdio.h>
int main(){
    printf("%d", EOF);
        
    return 0;
}

//  对字符进行计数
#include <stdio.h>
int main(){
    long nc = 0;
    
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
    

    return 0;
}

//  for循环精简字符计数程，并使用可处理更大数字的类型double
#include <stdio.h>
int main(){
    double nc;
    for (nc = 0;getchar() != EOF;++nc)
    ;//单独放是为了醒目
    printf("\n%.0f\n", nc);
    return 0;
}

//  统计行数
#include <stdio.h>
int main(){
    int nl = 0;
    int c;
    while ((c=getchar()) != EOF)
        if (c == '\n')//    '='为赋值运算符，'=='为相等的逻辑关系
            ++nl;
    printf("\t行数：%d\n", nl);

    return 0;
}
//  练习1-8 统计空格、制表符、换行符
#include <stdio.h>
int main(){
    int blanks = 0, tabs = 0, newlines = 0;
    int c;
    while ((c=getchar()) != EOF)
        if (c == ' ')
            ++blanks;
        else if(c == '\t')
            ++tabs;
        else if(c == '\n')
            ++newlines;

    printf("\t空格：%d\t制表符：%d\t换行符：%d\n", blanks, tabs, newlines);

    return 0;
}

//  练习1-9 编写一个将如数复制到输出的程序，并将其中连续的多个空格用一个空格代替
#include <stdio.h>
int main()
{
    int c;
    int inspace = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (inspace == 0)
            {
                putchar(c);
                inspace = 1;
            }
        }
        else
        {
            putchar(c);
            inspace = 0;
        }
    }

    return 0;
}//inspace在这里相当于flag，用于判断输入的空格前一个字符是不是空格，以进行替代处理，是在是妙。

//  练习1-10    编写一个将输入复制到输出的程序。并将其中的制表符替换为\t，将回退符替换为\b，将反斜杠替换为\\。这样可以将制表符和回退符以可见的方式显示出来。
#include <stdio.h>
int main()
{
    int c;
    while ((c=getchar()) != EOF)
    {
        if (c == '\t')
            printf(" \\t ");
        else if (c == '\b')
        {
            printf(" \\b ");
        }
        else if (c == '\\')
        {
            printf(" \\\\ ");
        }
        else
        {
            putchar(c);
        }
        
    }

    return 0;
}//主要要注意的是：1、全等。2、打印时'\'需要用'\\'

#include <stdio.h>
#define IN 1    //在单词内
#define OUT 0    //在单词外
//统计输入的行数，单词数与字符数
int main(){
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c=getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c==' ' || c=='\n' || c=='\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("nl:%d\nnw:%d\nnc:%d\n", nl, nw, nc);

    return 0;
}*/

// //练习1-11  测试单词计数程序
// //TO-DO:单元测试听说过，但还不大会，先贴上官方答案，待学会后再回来查看！！！
// #include <assert.h>
// #include <stdio.h>

// int main(void)
// {
//     FILE *f;
//     unsigned long i;
//     static char *ws = " \f\t\v";
//     static char *al = "abcdefghijklmnopqrstuvwxyz";
//     static char *i5 = "a b c d e f g h i j k l m "
//                       "n o p q r s t u v w x y z "
//                       "a b c d e f g h i j k l m "
//                       "n o p q r s t u v w x y z "
//                       "a b c d e f g h i j k l m "
//                       "n\n";

//     /* Generate the following: */
//     /* 0. input file contains zero words */
//     f = fopen("test0", "w");
//     assert(f != NULL);
//     fclose(f);

//     /* 1. input file contains 1 enormous word without any newlines */
//     f = fopen("test1", "w");
//     assert(f != NULL);
//     for (i = 0; i < ((66000ul / 26) + 1); i++)
//         fputs(al, f);
//     fclose(f);

//     /* 2. input file contains all white space without newlines */
//     f = fopen("test2", "w");
//     assert(f != NULL);
//     for (i = 0; i < ((66000ul / 4) + 1); i++)
//         fputs(ws, f);
//     fclose(f);

//     /* 3. input file contains 66000 newlines */
//     f = fopen("test3", "w");
//     assert(f != NULL);
//     for (i = 0; i < 66000; i++)
//         fputc('\n', f);
//     fclose(f);

//     /* 4. input file contains word/
//      *    {huge sequence of whitespace of different kinds}
//      *    /word
//      */
//     f = fopen("test4", "w");
//     assert(f != NULL);
//     fputs("word", f);
//     for (i = 0; i < ((66000ul / 26) + 1); i++)
//         fputs(ws, f);
//     fputs("word", f);
//     fclose(f);

//     /* 5. input file contains 66000 single letter words,
//      *    66 to the line
//      */
//     f = fopen("test5", "w");
//     assert(f != NULL);
//     for (i = 0; i < 1000; i++)
//         fputs(i5, f);
//     fclose(f);

//     /* 6. input file contains 66000 words without any newlines */
//     f = fopen("test6", "w");
//     assert(f != NULL);
//     for (i = 0; i < 66000; i++)
//         fputs("word ", f);
//     fclose(f);

//     return 0;
// }

//练习1-12  以每行一个单词的形式打印其输入
#include <stdio.h>
#define OUT 1
#define IN 0
int main()
{
    int c;
    int state = IN;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
        {
            if (state == IN)
            {
                state = OUT;
                putchar(c);
                printf("\n");
            }
        }
        else
        {
            state = IN;
            putchar(c);
        }
    }

    return 0;
}