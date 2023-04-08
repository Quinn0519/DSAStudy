#include <stdio.h>
#include <iostream>
#define MaxSize 10

// 静态的顺序表一旦确定表长就无法更改

typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

// 初始化
void InitList(SqList &L)
{
    // 给各个元素设置默认值的部分可以省略--初始长度为0，循环无法执行
    //  for (int i = 0; i < L.length; i++)
    //  将所有数据的初始值置为0，
    //   L.data[i] = 0;
    //  顺序表的当前长度为0--未存入任何值
    L.length = 0;
}

// 插入数据

// i:表示第i个位置
// e：表示插入的元素e
bool ListInsert(SqList &L, int i, int e)
{
    // 1.判断合法性
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }

    // 2.判断顺序表是否已满
    if (L.length >= MaxSize)
    {
        return false;
    }

    // 3.插入操作：静态存储顺序表大小固定，所以插入操作需移动元素
    //            从最后一个元素开始，将第i个位置及以后的元素往后移动一位
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }

    // 4.将要插入的元素存入第i个位置
    L.data[i - 1] = e;

    // 5.修改顺序表长度，使其加一
    L.length++;

    return true;
}

// 删除数据
bool ListDelete(SqList &L, int i, int &e)
{
    // 1.判断合法性
    if (i < 1 || i > L.length)
    {
        return false;
    }

    // 将被删除的元素赋给e
    e = L.data[i - 1];
    // 2.删除操作：
    // 从第(i+1)个位置起，将第(i+1)个位置及其往后的所有元素往前移动一位
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;

    return true;
}

// 查找数据--按位查找
int GetElem(SqList L, int i)
{
    // 1.判断合法性
    if (i < 1 || i > L.length)
    {
        return -9999;
    }

    // 2.查找表中第i个元素的值
    return L.data[i - 1];
}

// 查找数据--按值查找
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }

    return -9999;
}

void PrintfList(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        std::cout << L.data[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // 声明一个顺序表，表名为L
    SqList L;
    InitList(L);

    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    PrintfList(L);

    int e = 0;
    ListDelete(L, 2, e);
    PrintfList(L);
    std::cout << "被删除的是：" << e << std::endl;

    std::cout << "第二个位置的元素是：" << GetElem(L, 2) << std::endl;

    std::cout << "值为3的位置是：" << LocateElem(L, 3) << std::endl;

    return 0;
}
