#define _CRT_SECURE_NO_WARNINGS 1

#include"productor_customer.h"

void thr_pro(BlockQueue* bq)
{
	int i = 0;
	while (1)
	{
		bq->Push(i);
		printf("pro data : %d\n", i++);
	}
}

void thr_cus(BlockQueue* bq)
{
	int data;
	while (1)
	{
		bq->Pop(&data);
		printf("cus data : %d\n", data);
	}
}
int main()
{
	vector<thread> vtp;
	vector<thread> vtc;
	BlockQueue bq;
	for (int i = 0; i < 4; i++)
	{
		vtp.push_back(thread(thr_pro, &bq));
		vtc.push_back(thread(thr_cus, &bq));
	}

	for (int i = 0; i < 4; i++)
	{
		vtp[i].join();
		vtc[i].join();
	}
	return 0;
}