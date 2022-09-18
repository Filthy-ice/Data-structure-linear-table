#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define N 1000


////��̬˳���
//typedef struct SeqList
//{
//	SLDatatype a[N];
//	int size;
//}SL;
//
////���������������ݽṹ���ֳ�Ϊ  �ӿں���
//void SeqListInit(SL* ps, SLDatatype x);
//void SeqListPushBack(SL* ps, SLDatatype x);//ĩβ����
//void SeqListPopBack(SL* ps);//ĩβɾ��
//void SeqListPushFront(SL* ps, SLDatatype x);//��ͷ����
//void SeqListPopFront(SL* ps);//��ͷɾ��
////....




typedef int SLDatatype;

//��̬˳���
typedef struct SeqList
{
	SLDatatype* arr;
	int size;//�洢���ݵĸ���
	int capacity;//���Դ洢���ݵĸ���
}SL;

void SeqListPrintf(SL* ps);//��ӡ����
void SeqListCheckCapacity(SL* ps);//�������

//���������������ݽṹ���ֳ�Ϊ  �ӿں���
void SeqListInit(SL* ps);//��ʼ��
void SeqListDestory(SL* ps);//�ͷſռ䣨���٣�

void SeqListPushBack(SL* ps, SLDatatype x);//ĩβ����
void SeqListPopBack(SL* ps);//ĩβɾ��
void SeqListPushFront(SL* ps, SLDatatype x);//��ͷ����
void SeqListPopFront(SL* ps);//��ͷɾ��
//....