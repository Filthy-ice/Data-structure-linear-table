#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void TestSeqlist1()
{
	SL seq;
	//先创建一个SL结构体变量
	//初始化
	SeqListInit(&seq);
	//尾插数据。
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 5);

	SeqListPrintf(&seq);

	SeqListPopBack(&seq);
	SeqListPopBack(&seq);
	SeqListPopBack(&seq);

	SeqListPrintf(&seq);
	//释放内存,防止内存泄露
	SeqListDestory(&seq);
}


void TestSeqlist2()
{
	SL seq;
	//先创建一个SL结构体变量
	//初始化
	SeqListInit(&seq);
	//尾插数据。
	SeqListPushBack(&seq, 1);
	SeqListPushBack(&seq, 2);
	SeqListPushBack(&seq, 3);
	SeqListPushBack(&seq, 4);
	SeqListPushBack(&seq, 5);

	SeqListPrintf(&seq);

	//首插数据。
	SeqListPushFront(&seq,10);
	SeqListPushFront(&seq,20);
	SeqListPushFront(&seq,30);

	SeqListPrintf(&seq);

	SeqListDestory(&seq);
}
int main()
{
	//TestSeqlist1();
	TestSeqlist2();
	return 0;
}