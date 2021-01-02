#include <iostream>
#include <algorithm>

using namespace std;

// this binary search tree is implemented by int datatype
typedef struct treeNode {
	int key; // the data which tree contains
	struct treeNode* left, * right, * parent;

}treeNode;
treeNode* root = NULL;

//khai bao ham
treeNode* create_node(int newKey);
treeNode* search(int target, treeNode* root);
treeNode* findMax(treeNode* root);
treeNode* findMin(treeNode* root);
treeNode* predecessor(treeNode* x); // tim ke can truoc
treeNode* successor(treeNode* x); // tim ke can sau
treeNode* Insert(int x, treeNode* root);
treeNode* Delete(int x, treeNode* root);

//cai dat ham
treeNode* create_node(int newKey) {
	treeNode* newNode = new treeNode;
	if (newNode == NULL) {
		cout << "ERROR: Out of memory\n";
		exit(1);
	}
	else
	{
		newNode->key = newKey; ///sdsds
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->parent = NULL;
	}
	return newNode;
}
treeNode* search(int target, treeNode* root) {
	if (root == NULL) return NULL; // can't find the target
	else if (target == root->key) return root;// finded the target
	else if (target < root->key) return search(target, root->left);
	else return search(target, root->right);

}
treeNode* findMin(treeNode* root) {
	if (root == NULL) return NULL;
	else {
		if (root->left == NULL) return root;
		else return findMin(root->left);
	}
}treeNode* findMax(treeNode* root) {
	if (root == NULL) return NULL;
	else {
		if (root->right == NULL) return root;
		else return findMax(root->right);
	}
}
treeNode* predecessor(treeNode* x) {
	if (x->left != NULL) return findMax(x->left);
	else {
		treeNode* t = x, * p = x->parent;
		while (p != NULL && p->right != t) { // lap den khi gap p la to tien gan nhat co con trai hoac la x hoac la to tien cua x
			t = p;
			p = p->parent;
		}
		return p;
	}
}
treeNode* successor(treeNode* x) {
	if (x->right != NULL) return findMin(x->right);
	else {
		treeNode* t = x, * p = x->parent;
		while (p != NULL && p->left != t) { // lap den khi gap p la to tien gan nhat co con phai hoac la x hoac la to tien cua x
			t = p;
			p = p->parent;
		}
		return p;
	}
}
treeNode* Insert(int x, treeNode* root) {
	if (root == NULL) root = create_node(x);
	else if (x < root->key) {
		root->left = Insert(x, root->left);
		root->left->parent = root;
	}
	else if (x >= root->key) {
		root->right = Insert(x, root->right);
		root->right->parent = root;
	}
	return root;
}
treeNode* Delete(int x, treeNode* root) {
	treeNode* tmp;
	if (root == NULL) cout << "Not found" << endl;
	else if (x < root->key) root->left = Delete(x, root->left);
	else if (x > root->key) root->right = Delete(x, root->right);
	else {
		/* Tình huống 4: phần tử thế chỗ là phần tử min ở cây con phải */
		if (root->left != NULL && root->right != NULL) {
			tmp = findMin(root->right);
			root->key = tmp->key;
			root->right = Delete(root->key, root->right);
		}
		else {
			/*TH1,2,3: có 1 con hoặc không có con */
			tmp = root;
			if (root->left == NULL) { /* chỉ có con phải hoặc không có con */
				if(root->right != NULL) root->right->parent = root->parent;
				root = root->right;
			}
			else if (root->right == NULL) { /* chỉ có con trái */
				if (root->left != NULL) root->left->parent = root->parent;
				root = root->left;
			}
			delete(tmp);
		}
	}
	return root;
}
void InorderPrint(treeNode* root) {
	if (root == NULL) return;
	InorderPrint(root->left);
	cout << root->key << " ";
	InorderPrint(root->right);
}
int main() {
	root = Insert(10, root);
	root = Insert(23, root);
	root = Insert(8, root);
	root = Insert(7, root);
	root = Insert(43, root);
	root = Insert(34, root);
	root = Insert(14, root);
	root = Insert(56, root);
	root = Insert(44, root);
	root = Insert(33, root);

	InorderPrint(root);
	cout << endl << findMax(root)->key << endl;
	cout << findMin(root)->key << endl;
	cout << search(14, root) << " " << search(14, root)->key << endl;
	cout << predecessor(search(14, root))->key << "---" << successor(search(14, root))->key << endl;
	root = Delete(33, root);
	InorderPrint(root);
	return 0;
}