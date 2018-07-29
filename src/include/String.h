#ifndef __STRING_H__
#define __STRING_H__

#include "utility.h"
#include "linkList.h"

class String
{
    protected:
        mutable char * strVal;
        int length;
    public:
        String();                               //构造函数
        virtual ~String();                      //析构函数
        String(const String &copy);             //复制构造函数
        String(const char *copy);               //从c风格串转换的构造函数
        String(SimpleLinkList<char> &copy);     //从线性表转换的构造函数
        int Length() const;                     //求串的长度
        bool Empty() const;                     //判断是否为空串
        String &operator=(const String &copy);  //赋值运算符重载
        const char *CStr() const;               //将串转换成c风格串
        char &String::operator [](int pos) const;   //重载下标运算符

};

String Read(istream &input);                                //从输入流读入串
String Read(istream &input, char &terminalChar);            //从输入流读入串并用 ter
void Write(String &s);                                      //输出串
void Concat(String &copy, const String &original);          //将串 original连接到copy后
void Copy(String &copy, const String &original);            //将串 original复制到copy后
void Copy(String &copy, const String &original, int n);     //将串 original的n个字符复制到copy后
void Index(const String &tag, const String &original, int pos = 0);     //查找模式串tag在 original串中第pos个字符后第一次出现的位置 
String SubString(const String &tag, int pos, int len);      //查找模式串tag从第pos个位置长度为len的字符串 
bool operator==(const String &srv, const String &org);      //重载运算符==
bool operator<(const String &srv, const String &org);       //重载运算符<
bool operator>(const String &srv, const String &org);       //重载运算符>
bool operator>=(const String &srv, const String &org);      //重载运算符>=
bool operator<=(const String &srv, const String &org);      //重载运算符<=
bool operator!=(const String &srv, const String &org);      //重载运算符!=


#endif //__STRING_H__
