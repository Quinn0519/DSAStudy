// 带头结点的队列链式存储
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
    // 初始时，front、rear都指向头结点
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    // 头结点的next指针指向NULL
    Q.front->next = NULL;
}

// 判空
bool IsEmpty(LinkQueue Q)
{ // 判空条件（带头结点）：Q.front = Q.rear或Q.front->next = NULL
    if (Q.front = Q.rear)
        return true;
    else
        return false;
}

// 入队
void EnQueue(LinkQueue &Q, int x)
{
    // 申请一个新结点s
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));

    s->data = x;
    // 新插入的结点为最后一个结点，所以该节点的next指针域指向NULL
    s->next = NULL;
    // 新结点插入rear之后
    // rear指向的是当前表尾结点，所以rear的next指针域指向s
    Q.rear->next = s;
    // 让表尾指针指向s--修改表尾指针
    Q.rear = s;
}

// 出队--队头元素出队
bool DeQueue(LinkQueue &Q, int &x)
{
    // 空队
    if (IsEmpty(Q))
        return false;

    // 定义一个p指针，指向要删除的结点
    LinkNode *p = Q.front->next;
    // 用变量x返回队头元素
    x = p->data;
    // 修改头结点的next指针
    Q.front->next = p->next;
    // 当最后一个结点出队
    if (Q.rear == p)
        // 修改rear指针指向头结点--删除p后队列为空队列
        Q.rear = Q.front;

    // 释放结点空间
    free(p);
    return true;
}

// 链式存储无需关心是否队满

int main()
{
    LinkQueue Q;
    InitQueue(Q);
    return 0;
}