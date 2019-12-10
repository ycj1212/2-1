다형성

```c++
class Animal {
public:
	void speak() { cout << "Animal speak()" << endl; }
};

class Dog : public Animal {
public:
	void speak() { cout << "멍멍" << endl; }
};

class Cat : public Animal {
public:
	void speak() { cout << "야옹" << endl; }
};

int main() {
	Animal* a1 = new Dog();
	a1->speak();

	Animal* a2 = new Cat();
	a2->speak();

	return 0;
}

/*  
 *  Animal speak()
 *  Animal speak()
 */
```

가상함수

```c++
class Animal {
public:
	virtual void speak() { cout << "Animal speak()" << endl; }
};

class Dog : public Animal {
public:
	void speak() { cout << "멍멍" << endl; }
};

class Cat : public Animal {
public:
	void speak() { cout << "야옹" << endl; }
};

int main() {
	Animal* a1 = new Dog();
	a1->speak();

	Animal* a2 = new Cat();
	a2->speak();

	return 0;
}

/*  
 *  멍멍
 *  야옹
 */
```

동적바인딩 vs 정적바인딩

객체 포인터의 타입 변환
- 상향 타입 변환(업캐스팅)
    
    `Child child;`
    
    `Child* c = &child`
    
    `Parent* p = c;`

- 하향 타입 변환(다운캐스팅)

    `c = (Child*)p;`

가상 소멸자

```c++
class Parent {
public:
	~Parent() { cout << "Parent 소멸자" << endl; }
};

class Child : public Parent {
public:
	~Child() { cout << "Child 소멸자" << endl; }
};

int main() {
	Parent* p = new Child();

	delete p;

	return 0;
}

/*  
 *  Parent 소멸자
 */
```

해결책: 부모클래스의 소멸자를 가상 함수로 선언

```c++
class Parent {
public:
	virtual ~Parent() { cout << "Parent 소멸자" << endl; }
};

class Child : public Parent {
public:
	~Child() { cout << "Child 소멸자" << endl; }
};

int main() {
	Parent* p = new Child();

	delete p;

	return 0;
}

/*  
 *  Child 소멸자
 *  Parent 소멸자
 */
```

순수 가상 함수

`virtual void show() = 0;`

추상 클래스

최소한 하나의 순수 가상 함수를 가진 클래스

```c++
class Shape {
public:
    virtual void draw() = 0;
};
```

객체 생성 불가능
하지만, 포인터는 선언 가능