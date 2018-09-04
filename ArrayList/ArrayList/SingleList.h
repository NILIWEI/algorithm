#pragma once

#include<iostream>
using namespace std;

template<class T>
struct DNode
{
public:
	T value;
	DNode* next;
public:
	DNode() {}
	DNode(T t, DNode* next)
	{
		this->value = t;
		this->next = next;
	}
};

template<class T>
class SingleLink
{
public:
	SingleLink();
	~SingleLink();
	int size();
	int is_empty();

	T get(int index);
	T get_first();
	T get_last();

	int insert(int index, T t);
	int insert_first(T t);
	int append_last(T t);

	int del(int index);
	int delete_first();
	int delete_last();

private:
	int count;
	DNode<T>* phead;
private:
	DNode<T>* get_node(int index);
};

template<class T>
SingleLink<T>::SingleLink() :count(0)
{
	phead = new DNode<T>();
	phead->next = NULL;
}

template<class T>
SingleLink<T>::~SingleLink()
{
	////删除所有节点，释放内存
	//DNode<T>* ptmp;
	//DNode<T>* pnode = phead->next;
	//while (pnode != phead)
	//{
	//	ptmp = pnode
	//}
}

template<class T>
int SingleLink<T>::size()
{
	return count;
}

template<class T>
int SingleLink<T>::is_empty()
{
	return count == 0;
}
template<class T>
DNode<T>* SingleLink<T>::get_node(int index)
{
	if (index < 0 || index >= count)
	{
		return NULL;
	}
	int i = 0;
	DNode<T>* pindex = phead->next;
	while (i++ < index)
	{
		pindex = pindex->next
	}
	return pindex;
}
template<class T>
T SingleLink<T>::get(int index)
{
	return get_node(index)->value;
}


template<class T>
T SingleLink<T>::get_first()
{
	return get_node(0);
}

template<class T>
T SingleLink<T>::get_last()
{
	return get_node(count - 1);
}

template<calss T>
int SingleLink<T>::insert(int index, T t)
{
	if (index == 0)
		return insert_first(0);
	else
	{
		DNode<T>* pindex = get_node(index);
		DNode<T>* pnode = new DNode(t, pindex);

		pindex->next = pnode;
	}

}







































