// 不带头结点的队列链式存储
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    // 头指针和尾指针
    LinkNode *front, *rear;
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue &Q)
{
    // 不带头结点，初始时front、rear均指向NUll
    Q.front = NULL;
    Q.rear = NULL;
}

// 判空
bool IsEmpty(LinkQueue Q)
{ // 判空条件：Q.front = NULL或Q.rear = NULL
    if (Q.front = NULL)
        return true;
    else
        return false;
}

// 入队
void EnQueue(LinkQueue &Q, int x)
{
    // 申请一个新结点s
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    // 向此结点写入数据x
    s->data = x;
    // 新插入的结点为最后一个结点，所以该节点的next指针域指向NULL
    s->next = NULL;

    // 不带头结点的队列，第一个元素入队需特别处理
    // 因为初始时front、rear均指向NUll，所以第一个元素入队front、rear均要改变
    if (Q.front == NULL)
    {
        Q.front->next = s;
        // 每次插入后rear指针需指向新的表尾结点
        Q.rear = s;
    }
    else
    {
        Q.rear->next = s;
        // 每次插入后rear指针需指向新的表尾结点
        Q.rear = s;
    }
}

// 出队
bool DeQueue2(LinkQueue &Q, int &x)
{
    // 空队
    if (IsEmpty(Q))
        return false;

    // p指向此次出队的结点
    LinkNode *p = Q.front;
    // 用变量x返回队头元素
    x = p->data;
    // 修改front指针
    Q.front = p->next;
    // 此次是最后一个结点出队
    if (Q.rear == p)
    {
        // front和rear指针指向NULL
        Q.front = NULL;
        Q.rear = NULL;
    }
    // 释放结点空间
    free(p);
    return true;
}

int main()
{
    LinkQueue Q;
    InitQueue(Q);
    return 0;
}