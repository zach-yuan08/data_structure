#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>

typedef int heap_data_type;
typedef struct {
	heap_data_type* arr;
	int capacity;
	int size;
}heap;

void heap_init(heap* php);

void heap_destroy(heap* php);

void swap(heap_data_type* child, heap_data_type* parent);

void adjust_up(heap_data_type* arr, int child); 

void heap_push(heap* php, heap_data_type x);

void adjust_down(heap_data_type* arr, int parent, int n);

void heap_pop(heap* php);

heap_data_type heap_top(heap* php);

bool heap_empty(heap* php);

void bubble_sort(int* arr, int size);

void heap_sort(heap_data_type* arr, int size);

void creat_data();

void top_k();