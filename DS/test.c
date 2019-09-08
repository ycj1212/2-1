#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef int element;
typedef struct {
    element array[SIZE];
    int size;
} ArrayListType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(ArrayListType* L) {
    L->size = 0;
}

int is_empty(ArrayListType* L) {
    return L->size == 0;
}

int is_full(ArrayListType* L) {
    return L->size == SIZE;
}

element get_entry(ArrayListType* L, int pos) {
    if(pos < 0 || pos >= L->size)
        error("위치 오류");
    return L->array[pos];
}

void print_list(ArrayListType* L) {
    for(int i=0; i<L->size; i++) {
        printf("%d -> ", L->array[i]);
    }
    printf("\n");
}

void insert_last(ArrayListType* L, element item) {
    if(is_full(L))
        error("리스트 오버플로우");
    L->array[L->size++] = item;
}

void insert(ArrayListType* L, int pos, element item) {
    if(!is_full(L) && (pos >= 0) && (pos < L->size)) {
        for(int i=(L->size-1); i>=pos; i--)
            L->array[i+1] = L->array[i];
        L->array[pos] = item;
        L->size++;
    }
}

void insert_first(ArrayListType* L, element item) {
    if(L->size >= SIZE)
        error("리스트 오버플로우");
    for(int i=(L->size-1); i >= 0; i--)
        L->array[i+1] = L->array[i];
    L->array[0] = item;
    L->size++;
}

element delete(ArrayListType* L, int pos) {
    element item;
    if (pos < 0 || pos >= L->size)
        error("위치 오류");
    item = L->array[pos];
    for (int i=pos; i<L->size-1; i++)
        L->array[i] = L->array[i+1];
    L->size--;
    return item;
}

element delete_first(ArrayListType* L) {
    element item;
    if (!is_empty(L)) {
        item = L->array[0];
        for (int i=0; i<L->size-1; i++) {
            L->array[i] = L->array[i+1];
        }
        L->size--;
    }
    return item;
}

element delete_last(ArrayListType*L) {
    element item;
    if (!is_empty(L)) {
        item = L->array[--(L->size)];
    }
    return item;
}

int main() {
    

    return 0;
}