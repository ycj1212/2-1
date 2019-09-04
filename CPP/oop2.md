## 자바 vs C++

|         | 자바 | C++ |
|---------| ---- | --- |
| 실행방식 | -- (컴파일) --> 바이트코드 -- (자바가상머신 - 인터프리터(해석기)) --> 기계어| -- (컴파일) --> 기계어 |
| 객체 | 힙 객체(new) | 힙 객체, ***스택 객체***(malloc) |
| 반환 | X | free() |
| 상속 | 단일 상속 | ***다중 상속*** |
| 중복 | 메소드 중복 | 메소드 중복, ***연산자 중복*** |
| 바인딩 | 동적 바인딩(실행 중..) | 정적 바인딩(실행 전..) |

-- (컴파일) --> 목적파일(.obj) -- (***링킹***) --> 실행파일(.exe) --> 실행

```c++
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    return 0;
}
```

## cout

- 스크린 출력 장치에 연결된 표준 C++ 출력 스트림 객체
- < iostream > 헤더 파일에 선언
- std 이름 공간에 선언: std::cout으로 사용

## << 연산자

- 스트림 삽입 연산자(stream insertion operator)
    - C++ 기본 산술 시프트 연산자(<<)가 스트림 삽입 연산자로 중복 정의됨
    - ostream 클래스에 구현됨
    - 오른쪽 피연산자를 왼쪽 스트림 객체에 삽입
    - cout 객체에 연결된 화면에 출력

- 여러 개의 << 연산자로 여러 값 출력

    `cout << "Hello\n" << "첫 번째 맛보기입니다.";`

## using namespace std;

- 변수 이름이나 함수 이름과 같은 수많은 이름(식별자)들은 이름 공간(name space)이라고 하는 영역으로 분리되어 저장
    - 프로그램에서 사용되는 이름들간의 충돌 방지
    - 개발자 자신만의 이름 공간을 생성할 수 있게 함
    - 이름 충돌 사례
        - 프로젝트를 여러 명이 나누어 개발하는 경우
        - 다른 사람이 작성한 소스코드나 목적파일을 사용하는 경우

## std:: 란?

- std
    - C++ 표준에서 정의한 이름 공간(namespace) 중 하나
        - < iostream > 헤더 파일(모든 C++ 표준 라이브러리 포함)에 선언된 모든 이름은 std 이름 공간 안에 있음
        - cout, cin, endl 등
    - std 이름 공간에 선언된 이름을 접근하기 위해 std:: 접두어 사용
        - std::cout, std::cin, std::endl
        - '::'은 범위 지정 연산자
    
- std:: 생략
    - using 지시어 사용

- JAVA 관련
    - namespace vs package
    - using vs import

## #include < iostream > 과 std

- < iostream >이 통째로 std 이름 공간 내에 선언
    - < iostream > 헤더 파일을 사용하려면 다음 코드 필요
    ```c++
    #include <iostream>
    using namespace std;

    int main() {
        cout << "너비 입력>>";
        
        int width;
        cin >> width;

        cout << "높이 입력>>";

        int height;
        cin >> height;
        
        int area = width * height;
        cout << "면적은 " << area << "\n";
    }
    ```

## cin과 >> 연산자를 이용한 키 입력

- cin
    - 표준 입력 장치인 키보드를 연결하는 C++ 입력 스트림 객체

- `>>` 연산자
    - 스트림 추출 연산자(stream extraction operator)
        - C++ 산술 시프트 연산자(>>)가 < iostream > 헤더 파일에 스트림 추출 연산자로 중복정의됨
        - 입력 스트림에서 값을 읽어 변수에 저장

    - 연속된 >> 연산자를 사용하여 여러 값 입력 가능
    ```c++
    cout << "너비와 높이 입력>>";
    cin >> width >> height;
    cout << width << '\n' << height << '\n';
    ```

## cin과 >> 연산자를 이용한 키 입력

- 다음의 모든 기본 타입에 대해서 >> 연산자로 데이터 입력 가능
    - bool, char, short, int, long, float, double

```c++
int i;
cin >> i;

double d;
cin >> d;
```

## C++ 기본 데이터 타입

| type | byte |
| ---- | ---- |
| bool | 1 |
| char | 1 |
| short | 2 |
| int | 4 |
| float | 4 |
| long long | 8 |
| double | 8 |
| long double | 8 |

## string 클래스

```c++
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "Good";
    string s2 = "Morning";
    string s3 = s1 + " " + s2 + "!";

    cout << s3 << endl;
    
    return 0;
}
```

- 문자열 비교
```c++
string s1 = "Good";
string s2 = "Bad";
bool b = (s1 == s2);
```

- 문자열과 숫자 연결
```c++
string s1 = "사과";
string s2;

s2 = s1 + " " + to_string(10) + "개";
cout << s2 << endl;
```

- 문자열 입력
```c++
string name;

cout << "Enter your name:";
cin >> name;
cout << name << "are welcomed" << endl;
```