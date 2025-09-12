#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void stack_test01()
{
	stack st;
	stack_init(&st);
	stack_push(&st, 1);
	stack_push(&st, 2);
	stack_push(&st, 3);
	stack_push(&st, 4);
	stack_pop(&st);
	stack_pop(&st);
	stack_pop(&st);
	stack_pop(&st);
	stack_destroy(&st);
}

void stack_test02()
{
	stack st;
	stack_init(&st);
	stack_push(&st, 1);
	stack_push(&st, 2);
	stack_push(&st, 3);
	stack_push(&st, 4);
	// 实现循环出栈
	while (!stack_empty(&st))
	{
		printf("%d ", stack_top(&st));
		stack_pop(&st);
	}
	printf("\n%d ", stack_size(&st));
}
int main()
{
	//stack_test01();
	stack_test02();
	return 0;
}