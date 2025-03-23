#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char ElemType;

// ������ջ�ڵ�ṹ
typedef struct linknode
{
    ElemType data;              // ������
    struct linknode* next;      // ָ����ָ����һ���ڵ�
} LinkStNode;

// ��ʼ��ջ
LinkStNode* InitStack();

// ����ջ
void DestroyStack(LinkStNode* top);

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(LinkStNode* top);

// ��ջ
void Push(LinkStNode* top, ElemType e);

// ��ջ
bool Pop(LinkStNode* top, ElemType* e);

// ��ȡջ��Ԫ��
bool GetTop(LinkStNode* top, ElemType* e);

#endif // LINKSTACK_H