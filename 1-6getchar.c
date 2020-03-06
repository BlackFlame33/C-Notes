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
}*/

//   练习1-7 编写一个打印EOF值的程序
#include <stdio.h>
int main(){
    printf("%d", EOF);
        
    return 0;
}
