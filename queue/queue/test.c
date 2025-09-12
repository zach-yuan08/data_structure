#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"

void queue_test01()
{
	queue q;
	queue_init(&q);
	queue_push(&q, 1);
	queue_push(&q, 2);
	queue_push(&q, 3);
	queue_push(&q, 4);
	queue_pop(&q);
	queue_pop(&q);
	queue_pop(&q);
	queue_pop(&q);
	queue_destroy(&q);
}

void queue_test02()
{
	queue q;
	queue_init(&q);
	queue_push(&q, 1);
	queue_push(&q, 2);
	queue_push(&q, 3);
	queue_push(&q, 4);
	printf("head = %d\n", queue_front(&q));
	printf("tail = %d\n", queue_back(&q));
	queue_destroy(&q);
}
int main()
{
	queue_test01();
	//queue_test02();
	return 0;
}