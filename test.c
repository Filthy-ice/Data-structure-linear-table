#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void menu()
{
	printf("********      ��ѡ����Ҫ�Ĳ���    ********\n");
	printf("********  1.�ײ�          2.��ɾ  ********\n");
	printf("********  3.β��          4.βɾ  ********\n");
	printf("********  5.ָ������      6.ָɾ  ********\n");
	printf("********  7.����          0.Exit  ********\n");
}

void Test()
{
	SL seq;
	SeqListInit(&seq);
	int input = 0;
	do
	{
		printf("��ѡ��>");
		scanf("%d", &input);
		int x = 0;
		int pos = 0;
		switch (input)
		{
		case PushFront:
			printf("�����������������ݣ�>");
			scanf("%d", &x);
			SeqListPushFront(&seq, x);
			SeqListPrintf(&seq);
			break;
		case PopFront:
			SeqListPopFront(&seq);
			printf("����ɾ���ɹ���\n");
			SeqListPrintf(&seq);
			break;
		case PushBack:
			printf("������ĩβ��������ݣ�>");
			scanf("%d", &x);
			SeqListPushBack(&seq, x);
			SeqListPrintf(&seq);
			break;
		case PopBack:
			SeqListPopBack(&seq);
			printf("β��ɾ���ɹ���\n");
			SeqListPrintf(&seq);
			break;
		case Insert:
			printf("������������ݵ��±꣺>");
			scanf("%d", &pos);
			printf("��������Ҫ��������ݣ�>");
			scanf("%d", &x);
			SeqListInsert(&seq, pos, x);
			SeqListPrintf(&seq);
			break;
		case Erase:
			printf("������ɾ�����ݵ��±꣺>");
			scanf("%d", &pos);
			SeqListErase(&seq, pos);
			SeqListPrintf(&seq);
			break;
		case Find:
			SeqListPrintf(&seq);
			printf("��������Ҫ���ҵ����ݣ�>");
			scanf("%d", &x);
			pos = SeqListFind(&seq, x);
			if (-1 != pos)
			{
				printf("�ҵ��ˣ��±�Ϊ %d ��\n", pos);
			}
			else
				printf("û�ҵ���\n");
			break;
		case Exit:
			printf("�˳�����\n");
			SeqListDestory(&seq);
			break;
		default:
			printf("ѡ����������ԡ�\n");
			break;
		}
	} while (input);
}

int main()
{
	menu();
	Test();
	return 0;
}