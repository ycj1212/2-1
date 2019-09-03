# ***Data_Structure***

## **1. 자료구조와 알고리즘**

- 자료구조 - 프로그램에서 *자료를 정리하여 보관* 하는 여러가지 구조들
- 알고리즘 - 주어진 문제를 해결하는 절차

    ∴ 프로그램 = 자료구조 + 알고리즘

- 알고리즘
    - 정의
        - 입력 : 0개 이상의 입력이 존재하여야 한다.
        - 출력 : 1개 이상의 출력이 존재하여야 한다.
        - 명확성 : 각 명령어의 의미는 모호하지 않고 명확해야 한다.
        - 유한성 : 반드시 종료되어야한다.
        - 유효성 : 실행 가능한 연산이어야 한다.
    
- 추상자료형(ADT)
    - 좋은 추상화는 중요한 내용을 강조하고 불필요한 내용은 제거되는 것이다.
    - 이를 위하여 **정보은닉기법**이 개발되었다.
    - **정보은닉기법**은 ADT가 구현될 때 구현세부사항을 외부에 알리지 않고 외부와의 인터페이스만을 공개하여 전체 프로그램의 변경 가능성이 있는 구현의 세부사항으로부터 보호하는 것이다.

- 알고리즘의 성능분석
    - 시간복잡도 함수
        - 연산의 수행횟수를 분석
        - 산술, 대입, 비교, 이동 연산 등..
    - 빅오표기법
        - `두개의 함수 f(n)과 g(n)이 주어졌을 때 모든 n > n0 에 대하여 |f(n)| <= c|g(n)|을 만족하는 2개의 상수 c와 n0가 존재하면 f(n) = O(g(n))이다.`
        - 시간복잡도 함수에서 차수가 가장 큰 항만 고려
        - ex) f(n) = 5 이면 O(1)이다. 왜냐하면 n0=1, c=10 일 때, n>1에 대하여 5<=10·1 이 되기 떄문이다.
        - ex) f(n) = 2n+1 이면 O(n)이다. 왜냐하면 n0=2, c=3일 때, n>2에 대하여 2n+1<=3n 이 되기 떄문이다.
        - ex) f(n) = 3n²+100 이면 O(n²)이다. 왜냐하면 n0=100, c=5일 때, n>100에 대하여 3n²+100<=5n² 이 되기 떄문이다.
        - ex) f(n) = 5·2^n+10n²+100 이면 O(2^n)이다. 왜냐하면 n0=1000, c=10일 때, n>1000에 대하여 5·2^n+10n²+100<=10·2^n 이 되기 때문이다.
    - 빅오표기법에 의한 알고리즘 수행시간 비교
        - O(1) < O(logn) < O(n) < O(nlogn) < O(n²) < O(2^n) < O(n!) < O(n^n)
    - 최악의 경우 : 알고리즘의 수행시간이 가장 오래 걸리는 경우
    - 최선의 경우 : 알고리즘의 수행시간이 가장 적게 걸리는 경우
    - 평균적인 경우
    - **순차탐색 알고리즘**
    ```
    int seq_search(int list[], int key){
        for(int i=0;i<n;i++){
            if(list[i] == key)
                return i;
        }           // 탐색에 성공하면 키 값의 인덱스 반환
        return -1;  // 탐색에 실패하면 -1 반환
    }
    ```
    - 최선의 경우 : 찾고자 하는 숫자가 배열의 맨 처음에 있는 경우 ∴ O(n)
    - 최악의 경우 : 찾고자 하는 숫자가 배열의 맨 끝에 있는 경우 ∴ O(n)
    - 평균적인 경우 : 모든 숫자들이 탐색될 가능성 1/n, (1+2+...+n)/n = (n+1)/2 ∴ O(n)

- 퀴즈
```
sum = 0;
for(int i=1;i<n;i*=2){
    sum = sum+i;
}
```
1. 다음 코드에 대한 시간 복잡도 함수를 작성하라.
```
sum = 0;                // 대입 1
for(int i=1;i<n;i*=2){  // 대입 1+log₂n, 비교 log₂n+1, 곱셈 log₂n
    sum = sum+i;        // 대입 log₂n, 덧셈 log₂n
}

∴ T(n) = 5log₂n+3
```
2. 1)의 관점에서 위 코드의 시간 복잡도를 빅오 표기법으로 나타내라. 그 이유를 주라.
```
f(n) = 5log₂n+3 이면 O(log₂n)이다. 왜냐하면 c=10, n0=2 일 때, n>2 에 대하여 5log₂n+3 <= 10·log₂n 이 되기 때문이다. 
```

---
## **2. 순환**

- 순환 - 어떤 알고리즘이나 함수가 *자기 자신을 호출*하여 문제를 해결하는 프로그래밍 기법
    - 순환적인 팩토리얼 계산 프로그램
    ```
    int factorial(int n){
        if(n <= 1)    return 1;
        else        return (n*factorial(n-1));
    }
    ```
- 순환 알고리즘의 구조
    - 순환을 멈추는 부분과 순환 호출을 하는 부분으로 구성
    ```
    int factorial(int n){
        if(n <= 1)    return 1; ← 순환을 멈추는 부분
        else        return (n*factorial(n-1)); ← 순환 호출을 하는 부분
    }
    ```
- 프로그래밍 언어에서 되풀이하는 방법에는 순환과 반복이 있다.
- 기본적으로 순환과 반복은 문제해결능력이 같으며 많은 경우에 순환 알고리즘을 반복버전으로, 반복 알고리즘을 순환버전으로 바꾸어 쓸 수 있다. 특히 순환 호출이 끝에서 이루어지는 순환을 꼬리 순환이라고 하는데, 이를 반복 알고리즘으로 쉽게 바꾸어 쓸 수 있다.
- 순환은 반복에 비해 알고리즘을 훨씬 명확하고 간결하게 나태낼수 있지만, 반복에 비해 수행속도 면에서는 떨어진다.
    
    - 반복적인 팩토리얼 계산 프로그램
    ```
    int factorial(int n){
        int result = 1;
        for(int i=1;i<=n;i++){
            result *= i;
        }
        return result;
    }
    ```
    
- 거듭제곱값 계산
    - 반복적인 거듭제곱 계산 프로그램
    ```
    double slow_power(double x, int n){
        double result = 1.0;
        for(int i=0;i<n;i++)
            result = result * x;
        return result;
    }
    ```
    - x^n = (x²)^n/2 공식을 이용
    
    - 순환적인 거듭제곱 계산 프로그램
    ```
    double power(double x, int n){
        if(n==0)    return 1;
        else if(x%2==0)
            return power(x*x, n/2);
        else return x*power(x*x, (n-1)/2);
    }
    ```

    - 순환버전이 반복버전보다 수행속도가 더 빠른 경우이다.
    - k번의 순환호출이 일어나 n=2^k 이고 log₂n=k 이다. 시간복잡도는 O(log₂n) 이다.
    - 반복버전의 시간복잡도는 O(n) 이다.

- 피보나치 수열의 계산
    - 순환적인 피보나치 수열 계산 프로그램
    ```
    int fib(int n){
        if(n==0)    return 0;
        if(n==1)    return 1;
        return (fib(n-1) + fib(n-2));
    }
    ```
    - 시간복잡도는 O(2^n)
    
    - 반복적인 피보나치 수열 계산 프로그램
    ```
    int fib(int n){
        if(n==0)    return 0;
        if(n==1)    return 1;

        int pp=0;
        int p=1;
        int result=0;

        for(int i=2;i<=n;i++){
            result = p + pp;
            pp = p;
            p = result;
        }

        return result;
    }
    ```

- 하노이탑 문제
    - 막대 A에 쌓여있는 원판들을 막대 C로 옮기는 것이다. 단 다음의 조건을 지켜야 한다.
        - 한 번에 하나의 원판만 이동할 수 있다.
        - 맨 위에 있는 원판만 이동할 수 있다.
        - 크기가 작은 원판위에 큰 원판이 쌓일 수 없다.
        - 중간의 막대를 임시적으로 이용할 수 있으나 앞의 조건들을 지켜야 한다.
    ```
    void hanoi_tower(int n, char A, char B, char C){
        if(n==1)
            A에 있는 한 개의 원판을 C로 옮긴다.
        else{
            ① A에 맨 밑의 원판을 제외한 나머지 원판들을 B로 옮긴다.
            ② A에 있는 한 개의 원판을 C로 옮긴다.
            ③ B의 원판들을 C로 옮긴다.
        }
    }
    ```
    ```
    void hanoi_tower(int n, char A, char B, char C){
        if(n==1)
            printf("원판 1을 %c에서 %c으로 옮긴다.\n", A, C);
        else{
            hanoi_tower(n-1, A, C, B);
            printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, A, C);
            hanoi_tower(n-1, B, A, C);
        }
    }
    ```

- 반복적인 형태로 바꾸기 어려운 순환
    ```
    ① return n*factorial(n-1);
    ② return factorial(n-1)*n;
    ```

    - ① 과 같은 꼬리순환의 경우 반복적인 형태로 변환이 가능하다.
    - ② 과 같은 머리순환의 경우나 하노이탑 문제처럼 여러 군데에서 자기 자신을 호출하는 경우 쉽게 반복적인 형태로 바꿀 수 없다.

- 퀴즈
1. 다음 C프로그램의 실행 결과는 무엇인가? 그 이유를 주라.
```
int f(int a, int b){
    while(b!=0){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    printf("%d", f(24,10));
    
    return 0;
}

-----------------------------
int f(24, 10){
    while(10!=0){
        int r = 24%10 = 4;
        a=10;
        b=4;
    }
    while(4!=0){
        int r = 10%4 = 2;
        a=4;
        b=2;
    }
    while(2!=0){
        int r = 4%2 = 0;
        a = 2;
        b = 0;
    }
    while(0==0)

    return a;   // a = 2
}
```

2. 1)의 f() 함수에 대한 순환(재귀)적 버전을 작성하라.
```
int f(int a, int b){
    if(b==0)    return a;
    else        return f(b, a%b);
}
```

---
## **3. 배열, 구조체, 포인터**

- 배열의 응용 : 다항식
    - 첫 번째 방법 : 모든 차수의 계수값을 배열에 저장
    - 다항식 덧셈 프로그램 #1
    ```
    #include <stdio.h>
    #define MAX(a,b) ( ((a)>(b))?(a):(b) )
    #define MAX_DEGREE 101
    typedef struct{
        int degree;                 // 다항식의 차수
        float coef[MAX_DEGREE];     // 다항식의 계수
    } polynomial;

    polynomial poly_add1(polynomial A, polynomial B){
        polynomial C;
        int Apos = 0, Bpos = 0, Cpos = 0;
        int degree_a = A.degree;
        int degree_b = B.degree;
        C.degree = MAX(A.degree, B.degree);

        while(Apos <= A.degree && Bpos <= B.degree){
            if(degree_a > degree_b){
                C.coef[Cpos++] = A.coef[Apos++];
                degree_a--;
            }
            else if(degree_a == degree_b){
                C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
                degree_a--; degree_b--;
            }
            else{
                C.coef[Cpos++] = B.coef[Bpos++];
                degree_b--;
            }
        }
        return C;
    }

    void print_poly(polynomial p){
        for(int i=p.degree;i>0;i--)
            printf("%3.1fx^%d + ", p.coef[p.degree-i], i);
        printf("%3.1f \n", p.coef[p.degree]);
    }

    int main(void){
        polynomial a = {5, {3, 6, 0, 0, 0, 10} };
        polynomial b = {4, {7, 0, 5, 0, 1} };
        polynomial c;

        print_poly(a);
        print_poly(b);
        c = poly_add1(a, b);
        printf("-------------------------------------------------------------------\n");
        print_poly(c);

        return 0;
    }
    ```

    - 두 번째 방법
    - (계수, 차수)의 형식의 구조체 배열
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #define MAX 101
    typedef struct{
        float coef;
        int expon;
    } polynomial;
    polynomial terms[MAX] = { {8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0} };
    int avail = 6;

    char compare(int a, int b){
        if(a>b) return '>';
        else if(a==b) return '=';
        else return '<';
    }

    void attach(float coef, int expon){
        if(avail > MAX){
            fprintf(stderr, "항의 개수가 너무 많음\n");
            exit(1);
        }
        terms[avail].coef = coef;
        terms[avail].expon = expon;
        avail++;
    }
    
    void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce){
        float tempcoef;
        *Cs = avail;
        while(As <= Ae && Bs <= Be){

        }
    }

    ```

- 배열의 응용 : 희소행렬
    - 2차원 배열을 사용
    - 전치행렬 계산하기 #1
    ```
    #include <stdio.h>
    #define ROWS 3
    #define COLS 3
    
    void matrix_transpose(int A[ROWS][COLS], int B[COLS][ROWS]){
        for(int r=0;r<ROWS;r++)
            for(int c=0;c<COLS;c++)
                B[c][r] = A[r][c];
    }

    void matrix_print(int A[ROWS][COLS]){
        printf("=======================\n");
        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                printf("%d", A[r][c]);
            }
            printf("\n");
        }
        printf("=======================\n");
    }

    int main(void){
        int array1[ROWS][COLS] = { {2,3,0}, {8,9,1}, {7,0,5} };
        int array2[ROWS][COLS];

        matrix_transpose(array1, array2);
        matrix_print(array1);
        matrix_print(array2);
        
        return 0;
    }
    ```

    - 0이 아닌 노드만을 (행, 열, 값)으로 표시
    - 전치행렬 계산하기 #2
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #define MAX 100
    
    typedef struct{
        int row;
        int col;
        int value;
    } element;

    typedef struct{
        element data[MAX];
        int rows;
        int cols;
        int terms;
    } SparseMatrix;

    SparseMatrix matrix_transpose2(SparseMatrix a){
        SparseMatrix b;

        int bindex;
        b.rows = a.rows;
        b.cols = a.cols;
        b.terms = a.terms;

        if(a.terms > 0){
            bindex = 0;
            for(int c=0;c<a.cols;c++){
                for(int i=0;i<a.terms;i++){
                    if(a.data[i].col == c){
                        b.data[bindex].row = a.data[i].col;
                        b.data[bindex].col = a.data[i].row;
                        b.data[bindex].value = a.data[i].value;
                        bindex++;
                    }
                }
            }
        }
        return b;
    }

    void matrix_print(SparseMatrix a){
        printf("=======================\n");
        for(int i=0;i<a.terms;i++){
            printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
        }
        printf("=======================\n");
    }

    int main(void){
        SparseMatrix m = { { {0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5}, {4,5,1}, {5,2,2} } {6, 6, 7} };
        SparseMatrix result;

        result = matrix_transpose2(m);
        matrix_print(result);
        
        return 0;
    }
    ```

- 포인터
    - swap
    ```
    #include <stdio.h>

    void swap(int *px, int *py){
        int tmp;
        tmp = *px;
        *px = *py;
        *py = tmp;
    }

    int main(void){
        int a=1, b=2;
        printf("swap을 호출하기 전 : a=%d, b=%d\n", a, b);
        swap(&a, &b);
        printf("swap을 호출한 다음 : a=%d, b=%d\n", a, b);
        
        return 0;
    }
    ```

