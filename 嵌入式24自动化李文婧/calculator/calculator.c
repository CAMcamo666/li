#include "calculator.h"
#include<stdlib.h>
// 初始化
void initStack(Stack* s)
{
    s->top = -1; /*构造空栈*/
}

// 检查栈是否为空
int isEmpty(Stack* s)
{
    return s->top == -1;
}

// 栈是否已满
int isFull(Stack* s)
{
    return s->top == MAX_STACK_SIZE - 1;  /*空间大小关系，栈顶指针到最大容量，就满*/
}

// 入栈
void push(Stack* s, int value)
{
    if (isFull(s))  /* 检查站是否已满*/
    {
        printf("栈溢出\n"); 
        exit(1);
    }
    s->data[++(s->top)] = value; /*栈指针加1，存入栈中*/
}

// 出栈操作
int pop(Stack* s) 
{
    if (isEmpty(s))   /*检查栈是否空*/
    {
        printf("栈下溢\n");
        exit(1);  /*返回栈顶元素，栈顶指针减1*/
    }
    return s->data[(s->top)--];
}

// 查看栈顶元素
int peek(Stack* s) 
{
    if (isEmpty(s))
    {
        printf("栈为空\n");
        exit(1);
    }
    return s->data[s->top]; /*返回栈顶元素*/
}

// 获取运算符优先级 功能函数
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

// 应用运算符
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

// 表达式求值函数
int evaluate(char* expression)
{
    Stack values, ops; /*操作数栈，符栈*/
    initStack(&values);/*初始化*/
    initStack(&ops);

    for (int i = 0; i < strlen(expression); i++) /*遍历*/
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
            i--;  /*回退一步*/
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
                push(&values, applyOp(val1, val2, op)); /*计算结果压入操作数栈*/
            }
            pop(&ops); /*移除 '('*/
        }
        else 
        {  
            /*处理优先级高的*/
            while (!isEmpty(&ops) && precedence(peek(&ops)) >= precedence(expression[i])) {
                int val2 = pop(&values);
                int val1 = pop(&values);
                char op = pop(&ops);
                push(&values, applyOp(val1, val2, op));
            }
            push(&ops, expression[i]);
        }
    }
   /* 处理剩余运算符*/
    while (!isEmpty(&ops)) 
    {
        int val2 = pop(&values);
        int val1 = pop(&values);
        char op = pop(&ops);
        push(&values, applyOp(val1, val2, op));
    }

    return pop(&values);
}

// 主函数
int main() 
{
    char expression[100];
    printf("请输入: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0; /*移除换行符*/

    int result = evaluate(expression);
    printf("结果: %d\n", result);

    system("pause");
    return 0;
}