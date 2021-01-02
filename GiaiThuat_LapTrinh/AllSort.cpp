#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
void InsertionSort(int a[], int size) {
	for (int i = 1; i < size; i++) {
		int temp = a[i];
		int pos = i;
		while (i > 0 && a[i - 1] > temp) {
			a[i] = a[i - 1];	// bước lặp k: liên tục đổi chỗ phần tử thứ k và phần tử kề bên trái nó nếu phần tử k còn nhỏ hơn phần tử đó
			i--;
		}
		a[i] = temp;
	}
}

void SelectionSort(int a[], int size) {
	int index_min;
	for (int i = 0; i < size - 1; i++) {
		index_min = i;
		// tìm phần tử nhỏ nhất trong mảng từ i + 1 -> n
		for (int j = i + 1; j < size; j++) {
			if (a[j] < a[index_min]) index_min = j;
		}
		//đổi chỗ phần từ nhỏ nhất vừa tìm được về vị trí thứ i
		swap(&a[i], &a[index_min]);
	}
}


void BubbleSort(int a[], int size) {
	int sorted = 1; // dùng để ghi nhận xem bước lặp không có phép hoán đổi nào được thực hiện -> thực hiện xong
	for (int i = 0; i < size; i++) {
		if (sorted == 1) {
			sorted = 0;
			for (int j = 0; j < size - i - 1; j++) {
				if (a[j] > a[j + 1]) {
					swap(&a[j], &a[j + 1]);
					sorted = 1;
				}
			}
		}
	}
}

void Merge1(int a[], int front, int mid, int end) {
	int n1 = mid - front + 1;
    int n2 = end  - mid;
	int* left = (int*)malloc((n1 + 1) * sizeof(int));
	int* right = (int*)malloc((n2 + 1) * sizeof(int));

	for (int i = 0; i < n1; i++) {
		left[i] = a[front + i];
	}
	left[n1] = INT_MAX; right[n2] = INT_MAX; // must set this line to recursive merge sort
	for (int j = 0; j < n2; j++) {
		right[j] = a[mid + 1 + j];
	}

	int i = 0, j = 0;
	for (int k = front; k <= end; k++) {
		if (left[i] >= right[j]) {
			a[k] = right[j]; j++;
		}
		else
		{
			a[k] = left[i]; i++;
		}
	}
}

void MergeSort(int a[], int front, int end) {
	if (front < end) {
		int mid = (front + end) / 2;
		MergeSort(a, front, mid);
		MergeSort(a, mid + 1, end);
		Merge1(a, front, mid, end);
		//Merge2(a, front, mid, end);
	}
}

int Partition(int a[], int left, int right) {
	int i = left, j = right + 1;
	int pivot = a[left]; // pivot is the first element of array (sorted)
	while (true) {
		i++;
		//find from left to right to find the first element >= pivot
		while (i <= right && a[i] < pivot) i++;
		j--;
		//find from right to left to find the first element <= pivot
		while (j >= left && pivot < a[j]) j--;
		if (i >= j) break;
		swap(a + i, a + j);
	}
	swap(a + j, a + left); // swap a[j] with a[left] +> return pivot -> a[j]
	return j;
}

void QuickSort(int a[], int left, int right ) {
	int pivot;
	if (left < right) {
		pivot = Partition(a, left, right);
		QuickSort(a, left, pivot - 1); // all elements of left array is smaller than pivot
		QuickSort(a, pivot + 1, right);// all elements of right array is bigger than pivot
	}

}

int main() {
	int a[9] = { 1, 5, 4, 7, 2, 9, 4, 3, 5 };
	//InsertionSort(a, 9);
	//SelectionSort(a, 9);
	//BubbleSort(a, 9);
	MergeSort(a, 0, 8);
	//QuickSort(a, 0, 8);
	for (int i = 0; i < 9; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}