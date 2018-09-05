#pragma once
#ifndef Queue 
#define Queue
#include <iostream>
using namespace std;


template<class T>
class ArrayQueue
{
public:
	ArrayQueue();
	~ArrayQueue();

	void add(T t);
	T front();
	T pop();
	int size();
	int is_empty();
private:
	T * arr;
	int count;
};

template<class T>
ArrayQueue<T>::ArrayQueue()
{
	arr = new T[12];
	if (!arr)
	{
		cout << "ÄÚ´æ·ÖÅäÊ§°Ü£¡" << endl;
	}
}

template<class T>
ArrayQueue<T>::~ArrayQueue()
{
	if (arr)
	{
		delete[] arr;
		arr = NULL;
	}
}

template<class T>
void ArrayQueue<T>::add(T t)
{
	arr[count++] = t;
}

template<class T>
T ArrayQueue<T>::front()
{
	return arr[0];
}

template<class T>
T ArrayQueue<T>::pop()
{
	T temp = arr[0];
	for (int i = 0;i<count;i++)
	{
		arr[i] = arr[i + 1];
	}
	count--;
	return temp;

}
template<class T>
int ArrayQueue<T>::size()
{
	return count;
}

template<class T>
int ArrayQueue<T>::is_empty()
{
	return count == 0;
}









#endif