#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void heap_test01()
{
	//int ret = -1 / 2;
	//printf("%d ", ret); // 0
	heap hp;
	heap_init(&hp);

	int arr[] = { 17,20,10,13,19,15 };
	for (int i = 0; i < 6; i++)
	{
		heap_push(&hp, arr[i]);
	}

	//HPPop(&hp);

	while (!heap_empty(&hp))
	{
		printf("%d ", heap_top(&hp));
		heap_pop(&hp);
	}


	heap_destroy(&hp);
}

void test_bubble_sort()
{
	int arr[] = { 17,20,10,13,19,15 };
	bubble_sort(arr, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test_heap_sort()
{
	int arr[] = { 17,20,10,13,19,15 };
	heap_sort(arr, 6);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test_topk()
{
	//creat_data();
	top_k();
}

int main()
{
	//heap_test01();
	//test_bubble_sort();
	//test_heap_sort();
	test_topk();
	return 0;
}