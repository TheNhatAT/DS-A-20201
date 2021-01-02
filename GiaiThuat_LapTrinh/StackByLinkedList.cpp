#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
	int price;
}Data;

typedef struct StackNode {
	Data data;
    StackNode* next;
}StackNode;

typedef struct Stack {
     StackNode* top; // là phần tử cuối cùng
}Stack;

//khoi tao cac ham
Stack* StackInit();
int isEmpty(Stack* s);
void Push(Stack* s, Data data);
void Pop(Stack* s);
void print(StackNode* s);

int main() {
	Data data1, data2, data3;
	data1.price = 1;
	data2.price = 2;
	data3.price = 3;
	Stack* check = StackInit();
	Push(check, data1);
	Push(check, data2);
	Push(check, data3);
	//Pop(check);
	//Pop(check);
	print(check->top);
	return 0;
}

Stack* StackInit() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	if (s == NULL) return NULL;
	s->top = NULL;
	return s;
}
int isEmpty(Stack* s) {
	return s->top == NULL;
}
void Push(Stack* s, Data data) {
	if (isEmpty(s)) {
		StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
		newNode->data = data;
		newNode->next = NULL;
		s->top = newNode;
	}
	else {
		StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
		newNode->data = data;
		newNode->next = s->top;
		s->top = newNode;
	}
}

void Pop(Stack* s) {
	StackNode* node;
	if (isEmpty(s)) {
		printf("NULL");
	}
	else {
		node = s->top;
		s->top = node->next;
		free(node);
	}
}

void print(StackNode* s) {
	if (s == NULL) return;
	else printf("%d ", s->data); // duyệt từ trên xuống
	print(s->next);
	//printf("%d ", s->data); // duyệt từ dưới lên
}
