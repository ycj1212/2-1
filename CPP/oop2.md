# 2. 제어 구조와 배열

```c++
#include <iostream>
using namespace std;

int main() {
    bool b;
    b = (1 == 2);
    
    cout << std::boolalpha;
    cout << b << endl;

    return 0;
}
```

- b를 출력할 때 b가 true이면 1, false이면 0을 출력하는데 std::boolalpha 를 사용하면 "true"나 "false"를 출력한다.

## continue 문장 예제
```c++
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    do {
        i++;
        cout << "continue 문장 전에 있는 문장" << endl;
        continue;
        cout << "continue 문장 후에 있는 문장" << endl;
    } while (i<3);

    return 0;
}
```

- continue는 continue 뒤에 있는 문장들을 실행하지 않고 조건문으로 스킵되기 때문에, continue 문장 전에 있는 문장만 출력된다.

## C++에는 for-each 반복문도 있다.

```c++
#include <iostream>
using namespace std;

int main() {
    int list[] = {1,2,3,4,5,6,7,8,9,10};

    for (int i : list) {
        cout << i << " ";
    }
    cout << endl;
}
```

# 3. 함수와 문자열

## 함수 원형(Function prototype)

```c++
#include <stdio.h>

int square(int n);
int main()
{
    int result;
    result = square(5);
    printf("%d\n", result);

    return 0;
}

int square(int n)
{
    return(n * n);
}
```

함수 원형은 컴파일러에게 함수에 대한 인터페이스 정보를 주어서 컴파일러가 매개변수 검사, 반환형 검사 등을 하게 하기 위한 것이다.

컴파일러는 함수 square()가 어떤 매개변수를, 어떤 반환형을 가지고 있는지 전혀 알 수가 없어서 컴파일러가 해야 할 중요한 검사를 할 수가 없게 된다.

`int square(int); // 매개 변수의 이름 생략 가능`

## 함수 호출 시 인수 전달 방법

### call-by-value
: 함수 호출 시 인수의 값이 매개변수로 복사된다.

### call-by-reference
: 인수의 원본(ex..주소값)이 함수에 전달된다.
매개변수를 변경하면 원본 인수가 변경된다.

c에서는 포인터를 사용하지만, c++에서는 참조자를 사용하여 구현할 수 있다.

#### 참조자 : 변수의 별명

```c++
int var = 10;
int &ref = var;
// &기호는 변수의 주소를 계산하는 연산자가 아니다.
ref = 20;
// ref=20, var=20
```

함수의 매개변수 외에 참조자를 사용하려면 반드시 선언과 동시에 초기화해야 한다.

## 중복 함수(Overloaded functions)

동일한 이름의 함수를 여러 개 정의하는 것을 **중복 함수**라고한다.

매개변수의 개수, 타입, 순서를 시그니처라고 한다.
중복 함수는 이름은 같지만 시그니처가 달라야 한다.

반환형이 다르다고 해서 함수를 중복시킬 수는 없다.
매개변수가 달라야한다.

```c++
#include <iostream>
using namespace std;

int square(int i)
{
    return i * i;
}

double square(double i)
{
    return i * i;
}

int main()
{
    cout << square(10) << endl;
    cout << square(2.0) << endl;
    
    return 0;
}
```

## 디폴트 인수

함수의 매개변수의 개수보다 전달되는 인수의 개수가 더 적을 경우 오류가 발생한다.
이를 대비해서, 인수를 전달하지 않아도 디폴트값(***기본값***)을 전달하는 기능이 있다.
이것을 디폴트 인수라고 한다.

```c++
void display(char c = '*', int n = 10)
{
    for(int i=0; i<n; i++)
        cout << c;
    cout << endl;
}

int main()
{
    display();          // 아무런 인수가 전달되지 않는 경우
    display('#');       // 첫번째 인수만 전달되는 경우
    display('#', 5);    // 모든 인수가 전달되는 경우
}
```

### 주의점

디폴트 인수는 반드시 마지막 인수이어야 한다.

`int print(double value = 0,0, int prec);   // error`

인수가 매개변수로 전달될 때는 왼쪽에서 오른쪽 순서로 전달된다.
디폴트 인수는 오른쪽에서 시작하여서 왼쪽으로 지정하여야 한다.

## 인라인 함수

함수 호출 시에는 약간의 오버헤드가 발생한다.
아주 간단한 함수의 경우, 크기가 작은 함수의 경우 함수 호출을 하지 않고 코드를 복사하여서 넣어주는 편이 효율적일 수 있다.
c++에서는 인라인(inline)이라고 하는 키워드가 있다.
함수 이름 앞에 inline이 붙으면 컴파일러는 함수를 생성하지 않고 함수의 코드를 호출한 곳에 직접 집어넣는다.
함수를 인라인으로 만들면 함수 호출 오버헤드가 사라지므로 프로그램이 더 빠르게 실행할 수 있다.

```c++
inline double square(double i)
{
    return i * i;
}
```

## String 클래스

### 문자열 비교

```c++
string s1 = "Hello", s2 = "World";
if(s1 == s2)
    cout << "동일한 문자열입니다." << endl;
else
    cout << "동일한 문자열이 아닙니다." << endl;

if(s1 > s2)
    cout << "s1이 앞에 있습니다." << endl;
else
    cout << "s2가 앞에 있습니다." << endl;
```