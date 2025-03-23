#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char ElemType;

// 定义链栈节点结构
typedef struct linknode
{
    ElemType data;              // 数据域
    struct linknode* next;      // 指针域，指向下一个节点
} LinkStNode;

// 初始化栈
LinkStNode* InitStack();

// 销毁栈
void DestroyStack(LinkStNode* top);

// 判断栈是否为空
bool StackEmpty(LinkStNode* top);

// 入栈
void Push(LinkStNode* top, ElemType e);

// 出栈
bool Pop(LinkStNode* top, ElemType* e);

// 获取栈顶元素
bool GetTop(LinkStNode* top, ElemType* e);

#endif // LINKSTACK_H