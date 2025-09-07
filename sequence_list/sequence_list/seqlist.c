#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

void sl_init(sl* ps)
{
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

void sl_destroy(sl* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}

void sl_check_capacity(sl* ps)
{
	if (ps->size == ps->capacity)
	{
		int new_capacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		sl_data_type* tmp = (sl_data_type*)realloc(ps->arr, new_capacity * sizeof(sl_data_type));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = new_capacity;
	}
}

void sl_push_back(sl* ps, sl_data_type x)
{
	assert(ps);
	sl_check_capacity(ps);
	ps->arr[ps->size++] = x;
}

void sl_print(sl* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

void sl_push_front(sl* ps, sl_data_type x)
{
	assert(ps);
	sl_check_capacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

void sl_pop_back(sl* ps)
{
	assert(ps);
	assert(ps->arr);
	ps->size--;
}

void sl_pop_front(sl* ps)
{
	assert(ps);
	assert(ps->arr);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

void sl_insert(sl* ps, sl_data_type x, size_t pos)
{
	assert(ps);
	assert(pos >= 1 && pos <= ps->size + 1);
	sl_check_capacity(ps);
	for (int i = ps->size; i >= pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos - 1] = x;
	ps->size++;
}

void sl_erase(sl* ps, size_t pos)
{
	assert(ps);
	assert(ps->arr);
	for (int i = pos - 1; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

int sl_find(sl* ps, sl_data_type x)
{
	for (int i = 0; i <= ps->size; i++)
	{
		if (ps->arr[i] == x) return i + 1;
	}
	return -1;
}