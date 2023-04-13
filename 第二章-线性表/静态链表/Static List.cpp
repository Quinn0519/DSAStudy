#include <stdio.h>
#define MaxSize 10

// struct Node
// {
//     int data;
//     int next;
// } ;
// 和下面typedef struct 的代码等价

typedef struct
{
    // 存储数据元素
    int data;
    // 下一个元素的数组下标
    int next;
} SLinkList[MaxSize];

// 查找--按位序查找
// 从头结点往后遍历

// 插入
// 判断结点为空，然后插入数据
// 从头结点出发找到位序为(i-1)的结点
// 修改新结点的next
// 修改(i-1)号结点的next

// 删除
// 从头结点出发，找到前驱结点
// 修改前驱结点的游标
//被删除的结点next设为-2

int main()
{
    //  SLinkList a;等价于 struct Node a[MaxSize];
    SLinkList a;
}
