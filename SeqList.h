#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define N 1000


////静态顺序表
//typedef struct SeqList
//{
//	SLDatatype a[N];
//	int size;
//}SL;
//
////函数声明，在数据结构里又称为  接口函数
//void SeqListInit(SL* ps, SLDatatype x);
//void SeqListPushBack(SL* ps, SLDatatype x);//末尾插入
//void SeqListPopBack(SL* ps);//末尾删除
//void SeqListPushFront(SL* ps, SLDatatype x);//开头插入
//void SeqListPopFront(SL* ps);//开头删除
////....




typedef int SLDatatype;

//动态顺序表
typedef struct SeqList
{
	SLDatatype* arr;
	int size;//存储数据的个数
	int capacity;//可以存储数据的个数
}SL;

void SeqListPrintf(SL* ps);//打印函数
void SeqListCheckCapacity(SL* ps);//检查容量

//函数声明，在数据结构里又称为  接口函数
void SeqListInit(SL* ps);//初始化
void SeqListDestory(SL* ps);//释放空间（销毁）

void SeqListPushBack(SL* ps, SLDatatype x);//末尾插入
void SeqListPopBack(SL* ps);//末尾删除
void SeqListPushFront(SL* ps, SLDatatype x);//开头插入
void SeqListPopFront(SL* ps);//开头删除
//....