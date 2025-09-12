#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
//
//typedef char stack_data_type;
//typedef struct stack
//{
//	stack_data_type* arr;
//	int capacity;
//	int top;
//}stack;
//
//
//void stack_init(stack* ps)
//{
//	assert(ps);
//	ps->arr = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void stack_destroy(stack* ps)
//{
//	assert(ps);
//	if (ps->arr)
//		free(ps->arr);
//	ps->arr = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void stack_push(stack* ps, stack_data_type x)
//{
//	assert(ps);
//	// chack_capacity
//	if (ps->capacity == ps->top)
//	{
//		int new_capacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
//		stack_data_type* tmp = (stack_data_type*)realloc(ps->arr, sizeof(stack) * new_capacity);
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			exit(1);
//		}
//		ps->capacity = new_capacity;
//		ps->arr = tmp;
//	}
//	ps->arr[(ps->top)++] = x;
//}
//
//void stack_pop(stack* ps)
//{
//	assert(ps);
//	if (!stack_empty(ps))
//	{
//		--ps->top;
//	}
//}
//
//bool stack_empty(stack* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//
//stack_data_type stack_top(stack* ps)
//{
//	assert(ps);
//	assert(!stack_empty(ps));
//	return ps->arr[ps->top - 1];
//}
//
//int stack_size(stack* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//
//// https://leetcode.cn/problems/valid-parentheses/description/
//bool isValid(char* s) 
//{
//	stack st;
//	stack_init(&st);
//	int i = 0;
//	int len = strlen(s);
//	while (i < len)
//	{
//		
//		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//		{
//			stack_push(&st, s[i++]);
//		}
//		else
//		{
//			if (s[i] == ')' || s[i] == ']' || s[i] == '}')
//			{
//				if (stack_empty(&st))
//				{
//					stack_destroy(&st);
//					return false;
//				}
//				char ch = stack_top(&st);
//				if (ch == '(' && s[i] == ')'  
//					|| ch == '[' && s[i] == ']'
//					|| ch == '{' && s[i] == '}')
//				{
//					i++;
//					stack_pop(&st);
//				}
//				else
//				{
//					stack_destroy(&st);
//					return false;
//				}
//			}
//		}	
//	}
//	bool ret = stack_empty(&st);
//	stack_destroy(&st);
//	return ret;
//}

// https://leetcode.cn/problems/implement-stack-using-queues/description/
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<stdbool.h>
//
//typedef int queue_data_type;
//typedef struct queue_node
//{
//	queue_data_type data;
//	struct queue_node* next;
//}queue_node;
//
//typedef struct queue
//{
//	queue_node* phead;
//	queue_node* ptail;
//	int size;
//}queue;
//
//void queue_init(queue* pq)
//{
//	assert(pq);
//	pq->phead = pq->ptail = NULL;
//	pq->size = 0;
//}
//
//void queue_push(queue* pq, queue_data_type x)
//{
//	assert(pq);
//	queue_node* new_node = (queue_node*)malloc(sizeof(queue_node));
//	if (new_node == NULL)
//	{
//		perror("malloc fail");
//		exit(1);
//	}
//
//	new_node->data = x;
//	new_node->next = NULL;
//	if (pq->phead == NULL)
//	{
//		pq->phead = pq->ptail = new_node;
//	}
//	else
//	{
//		pq->ptail->next = new_node;
//		pq->ptail = new_node;
//	}
//	pq->size++;
//}
//
//bool queue_empty(queue* pq)
//{
//	assert(pq);
//	return pq->phead == NULL;
//}
//void queue_pop(queue* pq)
//{
//	assert(pq);
//	assert(!queue_empty(pq));
//	if (pq->phead == pq->ptail)
//	{
//		free(pq->phead);
//		pq->phead = pq->ptail = NULL;
//	}
//	else
//	{
//		queue_node* del = pq->phead;
//		pq->phead = pq->phead->next;
//		free(del);
//		del = NULL;
//	}
//	pq->size--;
//}
//
//queue_data_type queue_front(queue* pq)
//{
//	assert(pq);
//	assert(!queue_empty(pq));
//	return pq->phead->data;
//}
//
//queue_data_type queue_back(queue* pq)
//{
//	assert(pq);
//	assert(!queue_empty(pq));
//	return pq->ptail->data;
//}
//
//int queue_size(queue* pq)
//{
//	return pq->size;
//}
//
//void queue_destroy(queue* pq)
//{
//	assert(pq);
//	while (pq->size)
//	{
//		queue_node* del = pq->phead;
//		pq->phead = pq->phead->next;
//		free(del);
//		del = NULL;
//		pq->size--;
//	}
//	pq->phead = pq->ptail = NULL;
//	pq->size = 0;
//}
//
//typedef struct {
//	queue q1;
//	queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate() {
//	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
//	queue_init(&pst->q1);
//	queue_init(&pst->q2);
//	return pst;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	if (!queue_empty(&obj->q1))
//	{
//		queue_push(&obj->q1, x);
//	}
//	else
//	{
//		queue_push(&obj->q2, x);
//	}
//}
//
//int myStackPop(MyStack* obj) {
//	queue* empq = &obj->q1;
//	queue* noneq = &obj->q2;
//	if (!queue_empty(&obj->q1))
//	{
//		empq = &obj->q2;
//		noneq = &obj->q1;
//	}
//	while (queue_size(noneq) > 1)
//	{
//		queue_data_type data = queue_front(noneq);
//		queue_push(empq, data);
//		queue_pop(noneq);
//	}
//	queue_data_type pop = queue_front(noneq);
//	queue_pop(noneq);
//	return pop;
//}
//
//int myStackTop(MyStack* obj) {
//	if (!queue_empty(&obj->q1))
//		return queue_back(&obj->q1);
//	else
//		return queue_back(&obj->q2);
//}
//
//bool myStackEmpty(MyStack* obj) {
//	return queue_empty(&obj->q1) && queue_empty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj) {
//	queue_destroy(&obj->q1);
//	queue_destroy(&obj->q2);
//	free(obj);
//	obj = NULL;
//}

