#ifndef STACK_H
#define STACK_H
#include"BasicDataStruct.h"
#endif

#define MAX_STACK 65535


/***********
 *栈结构
 ***********/
typedef struct Stack
{
    int data[MAX_STACK];
    int top;
}Stack;

/***********
 *创建整形栈，输入栈最大深度和初始化值，返回栈顶指针
 ***********/
Stack* pnCreateStack(int nMaxDeep, int nInit){
    Stack* stack;
    uint64 curPos = 0;
    while(curPos < nMaxDeep){
        stack->data[curPos++] = nInit;
    }
    stack->top = nMaxDeep-1;
    return stack;
}

/***********
 *压栈，返回操作是否成功
 ***********/
bool bPushStack(Stack* pstStack, int nElement){


}

/***********
 *弹栈，返回栈顶值
 ***********/
int nPopStack(Stack* pstStack){


}

/***********
 *查看栈顶，返回栈顶值
 ***********/
int nPeekStack(Stack* pstStack){


}

/***********
 *查询栈空，若空返回VOS_OK，否则返回VOS_ERR
 ***********/
bool bIsEmpty(Stack* pstStack){


}

/***********
 *查询栈深，返回栈的深度
 ***********/
int nLenStack(Stack* pstStack){


}

/***********
 *打印栈
 ***********/
void PrintStack(Stack* pstStack){
    int curPos = pstStack->top;
    while(curPos-- >= 0){
        printf("\t|\t");
        printf("%d",pstStack->data);
        printf("\t|\t\n");
        printf("\t -\t\t-\t\n");
    }
}