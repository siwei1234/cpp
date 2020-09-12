#define _CRT_SECURE_NO_WARNINGS 1


#include"threadpool.h"
#include<cstdio>
#include<windows.h>
void func1(int data)
{
	printf("%d : %d\n", this_thread::get_id(), data);
}

void func2(int data)
{
	printf("%d : %d\n", this_thread::get_id(), data);
}


int main()
{
	ThreadPool p;
	for (int i = 0; i < 10; i++)
	{
		ThreadTask task;
		if (i % 2 == 0)
			task.SetTask(func1, i);
		else
			task.SetTask(func2, i);
		p.TaskPush(task);
	}
	Sleep(1000);
	return 0;
}