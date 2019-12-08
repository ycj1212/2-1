복사생성자

객체를 복사 생성할 때 사용하는 생성자

```c++
MyClass(const MyClass& other) {
    ...
}
```

같은 종류의 객체로 초기화하는 경우

객체를 함수로 전달하는 경우

함수에서 객체를 반환하는 경우

얕은복사

복사생성자에서 포인터를 복사하는 경우 같은 메모리를 가리키고 있어 수정, 삭제 시 문제 발생

깊은복사

복사생성자에서 포인터를 복사하는 경우 새로운 메모리 공간을 할당받음

객체간 비교(==)를 할 수 없다 -> 연산자 중복 정의 필요!

객체간의 관계

is-a 관계
: 상속관계

has-a 관계
: 하나의 객체가 다른 객체를 가지고 있는 관계

```c++
class Date {

};

class Person {
    Date birth;     // has-a 관계
};
```

정적 변수

static member

프로그램이 시작할 때 생성

클래스마다 하나만 생성

클래스의 모든 객체가 하나의 변수를 공유

non-static member

객체가 생성될 때 함께 생성

인스턴스 멤버

```c++
class Circle {
    int x, y, radius;
    static int count;   // 정적 변수
    const static int MAX_CIRCLE = 300;   // 정적 상수의 경우 클래스 내부에서 초기화 가능
public:
    Circle() {
        count++;
    }
    ~Circle() {
        count--;
    }
    static int getCount() { // 정적 함수
        return count;
    }
};

int Circle::count = 0;  // 정적 변수는 반드시 클래스 외부에서 초기화

int main() {
    Circle c1;
    cout << Circle::getCount() << endl;
    Circle c2;
    cout << Circle::getCount() << endl;

    return 0;
}
```

정적 함수는 일반 멤버에 접근 불가
함수내의 지역변수는 접근 가능

this 포인터를 사용할 수 없다. 왜냐하면 this가 가리키는 객체가 없기 때문이다.