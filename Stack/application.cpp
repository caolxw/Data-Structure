//ջ��Ӧ��
#include "sqhead.h"

int D[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

//����ת��
void conversion()
{
    int num;
    int d;
    printf("������һ���Ǹ�ʮ��������:");
    scanf("%d", &num);
    if(num <= 0) {
        printf("�������\n");
        return ;
    }
    printf("��������ƣ�");
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
