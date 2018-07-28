#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <cstring>       //标准串和操作
#include <iostream>     //标准流操作
#include <limits>       //极限
#include <cmath>        //数学函数
#include <fstream>      //文件输入输出
#include <cctype>       //字符处理
#include <cstdlib>      //标准库
#include <iomanip>      //输入输出流格式设置
#include <cstdio>       //标准输入输出
#include <cstdarg>      //支持变长函数参数
#include <cassert>      //支持断言
#include <ctime>        //时间

using namespace std;

enum StatusCode
{
    FAIL,
    SUCCESS,
    UNDER_FLOW,
    OVER_FLOW,
    RANGE_ERROR,
    DUPLICATE_ERROR,
    NOT_PRESENT,
    ENTRY_INSERTED,
    ENTRY_FOUND,
    VISITED,            //访问错误
    UNVISITED,
};

#define DEFAULT_SIZE        100         //默认元素个数
#define DEFAULT_INFINIYT    0x3F3F3F3F  //无穷大 
#define MAX_LEN             10          //数组大小

char GetChar();    //获取字符（忽略空格和tab）
bool UserSayYes();                  //用户输入y/n
void SetRandSeed();
int GetRand(int n);
int GetRand();


template <typename ElemType>

void Swap(ElemType &a, ElemType &b)
{
    ElemType temp;

    temp = a;
    a = b;
    b = temp;
}

template <typename ElemType>

void Display(ElemType *m, int n)
{
    int i = 0;

    for(i=0; i<n; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
}



//定时器类Timer
class Timer
{
    private:
        clock_t startTime;
    public:
        Timer();
        ~Timer(void){};
        double getTime();       //获取运动时间
        void reset();           //重置时间
};

// 通用异常类
#define MAX_ERROR_MESSAGE_LEN 100

class Error
{
    //数据成员
    private:
        char message[MAX_ERROR_MESSAGE_LEN];
    // 方法声明
    public:
        Error();
        Error(char mes[]);
        ~Error(void) {};
        void Show() const;
};

#endif
