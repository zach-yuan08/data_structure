#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int stack_data_type;
typedef struct stack
{
	stack_data_type* arr;
	int capacity;
	int top;
}stack;

void stack_init(stack* ps);

void stack_destroy(stack* ps);

void stack_push(stack* ps, stack_data_type x);

void stack_pop(stack* ps);

bool stack_empty(stack* ps);

stack_data_type stack_top(stack* ps);

int stack_size(stack* ps);
