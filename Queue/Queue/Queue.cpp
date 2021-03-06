// Queue.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Queue.h"
using namespace std;

void test()
{
	ArrayQueue<int>* array = new ArrayQueue<int>();
	array->add(12);
	array->add(14);
	array->add(22);
	int t = 0;
	t = array->pop();
	cout << "第一次pop:" << t << endl;

	cout << "是否为空：" << array->is_empty() << endl;
	cout << "大小" << array->size() << endl;
	while (!array->is_empty())
	{
		t = array->pop();
		cout << t << endl;
	}


}
//这里是使用C++的STL库
#include <queue>
void testSTL()
{
	int t = 0;
	queue<int> que;
	que.push(12);
	que.push(22);
	que.push(32);

	que.pop();

	t = que.front();
	cout << t << endl;

	que.push(42);

	cout << "是否为空：" << que.empty() << endl;
	cout << "大小" << que.size() << endl;
	while (!que.empty())
	{
		t = que.front();
		cout << t << endl;
		que.pop();
	}

}

int main()
{
	testSTL();
	getchar();
    return 0;
}

