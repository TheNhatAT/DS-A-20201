#include <iostream>
#include <algorithm>
#include <queue>

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
// find at the right subtree first, if can't fine then find the left subtree
treeNode* maxOdd(treeNode* root) {
	if (root == NULL) return NULL;
    if (root->right != NULL && maxOdd(root->right)->key % 2 == 1) {
		return maxOdd(root->right);
	}
	else if (root->left != NULL) {
		return maxOdd(root->left);
	}
}
//check BST
bool isBST(treeNode* root) {
	if (root == NULL) return true;
	else if (root->right != NULL && root->right->key < root->key) return false;
	else if (root->left != NULL && root->left->key > root->key) return false;
	else if (!isBST(root->left) || !isBST(root->right)) return false;
	return true;
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
void t1(treeNode* x) {
	if (x != NULL) {
		cout << x->key << " ";
		t1(x->left);
		t1(x->right);
		cout << x->key << " ";
	}
}
int countNodes(treeNode* x, int k) {
	if (x == NULL) return 0;
	else if (x->key % 2 == 0) return countNodes(x->left, k) + countNodes(x->right, k) + 1;
	else {
		 countNodes(x->left, k);
	     countNodes(x->right, k);
	}
}
//count the total of even number in leaves nodes
int evenLeafs(treeNode* x) {
	if (x == NULL) return 0;
	else if (x->left != NULL || x->right != NULL) {
		return evenLeafs(x->left) + evenLeafs(x->right);
	}
	else if (x->key % 2 == 0) return 1;
	else return 0;
}
//Sum of all nodes in a binary tree 
//The idea: call left subtree sum, right subtree sum and add their values to current node’s data.
int sumTree(treeNode* x) {
	if (x == NULL) return 0;
	else return root->key + sumTree(x->left) + sumTree(x->right);
}
int main() {
	root = Insert(5, root);
	root = Insert(3, root);
	root = Insert(1, root);
	root = Insert(4, root);
	root = Insert(8, root);
	root = Insert(7, root);
	root = Insert(10, root);
	 
	cout << maxOdd(root)->key;
	//cout << sumTree(root);
	//cout << isBST(root);
	//evenLeafs(root);
	//cout << evenLeafs(root);
	//cout << countNodes(root, 7);
	/*cout << countNodes(root, 5);
	/*InorderPrint(root);
	cout << endl;
	t1(root);
	/*InorderPrint(root);
	cout << endl << findMax(root)->key << endl;
	cout << findMin(root)->key << endl;
	cout << search(14, root) << " " << search(14, root)->key << endl;
	cout << predecessor(search(14, root))->key << "---" << successor(search(14, root))->key << endl;
	root = Delete(33, root);
	InorderPrint(root);*/
	return 0;
}