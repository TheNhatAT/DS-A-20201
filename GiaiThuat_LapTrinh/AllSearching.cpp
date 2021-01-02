#include <iostream>
#include <algorithm>
using namespace std;

void linearSearch(int arr[], int size, int target) {
	for (int i = 1; i <= size; i++) {
		if (arr[i] == target) {
			cout << " Target is in the list where index is " << i;
			return;
		}
	}
	cout << "Target isn't in the list!!!";
}

//you need to sort the list before you use binary search
int binsearch(int low, int high, int A[], int target)
{
	int mid;
	if (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid] == target) return mid;
		else if (target < A[mid])
			return binsearch(low, mid - 1, A, target);
		else
			return binsearch(mid + 1, high, A, target);
	}
	else return -1;
}
int main() {
	return 0;
}
