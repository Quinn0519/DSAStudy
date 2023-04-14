#include <stdio.h>
#include <stdlib.h>

typedef struct Linknode
{
    // 数据域
    int data;
    // 指针域
    struct Linknode *next;
} *LinkStack;

// 初始化链栈
bool InitStack(LinkStack &S)
{
    // 为不带头结点的链栈分配内存空间
    S = (LinkStack)malloc(sizeof(Linknode));

    // 分配内存失败
    if (S->next == NULL)
        return false;

    // 不带头结点的链栈是链头置空
    S = NULL;

    return true;
}

// 判断栈空
bool StackEmpty(LinkStack S)
{
    if (S == NULL)
        return true;
    else
        false;
}

// 进栈操作
bool Push(LinkStack &S, int x)
{
    // 为结点p分配内存空间
    Linknode *p = (Linknode *)malloc(sizeof(Linknode));
    // 分配内存空间失败
    if (p == NULL)
        return false;
    // 把插入x的数值赋给p的数据域
    p->data = x;
    // 将p的next指向链头
    p->next = S;
    // S指向p
    S = p;

    return true;
}

// 出栈操作
bool Pop(LinkStack &S, int &x)
{
    // 判断栈空
    // StackEmpty(S);
    if (S == NULL)
        return false;

    // 让e指向开始的S，方便free
    Linknode *e;
    e = S;

    // 把要删除结点数据带回
    x = S->data;

    // S指向栈顶后的结点
    S = S->next;

    // 释放结点
    free(e);
    return true;
}

// 读取栈顶元素
int GetTop(LinkStack S)
{
    // 判断栈空
    if (StackEmpty(S))
        return 0;

    int x = S->data;
    return x;
}

int main()
{
    LinkStack S;
    InitStack(S);

    StackEmpty(S);

    Push(S, 1);
    printf("当前栈顶元素：%d\n", GetTop(S));

    Push(S, 2);
    printf("当前栈顶元素：%d\n", GetTop(S));

    Push(S, 3);
    printf("当前栈顶元素：%d\n", GetTop(S));

    int x = 0;

    Pop(S, x);
    printf("第一个出栈的元素： %d\n", x);
    Pop(S, x);
    printf("第二个出栈的元素： %d\n", x);
    Pop(S, x);
    printf("第三个出栈的元素： %d\n", x);

    printf("栈是否为空：%d", StackEmpty(S));

    return 0;
}
