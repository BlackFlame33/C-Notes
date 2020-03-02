#include <stdio.h>
int main()
{
    printf("Hello, ");
    printf("world!");
    printf("\c");

    return 0;
}
//练习1-2:
// hello.c:6:13: warning: unknown escape sequence '\c' [-Wunknown-escape-sequence]
//     printf("\c");
//             ^~
// 1 warning generated.
// 警告：未知的转义字符序列。Ps：推测\c可能没有实际意义
