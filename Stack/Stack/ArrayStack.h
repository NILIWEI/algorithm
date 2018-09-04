#pragma once
#include<iostream>
using namespace std;

template<class T>
class ArrayStack
{
public:
	ArrayStack();
	~ArrayStack();

	void push(T t);
	T peek();
	T pop();
	int size();
	int isEmpty();
private:
	T * arr;
	int count;
};

//创建栈
template<class T>
ArrayStack<T>::ArrayStack() :count(0)
{
	arr = new T[12];
	if (!arr)
	{
		cout << "创建时分配内存出错" << endl;
	}
}

template<class T>
ArrayStack<T>::~ArrayStack()
{
	if (arr)
	{
		delete[] arr;
		arr = NULL;
	}
}


template<class T>
void ArrayStack<T>::push(T t)
{
	arr[count++] = t;
}

template<class T>

T ArrayStack<T>::peek()
{
	return arr[count-1];
}


template<class T>
T ArrayStack<T>::pop()
{
	int temp = arr[count-1];
	count--;
	return temp;
}

template<class T>
int ArrayStack<T>::size()
{
	return count;
}
template<class T>
int ArrayStack<T>::isEmpty()
{
	return count == 0;
}


















































