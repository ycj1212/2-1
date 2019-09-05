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
