#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// 定义栈结构
typedef struct {
    int data[MAX_STACK_SIZE]; /*栈的存储数组*/
    int top; /*栈顶指针*/
} Stack;

// 函数声明
//初始化
void initStack(Stack* s);
//检查是否为空
int isEmpty(Stack* s);
//检查满
int isFull(Stack* s);
//入栈
void push(Stack* s, int value);
//出栈
int pop(Stack* s);
//查看栈顶元素
int peek(Stack* s);
//获取运算符优先级
int precedence(char op);
//应用运算符进行计算
int applyOp(int a, int b, char op);
//求值函数
int evaluate(char* expression);

#endif // CALCULATOR_H

