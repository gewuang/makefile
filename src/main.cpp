/**
 * @file:    main.cpp
 * @brief: 
 * @author:  gewuang:751702112@qq.com
 * @version: 
 * @date:    2018-07-27
 */

#include "utility.h" 
#include "sort.h" 
#include "linkList.h"

#define MAX_LEN 10

int main(void)
{
    Timer timer;
    int a[MAX_LEN] = {0};
    int i = 0;
    SimpleLinkList<int> linklist;

    timer.reset();

    cout << "hello world!" << endl;
    SetRandSeed();

    for(i = 0; i < MAX_LEN; i++)
    {
        a[i] = GetRand(10);
        if(!linklist.Insert(i+1, a[i]))
        {
            cout << "插入失败" << endl;
        }
    }

    cout << "链表中的数据：" << endl;
    linklist.Traverse();

    cout << "排序前：" << endl;
    Display(a, MAX_LEN);

    mysort(a);

    cout << "排序后：" << endl;
    Display(a, MAX_LEN);

    cout << "pass time is " << timer.getTime() << "s." << endl;

    return 0;
}


