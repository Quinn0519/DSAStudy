#include <stdio.h>
#define MaxSize 10

typedef struct
{
    // 静态数组存放栈中元素
    int data[MaxSize];
    // 栈顶指针
    int top;
} SqStack;

// 初始化栈
void InitStack(SqStack &S)
{
    // 初始化栈顶指针
    S.top = -1;
}

// 判断栈空
bool StackEmpty(SqStack S)
{
    // 栈空
    if (S.top == -1)
        return true;

    // 不空
    else
        false;
}

// 进栈操作--向栈顶插入元素
bool Push(SqStack &S, int x)
{
    // 判断是否栈满，栈满报错
    // 若初始化时，S.top=0 则栈满条件为 S.top==MaxSize
    if (S.top == MaxSize - 1)
        return false;

    // 指针加一
    S.top = S.top + 1;
    // 新元素入栈--S.top代表下标
    S.data[S.top] = x;

    // 指针加一和新元素入栈可以合并为 S.data[++S.top]=x;
    // 先使top值加一在使用该值
    // 注：变量++，代表先使用该变量值在加一

    return true;
}

// 出栈操作--向栈顶删除元素
bool Pop(SqStack &S, int &x)
{
    // 栈空，报错
    if (S.top == -1)
        return false;

    // 栈顶元素先出栈--栈顶指针指向的元素的值赋给了x
    // 逻辑删除，实际数据还残留在内存中
    // 下面两行代码可以合并成 x=S.data[S.top--];
    x = S.data[S.top];
    // 指针减一
    S.top--;

    return true;
}

// 查找--读取栈顶元素
bool GetTop(SqStack S, int &x)
{
    // 栈空，报错
    if (S.top == -1)
        return false;

    // x记录栈顶元素
    x = S.data[S.top];
}

// 销毁栈--函数运行结束后会自动回收内存

int main()
{
    SqStack S;
    InitStack(S);
    return 0;
}