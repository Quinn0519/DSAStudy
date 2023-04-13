#include<stdio.h>
#define MaxSize 10

// 创建一个结构体类型的共享栈
typedef struct
{
    // 静态数组存放栈中元素
    int data[MaxSize];

    // 0号栈栈顶指针--自下而上
    int top0;
    // 1号栈栈顶指针--自上而下
    int top1;
} ShStack;

// 初始化栈
void InitStack(ShStack &S)
{
    // 初始化栈顶指针
    S.top0 = -1;
    S.top1 = MaxSize;
}

// 判断是否栈满条件--top0+1==top1；

int main()
{
    ShStack S;
    InitStack(S);
    return 0;
}