#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void heap_init(heap* php)
{
	assert(php);
	php->arr = NULL;
	php->capacity = php->size = 0;
}

void heap_destroy(heap* php)
{
	assert(php);
	if(php->arr)
	free(php->arr);
	php->arr = NULL;
	php->capacity = php->size = 0;
}
void swap(heap_data_type* child, heap_data_type* parent)
{
	heap_data_type tmp = *child;
	*child = *parent;
	*parent = tmp;
}

void adjust_up(heap_data_type* arr, int child)
{
	// 这里维护的是小根堆
	int parent = (child - 1) / 2;
	while (child > 0) 
	{
		if (arr[child] < arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2; // -1 / 2 = 0
		}	
		else
		{
			break;
		}
	}
}

void heap_push(heap* php, heap_data_type x)
{
	assert(php);
	// 判断空间是否充足
	if (php->capacity == php->size)
	{
		int new_capacity = php->capacity == 0 ? 4 : php->capacity * 2;
		heap_data_type* tmp = (heap_data_type*)realloc(php->arr, new_capacity * sizeof(heap_data_type));
		if (tmp == NULL)
		{
			perror("reallo fail");
			exit(1);
		}
		php->arr = tmp;
		php->capacity = new_capacity;
	}
	php->arr[php->size] = x;
	adjust_up(php->arr, php->size); // 进行向上调整算法，维护小根堆的数据结构
	php->size++;
}

void adjust_down(heap_data_type* arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] > arr[child + 1])
			child++;
		if (arr[parent] > arr[child])
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void heap_pop(heap* php) 
{
	// 堆结构的特点，出堆时，出根节点
	assert(php);
	// 上来先交换根结点和最后一个结点的位置
	// 因为堆的底层数组，直接删除根节点需要移动大量数据
	// 但是数组的尾删就能很好的解决
	php->size--;
	swap(&php->arr[0], &php->arr[php->size]); 
	adjust_down(php->arr, 0, php->size);
}

heap_data_type heap_top(heap* php)
{
	assert(php && php->size);
	return php->arr[0];
}

bool heap_empty(heap* php)
{
	assert(php);
	return php->size == 0;
}

void bubble_sort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int flag = 0;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 1;
				swap(&arr[j], &arr[j + 1]);
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

void heap_sort(heap_data_type* arr, int size)
{
	// 向上调整算法建堆
	// 时间复杂度 O（nlogn）
	//for (int i = 0; i < size; i++)
	//{
	//	adjust_up(arr, i);
	//}

	// 向下调整建堆，从最后一个子树向上调整
	// 时间复杂度O（n）
	for (int i = size - 1 - 1 / 2; i >= 0; i--)
	{
		adjust_down(arr, i, size);
	}

	// 排序 堆结构的特点是根结点一定是最小值（小根堆）
	// 不断将根节点与最后一个结点交换位置，再将根结点向下调整就可得到降序数组
	int end = size - 1;
	while (end > 0)
	{
		swap(&arr[0], &arr[end]);
		adjust_down(arr, 0, end);
		end--;
	}
}

void creat_data()
{
	int n = 100000; // 数据个数
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int x = (rand() + i) % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

void top_k()
{
	int k = 0;
	printf("请输入k:");
	scanf("%d", &k);

	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		exit(1);
	}
	int* minheap = (int*)malloc(k * sizeof(int));
	if (minheap == NULL)
	{
		perror("malloc fail");
		exit(2);
	}

	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "&d", &minheap[i]);
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		adjust_down(minheap, i, k);
	}

	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > minheap[0])
		{
			minheap[0] = x;
			adjust_down(minheap, 0, k);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}

	fclose(fout);
}