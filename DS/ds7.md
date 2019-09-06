## **7. 연결리스트(2)**
    
- 연결리스트의 응용 : 다항식    
```
typedef struct{
    int coef;
    int expo;
    ListNode* link;
} ListNode;

typedef struct{
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

ListType* create(){
    ListType*p = (ListType*)malloc(sizeof(ListType));
    p->size=0;
    p->head = p->tail = NULL;
    return p;
}

void insert_last(ListNode* head, int coef, int expo){
    ListNode *p, *q;
    p=(ListNode*)malloc(sizeof(ListNode));
    p->coef = coef;
    p->expo = expo;
    p->link = NULL;
    if(head == NULL){
        head = p;
    }
    else{
        q = head;
        while(q->link != NULL){
            q=q->link;
        }
        q->link = p;
    }
    return head;
}

void poly_add(ListNode* list1, ListNode* list2, ListNode* r){
    ListNode *p = list1;
    ListNode *q = list2;

    while((p!=NULL) && (q!=NULL)){
        if(p->expo == q->expo){
            r = insert_last(r, p->coef+q->coef, p->expo);
            p = p->link;
            q = q->link;
        }
        else if(p->expo > q->expo){
            r = insert_last(r, p->coef, p->expo);
            p = p->link;
        }
        else{
            r = insert_last(r, q->coef, q->expo);
            q = q->link;
        }
    }

    while(p != NULL){
        r = insert_last(r, p->coef, p->expo);
        p = p->link;
    }
    while(q != NULL){
        r = insert_last(r, q->coef, q->expo);
        q = q->link;
    }

    return r;
}

void poly_print(ListNode *list){
    ListNode *p = list;
    while(p!=NULL){
        printf("%dx^%d + ", p->coef, p->expo);
        p = p->link;
    }
}
```

- 원형 연결 리스트
```
typedef struct{
    int data;
    ListNode *link;
} ListNode;

ListNode* insert_first(ListNode *head, int val){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = val;
    if(head == NULL){
        head = p;
        p->link = head;
    }
    else{
        p->link = head->link;
        head->link = p;
    }
    return head;
}
ListNode* insert_last(ListNode *head, int val){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = val;
    if(head == NULL){
        head = p;
        p->link = head;
    }
    else{
        p->link = head->link;
        head->link = p;
        head = p;
    }
    return head;
}
ListNode* delete_first(ListNode *head){
    ListNode *p;
    if(p != NULL){
        p = head->link;
        if(p == NULL)
            head = NULL;
        else{
            head->link = p->link;
            free(p);
        }
    }
}
```

- 이중 연결 리스트
```

```