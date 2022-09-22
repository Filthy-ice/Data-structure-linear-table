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
void SeqListPopFront(SL* ps)//��ͷɾ��
{
	//��ͷ��һ������Ҫ���ǷǷ��������⡣���û��Ԫ�أ���ôɾ�����������塣
	assert(ps->size > 0);
	int begin = 1;//������±�Ϊ0����ǰŲ������ȻԽ�硣
	while (begin < ps->size)
	{
		ps->arr[begin - 1] = ps->arr[begin];//��ǰŲ��
		begin++;
	}
	//Ų����ɺ�Ԫ����������
	ps->size--;
}
int SeqListFind(SL* ps, SLDatatype x)//����Ԫ�غ���  �ҵ������±꣬û�ҵ�����-1
{
	//���Ȼ��ǵÿ����Ƿ�Ϸ������⡣��Ȼ���Һ������塣
	assert(ps->size > 0);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDatatype x)//ָ��λ�ò���
{
	//���ж�posָ���±�ĺ����ԡ�
	assert(pos >= 0);
	assert(pos < ps->size);
	//�����ж������λ���Ƿ���ڣ�����˵Ԫ�ظ�����Ԫ�������Ƿ��������
	if (ps->capacity == 0)//û������
	{
		printf("����ʧ�ܣ����ݱ�û��������\n");
		exit(-1);
	}
	else if (ps->size == ps->capacity != 0)//��������
	{
		SeqListCheckCapacity(ps);//���ٿռ�
	}
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->arr[end + 1] = ps->arr[end];
		end--;
	}
	ps->arr[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)//ָ��λ��ɾ��
{
	assert(ps->size > 0);
	assert(pos >= 0);
	assert(pos <= ps->size);
	if (pos != ps->size-1)
	{
		while (pos <= ps->size - 2)
		{
			ps->arr[pos] = ps->arr[pos + 1];
			pos++;
		}
	}
	ps->size--;
}
