// Stack.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include"ArrayStack.h"
#include<iostream>

using namespace std;

void test()
{
	int temp = 0;
	ArrayStack<int> *arr = new ArrayStack<int>();

	arr->push(10);
	arr->push(30);
	arr->push(20);

	temp = arr->pop();
	cout << "(pop)temp=" << temp << endl;
	temp = arr->peek();

	cout << "(peek)temp=" << temp << endl;

	arr->push(60);
	while (!arr->isEmpty())
	{
		temp = arr->pop();
		cout << temp << endl;
	}


}


int main()
{
	test();
	getchar();
    return 0;
}

