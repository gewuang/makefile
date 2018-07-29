#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include "utility.h"


/**
 * @brief: 结点类
 */
template <class ElemType>

class Node
{
    public:
        ElemType data;
        Node<ElemType> *next;
        Node();                 //构造函数
        Node(ElemType item, Node<ElemType> * link = NULL);
};

template <class ElemType>

class SimpleLinkList
{
    protected:
        Node<ElemType>* head;   //头结点指针
        void Init();            //初始化线性表
        Node<ElemType>* GetElemType(int position) const;        //返回指向第position个结点的指针
    public:
        SimpleLinkList();           //构造函数
        virtual ~SimpleLinkList();  //析构函数
        int Length() const;         //求线性表长度
        bool Empty() const;         //判断线性表是否为空
        void Clear();               //将线性表清空
        void Traverse();            //遍历线性表
        StatusCode GetElem(int position, ElemType &e) const;    //求指定位置的元素 
        StatusCode SetElem(int position, const ElemType &e);    //设置指定位置的元素 
        StatusCode Delete(int position, ElemType &e);           //删除元素，并将删除的数据存储的e中
        StatusCode Insert(int position, const ElemType &e);     //将e插入到指定位置
        SimpleLinkList(const SimpleLinkList<ElemType> &copy);   //复制构造函数
        SimpleLinkList<ElemType>&operator=(const SimpleLinkList<ElemType> &copy);   //运算符=重载
};
//--------------------------class Node

template <class ElemType>
Node<ElemType>::Node()                  //构造函数
{
    data = 0;
    next = NULL;
}

template <class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType>* link) 
{
    data = item;
    next = link;
}

//--------------------------class SimpleLinkList 

template <class ElemType>
void SimpleLinkList<ElemType>::Init()           //初始化线性表
{
    head = new Node<ElemType>;                  //构造头指针
}

template <class ElemType>
Node<ElemType>* SimpleLinkList<ElemType>::GetElemType(int position) const           //返回指向第position个结点的指针
{
    Node<ElemType>* tmpPtr = head;      //用tmpPtr遍历线性表以查找第postion个结点
    int curpotion = 0;

    //找到对应结点
    while(tmpPtr!=NULL && curpotion<position)
    {
        tmpPtr = tmpPtr->next;
        curpotion++;
    }

    //没找到
    if(curpotion != position)
    {
        tmpPtr = NULL;
    }
    return tmpPtr;
}

template <class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList()            //构造函数
{
    Init();
}

template <class ElemType>
SimpleLinkList<ElemType>::~SimpleLinkList()   //析构函数
{
    Clear();
    delete head;
}

template <class ElemType>
int SimpleLinkList<ElemType>::Length() const          //求线性表长度
{
    int length = 1;
    Node<ElemType> *tmpPtr = head->next;

    while(tmpPtr != NULL) 
    {
        length++;
        tmpPtr = tmpPtr->next;
    }
    return length;
}

template <class ElemType>
bool SimpleLinkList<ElemType>::Empty() const          //判断线性表是否为空
{
    return head->next==NULL;
}

template <class ElemType>
void SimpleLinkList<ElemType>::Clear()                //将线性表清空
{
    ElemType tmpElem;

    while(!Empty())
    {
        Delete(1, tmpElem);
    }
}

template <class ElemType>
void SimpleLinkList<ElemType>::Traverse()              //遍历线性表
{
    Node<ElemType> *tmpPtr = head->next;

    if(Empty())
    {
        cout << "线性表为空" << endl;
    }
    else
    {
        cout << "线性表数据如下:" << endl;
        while(tmpPtr != NULL)
        {
            cout << tmpPtr->data << " ";
            tmpPtr = tmpPtr->next;
        }
    }

    cout << endl;
    cout << endl;
}

template <class ElemType>
StatusCode SimpleLinkList<ElemType>::GetElem(int position, ElemType &e) const     //求指定位置的元素 
{
    StatusCode ret = FAIL;

    if(position<1 || position > Length())
    {
        ret = FAIL;
    }
    else
    {
        Node<ElemType>* ElemPtr = NULL;        //返回指向第position个结点的指针
        ElemPtr = GetElemType(position);        //返回指向第position个结点的指针
        e = ElemPtr->data;
        ret = SUCCESS;
    }

    return ret;
}

template <class ElemType>
StatusCode SimpleLinkList<ElemType>::SetElem(int position, const ElemType &e)     //设置指定位置的元素 
{
    StatusCode ret = FAIL;

    if(position<1 || position > Length())
    {
        ret = FAIL;
    }
    else
    {
        Node<ElemType>* ElemPtr = NULL;        //返回指向第position个结点的指针
        ElemPtr = GetElemType(position);        //返回指向第position个结点的指针
        ElemPtr->data = e;
        ret = SUCCESS;
    }

    return ret;
}

template <class ElemType>
StatusCode SimpleLinkList<ElemType>::Delete(int position, ElemType &e)            //删除元素，并将删除的数据存储的e中
{
    StatusCode ret = FAIL;

    if(position<1 || position > Length())
    {
        ret = FAIL;
    }
    else
    {
        Node<ElemType>* ElemPtr = NULL;        //返回指向第position个结点的指针
        Node<ElemType>* tmpPtr = NULL;        //返回指向第position个结点的指针
        ElemPtr = GetElemType(position-1);        //返回指向第position个结点的指针
        tmpPtr = ElemPtr->next;
        e = tmpPtr->data;
        ElemPtr->next = tmpPtr->next;
        delete tmpPtr;
        ret = SUCCESS;
    }

    return ret;
}


template <class ElemType>
StatusCode SimpleLinkList<ElemType>::Insert(int position, const ElemType &e)      //将e插入到指定位置
{
    StatusCode ret = FAIL;

    if(position<1 || position > Length())
    {
        ret = FAIL;
    }
    else
    {
        Node<ElemType>* ElemPtr = NULL;        //返回指向第position个结点的指针
        ElemPtr = GetElemType(position-1);        //返回指向第position个结点的指针
        Node<ElemType>* tmpPtr = new Node<ElemType>(e, ElemPtr->next);        //返回指向第position个结点的指针
        ElemPtr->next = tmpPtr;

        ret = SUCCESS;
    }

    return ret;
}

template <class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList(const SimpleLinkList<ElemType> &copy)    //复制构造函数
{
    int curpotion = 0;
    Node<ElemType>* ElemPtr = NULL;
    int length = copy.Length();
    Delete();
    Init();
    ElemPtr = head;

    while(curpotion < length)
    {
        Node<ElemType>* tmpPtr = new Node<ElemType>; 
        copy.GetElem(curpotion+1, tmpPtr->data);
        tmpPtr->next = NULL;
        ElemPtr->next = tmpPtr;
        ElemPtr = tmpPtr;
        curpotion++;
    }
}

// SimpleLinkList<ElemType>&operator=(const SimpleLinkList<ElemType> &copy);   //运算符=重载


#endif

