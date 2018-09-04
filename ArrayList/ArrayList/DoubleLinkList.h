#pragma once
#ifndef DOUBLE_LINK_HXX
//#ifndef在头文件中的作用就是在一个.cpp源文件引用多个头文件时，
//可能这些头文件中也引用了相同的头文件，以此来避免这些头文件的重复引用

#define DOUBLE_LINK_HXX
using namespace std;
//模板类的使用，和泛型有些类似，泛型是模板类的一种推广使用
template<class T>
struct DNode
{
	public:
		T value;
		DNode *prev;
		DNode *next;
	public:
		DNode() {}
		DNode(T t, DNode *prev, DNode *next)
		{
			this->value = t;
			this->prev = prev;
			this->next = next;
		}
};

template<class T>
class DoubleLink {

public:
	DoubleLink();
	~DoubleLink();

	int size();
	int is_empty();

	T get(int index);
	T get_first();
	T get_last();

	int insert(int index,T t);
	int insert_first(T t);
	int append_last(T t);

	int del(int index);
	int delete_first();
	int delete_last();

private:
	int count;
	DNode<T> *phead;//phead作为头节点，不存储数据
private:
	DNode<T> *get_node(int index);

};

//构造一个双链表
template<class T>
DoubleLink<T>::DoubleLink() :count(0)
{
	//创建表头，注意表头没有存储数据
	phead = new DNode<T>();
	phead->prev = phead->next = phead;
	//设置链表计数为0
	//已经在上面将count初始化了

}


//析构函数，将内存清空，并回收内存
template<class T>
DoubleLink<T>::~DoubleLink()
{
	
	//删除所有的节点
	DNode<T>* ptmp;
	DNode<T>*  pnode = phead->next;
	while (pnode!=phead)
	{
		ptmp = pnode;
		pnode = pnode->next;
		delete ptmp;
	}

	//删除“表头”
	delete phead;
	phead = NULL;
}
//返回节点数目
template<class T>
int DoubleLink<T>::size()
{
	return count;
}
//返回链表是否为空
template<class T>
int DoubleLink<T>::is_empty()
{
	return count == 0;
}
//获取index位置的节点,
//然后获取了节点之后便可以进行获取值，删除节点，增加节点的操作
template<class T>
DNode<T>* DoubleLink<T>::get_node(int index)
{
	//判断参数的有效性
	if (index < 0 || index >= count)
	{
		cout << "获取节点失败，越界" << endl;
		return NULL;
	}
	//正向查找
	if (index <= count / 2)
	{
		int i = 0;
		DNode<T>* pindex = phead->next;
		while (i++<index)
		{
			pindex = pindex->next;
		}
		return pindex;
	}
	//反向查找
	else
	{
		int j = 0;
		int rindex = count - index - 1;
		DNode<T>* prindex = phead->prev;
		while (j++<rindex)
		{
			prindex = prindex->prev;
		}
		return prindex;
	}
}
//获取第index位置节点的值
template<class T>
T DoubleLink<T>::get(int index)
{
	return get_node(index)->value;
}

//获取第一个节点的值
template<class T>

T DoubleLink<T>::get_first()
{
	return get_node(0)->value;
}
//获取最后一个节点的值
template<class T>

T DoubleLink<T>::get_last()
{
	return get_node(count-1)->value;
}
//将节点插入到第index位置之前
template<class T>
int DoubleLink<T>::insert(int index, T t)
{
	if (index == 0)
	{
		return insert_first(t);
	}
	else
	{
		DNode<T>* pindex = get_node(index);
		DNode<T>* pnode = new DNode<T>(t,pindex->prev,pindex);
		pindex->prev->next = pnode;
		pindex->prev = pnode;
		count++;
		return 0;
	}

}
//将节点插入第一个节点处
template<class T>
int DoubleLink<T>::insert_first(T t)
{
	DNode<T>* pnode = new DNode<T>(t, phead, phead->next);
	phead->next->prev = pnode;
	phead->next = pnode;
	count++;
	return 0;

}

//将节点追加到链表末尾
template<class T>
int DoubleLink<T>::append_last(T t)
{
	DNode<T>* pnode = new DNode<T>(t,phead->prev,phead);
	phead->prev->next = pnode;
	phead->prev = pnode;
	count++;
	return 0;
}

//删除index位置的节点
template<class T>
int DoubleLink<T>::del(int index)
{
	DNode<T>* pnode = get_node(index);

	pnode->prev->next = pnode->next;
	pnode->next->prev = pnode->prev;
	delete pnode;
	count--;
	return 0;
}
//删除链表第一个节点
template<class T>
int DoubleLink<T>::delete_first()
{
	return del(0);
}
//删除链表最后一个节点

template<class T>
int DoubleLink<T>::delete_last()
{
	return del(count-1);
}
































#endif // !1
