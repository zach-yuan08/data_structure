#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void stack_init(stack* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}

void stack_destroy(stack* ps)
{
	assert(ps);
	if (ps->arr)
		free(ps->arr);
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}

void stack_push(stack* ps, stack_data_type x)
{
	assert(ps);
	// chack_capacity
	if (ps->capacity == ps->top)
	{
		int new_capacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		stack_data_type* tmp = (stack_data_type*)realloc(ps->arr,sizeof(stack) * new_capacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(1);
		}
		ps->capacity = new_capacity;
		ps->arr = tmp;
	}
	ps->arr[(ps->top)++] = x;
}

void stack_pop(stack* ps)
{
	assert(ps);
	if (!stack_empty(ps))
	{
		--ps->top;
	}
}

bool stack_empty(stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

stack_data_type stack_top(stack* ps)
{
	assert(ps);
	assert(!stack_empty(ps));
	return ps->arr[ps->top - 1];
}

int stack_size(stack* ps)
{
	assert(ps);
	return ps->top;
}