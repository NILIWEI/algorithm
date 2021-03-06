// ArrayList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"DoubleLinkList.h"
#include<iostream>
#include<string>
using namespace std;

void int_Test()
{
	cout << "*************双向链表测试开始*************" << endl;
	//创建双向链表
	DoubleLink<int>* pdlink = new DoubleLink<int>();
	pdlink->insert(0,20);
	pdlink->append_last(20);
	pdlink->insert_first(10);
	pdlink->insert_first(9);
	/*pdlink->append_last(20);
	pdlink->append_last(30);
	pdlink->append_last(40);
*/
	//双向链表是否为空
	cout << "链表是否为空：" << pdlink->is_empty() << endl;
	//双向链表的大小
	cout << "链表大小：" << pdlink->size() << endl;

	//打印链表全部数据
	int size = pdlink->size();
	for (int i = 0; i < size; i++)
	{
		cout << "pdlink(" << i << ")=" << pdlink->get(i) << endl;
	}

}




void string_Test()
{
	string sarr[4] = { "ten", "twenty", "thirty", "forty" };
	cout << "\n----string_test----" << endl;
	// 创建双向链表
	DoubleLink<string>* pdlink = new DoubleLink<string>();

	pdlink->insert(0, sarr[1]);        // 将 sarr中第2个元素 插入到第一个位置
	pdlink->append_last(sarr[0]);    // 将 sarr中第1个元素  追加到链表末尾
	pdlink->insert_first(sarr[2]);    // 将 sarr中第3个元素  插入到第一个位置

		 // 双向链表是否为空
	cout << "is_empty()=" << pdlink->is_empty() << endl;
	// 双向链表的大小
	cout << "size()=" << pdlink->size() << endl;

	// 打印双向链表中的全部数据
	int sz = pdlink->size();
	for (int i = 0; i < sz; i++)
	{
		cout << "pdlink(" << i << ")=" << pdlink->get(i) << endl;
	}


}




struct stu
{
	int id;
	string name;
};

static stu arr_stu[]=
{
	{10,"sky"},{20,"butt"},{30,"dandan"}
};

#define ARR_STU_SIZE （（sizeof(arr_stu)）/sizeof(arr_stu[0])）

void object_Test()
{
	DoubleLink<stu>* pdlink = new DoubleLink<stu>();
	pdlink->insert(0,arr_stu[0]);
	pdlink->append_last(arr_stu[1]);
	pdlink->insert_first(arr_stu[2]);
	// 双向链表是否为空
	cout << "is_empty()=" << pdlink->is_empty() << endl;
	// 双向链表的大小
	cout << "size()=" << pdlink->size() << endl;

	// 打印双向链表中的全部数据
	int sz = pdlink->size();
	struct stu p;
	for (int i = 0; i < sz; i++)
	{
		p = pdlink->get(i);
		cout << "pdlink(" << i << ")=" << p.id<<","<<p.name<< endl;
	}


}


void main()
{
	int_Test();
	string_Test();
	object_Test();
	getchar();

}

