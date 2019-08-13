#include <stdio.h>
#include "sqhead.h"
#include "sqstack.cpp"

int main(){
    SqStack S;
    Init_Stack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 4);
    showup(S);
    ELemType e;
    Pop(S, e);
    printf("%d\n", e);
    showup(S);
    int length = Stack_Length(S);
    printf("%d \n", length);
}
