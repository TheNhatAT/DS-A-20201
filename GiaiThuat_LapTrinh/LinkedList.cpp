#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	node* next;
}node;

node* head = NULL;

int sizeList();
node* makeNewNode(int data);
void InsertToHead(int data); 
void InsertAt(int data, int at);
void TraverseList();
void InsertToLast(int data);
void DeleteAt(int at);
int countNodes(int x);

node* makeNewNode(int data) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void InsertToHead(int data) {
	node* newNode = makeNewNode(data);
	if (head == NULL) head = newNode;
	else
	{
		newNode->next = head;
		head = newNode;
	}
}
void TraverseList() {
	node* cur = head;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void InsertAt(int data, int at) {
	if (at < sizeList() && at > 0) {
		node* newNode = makeNewNode(data);
		int count = 0;
		node* cur;
		if (head == NULL) head = newNode;
		else if (head->next == NULL) head->next = newNode;
		else
		{
			cur = head;
			while (count != at - 1)
			{
				cur = cur->next;
				count++;
			}
			newNode->next = cur->next;
			cur->next = newNode;
		}
	}
	else
	{
		printf("Error");
	}
}
void InsertToLast(int data){
	node* newNode = makeNewNode(data);
	if (head == NULL) head = newNode;
	else
	{
		node* last = head;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = newNode;
	}
}
int  sizeList() {
	int size = 0;
	node* cur = head;
	while (cur != NULL)
	{
		cur = cur->next;
		size++;
	}
	return size;
}
void DeleteAt(int at) {
	node* cur = head;
	node* prevCur;
	if (1 == at) {
		head = cur->next;
		free(cur);
	}
	else if (at < 1 || at > sizeList()) {
		printf("At range from 1 to size of list");
	}
	else if(at < sizeList())
	{
		int count = 0;
		while (count != at - 2)
		{
			cur = cur->next;
			count++;
		}
		prevCur = cur->next;
		cur->next = cur->next->next;
		free(prevCur);
	}
	else if(at == sizeList())
	{
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		prevCur = cur->next;
		cur->next = NULL;
		free(prevCur);
	}
}
int countNodes(int x) {
	int count = 0;
	node* e = head;
	while (e != NULL) {
		if (e->data == x) count++;
		e = e->next;
	}
	return count; // return number of x
}
int main() {
	InsertToHead(3);
	InsertToHead(2);
	InsertToHead(1);
	InsertToLast(4);
	InsertToLast(5);

	//InsertAt(10, 2);
	DeleteAt(5);
	//int size = sizeList();
	//printf("%d", size);
	TraverseList();
}

