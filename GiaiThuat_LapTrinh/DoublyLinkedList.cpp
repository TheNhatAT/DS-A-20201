#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct dllist {
	int number;
	struct dllist* next;
	struct dllist* prev;
} dllist;
dllist* head, * tail;
/* Thêm 1 nút p vào cuối danh sách */
void append_node(dllist* p);
/* Thêm 1 nút mới p vào sau nút đang trỏ bởi con trỏ after */
void insert_node(dllist* p, dllist* after);
/* Xóa 1 nút đang trỏ bởi con trỏ p */
void delete_node(dllist* p);

/* Thêm 1 nút p vào cuối danh sách */
void append_node(dllist* p) {
	if (head == NULL)
	{
		head = p;
		p->prev = NULL;
	}
	else {
		tail->next = p;
		p->prev = tail;
	}
	tail = p;
	p->next = NULL;
}
/* Thêm 1 nút mới p vào sau nút đang trỏ bởi con trỏ after */
void insert_node(dllist* p, dllist* after) {
	p->next = after->next;
	p->prev = after;
	if (after->next != NULL) // nếu không phải nút cuối thì vào if
		after->next->prev = p;
	else
		tail = p;
	after->next = p;
}
/* Xóa 1 nút đang trỏ bởi con trỏ p */
void delete_node(dllist* p) {
	if (p->prev == NULL)
		head = p->next;
	else p->prev->next = p->next;

	if (p->next == NULL)
		tail = p->prev;
	else p->next->prev = p->prev;
}
int main() {
	dllist* tempnode; int i;

	/* tạo danh sách liên kết đôi gồm 5 số nguyên 1,2,3,4,5 */
	for (i = 1; i <= 8; i++) {
		tempnode = (dllist*)malloc(sizeof(dllist));
		tempnode->number = i;
		append_node(tempnode);
	}
	/* in các số trong danh sách theo thứ tự từ đầu đến cuối */
	printf(" Traverse the dll list forward \n");
	for (tempnode = head; tempnode != NULL; tempnode = tempnode->next)
		printf("%d\n", tempnode->number);

	/* in các số trong danh sách theo thứ tự ngược từ cuối lên đầu ds*/
	printf(" Traverse the dll list backward \n");
	for (tempnode = tail; tempnode != NULL; tempnode = tempnode->prev)
		printf("%d\n", tempnode->number);

	/* Giải phóng bộ nhớ cấp phát cho danh sách liên kết */
	while (head != NULL) delete_node(head);

	return 0;
}