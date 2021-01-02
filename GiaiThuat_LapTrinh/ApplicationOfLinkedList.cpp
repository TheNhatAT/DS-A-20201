#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Polynom {
	int coef; // he so
	int exp; // so mu
	Polynom* next;
}Polynom;
Polynom* Poly1 = NULL, * Poly2 = NULL, * PolySum;

Polynom* makeNewNode(int coef, int exp) {
	Polynom* newPoly = (Polynom*)malloc(sizeof(Polynom));
	newPoly->coef = coef;
	newPoly->exp = exp;
	newPoly->next = NULL;
	return newPoly;
}
void InsertToTail(Polynom *(*polyHead), int coef, int exp) {
	Polynom* newNode = makeNewNode(coef, exp);
	if (*polyHead == NULL) {
		*polyHead = newNode;
	}
	else if (*polyHead != NULL) {
		Polynom* cur = *polyHead;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void sumTwoPoly() {
	Polynom* ptr1 = Poly1, * ptr2 = Poly2, * ptrSum = NULL, * node;
	node = (Polynom*)malloc(sizeof(Polynom));
	PolySum = node; // gan PolySum(headNode cua PolySum) cho node(node dau tien cua list sum)
	while (ptr1 != NULL && ptr2 != NULL) {
		ptrSum = node; //
		if (ptr1->exp < ptr2->exp) {
			node->coef = ptr2->coef;
			node->exp = ptr2->exp;
			ptr2 = ptr2->next; // cap nhat ptr2(poly2)
		}
		else if (ptr1->exp > ptr2->exp) {
			node->coef = ptr1->coef;
			node->exp = ptr1->exp;
			ptr1 = ptr1->next; // cap nhat ptr1(poly1)
		}
		else {
			node->coef = ptr1->coef + ptr2->coef;
			node->exp = ptr1->exp;
			ptr2 = ptr2->next; // cap nhat ptr2(poly2)
			ptr1 = ptr1->next; // cap nhat ptr1(poly1)
		}
		node = (Polynom*)malloc(sizeof(Polynom));
		ptrSum->next = node; // cap nhat PolySum
	} //end while loop
	if (ptr1 == NULL) {
		while (ptr2 != NULL) {
			node->coef = ptr2->coef;
			node->exp = ptr2->exp;
			ptr2 = ptr2->next; //update ptr list 2
			ptrSum = node;
			node = (Polynom*)malloc(sizeof(Polynom));
			ptrSum->next = node; //update ptr listResult
		}
	}
	if (ptr2 == NULL) //end of list 2
	{
		while (ptr1 != NULL) //copy the remaining of list1 to the listResult
		{
			node->coef = ptr1->coef;
			node->exp = ptr1->exp;
			ptr1 = ptr1->next; //update ptr list 1
			ptrSum = node;
			node = (Polynom*)malloc(sizeof(Polynom));
			ptrSum->next = node; //update ptr listResult
		}
	}
	ptrSum->next = NULL;

}

int main() {
	InsertToTail(&Poly1, 2, 1000);
	InsertToTail(&Poly1, 1, 3);

	InsertToTail(&Poly2, 1, 4);
	InsertToTail(&Poly2, 10, 3);
	InsertToTail(&Poly2, 3, 2);
	InsertToTail(&Poly2, 4, 1);

	for (Polynom* i = Poly1; i != NULL; i = i->next) {
		printf("%d*x^%d ", i->coef, i->exp);
		if(i->next != NULL) printf("+ ");
	}
	printf("\n");
	for (Polynom* i = Poly2; i != NULL; i = i->next) {
		printf("%d*x^%d ", i->coef, i->exp);
		if (i->next != NULL) printf("+ ");
	}
	sumTwoPoly();
	printf("\n");
	for (Polynom* i = PolySum; i != NULL; i = i->next) {
		printf("%d*x^%d ", i->coef, i->exp);
		if (i->next != NULL) printf("+ ");
	}
	return 0;
}