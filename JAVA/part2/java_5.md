# 5주차

## Java Collection Framework

### 인터페이스

java.util.List, java.util.Set, java.util.Queue, java.util.Map

### 구현 클래스

ArrayList, LinkedList, HashMap, TreeMap, HashSet, TreeSet
 
### 알고리즘

검색, 정렬 및 셔플링과 같은 몇 가지 일반적인 기능을 제공하는 유용한 방법

### 장점

* 개발 노력 감소
* 품질향상
* 재사용성과 상호 운용성

### 반복자 사용하기

```java
ArrayList<String> list = new ArrayList<String>();
list.add("하나 ");
list.add("둘 ");
list.add("셋 ");
list.add("넷 ");
String s;
Iterator e = list.iterator();
while (e.hasNext()) {
    s = (String)e.next();
    System.out.println(s);
}
```

### 리스트에서 조건에 맞는 요소 찾기

```java
ArrayList<String> list = new ArrayList<>();
list.add("iPhone");
list.add("Ubuntu");
list.add("Android");
list.add("Mac OS X");
list.removeIf(c -> c.toLowerCase().contains("x"));
list.forEach(c -> System.out.println(c));
```

### LinkedList

삽입과 삭제가 빈번하게 일어나는 경우에 사용

```java
LinkedList<String> list = new LinkedList<String>();
list.add("MILK");
list.add("BREAD");
list.add("BUTTER");
list.add(1, "APPLE");
list.set(2, "GRAPE");
list.remove(3);
for (int i=0; i<list.size; i++) {
    System.out.println(list.get(i));
}
```

ArrayList | LinkedList
-|-
동적 배열 사용 | 이중 연결 리스트 사용
리스트의 중간 위치의 요소를 수정할 경우 느리다 | 보다 빠르다 
리스트로도 사용 | 리스트와 큐로도 사용
저장 및 접근에 용이 | 데이터 조작(삽입, 삭제) 시 용이

```java
class Book implements Comparable<Book> {
	int id;
	String name, author, publisher;
	int quantity;
	
	public Book(int id, String name, String author, String publisher, int quantity) {
		this.id = id;
		this.name = name;
		this.author = author;
		this.publisher = publisher;
		this.quantity = quantity;
	}
	
    // Comparable 인터페이스 구현
	public int compareTo(Book b) {
		if (id > b.id) {
			return 1;
		}
		else if (id < b.id) {
			return -1;
		}
		else {
			return 0;
		}
	}
}

public class Collections {
	public static void main(String[] args) {
		List<Book> list = new LinkedList<Book>();

		list.add(new Book(1, "", "", "", 1));
		list.add(new Book(2, "", "", "", 2));
		list.add(new Book(3, "", "", "", 3));
		for (Book b : list) {
			System.out.println(b.id+" "+b.name+" "+b.author+" "+b.publisher+" "+b.quantity);
		}
	}
}
```

### Set

순서가 없고, 중복을 허용하지 않음

- **HashSet**: 해쉬 테이블에 원소 저장, 성능 우수, 원소 순서 일정하지 않음
- **TreeSet**: 트리에 원소 저장, HashSet보다 느림, 값에 따라 순서 결정
- **LinkedHashSet**: 해쉬 테이블과 연결 리스트를 결합한 것

### HashSet

```java
HashSet<String> set = new HashSet();
set.add("One");
set.add("Two");
set.add("Three");
set.add("Four");
set.add("Five");
Iterator<String> i = set.iterator();
while (i.hasNext()) {
    System.out.println(i.next());	// 순서가 일정하지 않음
}
```

```java
Set<String> set1 = new HashSet<String>();
String[] sample = {"단어", "중복", "구절", "중복"};
for (String a : sample) {
    if (!set1.add(a)) {
        System.out.println("중복된 단어 " + a);
    }
}
System.out.println(set1.size() + "중복되지 않은 단어: " + set1);
```

### 대량 연산 메소드

```java
set1.containsAll(set2);	// 부분집합
set1.addAll(set2);		// 합집합
set1.retainAll(set2);	// 교집합
set1.removeAll(set2);	// 차집합
```

### TreeSet

```java
TreeSet<String> set = new TreeSet<String>();
set.add("A");
set.add("B");
set.add("C");
set.add("D");
set.add("E");
System.out.println(set);	// 기본 오름차순
System.out.println(set.descendingSet());	// 내림차순
System.out.println(set.headSet("C", true));	// C 포함(true) 앞에 있는 원소들 출력
System.out.println(set.subSet("A", false, "E", true));	// A(포함X) 부터 E(포함)까지 출력
System.out.println(set.tailSet("C", false));	// C(포함X) 뒤에 있는 원소들 출력
```

### Queue

후단에서 원소를 추가하고 전단에서 원소를 삭제

```java
// Queue
Queue<Integer> queue = new LinkedList<Integer>();
int time = 10;
for (int j=time; j>=0; j--) {
    queue.add(j);
}
while (!queue.isEmpty()) {
    System.out.print(queue.remove()+" ");
    // Thread.sleep(1000);
}
```

### Priority Queue

- 원소들이 무작위로 삽입되었더라도 정렬된 상태로 원소들을 추출한다.
- remove() 호출 시 가장 작은 원소가 추출
- 히프(Heap) 자료구조 사용

```java
PriorityQueue<Integer> pq = new PriorityQueue<Integer>();

pq.add(30);
pq.add(80);
pq.add(20);

for (Integer o : pq) {
    System.out.println(o);
}
System.out.println("원소 삭제");
while (!pq.isEmpty()) {
    System.out.println(pq.remove());
}
```