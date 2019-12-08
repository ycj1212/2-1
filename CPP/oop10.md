연산자 중복

연산자의 의미 추가, 중복

연산자 함수 구현 방법

클래스 내부
클래스 외부

(v1 + v2)
(v1.operator+(v2))

```c++
class MyVector {
    double x, y;
public:
    MyVector operator+(const MyVector& v2);    
};

MyVector MyVector::operator+(const MyVector& v2) {
    MyVector v;
    v.x = this->x + v2.x;
    v.y = this->y + v2.y;
    return v;
}
```

프렌드

(~에서 접근할 수 있다)
외부함수
다른 클래스의 멤버 함수
다른 클래스 전체

```c++
class Power {
    int kick, punch;
public:
    Power operator+(int op1, Power op2);
    friend Power operator+(int op1, Power op2); //
}

Power Power::operator+(int op1, Power op2) {}
Power operator+(int op1, Power op2) {}          //
```

할당 연산자 중복

```c++
class Box {
    double width, height;
public:
    Box& operator=(const Box& b2) {
        this->width = b2.width;
        this->height = b2.height;
        return *this;
    }
};
```

+= 연산자 중복