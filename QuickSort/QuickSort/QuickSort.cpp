// QuickSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<ctime>
using namespace std;
//从数列中找出一个基准值，前面都是比其小的，后面都是比其大的
//然后进行递归

void Q(int* a, int l, int r);
void QuickSort(int* a, int l, int r);

void QuickSort(int* a, int l, int r)
{
	if (l < r)
	{
		int i = l;
		int j = r;
		int x = a[i];//划分数列左右的基准值
		while (i < j)
		{
			while (i<j&&a[j]>x)
			{
				j--;
			}
			if (i<j)
			{
				a[i++] = a[j];
			}
			while (i<j&&a[i]<x)
			{
				i++;
			}
			if (i<j)
			{
				a[j--] = a[i];
			}
		}
		a[i] = x;
		QuickSort(a, l, i - 1);
		QuickSort(a, i + 1, r);
	}
}



int main()
{
	clock_t startTime, endTime;
	startTime = clock();
	int i = 0;
	int a[] = { 1,3,57,23,4,56,1,3,57,23,4,56 ,1,3,57,23,4,56 ,1,3,57,23,4,56 };
	int len = (sizeof(a)) / (sizeof(a[0]));
	cout << "排序之前：" << endl;
	for (int i = 0;i<len;i++)
	{
		cout << a[i] << "\t" ;
	}
	cout << endl;

	Q(a, 0, len - 1);
	cout << "排序之后：" << endl;
	for (int i = 0;i < len;i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;

	endTime = clock();
	cout << "运行时间："<<(double)(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;

	system("pause");
	return 0;
}

void Q(int* a, int l, int r)
{
	if (l<r)
	{
		int i = l;
		int j = r;
		int x = a[i];
		while (i < j)
		{
			while (i<j&&a[j]>x)
			{
				j--;
			}
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}
			while (i < j&&a[i] < x)
			{
				i++;
			}
			if (i < j)
			{
				a[j] = a[i];
				j--;
			}
		}
		a[i] = x;
		Q(a, l, i - 1);
		Q(a, i + 1, r);

	}
	


}