#include <stdio.h>
#define MaxSize 10

// 队满条件：
// 1.队尾指针的下一个元素为队头--但会浪费最后一个存储空间
//   if ((Q.rear + 1) % MaxSize == Q.front)

// 2.引入队列长度size后，插入成功size++，删除成功size--
// 当size等于数组长度时，队满
// Q.size == MaxSize

// 3.引入变量tag--表示最近进行的操作
// 值为0时表示最近执行删除，值为1时表示最近执行插入,执行相应操作后rear指针后移
// front==rear && tag==1

// 队空条件：
// 1.Q.rear == Q.front
// 2.size==0
// 3.front==rear && tag==0

// 注： 当前写法rear代表指向队尾元素的后一个位置，但也可能出现让rear指向队尾元素的情况

typedef struct
{
    // 用静态数组存放队列元素
    int data[MaxSize];
    // 定义队头和队尾指针
    // 队头指针指向队头元素，队尾指针指向队尾元素的后一个位置
    // 也就是队尾指针指向接下来要插入元素的位置
    int front, rear;
    // 队列当前长度
    int size;
} SqQueue;

// 初始化队列
void InitQueue(SqQueue &Q)
{
    // 由于队尾指针要指向要插入元素的位置，所以初始时，队头队尾指针均指向0
    Q.rear = Q.front = 0;
    Q.size = 0;
}

// 判断队列是否为空
bool QuueEmpty(SqQueue Q)
{
    if (Q.size == 0)
        return true;
    else
        return false;
}

// 入队
bool EnQueue(SqQueue &Q, int x)
{
    // 队满条件：队尾指针的下一个元素为队头--浪费空间暂不使用
    // if ((Q.rear + 1) % MaxSize == Q.front)

    // if (QuueFull(Q))
    //     printf("ee");
    // return false;

    if (Q.size == MaxSize)
        return false;

    // 将x插入队尾
    Q.data[Q.rear] = x;

    // 队尾指针加一取模--将存储空间从逻辑上变成了“环状”
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.size++;

    return true;
}

// 出队--删除一个队头元素并用x返回
bool DeQueue(SqQueue &Q, int &x)
{
    // 判空
    if (Q.size == 0)
        return false;

    x = Q.data[Q.front];
    // 队头指针后移--逻辑上成环状
    Q.front = (Q.front + 1) % MaxSize;
    Q.size--;
    return true;
}

// 查--获得队头元素的值，用x返回
int GetHead(SqQueue Q)
{
    // 判空
    if (Q.size == 0)
        return -999;

    int x = Q.data[Q.front];
    return x;
}

// 查--遍历
void GetAll(SqQueue Q, int &x)
{
    // 从队首开始输出--牺牲了一个存储空间
    // for (int i = Q.front; i != Q.rear; i = (i + 1) % MaxSize)
    // {
    //     printf("队列中的元素为：%d \n", Q.data[i]);
    // }

    for (int i = Q.front; Q.size != 0; i = (i + 1) % MaxSize)
    {
        printf("队列中的元素为：%d \n", Q.data[i]);
        Q.size--;
    }
    printf("\n");
}

int main()
{
    SqQueue Q;
    InitQueue(Q);

    // printf("当前队列是否为空：%d",QuueEmpty(Q));

    EnQueue(Q, 1);
    int x = 9;
    printf("队首元素为：%d \n", GetHead(Q));

    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    EnQueue(Q, 7);
    EnQueue(Q, 8);
    EnQueue(Q, 9);

    GetAll(Q, x);

    printf("队首：%d", GetHead(Q));

    int y = 2;
    DeQueue(Q, y);
    printf("出队元素为：%d \n", y);

    DeQueue(Q, y);
    DeQueue(Q, y);
    DeQueue(Q, y);
    DeQueue(Q, y);
    EnQueue(Q, 11);
    EnQueue(Q, 12);
    EnQueue(Q, 13);
    GetAll(Q, y);

    printf("当前队首：%d \n", GetHead(Q));

    printf("当前队列是否为空：%d ", QuueEmpty(Q));

    return 0;
}