#include "utility.h"


// 设置当前时间为随机种子
void SetRandSeed()
{
    srand((unsigned)time(NULL));
}

// 生成0~n的随机数
int GetRand(int n)
{
    return rand() % (n);
}

// 生成随机数
int GetRand()
{
    return rand();
}


char GetChar()
{
    char ch;

    ch = getchar();
    while(ch != EOF &&
            (ch==' ' || ch=='\t'))
    {
        ;
    }
    return ch;

}

bool UserSayYes()
{
    char ch;
    bool response = true;

    do
    {
        if(response)
        {
            cout<<"(y, n)?:";
        }
        else
        {
            cout<<"Please input y or n:";
        }
        ch = GetChar();
        response = false;
    }
    while(ch!='y' && ch!='Y' && ch!='N' && ch!='n');

    while(GetChar() != '\n');       //跳过当前行后面的字符

    if(ch=='y' || ch=='Y')
    {
        response = true;
    }

    return response;
}

// ----------实现定时器类Timer------------

clock_t startTime;

Timer::Timer()
{
    startTime = clock();
}
double Timer::getTime()        //获取运动时间
{
    clock_t endTime = clock();

    return (double)(endTime-startTime)/(double)CLOCKS_PER_SEC;

}
void Timer::reset()            //重置时间
{
    startTime = clock();
}



// ----------------通用异常类--------------

Error::Error()
{
    strcpy(message, "一般性错误!");
}

Error::Error(char mes[])
{
    strcpy(message, mes);
}
void Error::Show() const
{
    cout << message << endl;            // 显示异常信息
}





