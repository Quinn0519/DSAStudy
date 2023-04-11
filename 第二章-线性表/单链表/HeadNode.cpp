#include <stdio.h>
#include <stdlib.h>

// 定义了一个结构体类型 LNode
typedef struct LNode
{
    // 数据域
    int data;

    // 指针域
    struct LNode *next;

    // 这里的 LinkList 实际上是 LNode * 的一个别名--LinkList和LNode *是等价的
    // 是指向 LNode 结构体类型的指针
    //  LNode *L 声明一个指向单链表第一个节点的指针
    // LinkList L 声明一个指向单链表第一个节点的指针，代码可读性更强
} LNode, *LinkList;

// 初始化单链表
bool InitList(LinkList &L)
{

    // 分配一个头节点
    L = (LNode *)malloc(sizeof(LNode));

    // 内存分配不足
    if (L == NULL)
        return false;

    L->next = NULL;
    return true;
}

// 按位查找--查找第i个元素并返回
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;

    // 指针p指向的当前指向的结点
    LNode *p;

    // 当前p指向的是第几个结点--初值为0代表开始指向头结点
    int j = 0;
    p = L;
    // 使用循环找第(i-1)个结点
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找--找到数据域等于e的值的元素
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p != NULL || p->data == e)
    {
        p = p->next;
        return p;
    }
}

// 头插法
bool InsertPriorNode(LNode *p, int e)
{
    // 判断是否是空表
    if (p == NULL)
        return false;

    // 为结点s分配内存空间
    LNode *s = (LNode *)malloc(sizeof(LNode));
    // 内存分配失败
    if (s == NULL)
        return false;
    return false;

    s->next = p->next;
    p->next = s;

    // 将p的数据值复制给s
    s->data = p->data;
    p->data = e;
    return true;
}

// 尾插法
bool InsertNextNode(LNode *p, int e)
{
    // 判断是否为空表
    if (p == NULL)
        return false;

    // 为结点s分配内存空间
    LNode *s = (LNode *)malloc(sizeof(LNode));
    // 内存分配失败
    return false;

    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 插入操作--按位序插入
bool ListInsert(LinkList &L, int i, int e)
{
    // 判断该位置是否存在
    if (i < 1)
        return false;

    // 找到第(i-1)个元素，因为插入操作是在第(i-1)个元素后面执行
    LNode *p = GetElem(L, i - 1);
    return InsertNextNode(p, 1);
}

// 删除操作--按位序删除
bool ListDelete(LinkList &L, int i, int &e)
{
    LNode *p = GetElem(L, i - 1);

    // 判断是否合法
    if (i < 1)
        return false;

    if (p->next == NULL)
        return false;
    // 令q指向被删除结点
    LNode *q = p->next;
    // 用e返回元素的值
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// 删除指定节点p
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;

    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}

// 求表的长度
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

int main()
{
    LinkList L;
    InitList(L);
}