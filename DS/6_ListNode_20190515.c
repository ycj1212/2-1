#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
int is_empty(ListNode *L) {

}
int is_full(ListNode *L) {

}
ListNode* insert_first(ListNode *head, element value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
ListNode* insert(ListNode *head, ListNode *pre, element value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* insert_last(ListNode *head, element value) {
	ListNode *p = head;
	if (p == NULL) {
		p = (ListNode *)malloc(sizeof(ListNode));
		p->data = value;
		p->link = NULL;
		head = p;
	}
	else {
		while (p != NULL) {
			if (p->link == NULL)
				break;
			p = p->link;
		}
		p->link = (ListNode *)malloc(sizeof(ListNode));
		(p->link)->data = value;  (p->link)->link = NULL;
	}
	return head;
}

ListNode* delete_first(ListNode *head) {
	ListNode *p;
	if (head == NULL)	return NULL;
	p = head;
	head = p->link;
	free(p);
	return head;
}
ListNode* delete(ListNode *head, ListNode *pre) {
	ListNode *p;
	p = pre->link;
	pre->link = p->link;
	free(p);
	return head;
}
ListNode* delete_last(ListNode *head) {
	ListNode *p = head;
	if (p->link == NULL) {
		head = p->link;
		free(p);
	}
	else {
		while (p != NULL) {
			if ((p->link)->link == NULL)
				break;
			p = p->link;
		}
		p->link = NULL;
		free(p->link);
	}
	return head;
}
void print_list(ListNode *head) {
	ListNode *p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("NULL\n");
}
int main() {
	ListNode *list = NULL;
	
	list = insert_first(list, 10);	print_list(list);
	list = insert_first(list, 20);	print_list(list);
	list = insert_first(list, 30);	print_list(list);
	list = insert(list, list, 40);	print_list(list);
	list = insert(list, list, 50);	print_list(list);
	
	list = delete_first(list);		print_list(list);
	list = delete(list, list);		print_list(list);
	
	list = insert_last(list, 60);	print_list(list);
	list = insert_last(list, 70);	print_list(list);
	list = delete_last(list);		print_list(list);

	return 0;
}