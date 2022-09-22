#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void menu()
{
	printf("********      请选择需要的操作    ********\n");
	printf("********  1.首插          2.首删  ********\n");
	printf("********  3.尾插          4.尾删  ********\n");
	printf("********  5.指定插入      6.指删  ********\n");
	printf("********  7.查找          0.Exit  ********\n");
}

void Test()
{
	SL seq;
	SeqListInit(&seq);
	int input = 0;
	do
	{
		printf("请选择：>");
		scanf("%d", &input);
		int x = 0;
		int pos = 0;
		switch (input)
		{
		case PushFront:
			printf("请输入首项插入的数据：>");
			scanf("%d", &x);
			SeqListPushFront(&seq, x);
			SeqListPrintf(&seq);
			break;
		case PopFront:
			SeqListPopFront(&seq);
			printf("首项删除成功。\n");
			SeqListPrintf(&seq);
			break;
		case PushBack:
			printf("请输入末尾插入的数据：>");
			scanf("%d", &x);
			SeqListPushBack(&seq, x);
			SeqListPrintf(&seq);
			break;
		case PopBack:
			SeqListPopBack(&seq);
			printf("尾项删除成功。\n");
			SeqListPrintf(&seq);
			break;
		case Insert:
			printf("请输入插入数据的下标：>");
			scanf("%d", &pos);
			printf("请输入需要插入的数据：>");
			scanf("%d", &x);
			SeqListInsert(&seq, pos, x);
			SeqListPrintf(&seq);
			break;
		case Erase:
			printf("请输入删除数据的下标：>");
			scanf("%d", &pos);
			SeqListErase(&seq, pos);
			SeqListPrintf(&seq);
			break;
		case Find:
			SeqListPrintf(&seq);
			printf("请输入需要查找的数据：>");
			scanf("%d", &x);
			pos = SeqListFind(&seq, x);
			if (-1 != pos)
			{
				printf("找到了，下标为 %d 。\n", pos);
			}
			else
				printf("没找到。\n");
			break;
		case Exit:
			printf("退出程序。\n");
			SeqListDestory(&seq);
			break;
		default:
			printf("选择错误，请重试。\n");
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