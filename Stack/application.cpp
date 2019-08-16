//栈的应用
#include "sqhead.h"

int D[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

//数制转换
void conversion()
{
    int num;
    int d;
    printf("请输入一个非负十进制整数:");
    scanf("%d", &num);
    if(num <= 0) {
        printf("输入错误\n");
        return ;
    }
    printf("请输入进制：");
    scanf("%d", &d);

    SqStack S;
    Init_Stack(S);
    while(num)
    {
        Push(S, num % d);
        num = num / d;
    }
    int e;
    while(!isEmpty(S)){
        Pop(S, e);
        if(e > 9){
            printf("%c", D[e%10]);
            continue;
        }
        printf("%d ", e);
    }
    printf("\n");
}