// https://leetcode.cn/problems/implement-queue-using-stacks/description/
//typedef int stack_data_type;
//typedef struct stack
//{
//	stack_data_type* arr;
//	int capacity;
//	int top;
//}stack;
//
//void stack_init(stack* ps)
//{
//	assert(ps);
//	ps->arr = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void stack_destroy(stack* ps)
//{
//	assert(ps);
//	if (ps->arr)
//		free(ps->arr);
//	ps->arr = NULL;
//	ps->capacity = ps->top = 0;
//}
//
//void stack_push(stack* ps, stack_data_type x)
//{
//	assert(ps);
//	// chack_capacity
//	if (ps->capacity == ps->top)
//	{
//		int new_capacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
//		stack_data_type* tmp = (stack_data_type*)realloc(ps->arr, sizeof(stack) * new_capacity);
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			exit(1);
//		}
//		ps->capacity = new_capacity;
//		ps->arr = tmp;
//	}
//	ps->arr[(ps->top)++] = x;
//}
//
//void stack_pop(stack* ps)
//{
//	assert(ps);
//	if (!stack_empty(ps))
//	{
//		--ps->top;
//	}
//}
//
//bool stack_empty(stack* ps)
//{
//	assert(ps);
//	return ps->top == 0;
//}
//
//stack_data_type stack_top(stack* ps)
//{
//	assert(ps);
//	assert(!stack_empty(ps));
//	return ps->arr[ps->top - 1];
//}
//
//int stack_size(stack* ps)
//{
//	assert(ps);
//	return ps->top;
//}
//typedef struct {
//	stack stack_push;
//	stack stack_pop;
//
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//	MyQueue* pst = (MyQueue*)malloc(sizeof(MyQueue));
//	stack_init(&pst->stack_pop);
//	stack_init(&pst->stack_push);
//	return pst;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//	stack_push(&obj->stack_push, x);
//}
//
//int myQueuePop(MyQueue* obj) {
//	if (stack_empty(&obj->stack_pop))
//	{
//		while (!stack_empty(&obj->stack_push))
//		{
//			stack_push(&obj->stack_pop, stack_top(&obj->stack_push));
//			stack_pop(&obj->stack_push);
//		}
//	}
//	int top = stack_top(&obj->stack_pop);
//	stack_pop(&obj->stack_pop);
//	return top;
//}
//
//int myQueuePeek(MyQueue* obj) {
//	if (stack_empty(&obj->stack_pop))
//	{
//		while (!stack_empty(&obj->stack_push))
//		{
//			stack_push(&obj->stack_pop, stack_top(&obj->stack_push));
//			stack_pop(&obj->stack_push);
//		}
//	}
//	return stack_top(&obj->stack_pop);
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//	return stack_empty(&obj->stack_pop) && stack_empty(&obj->stack_push);
//}
//
//void myQueueFree(MyQueue* obj) {
//	stack_destroy(&obj->stack_pop);
//	stack_destroy(&obj->stack_push);
//	free(obj);
//	obj = NULL;
//}

// https://leetcode.cn/problems/design-circular-queue/description/
//typedef struct {
//	int* arr;
//	int front;
//	int rear;
//	int capacity;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//	MyCircularQueue* pst = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//	pst->arr = (int*)malloc(sizeof(int) * (k + 1));
//	pst->front = pst->rear = 0;
//	pst->capacity = k;
//	return pst;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//	return obj->front == obj->rear;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//	return (obj->rear + 1) % (obj->capacity + 1) == obj->front;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//	if (myCircularQueueIsFull(obj))
//		return false;
//	obj->arr[obj->rear++] = value;
//	obj->rear %= obj->capacity + 1;
//	return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//	if (myCircularQueueIsEmpty(obj))
//		return false;
//	obj->front++;
//	obj->front %= obj->capacity + 1;
//	return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	return obj->arr[obj->front];
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//	if (myCircularQueueIsEmpty(obj))
//		return -1;
//	if (obj->rear == 0)
//		return obj->arr[obj->capacity];
//	return obj->arr[obj->rear - 1];
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//	free(obj->arr);
//	free(obj);
//	obj = NULL;
//}