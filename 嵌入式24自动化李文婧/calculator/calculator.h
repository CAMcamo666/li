#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// ����ջ�ṹ
typedef struct {
    int data[MAX_STACK_SIZE]; /*ջ�Ĵ洢����*/
    int top; /*ջ��ָ��*/
} Stack;

// ��������
//��ʼ��
void initStack(Stack* s);
//����Ƿ�Ϊ��
int isEmpty(Stack* s);
//�����
int isFull(Stack* s);
//��ջ
void push(Stack* s, int value);
//��ջ
int pop(Stack* s);
//�鿴ջ��Ԫ��
int peek(Stack* s);
//��ȡ��������ȼ�
int precedence(char op);
//Ӧ����������м���
int applyOp(int a, int b, char op);
//��ֵ����
int evaluate(char* expression);

#endif // CALCULATOR_H

