#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//打印函数
void SeqListPrintf(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//检查容量
void SeqListCheckCapacity(SL* ps)
{
	//插入数据，前提是需要有足够的容量，判定有无空间或空间不足。
	if (ps->size == ps->capacity)
	{
		//int newcapacity = ps->capacity * 2;//这个写法有个bug，因为当数据刚开始存入时，结构体是没有空间容量的，0*0无意义。
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//开辟空间，在没有容量的时候，realloc和malloc的作用一样。
		SLDatatype* tmp = (SLDatatype*)realloc(ps->arr, newcapacity * sizeof(SLDatatype));
		if (tmp == NULL)
		{
			printf("%d\n", strerror(errno));
			exit(-1);
		}
		//动态开辟空间是否成功判定结束
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

void SeqListPushBack(SL* ps, SLDatatype x)//末尾插入
{
	SeqListCheckCapacity(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}

void SeqListPopBack(SL* ps)//末尾删除
{
	//强制判断
    //assert(ps->size > 0)  //直接用assert断言，如果size合法，进入；如果<0，运行时直接提示出错。
	//ps->arr[ps->size] = 0;//这种写法是不正确的，因为0也可能是数据，并不能代表将容器中的元素删除掉了
	//柔性方式，判断元素下标是否合法。
	if (ps->size > 0)
	{
		ps->size--;//直接让元素个数（可访问下标）减少，那么不管里面存储的数据是多少，元素个数都相当于减少了。
	}
	else
		printf("尾删失败。元素个数不足。\n");
}

void SeqListPushFront(SL* ps, SLDatatype x)//开头插入
{
	SeqListCheckCapacity(ps);
	//存在一个问题，如果元素个数和数据表容量相同，挪动数据会造成非法访问。所以在挪动之前需要检查或者扩容。
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->arr[end + 1] = ps->arr[end];
		end--;
	}//挪动后放入数据。
	ps->arr[0] = x;
	ps->size++;
}
void SeqListPopFront(SL* ps)//开头删除
{
	//和头插一样，需要考虑非法访问问题。如果没有元素，那么删除将毫无意义。
	assert(ps->size > 0);
	int begin = 1;//不会从下标为0的往前挪动，不然越界。
	while (begin < ps->size)
	{
		ps->arr[begin - 1] = ps->arr[begin];//向前挪动
		begin++;
	}
	//挪动完成后，元素数量减少
	ps->size--;
}
int SeqListFind(SL* ps, SLDatatype x)//查找元素函数  找到返回下标，没找到返回-1
{
	//首先还是得考虑是否合法的问题。不然查找毫无意义。
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

void SeqListInsert(SL* ps, int pos, SLDatatype x)//指定位置插入
{
	//先判定pos指定下标的合理性。
	assert(pos >= 0);
	assert(pos < ps->size);
	//首先判定插入的位置是否存在，或者说元素个数和元素容量是否允许插入
	if (ps->capacity == 0)//没有容量
	{
		printf("插入失败，数据表没有容量。\n");
		exit(-1);
	}
	else if (ps->size == ps->capacity != 0)//容量不足
	{
		SeqListCheckCapacity(ps);//开辟空间
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

void SeqListErase(SL* ps, int pos)//指定位置删除
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
