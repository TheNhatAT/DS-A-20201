#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct treeNode {
	char data;
	treeNode* left;  // ho?c không có con trái nh?t ho?c có 1 con trái nh?t
	treeNode* right; // ho?c không có em k? c?n ph?i ho?c có 1 em k? c?n ph?i
}treeNode;

typedef struct Tree {
	treeNode* root;
};

treeNode* makeNewNode(char data) {
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

treeNode* insertNode(treeNode* tree, char word, bool LEFT)
{
	treeNode* newNode, * p;
	newNode = makeNewNode(word);
	if (tree == NULL) return newNode;
	if (LEFT) //thêm nút vào vị trí trái nhất trên cây
	{
		p = tree;
		while (p->left != NULL) p = p->left;
		p->left = newNode;
		printf("Nút %s là con trái của nút %s \n", word, (*p).data);
	}
	else { //thêm nút vào vị trí phải nhất trên cây
		p = tree;
		while (p->right != NULL) p = p->right;
		p->right = newNode;
		printf("Nút %s là con phải của nút %s \n", word, (*p).data);
	}
	return tree;
}
int main() {
	return 0;
}