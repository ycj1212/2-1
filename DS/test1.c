#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
    element data;
    ListNode* link;
} ListNode;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
    ListNode* p = NULL;
    p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = NULL;
    p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* insert_last(ListNode* head, element value) {
    ListNode* p = NULL;
    p = head;
    if(p == NULL) {
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
        p->link = (ListNode*)malloc(sizeof(ListNode));
        (p->link)->data = value;
        (p->link)->link = NULL;
    }
    return head;
}

ListNode* delete_first(ListNode* head) {
    ListNode* p = NULL;
    if (head == NULL)
        return NULL;
    p = head;
    head = p->link;
    free(p);
    return head;
}

ListNode* delete(ListNode* head, ListNode* pre) {
    ListNode* p = NULL;
    p = pre->link;
    pre->link = p->link;
    free(p);
    return head;
}

ListNode* delete_last(ListNode* head) {
    ListNode* p = NULL;
    p = head;
    if (p == NULL)
        return NULL;

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

void print_list(ListNode* head) {
    ListNode* p = NULL;
    p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

// 리스트 탐색
ListNode* search_list(ListNode* head, element val) {
    ListNode* p = head;
    while(p != NULL) {
        if(p->data == val)
            return p;
        p = p->link;
    }
    return head;
}

// 리스트 합병
ListNode* concat_list(ListNode* list1, list2) {
    ListNode* p = list1;
    if(list1 == NULL)
        return list2;
    else if(list2 == NULL)
        return list1;
    else {
        while(p->link != NULL) {
            p = p->link;
        }
        p->link = list2;
    }
    return list1;
}

// 리스트 역순
ListNode* reverse(ListNode* head) {
    ListNode* p, q, r;
    p = head;
    q = NULL;
    while(p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}