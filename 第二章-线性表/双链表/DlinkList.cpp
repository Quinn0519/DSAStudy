#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    // 定义struct类型的前驱指针和后继指针
    struct DNode *next, *prior;
    // DlinkList等价于 DNode *
} DNode, *DlinkList;

// 初始化
bool InitDLiinkList(DlinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    // 双链表的头结点永远指向空
    L->prior == NULL;

    // 初始头结点后面没有元素
    L->next == NULL;
    return true;
}

// 判断该表是否为空表
bool EmptyList(DlinkList L)
{
    if (L->next == NULL)
        return true;
    else
        return false;
}

// 插入--在p结点后插入s结点
// 括号里的参数为p结点和s结点
// 操作结点就是DNode *变量
// 操作表就是DlinkList L
bool InserNexttNode(DNode *p, DNode *s)
{
    // 判断插入的位置是否非法
    if (p == NULL || s == NULL)
        return false;

    // 把p的后继赋给s的后继--相当于p的后继指向第(p+1)个结点
    s->next = p->next;

    // 判断p->next是否为空--若为空代表该位置已经为表尾所以不能插入
    // 如果p结点有后继结点执行下述操作
    if (p->next != NULL)
    {
        // 将p后继结点的前驱指向s
        p->next->prior = s;
        // 将s的前驱指向p
        s->prior = p;
        // 将p的后继指向s
        p->next = s;
    }
}

// 删除
bool DeleteNextNode(DNode *p)
{
    // 判断是否为空表
    if (p == NULL)
        return false;

    // 定义一个q结点，值为p的后继
    DNode *q = p->next;

    // 判断q结点是否为空
    if (q == NULL)
        return false;

    // p的后继指向q的后继
    p->next = q->next;

    if (q->next != NULL)

        // q后继节点的前驱指向p
        q->next->prior = p;
    free(q);
    return true;
}

// 双链表的销毁
bool DestoryList(DlinkList &L)
{
    // 循环释放各个结点
    while (L->next != NULL)
        DeleteNextNode(L);

    // 释放头结点
    free(L);

    // 然后改变头结点指向--头结点指向NULL
    L = NULL;
}

// 双链表的后向遍历
void BackwardTraversal(DNode *p)
{
    while (p != NULL)
    {
        p = p->next;
    }
}

// 双链表的前向遍历
void ForwardTraversal(DNode *p)
{
    while (p != NULL)
    {
        p = p->prior;
    }
}

// 双链表的前向遍历（跳过头结点）
void ForwardTraversal2(DNode *p)
{
    while (p->prior != NULL)
    {
        p = p->prior;
    }
}

// 判断结点p是否为双链表的表尾结点
bool isTail(DlinkList L, DNode *p)
{
    return (p->next == NULL);
}

int main()
{
    DlinkList L;
    InitDLiinkList(L);
}
