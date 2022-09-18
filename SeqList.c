#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//��ӡ����
void SeqListPrintf(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//�������
void SeqListCheckCapacity(SL* ps)
{
	//�������ݣ�ǰ������Ҫ���㹻���������ж����޿ռ��ռ䲻�㡣
	if (ps->size == ps->capacity)
	{
		//int newcapacity = ps->capacity * 2;//���д���и�bug����Ϊ�����ݸտ�ʼ����ʱ���ṹ����û�пռ������ģ�0*0�����塣
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//���ٿռ䣬��û��������ʱ��realloc��malloc������һ����
		SLDatatype* tmp = (SLDatatype*)realloc(ps->arr, newcapacity * sizeof(SLDatatype));
		if (tmp == NULL)
		{
			printf("%d\n", strerror(errno));
			exit(-1);
		}
		//��̬���ٿռ��Ƿ�ɹ��ж�����
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListDestory(SL* ps)
{
	free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPushBack(SL* ps, SLDatatype x)//ĩβ����
{
	SeqListCheckCapacity(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)//ĩβɾ��
{
	//ǿ���ж�
    //assert(ps->size > 0)  //ֱ����assert���ԣ����size�Ϸ������룻���<0������ʱֱ����ʾ����
	//ps->arr[ps->size] = 0;//����д���ǲ���ȷ�ģ���Ϊ0Ҳ���������ݣ������ܴ��������е�Ԫ��ɾ������
	//���Է�ʽ���ж�Ԫ���±��Ƿ�Ϸ���
	if (ps->size > 0)
	{
		ps->size--;//ֱ����Ԫ�ظ������ɷ����±꣩���٣���ô��������洢�������Ƕ��٣�Ԫ�ظ������൱�ڼ����ˡ�
	}
	else
		printf("βɾʧ�ܡ�Ԫ�ظ������㡣\n");
}

void SeqListPushFront(SL* ps, SLDatatype x)//��ͷ����
{
	SeqListCheckCapacity(ps);
	//����һ�����⣬���Ԫ�ظ��������ݱ�������ͬ��Ų�����ݻ���ɷǷ����ʡ�������Ų��֮ǰ��Ҫ���������ݡ�
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->arr[end + 1] = ps->arr[end];
		end--;
	}//Ų����������ݡ�
	ps->arr[0] = x;
	ps->size++;
}
void SeqListPopFront(SL* ps);//��ͷɾ��
