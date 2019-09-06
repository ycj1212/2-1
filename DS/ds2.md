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
