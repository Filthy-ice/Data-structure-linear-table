#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void TestSeqlist()
{
	SL seq;
	//�ȴ���һ��SL�ṹ�����
	//��ʼ��
	SeqListInit(&seq);
	//β�����ݡ�
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
	//�ͷ��ڴ�,��ֹ�ڴ�й¶
	SeqListDestory(&seq);
}

int main()
{
	TestSeqlist();
	return 0;
}