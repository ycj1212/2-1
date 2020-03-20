상속

상속 관계의 생성자와 소멸자 실행

- 자식 클래스의 객체가 생성될 때 자식 클래스의 생성자와 기본 클래스의 생성자가 모두 실행되는가?
아니면 자식 클래스의 생성자만 실행되는가?

- 자식 클래스의 생성자와 기본 클래스의 생성자 중에서 어떤 생성자가 먼저 실행되는가?

- 객체가 소멸될 경우에 그 순서는?

부모 클래스의 생성자 -> 자식 클래스의 생성자
자식 클래스의 소멸자 -> 부모 클래스의 소멸자

```c++
class A {
public:
    A() { cout << "생성자 A" << endl; }
    ~A() { cout << "소멸자 A" << endl; }
};

class B : public A {
public:
    B() { cout << "생성자 B" << endl; }
    ~B() { cout << "소멸자 B" << endl; }
}

class C : public B {
public:
    C() { cout << "생성자 C" << endl; }
    ~C() { cout << "소멸자 C" << endl; }
}

/* 
 *  생성자 A
 *  생성자 B
 *  생성자 C
 *  소멸자 C
 *  소멸자 B
 *  소멸자 A
 */
```

부모 클래스의 생성자를 명시하지 않으면, 항상 기본 생성자가 호출
부모 클래스의 기본 생성자가 없다면, 오류

부모 클래스의 다른 생성자 호출

```c++
class A {
public:
    A() { cout << "생성자 A" << endl; }
    A(int x) { cout << "매개변수 생성자 A" << endl; }
};

class B : class A {
public:
    B() { cout << "생성자 B" << endl; }
    B(int x) : A(x + 3) { cout << "매개변수 생성자 B" << x << endl; }
};
```

```c++
Rectangle(int x=0, int y=0, int w=0, int h=0) : Shape(x,y) {
    width = w;
    height = h;
}

Rectangle(int x=0, int y=0, int w=0, int h=0) : Shape(x,y), width(w), height(h) {}
```

접근 지정자

접근 지정자 | 자기 클래스 | 자식 클래스 | 외부
-|-|-|-
private|O|X|X
protected|O|O|X
public|O|O|O

함수 재정의(Overriding)

부모 클래스를 상속받는 3가지 방법

`|public으로 상속|protected로 상속|private로 상속
-|-|-|-|
부모 클래스의 public 멤버|public|protected|private|
부모 클래스의 protected 멤버|protected|protected|private
부모 클래스의 private 멤버|X|X|X

접근 지정자 생략 시 private 상속

다중 상속

```c++
class SuperA {
public:
    int x;
};
class SuperB {
public:
    int x;
};
class Sub : public SuperA, public SuperB {};

int main() {
    Sub obj;
    obj.x = 10; // 오류 발생

    obj.SuperA::x = 10;
    obj.SuperB::x = 20;

    return 0;
}
```