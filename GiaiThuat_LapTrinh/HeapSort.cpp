#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void HeadResize(int A[], int n) {
	//do something to resize heap
}
// max_heapipy thực hiện đổi chỗ với nút con lớn hơn
void Max_heapipy(int A[], int i, int n) {
	int largest;
	int left = 2 * i;
	int right = 2 * i + 1;
	if (left <= n && A[left] > A[i]) largest = left;
	else largest = i;

	if (right <= n && A[right] > A[largest]) largest = right;
	if (largest != i) {
		swap(A + i, A + largest);
		Max_heapipy(A, largest, n);
	}
}

void Buid_Max_Heap(int A[], int n) {
	for (int i = n / 2; i > 0; i--) { // chỉ cần build từ các nút ko phải nút lá
		Max_heapipy(A, i, n);
	}
}

void HeapSort(int A[], int n) {
	Buid_Max_Heap(A, n);       // O(n)
	for (int i = n; i >= 2; i--) {
		swap(A + 1, A + i);
		Max_heapipy(A, 1, i - 1); // O(log(n)) sau khi đổi chỗ phần tử root(max) về cuối thì cắt chuỗi thành n = n - 1;
	}
}

int HeapMax(int A[]) {
	return A[1];
}

int HeapExtractMax(int A[], int n) {
	int max;
	if (n < 1) printf("heap underflow");
	else {
	    max = A[1];
		A[1] = A[n];
		Max_heapipy(A, 1, n - 1);
	}
	return max;
}
void HeapIncreaseKey(int A[], int i, int key, int n) {
	if (A[i] > key) printf("New key is smaller than old one");
	else {
		A[i] = key;
		while (i > 1 && A[i / 2] < A[i]) {
			swap(A + i, A + i / 2);
			i = i / 2;
		}
	}
}
void MaxHeapInsert(int A[], int key, int n) {
	HeadResize(A, n + 1);
	A[n + 1] = INT_MIN;
	HeapIncreaseKey(A, n + 1, key, n + 1);
}
//main
int main() {
	int A[145] = { 0 };

	for (int i = 1; i <= 10; i++) {
		A[i] = i;
	}
	Buid_Max_Heap(A, 10);

	for (int i = 1; i <= 10; i++) {
		printf("%d ", A[i]);
	}
	HeapSort(A, 10);
	printf("\n");
	for (int i = 1; i <= 10; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	HeapIncreaseKey(A, 5, 19, 10);
	HeapSort(A, 10);
	for (int i = 1; i <= 10; i++) {
		printf("%d ", A[i]);
	}
}
