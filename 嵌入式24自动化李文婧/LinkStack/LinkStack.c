#include "LinkStack.h"
#include<stdlib.h>

// ��ʼ��ջ
LinkStNode* InitStack()
{
    LinkStNode* top = (LinkStNode*)malloc(sizeof(LinkStNode));
    top->next = NULL;
    return top;
}

// ����ջ
void DestroyStack(LinkStNode* top)
{
    LinkStNode* p = top->next;
    while (p != NULL)
    {
        LinkStNode* temp = p;
        p = p->next;
        free(temp);
    }
    free(top);
}

// �ж�ջ�Ƿ�Ϊ��
bool StackEmpty(LinkStNode* top)
{
    return (top->next == NULL);
}

// ��ջ
void Push(LinkStNode* top, ElemType e)
{
    LinkStNode* p = (LinkStNode*)malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = top->next;
    top->next = p;
}

// ��ջ
bool Pop(LinkStNode* top, ElemType* e)
{
    if (top->next == NULL) {
        return false;
    }
    LinkStNode* p = top->next;
    *e = p->data;
    top->next = p->next;
    free(p);
    return true;
}

// ��ȡջ��Ԫ��
bool GetTop(LinkStNode* top, ElemType* e)
{
    if (top->next == NULL)
    {
        return false;
    }
    *e = top->next->data;
    return true;
}

//����������

int main()
{
    ElemType e;
    LinkStNode* top = InitStack();

    Push(top, 'a');
    Push(top, 'b');
    Push(top, 'c');
    Push(top, 'd');
    Push(top, 'e');

    while (!StackEmpty(top))
    {
        Pop(top, &e);
        printf("%c", e);
    }
    printf("\n");

    DestroyStack(top);
    system("pause");
    return 0;
}