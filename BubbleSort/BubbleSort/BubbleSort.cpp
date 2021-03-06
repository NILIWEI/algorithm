// BubbleSort.cpp: 定义控制台应用程序的入口点。
//
//这里包含普通的冒泡排序以及其改进版

#include "stdafx.h"
#include<iostream>
#include <ctime>
using namespace std;


void BubbleSort(int* a,int n)
{
	for (int i = n - 1;i > 0;i--)
	{
		for (int j = 0;j < i;j++)
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}


//当数组中有数进行交换则说明排序还没完成，如果又一次排序过程中没有数的交换，则说明当前数组已经排好序了
void BubbleSortPlus(int* a,int n)
{
	int flag;//用来标记排序过程中有没有发生数的交换
	for (int i = n-1;i>0;i--)
	{
		flag = 0;
		for (int j = 0;j<i;j++)
		{
			if (a[j]>a[j+1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;

				flag = 1;
			}
		}
		if (flag ==0)
		{
			break;
		}
	}


}


int main()
{
	clock_t startTime, endTime;//计算程序的运行时间
	startTime = clock();
	int a[] = { 1,3,57,23,4,56,1,3,57,23,4,56 ,1,3,57,23,4,56 ,1,3,57,23,4,56 };
	int i_len = (sizeof(a)) / (sizeof(a[0]));
	cout << "排序之前：" << endl;
	for (int i  =0;i<i_len;i++)
	{
		cout << a[i] << endl;
	}

	BubbleSortPlus(a, i_len);

	cout<<"排序之后："<<endl;
	for (int i = 0;i < i_len;i++)
	{
		cout << a[i] << endl;
	}
	endTime = clock();
	cout << "TimeRun:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	system("pause");
    return 0;
}

