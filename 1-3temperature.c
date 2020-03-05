// 练习1-3 修改温度转换程序，使之能在转换表的顶部打印一个标题
// #include <stdio.h>
// /* 当fahr= 0, 20, ..., 300时，分别
//  * 打印华氏温度与摄氏温度对照表
//  * 浮点数版本*/
// int main()
// {
//     float fahr, celsius;
//     int lower, upper, step;

//     lower = 0;    /* 温度表的下限  */
//     upper = 300; /* 温度表的下限  */
//     step = 20;    /* 步长          */

//     fahr = lower;
//     printf("Temperature温度对照表\n");
//     printf("\t华氏度\t摄氏度\n");
//     while (fahr <= upper){
//         celsius = (5.0 / 9.0) * (fahr - 32.0);
//         printf("\t%3.0f   %7.1f\n", fahr, celsius);
//         fahr = fahr + step;
//     }
// }
// 练习1-4 摄氏度转换成相应华氏度的转换表
// 华氏度 = （9/5） * 摄氏度 + 32
//#include <stdio.h>
//int main(){
//    float fahr = 0;
//    printf("华氏度\t摄氏度\n");
//    for (int celsius = 1; celsius < 300;celsius += 20)
//    {
//        fahr = (9.0/5.0) * celsius + 32;
//        printf("%3d\t%6.1f\n", celsius, fahr);
//    }
//}
// 练习1-5 以逆序打印温度转换表
#include <stdio.h>
int main(){
    float fahr;
    printf("华氏度\t摄氏度\n");
    for (int celsius = 301; celsius >= 0;celsius -= 20)
    {
        fahr = (9.0/5.0) * celsius + 32;
        printf("%3d\t%6.1f\n", celsius, fahr);
    }
}