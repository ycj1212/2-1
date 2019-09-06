## **4. 스택**

- 스택 - 후입선출(LIFO : Last-In First-out)

- 스택의 구현
    - 정수 배열 스택 프로그램
    ```c
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
    ```c
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
    ```c
    
    ```

    - 스택의 응용 : 괄호 검사 프로그램
    ```c
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
    ```c
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
    ```c
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
    ```c
    ㅁㅇㄴㄹ
    ```
