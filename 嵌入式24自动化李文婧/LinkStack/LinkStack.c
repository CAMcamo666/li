#include "LinkStack.h"
#include<stdlib.h>

// 初始化栈
LinkStNode* InitStack()
{
    LinkStNode* top = (LinkStNode*)malloc(sizeof(LinkStNode));
    top->next = NULL;
    return top;
}

// 销毁栈
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

// 判断栈是否为空
bool StackEmpty(LinkStNode* top)
{
    return (top->next == NULL);
}

// 入栈
void Push(LinkStNode* top, ElemType e)
{
    LinkStNode* p = (LinkStNode*)malloc(sizeof(LinkStNode));
    p->data = e;
    p->next = top->next;
    top->next = p;
}

// 出栈
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

// 获取栈顶元素
bool GetTop(LinkStNode* top, ElemType* e)
{
    if (top->next == NULL)
    {
        return false;
    }
    *e = top->next->data;
    return true;
}

//主程序运行

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