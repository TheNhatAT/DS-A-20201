#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
	int price;
}Data;

static Data* stackData;
static int maxSize = 100;
static int numDatas = 0; // so phan tu hien co trong stack(moi khoi tao = 0)

void initStack();
int isEmpty();
int isFull();
void push(Data data);
Data pop();
void printStack();

int main() {
	Data a, b, c;
	a.price = 10; b.price = 15; c.price = 20;
	initStack();
	push(a);
	push(b);
	push(c);
	pop();
	printf("  %d", numDatas);
	//printStack();
	//pop();
	//printf("%d", pop().price);
	//printStack();
	return 0;
}
void initStack() {
	stackData = (Data*)malloc(maxSize * sizeof(Data));
	numDatas = 0;
}
int isEmpty() {
	return numDatas == 0;
}
int isFull() {
	return numDatas == maxSize;
}
void push(Data data) {
	if (isFull()) printf("Stackoverflow");
	else {
		stackData[numDatas] = data;
		numDatas++;
	}
}
Data pop() {
	if(isEmpty()) printf("Stackunderflow");
	else {
		numDatas--;
		printf("%d", numDatas);
		return stackData[numDatas + 1] ;
	}
}
void printStack() {
	for (int i = 0; i < numDatas; i++) {
		printf("%d\n", (stackData + i)->price);
	}
}