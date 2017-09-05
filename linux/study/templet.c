#include "stdio.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int a,b,c;			//步骤一：相当于设置初始值
    a=1;
    b=2;
    c=3;
    while(a!='q')
    {
        printf("%d",c); //步骤二：相当于重绘屏幕
        a=getchar();    //步骤三：相当于响应输入设备
        c=a*b;          //步骤四：相当于重新运算变量值
    }                   //步骤五：如果a不等于q 就继续循环步骤二到四
    return 0;
}
