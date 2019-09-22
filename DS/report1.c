#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 200

// 노드 타입
typedef struct TreeNode{
	char ch;
	int weight;
	struct TreeNode *left, *right;
} TreeNode;

// 히프 트리 항목 타입
typedef struct {
	TreeNode *ptree;
	char ch;
	int key; // 빈도수
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType* create();
void init(HeapType* h);
void insert_min_heap(HeapType* h, element item);
element delete_min_heap(HeapType* h);
TreeNode* make_tree(TreeNode* left, TreeNode* right);
void destroy_tree(TreeNode* root);
int is_leaf(TreeNode* root);
void print_array(int codes[], int n);
void print_codes(TreeNode* root, int codes[], int top);
HeapType* huffman_tree(int freq[], char ch_list[], int n);
void getMsg(char msg[]);
HeapType* gen_huffmanTree(char msg[]);
element gen_huffmanCode(HeapType* heap);
void encode_codes(TreeNode* root, int codes[], int top, char ch);
void encode(element e, char msg[]);
//void encode(HeapType* e, char msg[]);

int main() {
	HeapType* heap;
	element e;
	char message[82] = "";

	// 사용자로부터 메시지를 입력받는다. 메시지의 최대 길이는 81이다.
	getMsg(message);

	// 메시지에 포함된 각 글자의 빈도수를 계산하고, 이를 이용하여 허프만 트리를 생성하라.
	heap = gen_huffmanTree(message);
	
	// 허프만 트리를 이용하여 글자별 허프만 코드를 생성하라.
	e = gen_huffmanCode(heap);

	// 허프만 코드를 이용하여 메시지를 인코딩하라. (메시지와 인코딩 결과를 보여라)
	encode(e, message);
	//encode(heap, message);

	free(heap);

	return 0;
}

// 히프 생성
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// 히프 초기화
void init(HeapType* h) {
	h->heap_size = 0;
}

// 최소 히프 삽입 연산
void insert_min_heap(HeapType* h, element item) {
	int i = ++(h->heap_size);
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}

// 최소 히프 삭제 연산
element delete_min_heap(HeapType* h) {
	element item = h->heap[1];
	element temp = h->heap[(h->heap_size)--];
	int i = 1;
	int j = 2;
	while (j <= h->heap_size) {
		if ((j < h->heap_size) && (h->heap[j].key > h->heap[j + 1].key))
			j++;
		if (temp.key <= h->heap[j].key) break;
		h->heap[i] = h->heap[j];
		i = j;
		j = j * 2;
	}
	h->heap[i] = temp;
	return item;
}

// 이진 트리 생성
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}

// 이진 트리 삭제
void destroy_tree(TreeNode* root) {
	if (root == NULL)
		return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

int is_leaf(TreeNode* root) {
	return !(root->left) && !(root->right);
}

void print_array(int codes[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}

// 허프만 코드 생성 및 출력
void print_codes(TreeNode* root, int codes[], int top) {
	if (root->left) {
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}

	if (root->right) {
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);
	}

	if (is_leaf(root)) {
		printf("%c: ", root->ch);
		print_array(codes, top);
	}
}

// 허프만 코드 생성
HeapType * huffman_tree(int freq[], char ch_list[], int n) {
	TreeNode* node, * x;
	HeapType* heap;
	element e, e1, e2;
	int i;

	heap = create();
	init(heap);

	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(heap, e);
	}

	for (i = 1; i < n; i++) {
		e1 = delete_min_heap(heap);
		e2 = delete_min_heap(heap);
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d+%d->%d\n", e1.key, e2.key, e.key);
		insert_min_heap(heap, e);
	}

	printf("\n");

	return heap;
}

// 메시지 입력
void getMsg(char msg[]) {
	puts("메시지를 입력하시오: ");
	gets(msg);
}

// 메시지에 포함된 각 글자의 빈도수를 계산 후 허프만 트리 생성
HeapType* gen_huffmanTree(char msg[]) {
	char ch_msg[80];
	int freq[80];
	int idx = 0;
	char ch;
	int check;
	int size = strlen(msg);

	for (int i = 0; i < 80; i++) {
		freq[i] = 0;
	}

	// 빈도수 계산
	for (int i = 0; i < size; i++) {
		check = 0;
		ch = msg[i];

		for (int j = 0; j < idx; j++) {
			// 같은 글자가 있을 경우
			if (ch_msg[j] == ch) {
				check = 1;
				freq[j]++;
				break;
			}
		}

		// 같은 글자가 없을 경우
		if (check == 0) {
			ch_msg[idx] = ch;
			freq[idx]++;
			idx++;
		}
	}

	printf("\n빈도수: \n");

	for (int i = 0; i < idx; i++) {
		printf("%c : %d\n", ch_msg[i], freq[i]);
	}

	printf("\n");

	// 허프만 트리 반환
	return huffman_tree(freq, ch_msg, idx);
}

// 허프만 트리를 이용하여 글자별 허프만 코드를 생성하라
element gen_huffmanCode(HeapType* heap) {
	element e;
	int codes[100];
	int top = 0;

	e = delete_min_heap(heap);
	print_codes(e.ptree, codes, top);

	return e;
}

void encode_codes(TreeNode* root, int codes[], int top, char ch) {
	if (root->left) {
		codes[top] = 1;
		encode_codes(root->left, codes, top + 1, ch);
	}

	if (root->right) {
		codes[top] = 0;
		encode_codes(root->right, codes, top + 1, ch);
	}

	// 인코딩
	if (is_leaf(root) && ch == root->ch) {
		for (int i = 0; i < top; i++)
			printf("%d", codes[i]);
	}
}

// 메시지 인코딩
void encode(element e, char msg[]) {
	int codes[100];
	int top = 0;
	int size = strlen(msg);

	printf("\n메시지: %s\n인코딩: ", msg);

	for (int i = 0; i < size; i++) {
		encode_codes(e.ptree, codes, top, msg[i]);
	}

	destroy_tree(e.ptree);
}
/*
void encode(HeapType* heap, char msg[]) {
	element e;
	int codes[100];
	int top = 0;
	int size = strlen(msg);
	e = delete_min_heap(heap);

	printf("\n메시지: %s\n인코딩: ", msg);

	for (int i = 0; i < size; i++) {
		encode_codes(e.ptree, codes, top, msg[i]);
	}

	destroy_tree(e.ptree);
}
*/