- 동적 메모리 할당
    - 일반적인 배열은 크기가 고정되어 있다. 그래서 필요한 만큼의 메모리를 운영체제로부터 할당받아서 사용하고, 사용이 끝나면 시스템에 메모리를 반납하는 기능이 있다. 이것을 동적 메모리 할당이라고 한다.
    - 동적 메모리가 할당되는 공간을 히프(heap)라고 한다. 히프는 운영체제가 사용되지 않는 메모리 공간을 모아 놓은 곳이다. 필요한 만큼만 할당을 받고 또 필요한 때에 사용하고 반납하기 때문에 메모리를 매우 효율적으로 사용할 수 있다.
    - malloc.c 동적 메모리 할당의 예
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #include <malloc.h>
    #define SIZE 10

    int main(void){
        int *p;

        p = (int*)malloc(sizeof(int));
        if(p==NULL){
            fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
            exit(1);
        }
        
        for(int i=0;i<SIZE;i++){
            p[i] = i;
        }
        
        for(int i=0;i<SIZE;i++){
            printf("%d ", p[i]);
        }

        free(p);

        return 0;
    }
    ```

    - malloc.c 동적 메모리 할당의 예2
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct {
        char name[10];
        int age;
        double gpa;
    } student;

    int main(void){
        student *s;

        s = (student*)malloc(sizeof(student));
        if(s==NULL){
            fprintf(stderr, "메모리 부족");
            exit(1);
        }

        strcpy(s->name, "Yang");
        s->age = 20;

        free(s);

        return 0;
    }
    ```

---
## **4. 스택**

- 스택 - 후입선출(LIFO : Last-In First-out)

