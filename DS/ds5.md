## **5. 큐**

- 큐 : 선입선출(FIFO : First In First Out)
    
- 스택은 삽입과 삭제가 같은쪽에서 일어나지만, 큐는 삽입과 삭제가 다른쪽에서 일어남 
    
    `전단(front) <- |ㅇ||ㅇ||ㅇ| <- 후단(rear)`

    전단(front) = 삭제, 후단(rear) = 삽입

    - *선형 큐*
    
    ```
    - 선형 큐

    #include <stdio.h>
    #include <stdlib.h>
    #define SIZE 10
    typedef int element;
    typedef struct {
        element data[SIZE];
        int front, rear;
    }Queue;
    void error(char * message) {
        fprintf(stderr, "%s\n", message);
        exit(1);
    }
    void init(Queue *q) {
        q->front = q->rear = -1;
    }
    int is_full(Queue *q) {
        return q->rear == SIZE - 1;
    }
    int is_empty(Queue *q) {
        return q->rear == -1;
    }
    void enqueue(Queue *q, element item) {
        if (is_full(q)) {
            error("큐 포화 에러");
            return;
        }
        q->data[++(q->rear)] = item;	// else 안써도 될듯...
    }
    element dequeue(Queue *q) {
        if (is_empty(q)) {
            error("큐 공백 에러");
            return -1;	// 반환형에따라 반환값이 달라진다.
        }
        return q->data[++(q->front)];
    }
    void print_queue(Queue *q) {
        if (!is_empty(q)) {
            for (int i = q->front + 1; i <= q->rear; i++) {
                printf(" %d ", q->data[i]);
            }
            printf("\n");
        }
    }
    ```
    
    - 선형 큐는 배열의 크기가 정해져 있어 단점
    - 선형 큐는 rear, front 초기값이 -1

    - *원형 큐*
    ```
    - 원형 큐

    #include <stdio.h>
    #include <stdlib.h>
    #define SIZE 5
    typedef int element;
    typedef struct {
        element data[SIZE];
        int front, rear;
    }Queue;
    void error(char * message) {
        fprintf(stderr, "%s\n", message);
        exit(1);
    }
    void init(Queue *q) {
        q->front = q->rear = 0;
    }
    int is_empty(Queue *q) {
        return q->front == q->rear;
    }
    int is_full(Queue *q) {
        return ((q->rear + 1) % SIZE == q->front);
    }
    void enqueue(Queue *q, element item) {
        if (is_full(q))
            error("큐 포화 에러");
        q->rear = (q->rear + 1) % SIZE;
        q->data[q->rear] = item;
    }
    element dequeue(Queue *q) {
        if (is_empty(q))
            error("큐 공백 에러");
        q->front = (q->front + 1) % SIZE;
        return q->data[q->front];
    }
    element peek(Queue *q) {
        if (is_empty(q))
            error("큐 공백 에러");
        return q->data[(q->front + 1) % SIZE];
    }
    void print_queue(Queue *q) {
        printf("[front = %d, rear = %d] = ", q->front, q->rear);
        if (!is_empty(q)) {
            int i = q->front;
            do {
                i = (i + 1) % SIZE;
                printf("%d ", q->data[i]);
                if (i == q->rear)	break;
            } while (i != q->front);
            printf("\n");
        }
    }
    ```
    - 원형 큐는 rear, front 초기값이 0

    - 선형큐나 원형큐 - 인덱스 1증가 후 삽입, 삭제
    
    - 덱 - add_front(), delete_rear() 삽입, 삭제 후 인덱스 1증가

- 덱(Deque(Double-ended queue))
    - 전단과 후단에서 삽입, 삭제가 가능한 큐

    ```
    - 원형 덱

    #include <stdio.h>
    #include <stdlib.h>
    #define SIZE 5

    typedef int element;
    typedef struct {
        element data[SIZE];
        int front, rear;
    } Deque;

    void error(char * message) {
        fprintf(stderr, "%s\n", message);
        exit(1);
    }
    void init(Deque *q) {
        q->front = q->rear = 0;
    }
    int is_empty(Deque *q) {
        return q->front == q->rear;
    }
    int is_full(Deque *q) {
        return (q->front == (q->rear + 1) % SIZE);
    }
    void add_rear(Deque *q, element val) {
        if (is_full(q))
            error("큐 포화 에러");
        q->rear = (q->rear + 1) % SIZE;
        return q->data[q->rear];
    }
    element delete_front(Deque *q) {
        if (is_empty(q))
            error("큐 공백 에러");
        q->front = (q->front + 1) % SIZE;
        return q->data[q->front];
    }
    void add_front(Deque *q, element val) {
        if (is_full(q))
            error("큐 포화 에러");
        q->data[q->front] = val;
        q->front = (q->front + SIZE - 1) % SIZE;
    }
    element delete_rear(Deque *q) {
        element val;
        if (is_empty(q))
            error("큐 공백 에러");
        val = q->data[q->rear];
        q->rear = (q->rear + SIZE - 1) % SIZE;
        return val;
    }
    void print_deque(Deque *q) {
        if (!is_empty(q)) {
            int i = q->front;
            do {
                i = (i + 1) % SIZE;
                printf("%d ", q->data[i]);
                if (i == q->rear)
                    break;
            } while (i!=q->front);
        }
        printf("\n");
    }
    ```

    - 큐를 이용한 피보나치수열
    ```
    
    ```
