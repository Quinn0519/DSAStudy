#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define InitSize 3 // 顺序表初始长度为3

typedef struct
{
    // data指针是指向顺序表中的第一个元素
    int *data;

    // 动态分配，容量可变，所以定义一个最大容量
    int MaxSize;

    // 顺序表的当前长度
    int length;
} SeqList;

// 初始化
void InitList(SeqList &L)
{
    // 使用malloc函数申请一片连续存储的空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    // 初始化顺序表长度及将初识表长赋给动态容量
    L.length = 0;
    L.MaxSize = InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len)
{
    printf("超出最大长度,执行IncreaseSize。\n");
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        // 将数据复制到新申请的区域
        L.data[i] = p[i];
    }

    // 顺序表扩充后的长度
    L.MaxSize = L.MaxSize + len;

    // 释放原来的内存空间
    free(p);
}

// 在指定位置插入
bool ListInsert(SeqList &L, int i, int e)
{
    // 1.判断是否合法
    // i：为位序（从一开始）到 +1 结束
    // 考虑边界条件，即后插操作能否实现
    if (i < 1 || i > L.length + 1)
        return false;

    // 2.判断容量是否够用
    if (L.length >= L.MaxSize)
    {
        IncreaseSize(L, 5);
    }

    // 3.插入操作
    // 从第（i+1）个位置开始，每个元素往后往后一个位置
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }

    // 将插入的e值赋给位序为i的元素，表长加一
    L.data[i - 1] = e;
    L.length++;

    return true;
}

// 在指定位置删除
bool ListDelete(SeqList &L, int i, int &e)
{
    // 1.判断是否合法
    if (i < 1 || i > L.length)
        return false;

    e = L.data[i - 1];

    // 2.删除操作
    // 感觉直接使用i不是逻辑更清晰吗
    // A：循环变量会有各种奇怪的操作，导致最终结果和初始完全不同，故最好单独定义一个循环变量
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }

    L.length--;
    return true;
}

// 查找--按位查找
// i--位序为1
int GetElem(SeqList L, int i)
{
    // 1.判断合法性
    if (i < 1 || i > L.length)
    {
        return -9999;
    }

    // 2.查找表中第i个元素的值
    return L.data[i - 1];
}

// 查找--按值查找
int LocateElem(SeqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            // 返回的是位序
            return i + 1;
        }
    }
    return -9999;
}

int PrintfList(SeqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        printf("输出动态存储的顺序表的数据为：%d\n", L.data[i]);
    }

    return 0;
}

int main()
{
    // 声明一个顺序表，表名为L
    SeqList L;
    InitList(L);

    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    PrintfList(L);

    ListInsert(L, 4, 4);
    PrintfList(L);

    int e = -9999;
    ListDelete(L, 2, e);
    printf("被删除的是：%d \n", e);
    PrintfList(L);

    printf("第二个位置的元素是：%d\n", GetElem(L, 2));
    printf("值为3的位置是：%d \n", LocateElem(L, 3));

    return 0;
}