- 스택의 구현
    - 정수 배열 스택 프로그램
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #define SIZE 100
    typedef int element;
    element stack[SIZE];
    int top = -1;

    int is_empty(){
        return (top == -1);
    }

    int is_full(){
        return (top == SIZE-1);
    }

    void push(element item){
        if(is_full()){
           fprintf(stderr, "스택 포화 에러\n");
           return; 
        }
        else    stack[++top] = item;
    }

    element pop(){
        if(is_empty()){
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        else
            return stack[top--];
    }

    element peek(){
        if(is_empty()){
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        else
            return stack[top];
    }

    int main(){
        push(1);
        push(2);
        push(3);
        printf("%d\n", pop());
        printf("%d\n", pop());
        printf("%d\n", pop());
        
        return 0;
    }
    ```
    
    - 구조체 배열 스택 프로그램
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #define SIZE 100
    typedef int element;
    typedef struct{
        element data[SIZE];
        int top;
    } stack;

    void init(stack *s){
        s->top = -1;
    }

    int is_empty(stack *s){
        return s->top == -1;
    }

    int is_full(stack *s){
        return s->top == SIZE-1;
    }

    void push(stack *s, element item){
        if(is_full(s)){
            fprintf(stderr, "스택 포화 에러\n");
            return;
        }
        else
            s->data[++s->top] = item;
    }

    element pop(stack *s){
        if(is_empty(s)){
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        else
            return s->data[s->top--];
    }

    element peek(stack *s){
        if(is_empty(s)){
            fprintf(stderr, "스택 공백 에러\n");
            exit(1);
        }
        else
            return s->data[s->top];
    }

    int main(){
        stack s;
        init(&s);
        push(&s, 1);
        push(&s, 2);
        push(&s, 3);
        printf("%d\n", pop(&s));
        printf("%d\n", pop(&s));
        printf("%d\n", pop(&s));
        
        return 0;
    }
    ```

    - 동적 배열 스택 프로그램
    ```
    
    ```

    - 스택의 응용 : 괄호 검사 프로그램
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    typedef char element;

    int check_matching(const char * in){
        stack s;
        init(&s);
        char ch, open_ch;
        int n = strlen(in);

        for(int i=0;i<n;i++){
            ch = in[i];
            switch(ch){
            case '(': case '{': case '[':
                push(&s, ch);
                break;
            case ')': case '}': case ']':
                if(is_empty(&s))    return 0;
                else{
                    open_ch = pop(&s);
                    if ( (open_ch == '(' && ch != ')') ||
                       (open_ch == '{' && ch != '}' ||
                       (open_ch == '[' && ch != ']') ){
                        return 0;
                    }
                    break;
                }
            }
        }
        if(!is_empty(&s))   return 0;
        return 1;
    }

    int main(){
        char *p = "{ A[(i+1)]=0; }";
        if(check_matching(p) == 1)
            printf("%s 괄호검사성공\n", p);
        else
            printf("%s 괄호검사실패\n", p);
        
        return 0;
    }
    ```

    - 스택의 응용 : 후위 표기 수식의 계산
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #define SIZE 100

    typedef char element;

    int eval(char exp[]){
        int op1, op2, value;
        int len = strlen(exp);
        char ch;
        stack s;
        init(&s);
        
        for(int i=0;i<len;i++){
            ch = exp[i];
            if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){
                value = ch-'0';
                push(&s, value);
            }
            else{
                op2 = pop(&s);
                op1 = pop(&s);
                switch(ch){
                case '+' :  push(&s, op1 + op2);    break;
                case '-' :  push(&s, op1 - op2);    break;
                case '*' :  push(&s, op1 * op2);    break;
                case '/' :  push(&s, op1 / op2);    break;
                }
            }
        }
        return pop(&s);
    }

    int main(){
        int result;
        printf("후위표기식은 82/3-32*+\n");
        result = eval("82/3-32*+");
        printf("결과값은 %d\n", result);

        return 0;
    }
    ```

    - 중위표기수식을 후위표기수식으로 변환
    ```
    #include <stdio.h>
    #include <stdlib.h>
    #define SIZE 100

    typedef char element;

    int prec(char op){
        switch(op){
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        }
        return -1;
    }

    void infix_to_postfix(char exp[]){
        char ch, top_op;
        int len = strlen(exp);
        stack s;
        init(&s);

        for(int i=0;i<len;i++){
            ch = exp[i];
            switch(ch){
            case '+': case '-': case '*': case '/':
                while(!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                    printf("%c", pop(&s));
                }
                push(&s, ch);
                break;    
            case '(':
                push(&s, ch);
                break;
            case ')':
                top_op = pop(&s);
                while(top_op != '('){
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default:
                printf("%c", ch);
                break;
            }
        }
        while(!is_empty(&s)){
            printf("%c", pop(&s));
        }
    }

    int main(){
        char *s = "(2+3)*4+9";
        printf("중위표시수식 %s \n", s);
        printf("후위표시수식 ");
        infix_to_postfix(s);
        
        return 0;
    }
    ```

    - 스택의 응용 : 미로 문제
    ```
    ㅁㅇㄴㄹ
    ```

---
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

## **6. 연결리스트(1)**

- 리스트 추상 데이터 타입

    ```
    ADT 리스트

    객체 : n개의 element형으로 구성된 순서 있는 모임
    연산 :
    - insert(list, pos, item) ::= pos 위치에 요소를 추가한다.
    - insert_last(list, item) ::= 맨 끝에 요소를 추가한다.
    - insert_first(list, item) ::= 맨 처음에 요소를 추가한다.
    - delete(list, pos) ::= pos 위치의 요소를 제거한다.
    - clear(list) ::= 리스트의 모든 요소를 제거한다.
    - get_entry(list, pos) ::= pos 위치의 요소를 반환한다.
    - get_length(list) ::= 리스트의 길이를 구한다.
    - is_empty(list) ::= 리스트가 비었는지 검사한다.
    - is_full(list) ::= 리스트가 꽉찼는지 검사한다.
    - print_list(list) ::= 리스트의 모든 요소를 표시한다.
    ```

    - 리스트의 구현
        - 배열
            - 장점 : 구현이 간단, 속도가 빠름
            - 단점 : 크기가 고정
        - 포인터
            - 장점 : 크기 제한 없음, 유연한 리스트를 구현(중간 삽입, 삭제 등)
            - 단점 : 구현이 복잡, 임의의 항목 추출 시 배열보다 시간이 많이걸림

    - 구조체 포인터를 받아야 하는 이유는 함수 안에서 구조체를 변경할 필요도 있기 때문, 포인터를 사용하지 않으면 구조체의 복사본이 전달되어서 원본 구조체를 변경할 수 없다.

- 배열로 구현된 리스트(리스트의 순차적 표현)
    - [***배열 리스트***](6_ArrayList_20190515.c)
    - 실행 시간 분석
        - get_entry = O(1)
        - insert, delete = O(n)
        - insert_last = O(1)
    
- 연결 리스트(리스트의 연결된 표현)
    - 노드들의 집합(노드는 데이터필드와 링크필드로 구성)
    - head -> node -> node -> ... -> NULL
    - 연결 리스트의 종류
        - [***단순 연결 리스트***](6_ListNode_20190515.c)
        ```
        - 리스트 탐색
        
        ListNode* search_list(ListNode* head, element val){
            ListNode *p = head;
            while(p != NULL){
                if(p->data == val)
                    return p;
                p = p->link;
            }
            return head;
        }
        ```
        ```
        - 리스트 합병

        ListNode* concat_list(ListNode* list1, list2){
            ListNode *p = list1;
            if(list1 == NULL)   return list2;
            else if(list2 == NULL)  return list1;
            else{
                while(p->link != NULL)
                    p = p->link;
                p->link = list2;
            }
            return list1;
        }
        ```
        ```
        - 리스트 역순

        head -> |10| -> |20| -> |30| -> |40| ->
                          r       q       p
        p : 역순으로 만들 리스트를 가리킨다.
        q : 역순으로 만들 노드를 가리킨다.
        r : 역순화된 리스트를 가리킨다.

        * 초기에 p=head, q=NULL
        NULL head->| |->| |->| |->| |->NULL
         q          p
        
        * 다음에 r=q, q=p, p=p.link, q.link=r
          ┌-----------┐            
        NULL head->| |->| |->| |->| |->NULL 
         r          q    p
 
          ┌-----------┐┌---┐
        NULL head->| |->| |->| |->| |->NULL 
                    r    q    p

          ┌-----------┐┌---┐┌---┐
        NULL head->| |->| |->| |->| |->NULL 
                         r    q    p

          ┌-----------┐┌---┐┌---┐┌---┐
        NULL head->| |->| |->| |->| |->NULL
                              r    q    p

        ListNode* reverse(ListNode* head){
            ListNode* p, q, r;
            p = head;
            q = NULL;
            while(p != NULL){
                r=q; q=p; p=p->link; q->link=r;
            }
            return q;
        }
        ```        

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


## **8. 트리**

- 스택, 큐, 리스트는 선형구조
- 트리는 ***계층적*** 구조  ex) 폴더, 결정트리(decision tree) 등
```
 * 트리용어 *

- 트리 : 한 개 이상의 노드들로 이루어진 유한집합
- 루트 : 부모가 없는 노드
- 서브트리 : 루트를 제외한 노드들의 트리?
- 간선 : 노드간의 연결 선
- 노드의 차수 : 서브트리의 개수
- 단말노드 : 자식이 없는 노드, 차수가 0인 노드
- 비단말노드 : 단말노드 이외의 노드
- 자식노드 : 
- 부모노드 : 
- 형제노드 : 
- 조상노드 : 
- 자손노드 : 
- 트리의 차수 : 트리에 속한 노드의 최대 차수
- 레벨 : 
- 높이 : 트리에 속한 노드의 최대 수준
- 포레스트 : 트리들의 집합
```

- 이진트리 - 모든 노드가 2개의 서브트리를 가지고있는 트리(서브트리가 공집합 일수도 있다)
- 이진트리의 성질
    - 간선의 개수 : n-1
    - 노드의 개수 : 최소 - h(트리의 높이), 최대 - 2^h-1
    - 트리의 높이 : 최대 - n, 최소 - log₂(n+1)
- 이진트리의 종류
    - 포화 이진트리 - 각 레벨에 노드가 꽉차있는 이진트리
    - 완전 이진트리 - 마지막 레벨에서 왼쪽에서 오른쪽 순으로 노드가 순서대로 채워져있는 이진트리
    - 기타 이진트리 - 말 그대로 기타
- 이진트리의 표현
    - 배열
        - 2^h-1개의 공간을 할당
        - 인덱스 0은 사용하지않음
        - 기타 이진트리의 경우 기억공간낭비가 심해짐
        ```
        - 노드 i의 부모 노드 인덱스 = i/2
        - 노드 i의 왼쪽 자식 노드 인덱스 = 2i
        - 노드 i의 오른쪽 자식 노드 인덱스 = 2i+1
        ```
    - 포인터
        ```
        typedef struct {
            int data;
            TreeNode *left, *right;
        } TreeNode;
        ```
- 이진트리의 순회
    - 루트를 언제 방문하는지에 따라 분류
    - 전위순회
    ```
    preorder(T){
        if(T!=NULL){
            print(T)
            preorder(T->left)
            preorder(T->right)
        }
    }
    ```
    - 중위순회
    ```
    inorder(T){
        if(T!=NULL){
            inorder(T->left)
            print(T)
            inorder(T->right)
        }
    }
    ```
    - 후위순회
    ```
    postorder(T){
        if(T!=NULL){
            postorder(T->left)
            postorder(T->right)
            print(T)
        }
    }
    ```
    
    - 반복적 순회(스택 사용)
    ```
    - 중위순회

    void inorder_iter(TreeNode *root){
        // ver1
        while(root!=NULL || is_empty(s)){
            while(root!=NULL){
                push(&s,root);
                root = root->left;
            }
            root = pop(&s);
            print(root);
            root = root->right;
        }
        // ver2
        while(1){
            for(;root;root=root->left)
                push(root);
            root=pop();
            if(!root) break;
            printf("%d", root->data);
            root=root->right;
        }
    }
    ```

    - 레벨 순회(큐 사용)
    ```
    void level_order(TreeNode *root){
        QueueType q;
        init_queue(&q);
        if(root==NULL) return;
        enqueue(&q, root);
        while(!is_empty(&q)){
            root = dequeue(&q);
            printf("%d", root->data);
            if(root->left != NULL)
                enqueue(&q, root->left);
            if(root->right != NULL)
                enqueue(&q, root->right);
        }
    }
    ```
   

## **10. 그래프**

### **10-1 그래프란?**

#### 그래프의 소개

그래프는 객체 사이의 연결 관계를 표현할 수 있는 자료 구조다.
그래프의 대표적인 예는 지도이다.
지하철 노선도는 여러 개의 역들이 어떻게 연결되었는지를 보여준다.
지도를 그래프로 표현하면 지하철의 특정한 역에서 다른 역으로 가는 최단 경로를 쉽게 프로그래밍해서 찾을 수 있다.

또한 전기 소자를 그래프로 표현하게 되면 전기 회로의 소자들이 어떻게 연결되어 있는지를 표현해야 회로가 제대로 동작하는지 분석할 수 있으며, 운영 체제에서는 프로세스와 자원들이 어떻게 연관되는지를 그래프로 분석하여 시스템의 효율이나 교착상태 유무 등을 알아낼 수 있다.

이러한 많은 문제들을 공통적으로 도시, 소자, 자원, 프로젝트 등의 객체들이 서로 연결되어 있는 구조로 표현 가능하다.
그래프는 이러한 많은 문제들을 표현할 수 있는 훌륭한 논리적 도구이다.
우리가 여태까지 배워온 선형리스트나 트리의 구조로는 위와 같은 복잡한 문제들을 표현할 수 없다.
그래프 구조는 인접 행렬이나 인접 리스트로 메모리에 표현되고 처리될 수 있으므로 광범위한 분야의 다양한 문제들을 그래프로 표현하여 컴퓨터 프로그래밍에 의해 해결할 수 있다.

그래프는 아주 일반적인 자료 구조로서 앞에서 배웠던 트리도 그래프의 하나의 특수한 종류로 볼 수 있다.
그래프 이론은 컴퓨터 학문 분야의 활발한 연구 주제이며 문제 해결을 위한 도구로서 많은 이론과 응용이 존재한다.
우리는 여기서 그래프의 기본적인 알고리즘에 대해서 학습한다.

#### 그래프의 역사

1736년에 수학자 오일러(Euler)는 "Konigsberg의 다리" 문제를 해결하기 위하여 그래프를 처음으로 사용하였다.
Konigsberg시의 한 가운데는 Pregel 강이 흐르고 있고 여기에는 7개의 다리가 있다.
"Konigsberg의 다리" 문제란 "임의의 지역에서 출발하여 모든 다리를 단 한번만 건너서 처음 출발했던 지역으로 돌아올 수 있는가" 이다.

많은 사람들이 이 문제의 답을 찾기 위해 노력을 했다.
여러분도 한번 시도해보면 알 수 있지만 그런 방법은 없다는 것이 정답이다.
오일러는 어떤 한 지역에서 시작하여 모든 다리를 한 번씩만 지나서 처음 출발점으로 되돌아오려면 각 지역에 연결된 다리의 개수가 모두 짝수이어야 함을 증명하였다.
오일러는 위의 문제를 다음과 같이 간단하게 변경하였다.

오일러는 이 문제에서 핵심적이고 중요한 것은 'A, B, C, D의 위치가 어떠한 관계로 연결되었는가?'라고 생각하고, 특정 지역은 정점(node)로, 다리는 간선(edge)으로 표현하여 변환하였다.
오일러는 이러한 그래프에서 존재하는 모든 간선을 한번만 통과하면서 처음 정점으로 되돌아오는 경로를 오일러 경로(Eulerian tour)라 정의하고, 그래프의 모든 정점에 연결된 간선의 개수가 짝수일 때만 오일러 경로가 존재한다는 오일러의 정리를 증명하였다.
따라서 오일러의 정리에 의해 오일러 경로가 존재하지 않는다는 것을 복잡한 시행착오를 거치지 않고도 손쉽게 알 수 있게 한다.

#### 그래프로 표현할 수 있는 것들

- 도로
도로의 교차점과 일방통행길 등을 그래프로 효과적으로 표현할 수 있다.

- 미로

- 선수과목
대학교에서 전공과목을 수강하기 위해서는 미리 들어야 하는 선수과목들이 있다.
그래프는 이러한 선수과목 관계를 효과적으로 표현할 수 있다.

### **10-2 그래프의 정의와 용어**

#### 그래프의 정의

그래프는 정점(vertex)과 간선(edge)들의 유한 집합이라 할 수 있다.
수학적으로는 G = (V, E) 와 같이 표시한다.
여기서, V(G)는 그래프 G의 정점들의 집합을, E(G)는 그래프 G의 간선들의 집합을 의미한다.
정점은 여러 가지 특성을 가질 수 있는 객체를 의미하고, 간선은 이러한 정점들 간의 관계를 의미한다.
정점(vertex)은 노드(node)라고도 불리며, 간선(edge)는 링크(link)라고도 불린다.
이 책에서는 '정점'과 '간선'이라는 용어로 통일해서 사용하고자 한다.

그래프는 다음과 같이 집합으로 표현할 수 있다.

```
V(G1) = { 0, 1, 2, 3 }
E(G1) = { (0, 1), (0, 2), (0, 3), (1, 2) }
```

#### 무방향 그래프와 방향 그래프

간선의 종류에 따라 그래프는 무방향 그래프(undirected graph)와 방향 그래프(directed graph)로 구분된다.
무방향 그래프의 간선은 간선을 통해서 양방향으로 갈 수 있음을 나타내며 정점A와 정점B를 연결하는 간선은 (A, B)와 같이 정점의 쌍으로 표현한다.
(A, B)와 (B, A)는 동일한 간선이 된다.
방향 그래프는 간선에 방향성이 존재하는 그래프로서 도로의 일방통행길처럼 간선을 통하여 한쪽 방향으로만 갈 수 있음을 나타낸다.
정점 A에서 정점 B로만 갈 수 있는 간선은 <A, B>로 표시한다.
방향 그래프에서 <A, B>와 <B, A>는 서로 다른 간선이다.

#### 네트워크

간선의 가중치를 할당하게 되면, 간선의 역할이 두 정점간의 연결 유무뿐만 아니라 연결 강도까지 나타낼 수 있으므로 보다 복잡한 관계를 표현할 수 있게 된다.
이렇게 간선에 비용이나 가중치가 할당된 그래프를 가중치 그래프(weighted graph) 또는 네트워크(network)라고 한다.
이 책에서는 "네트워크"로 통일하여 사용하고자 한다.
네트워크는 도시와 도시를 연결하는 도로의 길이, 회로 소자의 용량, 통신망의 사용료 등을 추가로 표현할 수 있으므로 그 응용 분야가 보다 광범위하다.

#### 부분 그래프

어떤 그래프의 정점의 일부와 간선의 일부로 이루어진 그래프를 부분 그래프(subgraph)라고 한다.
그래프 G의 부분 그래프 S는 다음과 같은 수식을 만족시키는 그래프이다.

    V(S) ⊆ V(G)
    E(S) ⊆ E(G)

#### 정점의 차수

그래프에서 인접 정점(abjacent vertex)이란 간선에 의해 직접 연결된 정점을 뜻한다.
무방향 그래프에서 정점의 차수(degree)는 그 정점에 인접한 정점의 수를 말한다.

무방향 그래프에서 모든 정점의 차수를 합하면 간선 수의 2배가 된다.
이것은 하나의 간선이 두개의 정점에 인접하기 때문이다.
방향 그래프에서는 외부에서 오는 간선의 개수를 진입 차수(in-degree)라 하고 외부로 향하는 간선의 개수를 진출 차수(out-degree)라 한다.

#### 경로

무방향 그래프에서 정점 s로부터 정점 e까지의 경로는 정점의 나열 s, v1, v2, ... vk, e로서, 나열된 정점들 간에는 반드시 간선 (s, v1), (v1, v2), ... (vk, e)가 존재해야 한다.
만약 방향 그래프라면 <s, v1>, <v1, v2>, ... <vk, e>가 있어야 한다.

경로 중에서 반복되는 간선이 없을 경우에 이러한 경로를 단순 경로(simple path)라 한다.
만약에 단순 경로의 시작 정점과 종료 정점이 동일하다면 이러한 경로를 사이클(cycle)이라 한다.

#### 연결 그래프

무방향 그래프 G에 있는 모든 정점쌍에 대하여 항상 경로가 존재한다면 G는 연결되었다고 하며, 이러한 무방향 그래프 G를 연결 그래프(connected graph)라 부른다.
그렇지 않은 그래프는 비연결 그래프(unconnected graph)라고 한다.
트리는 그래프의 특수한 형태로서 사이클을 가지지 않는 연결 그래프이다.

#### 완전 그래프

그래프에 속해있는 모든 정점이 서로 연결되어 있는 그래프를 완전 그래프(complete graph)라고 한다.
무방향 완전 그래프의 정점 수를 n이라고 하면, 하나의 정점은 n-1개의 다른 정점으로 연결되므로 간선의 수는 n*(n-1)/2 가 된다.
만약 완전 그래프에서 n=4라면 간선의 수는 (4*3)/2=6 이다.

#### 그래프 추상 데이터 타입

```
ADT 10.1 추상 자료형 : Graph

- 객체 : 정점의 집합과 간선의 집합
- 연산 :
    create_graph() ::= 그래프를 생성한다.
    init(g) ::= 그래프 g를 초기화 한다.
    insert_vertex(g,v) ::= 그래프 g에 정점 v를 삽입한다.
    insert_edge(g,u,v) ::= 그래프 g에 간선 (u,v)를 삽입한다.
    delete_vertex(g,v) ::= 그래프 g의 정점 v를 삭제한다.
    delete_edge(g,u,v) ::= 그래프 g의 간선 (u,v)를 삭제한다.
    is_empty(g) ::= 그래프 g가 공백 상태인지 확인한다.
    adjacent(v) ::= 정점 v에 인접한 정점들의 리스트를 반환한다.
    destroy_graph(g) ::= 그래프 g를 제거한다.
```

간선은 2개의 정점을 이용하여 표현됨을 유의하라.

### **10-3 그래프의 표현 방법**

그래프를 표현하는 방법에는 다음과 같이 2가지의 방법이 있다.
그래프 문제의 특성에 따라 위의 두 가지 표현 방법은 각각 메모리 사용량과 처리 시간 등에서 장단점을 가지므로, 문제에 적합한 표현 방법을 선택해야 한다.

- 인접 행렬(adjacency matrix) : 2차원 배열을 사용하여 그래프를 표현한다.
- 인접 리스트(adjacency graph) : 연결 리스트를 사용하는 그래프를 표현한다.

#### 인접 행렬

그래프의 정점 수가 n이라면 n*n의 2차원 배열인 인접 행렬 M의 각 원소를 다음의 규칙에 의해 할당함으로써 그래프를 메모리에 표현할 수 있다.

```
if(간선 (i, j)가 그래프에 존재)  M[i][j] = 1,
otherwise                      M[i][j] = 0.
```

우리가 다루고 있는 그래프에서는 자체 간선을 허용하지 않으므로 인접 행렬의 대각선 성분은 모두 0으로 표시된다.
그림의 (a), (b)와 같이 무방향 그래프의 인접 행렬은 대칭 행렬이 된다.
이는 무방향 그래프의 간선(i, j)는 정점 i에서 정점 j로의 연결뿐만 아니라 정점 j에서 정점 i로의 연결을 동시에 의미하기 때문이다.
따라서 무방향 그래프의 경우, 배열의 상위 삼각이나 하위 삼각만 저장하면 메모리를 절약할 수 있다.
그러나 그림 (c)의 방향 그래프의 예에서 보듯이 방향 그래프의 인접 행렬은 일반적으로 대칭이 아니다.

n개의 정점을 가지는 그래프를 인접 행렬로 표현하기 위해서는 간선의 수에 무관하게 항상 n²개의 메모리 공간이 필요하다.
이에 따라 인접 행렬은 그림 (a)와 같이 그래프에 간선이 많이 존재하는 밀집 그래프(dense graph)를 표현하는 경우에는 적합하나 , 그림 (b)와 같이 그래프 내에 적은 숫자의 간선만을 가지는 희소 그래프(sparse graph)의 경우에는 메모리의 낭비가 크므로 적합하지 않다.

인접 행렬을 이용하면 두 정점을 연결하는 간선의 존재 여부를 O(1)시간 안에 즉시 알 수 있는 장점이 있다.
즉 정점 u와 정점 v를 연결하는 정점이 있는지를 알려면 M[u][v]의 값을 조사하면 바로 알 수 있다.
또한 정점의 차수는 인접 행렬의 행이나 열을 조사하면 알 수 있으므로 O(n)의 연산에 의해 알 수 있다.
정점 i에 대한 차수는 다음과 같이 인접 배열의 i번째 행에 있는 값을 모두 더하면 된다.

degree(i) = M[i][k] (k=0 ~ n-1)

반면에 그래프에 존재하는 모든 간선의 수를 알아내려면 인접 행렬 전체를 조사해야 하므로 n²번의 조사가 필요하게 되어 O(n²)의 시간이 요구된다.

#### 인접 행렬을 이용한 그래프 추상 데이터 타입의 구현

그래프에 관련된 변수들을 하나의 구조체 GraphType에 정리하도록 하자.
먼저 그래프에 존재하는 정점의 개수 n이 필요하다.
인접 행렬을 이용하여 구현하려면 또한 크기가 n*n인 2차원 배열인 인접 행렬이 필요하다.
인접 행렬의 이름을 adj_mat라고 하면 GraphType 구조체는 다음과 같이 정의할 수 있다.

```
#define MAX_VERTICES 50
typedef struct GraphType {
    int n;  // 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
```

물론 이런 식으로 구현하면 한정된 개수의 정점까지만 그래프에 삽입할 수 있다.
만약 동적 배열로 구현한다면 사용자가 정점을 삽입할 때마다 다시 크기를 조정할 수 있을 것이다.

정점을 삽입하는 연산은 n을 하나 증가하면 된다.
정점의 번호는 순차적으로 증가한다고 가정하자.
간선을 삽입하는 연산은 adj_mat[start][end]와 adj_mat[end][start]에 1을 삽입하면 된다.
물론 방향 그래프인 경우에는 adj_mat[start][end]에만 1을 삽입하여야 한다.
전체 프로그램은 다음과 같다.

```
프로그램 10.1 adj_mat.c

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
    int n;  // 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 그래프 초기화
void init(GraphType* g)
{
    int r, c;
    g->n = 0;
    for (r=0; r<MAX_VERTICES; r++)
        for (c=0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
    if (((g->n)+1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
    if (start >= g->n || end >= g->n)
    {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g)
{
    for (int i=0; i<g->n; i++) {
        for (int j=0; j<g->n; j++) {
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);
    print_adj_mat(g);

    free(g);
}
```

#### 인접 리스트

인접 리스트(adjacency list)는 그래프를 표현함에 있어 각각의 정점에 인접한 정점들을 연결리스트로 표시한 것이다.
각 연결 리스트의 노드들은 인접 정점을 저장하게 된다.
각 연결 리스트들은 헤더 노드를 가지고 있고 이 헤더 노드들은 하나의 배열로 구성되어 있다.
따라서 정점의 번호만 알면 이 번호를 배열의 인덱스로 하여 각 정점의 연결 리스트에 쉽게 접근할 수 있다.

무방향 그래프의 경우 정점 i와 정점 j를 연결하는 간선 (i,j)는 정점 i의 연결 리스트에 인접 정점 j로서 한번 표현되고, 정점 j의 연결 리스트에 인접 정점 i로 다시 한번 표현된다.
인접 리스트의 각각의 연결 리스트에 정점들이 입력되는 순서에 따라 연결 리스트 내에서 정점들의 순서가 달라질 수 있다.
우리는 그래프 표현의 일관성을 유지하기 위하여 그림과 같이 인접 리스트가 정점의 오름차순으로 연결된다고 가정한다.

따라서 정점의 수가 n개이고 간선의 수가 e개인 무방향 그래프를 표시하기 위해서는 n개의 연결 리스트가 필요하고, n개의 헤더 노드와 2e개의 노드가 필요하다.
따라서 인접 행렬 표현은 간선의 개수가 적은 희소 그래프(sparse graph)의 표현에 적합하다.

그래프에 간선 (i,j)의 존재 여부나 정점 i의 차수를 알기 위해서는 인접 리스트에서 정점 i의 연결 리스트를 탐색해야 하므로 연결 리스트에 있는 노드의 수만큼, 즉 정점 차수만큼의 시간이 필요하다.
즉 n개의 정점과 e개의 간선을 가진 그래프에서 전체 간선의 수를 알아내려면 헤더 노드를 포함하여 모든 인접 리스트를 조사해야 하므로 O(n+e)의 연산이 요구된다.

#### 인접 리스트를 이용한 그래프 추상 데이터 타입의 구현

그래프에 관련된 변수들을 하나의 구조체 GraphType에 정리하도록 하자.
먼저 그래프에 존재하는 정점의 개수 n이 필요하다.
인접 리스트를 이용하여 구현하려면 각 정점마다 하나의 연결 리스트가 필요하다.
따라서 정점의 개수만큼의 포인터 배열이 필요하다.
포인터 배열의 이름을 adj_list라고 하고 연결 리스트의 하나의 노드를 GraphNode라는 구조체를 이용하여 나타내자.

```
프로그램 10.2 adj_list.c

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n;  // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// 그래프 초기화
void init(GraphType* g)
{
    int v;
    g->n = 0;
    for (v=0; v<MAX_VERTICES; v++)
        g->adj_list[v] = NULL;
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
    if(((g->n)+1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v)
{
    GraphNode* node;
    if (u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    node = (GraphNode *)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void print_adj_list(GraphType* g)
{
    for(int i=0; i<g->n; i++) {
        GraphNode* p = g->adj_list[i];
        printf("정점 %d의 인접 리스트 ", i);
        while (p != NULL) {
            printf("-> %d ", p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}

int main()
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i=0;i<4;i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    print_adj_list(g);
    free(g);

    return 0;
}
```

위의 코드에서 정점 0의 인접 리스트가 형성되는 과정을 보자.
insert_edge(0, 1)가 호출되면 다음과 같은 상태가 된다.

이 상태에서 insert_edge(1, 0)가 호출되면 정점 1의 인접 리스트 맨 처음에 정점 0이 추가된다.

이 상태에서 insert_edge(0, 2)가 호출되면 인접 리스트 맨 처음에 정점 2가 추가된다.

### **10-4 그래프 탐색**

그래프 탐색은 가장 기본적인 연산으로서 하나의 정점으로부터 시작하여 차례대로 모든 정점들을 한 번씩 방문하는 것이다.
그래프 탐색은 아주 중요하다.
많은 문제들이 단순히 그래프의 노드를 탐색하는 것으로 해결된다.
대표적으로 특정한 정점에서 다른 정점으로 갈 수 있는지 없는지를 탐색을 통하여 알 수 있다.
예를 들어 도시를 연결하는 그래프가 있을 때, 특정 도시에서 다른 도시로 갈 수 있는지 없는지는 그래프를 특정 노드에서 시작하여 탐색하여 보면 알 수 있다.
또한 다음과 같은 전자 회로에서 특정 단자와 단자가 서로 연결되어 있는지 연결되어 있지 않은지를 탐색을 통하여 알 수 있다.

그래프의 탐색 방법은 깊이 우선 탐색과 너비 우선 탐색의 두 가지가 있다.

- 깊이 우선 탐색(DFS: depth first search)
- 너비 우선 탐색(BFS: breath first search)

깊이 우선 탐색은 트리에서 생각하면 이해하기 쉽다(트리도 그래프의 일종이라는 점을 명심하자).
트리를 탐색할 때 시작 정점에서 한 방향으로 계속 가다가 더 이상 갈 수 없게 되면 다시 가장 가까운 갈림길로 돌아와서 다른 방향으로 다시 탐색을 진행하는 방법과 유사하다.
그림에서 0->1->3->4->2->5->6의 순서대로 탐색이 진행된다.

너비 우선 탐색은 시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법이다.
그림에서 0->1->2->3->4->5->6의 순서대로 탐색이 진행된다.

### **10-5 깊이 우선 탐색**

그래프에서 깊이 우선 탐색은 어떻게 진행될까?
깊이 우선 탐색은 그래프의 시작 정점에서 출발하여 시작 정점 v를 방문하였다고 표시한다.
이어서 v에 인접한 정점들 중에서 아직 방문하지 않은 정점 u를 선택한다.
만약 그러한 정점이 없다면 탐색은 종료한다.
만약 아직 방문하지 않은 정점 u가 있다면 u를 시작 정점으로 하여 깊이 우선 탐색을 다시 시작한다.
이 탐색이 끝나게 되면 다시 v에 인접한 정점들 중에서 아직 방문이 안 된 정점을 찾는다.
만약 없으면 종료하고 있다면 다시 그 정점을 시작 정점으로 하여 깊이 우선 탐색을 다시 시작한다.
깊이 우선 탐색도 자기 자신을 다시 호출하는 순환 알고리즘의 형태를 가지고 있음을 알 수 있다.

```
알고리즘 10.1 깊이우선탐색

depth_first_search(v):

    v를 방문되었다고 표시;
    for all u ∈ (v에 인접한 정점) do
        if (u가 아직 방문되지 않았으면)
            then depth_first_search(u)
```

그림에 예제 그래프를 깊이 우선 탐색한 결과를 보였다.
여기서 0번 정점을 시작 정점으로 선택하였다.

#### 깊이 우선 탐색의 구현(인접 행렬 버전)

깊이 우선 탐색을 구현하는 데는 2가지의 방법이 있다.
순환 호출을 이용하는 것이 첫 번째 방법이고 두 번째 방법은 명시적인 스택을 사용하여 인접한 정점들을 스택에 저장하였다가 다시 꺼내어 작업을 하는 것이다.

여기서는 순환 호출을 이용하는 방법으로 구현하기로 한다.
방문 여부를 기록하기 위해 배열 visited를 사용하며, 모든 정점의 visited 배열값은 FALSE으로 초기화되고 정점이 방문될 때마다 해당 정점의 visited 배열값은 TRUE로 변경된다.

또한 그래프가 인접 행렬 또는 인접 리스트로 표현되었는가에 따라 깊이 우선 탐색 프로그램이 약간 달라지는데, 여기서는 먼저 인접 행렬을 이용하여 그래프가 표현되었다고 가정하고 깊이 우선 탐색 프로그램을 구현하였다.

adj_mat[v][w] 값이 1이면 정점 v와 정점 w는 인접한 것이고 정점 w가 아직 방문되지 않았으면 정점 w를 시작 정점으로 하여 깊이 우선 탐색을 다시 시작한다.

```
프로그램 10.3 인접 배열로 표현된 그래프에 대한 깊이우선탐색 프로그램

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
typedef struct GraphType {
    int n;  // 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

// 그래프 초기화
void init(GraphType* g)
{
    int r, c;
    g->n = 0;
    for (r=0; r<MAX_VERTICES; r++)
        for(c=0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
    if (((g->n)+1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

// 간접 삽입 연산
void insert_edge(GraphType *g, int start, int end)
{
    if (start >= g->n || end >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// 인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_mat(GraphType* g, int v)
{
    int w;
    visited[v] = TRUE;  // 정점 v의 방문 표시
    printf("정점 %d -> ", v);   // 방문한 정점 출력
    for (w=0; w<g->n; w++)
        if (g->adj_mat[v][w] && !visited[w])
            dfs_mat(g, w);  // 정점 w에서 DFS 새로 시작
}

int main(void)
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for (int i=0; i<4; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 3);

    printf("깊이 우선 탐색\n");
    dfs_mat(g, 0);
    printf("\n");
    free(g);

    return 0;
}
```

#### 깊이 우선 탐색의 구현(인접 리스트 버전)

프로그램 10.4는 그래프가 인접 리스트로 표현되었을 경우의 깊이 우선 탐색 프로그램이다.
인접 리스트는 다수의 연결 리스트로 구성되는데, 각 연결 리스트의 노드는 데이터 필드와 링크 필드로 이루어지는데, 데이터 필드에는 인접 정점의 번호가 저장되고 링크 필드에는 다음 인접 정점을 가리키는 포인터가 저장된다.
연결 리스트의 노드는 구조체 타입 GraphNode로 정의되었다.
포인터 배열 adj_list의 각 요소는 각 연결 리스트의 첫번째 노드를 가리킨다.
역시 방문 여부를 기록하기 위하여 visited를 사용하였다.

```
프로그램 10.4 인접배열로 표현된 그래프에 대한 깊이우선탐색 프로그램

int visited[MAX_VERTICES];

// 인접 리스트로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_list(GraphType* g, int v)
{
    GraphNode* w;
    visited[v] = TRUE;              // 정점 v의 방문 표시
    printf("정점 %d -> ", v);       // 방문한 정점 출력
    for (w = g->adj_list[v]; w; w = w->link)    // 인접 정점 탐색
        if (!visited[w->vertex])
            dfs_list(g, w->vertex); // 정점 w에서 DFS 새로 시작
}
```

#### 명시적인 스택을 이용한 깊이 우선 탐색의 구현

깊이 우선 탐색은 명시적인 스택을 사용하여 구현이 가능하다.
다음은 의사 코드이다.

```
DFS-iterative(G, v):

    스택 S를 생성한다.
    S.push(v)
    while (not is_empty(S)) do
        v = S.pop()
        if (v가 방문되지 않았으면)
            v를 방문되었다고 표시
            for all u ∈ (v에 인접한 정점) do
                if (u가 아직 방문되지 않았으면)
                    S.push(u)
```

택을 하나 생성하여서 시작 정점을 스택에 넣는다.
이어서 스택에서 하나의 정점을 꺼내서 탐색을 시작한다.
정점을 방문한 후에 정점의 모든 인접 정점들을 스택에 추가한다.
스택에 하나도 남지 않을 때까지 알고리즘은 계속된다.

#### 깊이 우선 탐색의 분석

깊이 우선 탐색은 그래프의 모든 간선을 조사하므로 정점의 수가 n이고 간선의 수가 e인 그래프인 경우, 그래프가 인접 리스트로 표현되어 있다면 시간 복잡도가 O(n+e)이고, 인접 행렬로 표시되어 있다면 O(n²)이다.
이는 희소 그래프인 경우 깊이 우선 탐색은 인접 리스트의 사용이 인접 행렬보다 시간적으로 유리함을 뜻한다.

### **10.6 너비 우선 탐색**

너비 우선 탐색(breath first search: BFS)은 시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법이다.

너비 우선 탐색을 위해서는 가까운 거리에 있는 정점들을 차례로 저장한 후 꺼낼 수 있는 자료구조인 큐(queue)가 필요하다.
알고리즘은 무조건 큐에서 정점을 꺼내서 정점을 방문하고 인접 정점들을 큐에 추가한다.
큐가 소진할 때까지 동일한 코드를 반복한다.
다음은 너비 우선 탐색의 의사 코드이다.

```
알고리즘 10.2 너비 우선 탐색 알고리즘

breath_first_search(v):

    v를 방문되었다고 표시;
    큐 Q에 정점 v를 삽입;
    while(Q가 공백이 아니면) do
        Q에서 정점 w를 삭제;
        for all u ∈ (w에 인접한 정점) do
            if (u가 아직 방문되지 않았으면)
                then    u를 큐에 삽입;
                        u를 방문되었다고 표시;
```

너비 우선 탐색의 특징은 시작 정점으로부터 거리가 가까운 정점의 순서로 탐색을 진행된다는 것이다.
너비 우선 탐색은 거리가 d인 정점들을 모두 방문한 다음, 거리가 (d+1)인 정점들을 모두 방문하게 된다.
즉 거리가 0인 시작 정점을 방문한 후, 거리가 1인 정점, 2인 정점, 3인 정점 등의 순서로 정점들을 방문해간다.

#### 너비 우선 탐색의 구현(인접 행렬 버전)

다음은 인접 행렬을 이용하여 너비 우선 탐색을 구현한 것이다.
너비 우선 탐색은 큐를 사용하여야 하므로 깊이 우선 탐색보다 코드가 약간 복잡해진다.

```
프로그램 10.5 너비 우선 탐색(인접 행렬 표현) 프로그램

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message)'
    exit(1);
}

void queue_init(QueueType *q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int is_full(QueueType *q) {
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType *q, element item) {
    if (is_full(q))
        error("큐 포화 에러");
    q->rear = ((q->rear+1)%MAX_QUEUE_SIZE);
    q->queue[q->rear] = item;
}

element dequeue(QueueType *q) {
    if (is_empty(q))
        error("큐 공백 에러");
    q->front = ((q->front+1)%MAX_QUEUE_SIZE);
    return q->queue[q->front];
}

#define MAX_VERTICES 50
typedef struct GraphType {
    int n;  // 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;
int visited[MAX_VERTICES];

// 그래프 초기화
void graph_init(GraphType* g) {
    int r, c;
    g->n = 0;
    for(r=0; r<MAX_VERTICES; r++)
        for(c=0; c<MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v) {
    if (((g->n)+1) > MAX_VERTICES)
        error("그래프: 정점의 개수 초과");
    g->n++;
}

// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n)
        error("그래프 : 정점 번호 오류");
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}
void bfs_mat(GraphType* g, int v) {
    int w;
    QueueType q;

    queue_init(&q);         // 큐 초기화
    visited[v] = TRUE;      // 정점 v 방문 표시
    printf("%d 방문 -> ", v);
    enqueue(&q, v);         // 시작 정점을 큐에 저장
    while(!is_empty(&q)) {
        v = dequeue(&q);    // 큐에 정점 추출
        for (w=0; w<g->n; w++)  // 인접 정점 탐색
            if (g->adj_mat[v][w] && !visited[w]) {
                visited[w] = TRUE;  // 방문 표시
                printf("%d 방문 -> ", w);
                enqueue(&q, w); // 방문한 정점을 큐에 저장
            }
    }
}

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);
    for (int i=0; i<6; i++)
        insert_vertex(g, i);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);

    printf("너비 우선 탐색\n");
    bfs_mat(g, 0);
    printf("\n");
    free(g);
    return 0;
}
```

#### 너비 우선 탐색의 구현(인접 리스트 버전)

```
프로그램 10.6 너비 우선 탐색(인접 리스트 표현) 프로그램

void bfs_list(GraphType* g, int v) {
    GraphNode* w;
    QueueType q;

    init(&q);               // 큐 초기화
    visited[v] = TRUE;      // 정점 v 방문 표시
    printf("%d 방문 -> ", v);
    enqueue(&q, v);         // 시작정점을 큐에 저장
    while(!is_empty(&q)) {
        v = dequeue(&q);    // 큐에 저장된 정점 선택
        for (w=g->adj_list[v]; w; w=w->link) {  // 인접 정점 탐색
            if (!visited[w->vertex]) {          // 미방문 탐색
                visited[w->vertex] = TRUE;      // 방문 표시
                printf("%d 방문 -> ", w->vertex);
                enqueue(&q, w->vertex);         // 정점을 큐에 삽입
            }
        }
    }
}
```

#### 너비 우선 탐색의 분석

너비 우선 탐색은 그래프가 인접 리스트로 표현되어 있으면 전체 수행시간이 O(n+e)이며, 인접행렬로 표현되는 있는 경우는 O(n²) 시간이 걸린다.
너비 우선 탐색도 깊이 우선 탐색과 같이 희소 그래프를 사용할 경우 인접리스트를 사용하는 것이 효율적이다.