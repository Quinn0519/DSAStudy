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
        return false;
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
int Pop(SqStack &S)
{
    // 栈空，报错
    if (S.top == -1)
        return 0;

    // 栈顶元素先出栈--栈顶指针指向的元素的值赋给了x
    // 逻辑删除，实际数据还残留在内存中
    // 下面两行代码可以合并成 x=S.data[S.top--];
    int x = S.data[S.top];
    // 指针减一
    S.top--;

    return x;
}

// 查找--读取栈顶元素
int GetTop(SqStack S)
{
    // 栈空，报错
    if (S.top == -1)
        return -9999;

    // x记录栈顶元素
    int x = S.data[S.top];
    return x;
}

// 销毁栈--函数运行结束后会自动回收内存

int main()
{
    SqStack S;
    InitStack(S);

    Push(S, 1);
    printf("当前栈顶元素： %d\n", GetTop(S));

    Push(S, 2);
    printf("当前栈顶元素： %d\n", GetTop(S));

    Push(S, 3);
    printf("当前栈顶元素： %d\n", GetTop(S));

    printf("栈顶元素为: %d\n", GetTop(S));

    printf("第一个出栈的元素： %d\n", Pop(S));
    printf("第二个出栈的元素： %d\n", Pop(S));
    printf("第三个出栈的元素： %d\n", Pop(S));

    return 0;
}