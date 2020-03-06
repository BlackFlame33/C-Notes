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
}*/
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