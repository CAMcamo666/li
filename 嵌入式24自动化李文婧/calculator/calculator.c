#include "calculator.h"
#include<stdlib.h>
// ��ʼ��
void initStack(Stack* s)
{
    s->top = -1; /*�����ջ*/
}

// ���ջ�Ƿ�Ϊ��
int isEmpty(Stack* s)
{
    return s->top == -1;
}

// ջ�Ƿ�����
int isFull(Stack* s)
{
    return s->top == MAX_STACK_SIZE - 1;  /*�ռ��С��ϵ��ջ��ָ�뵽�������������*/
}

// ��ջ
void push(Stack* s, int value)
{
    if (isFull(s))  /* ���վ�Ƿ�����*/
    {
        printf("ջ���\n"); 
        exit(1);
    }
    s->data[++(s->top)] = value; /*ջָ���1������ջ��*/
}

// ��ջ����
int pop(Stack* s) 
{
    if (isEmpty(s))   /*���ջ�Ƿ��*/
    {
        printf("ջ����\n");
        exit(1);  /*����ջ��Ԫ�أ�ջ��ָ���1*/
    }
    return s->data[(s->top)--];
}

// �鿴ջ��Ԫ��
int peek(Stack* s) 
{
    if (isEmpty(s))
    {
        printf("ջΪ��\n");
        exit(1);
    }
    return s->data[s->top]; /*����ջ��Ԫ��*/
}

// ��ȡ��������ȼ� ���ܺ���
int precedence(char op) 
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

// Ӧ�������
int applyOp(int a, int b, char op)
{
    switch (op) 
    {
    case '+': return a + b; 
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return 0;
    }
}

// ���ʽ��ֵ����
int evaluate(char* expression)
{
    Stack values, ops; /*������ջ����ջ*/
    initStack(&values);/*��ʼ��*/
    initStack(&ops);

    for (int i = 0; i < strlen(expression); i++) /*����*/
    {
        if (expression[i] == ' ') 
        {
            continue;
        }
        else if (isdigit(expression[i])) 
        {
            int val = 0;
            while (i < strlen(expression) && isdigit(expression[i]))
            {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            i--;  /*����һ��*/
            push(&values, val);
        }
        else if (expression[i] == '(')
        {
            push(&ops, expression[i]);
        }
        else if (expression[i] == ')') 
        {
            while (!isEmpty(&ops) && peek(&ops) != '(') 
            {
                int val2 = pop(&values);
                int val1 = pop(&values);
                char op = pop(&ops);
                push(&values, applyOp(val1, val2, op)); /*������ѹ�������ջ*/
            }
            pop(&ops); /*�Ƴ� '('*/
        }
        else 
        {  
            /*�������ȼ��ߵ�*/
            while (!isEmpty(&ops) && precedence(peek(&ops)) >= precedence(expression[i])) {
                int val2 = pop(&values);
                int val1 = pop(&values);
                char op = pop(&ops);
                push(&values, applyOp(val1, val2, op));
            }
            push(&ops, expression[i]);
        }
    }
   /* ����ʣ�������*/
    while (!isEmpty(&ops)) 
    {
        int val2 = pop(&values);
        int val1 = pop(&values);
        char op = pop(&ops);
        push(&values, applyOp(val1, val2, op));
    }

    return pop(&values);
}

// ������
int main() 
{
    char expression[100];
    printf("������: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0; /*�Ƴ����з�*/

    int result = evaluate(expression);
    printf("���: %d\n", result);

    system("pause");
    return 0;
}