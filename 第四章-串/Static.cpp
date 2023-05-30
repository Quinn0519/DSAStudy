#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

// 预定义最大串长为255
#define MAXLEN 255

typedef struct SString
{
    // 每个分量存储一个字符--使用静态数组实现
    char ch[MAXLEN];
    // 串的实际长度
    int length = 0;
} SString;

// 赋值操作
bool StrAssign(SString &T, char *chars)
{
    // 当输入的字符串长度比静态数组值大，赋值失败
    if (strlen(chars) > MAXLEN)
        return false;
    T.length = 0;
    for (int i = 0; i <= strlen(chars); i++)
    {
        T.ch[T.length + 1] = chars[i];
        T.length++;
    }

    return true;
}

// 复制操作
bool Strcopy(SString &T, SString S)
{
    if (S.length > MAXLEN)
    {
        // 超过最大长度限制，复制失败
        return false;
    }

    strcpy(T.ch, S.ch);
    T.length = S.length;
    return true;
}

// 判空操作
bool StrEmpty(SString S)
{
    return (S.length == 0);
}

// 求串长
int StrLength(SString S)
{
    return S.length;
}

// 清空操作
bool ClearString(SString &S)
{
    S.length = 0;
    return true;
}

// 串联接--用T返回由s1和s2联接成的新串
bool Concat(SString &T, SString S1, SString S2)
{
    if (S1.length + S2.length > MAXLEN)
    {
        return false; // 超过最大长度限制，串联接失败
    }

    strcpy(T.ch, S1.ch);
    strcat(T.ch, S2.ch);
    T.length = S1.length + S2.length;
    return true;
}

// bool Concat(SString &T, SString S1, SString S2)
// {
//     for (int i = 0; i < S1.length; i++)
//     {
//         T.ch[i] = S1.ch[i];
//     }
//     T.length = S1.length;

//     for (int i = (S1.length); i <= (S1.length + S2.length); i++)
//     {
//         T.ch[i] = S2.ch[i - S1.length];
//     }
//     T.length += S2.length;

//     return true;
// }

// 输出串
void PrintString(SString S)
{
    for (int i = 0; i < S.length; i++)
    {
        cout << S.ch[i];
    }
    cout << endl;
}

// 求字串--用Sub返回串S的第pos个字符起长度为len的字串
bool SubString(SString &Sub, SString S, int pos, int len)
{
    pos = pos - 1;
    // 字串范围越界
    if (pos + len - 1 > S.length)
        return false;
    for (int i = pos; i < pos + len; i++)
    {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

// 比较操作--若S>T,返回值>0;若S=T,返回值=0;若S<T,返回值<0
int StrCompare(SString S, SString T)
{
    for (int i = 1; i < S.length && i < T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }

    // 扫描过的所有字符都相同，则长度长的串更大
    return S.length - T.length;
}

// 定位操作--若主串S中与串T存在值相同的字串，则返回它在主串S中第一次出现的位置，否则函数值为0
// 使用的是朴素模式匹配算法的思想
int Index(SString S, SString T)
{
    // 求出串S和串T的长度
    int i = 1, n = StrLength(S), m = StrLength(T);
    // 用于暂存字串
    SString sub;
    // 最多对比n - m + 1个字串
    while (i <= n - m + 1)
    {
        // 取出从位置i开始长度为m的字串，放到sub中
        SubString(sub, S, i, m);
        // 比较字串和模式串
        if (StrCompare(sub, T) != 0)
            // 若二者不相同即不匹配，则匹配下一个字串
            ++i;
        // 若相同，返回字串在主串中的位置
        else
            return i;
    }
    // S中不存在与T相等的字串,匹配失败
    return 0;
}

// 实际的朴素模式匹配算法--最坏时间复杂度O(mn)
int index2(SString S, SString T)
{
    // 分别用指针i和j去扫描主串S和模式串T
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {

        if (S.ch[i] == T.ch[j])
        {
            // 当i所指的字符与j所指的字符相同，则往后继续比较
            ++i;
            ++j;
        }

        else
        {
            // 匹配失败i指针疯狂回溯
            //  i指针指向下一个子串起始位置，j指向模式串的第一个位置
            //  即指针后退重新匹配
            i = i - j + 2;
            j = 1;
        }
    }

    if (j > T.length)
        return i - T.length;

    else
        return 0;
}

// KMP算法--最坏时间复杂度O(m+n)
// 求next数组的时间复杂度O(m)--预处理时间
// 模式匹配过程最坏的时间复杂度O(n)

// 过程：
// 根据模式串T，求出next数组
// 利用next数组进行匹配
int index_KMP(SString S, SString T, int next[])
{
    // 分别用指针i和j去扫描主串S和模式串T
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {

        if (j == 0 || S.ch[i] == T.ch[j])
        {
            // 当i所指的字符与j所指的字符相同，则往后继续比较
            ++i;
            ++j;
        }

        else
        {
            // i指针指不回溯
            // 模式串向右移动
            j = next[j];
        }
    }

    if (j > T.length)
        return i - T.length;

    else
        return 0;
}

int main()
{
    SString str1, str2, result;
    char chars1[] = "Hello";
    char chars2[] = "World";

    StrAssign(str1, chars1);
    StrAssign(str2, chars2);

    // 输出str1和str2
    cout << "str1: ";
    PrintString(str1);
    cout << "str2: ";
    PrintString(str2);

    // 进行串联接
    Concat(result, str1, str2);
    cout << "str1 + str2: ";
    PrintString(result);

    // // 清空str1
    // ClearString(str1);
    // cout << "str1 after clear: ";
    // PrintString(str1);

    // // 求子串
    // SString Sub;
    // SubString(Sub, str1, 2, 3);
    // PrintString(Sub);

    return 0;
}