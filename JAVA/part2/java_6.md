# 6주차

```java
List<Integer> list = Arrays.asList(3,2,1,4,5,6,6);

// 표준 반복 구문
for (int i=0; i<list.size(); i++) {
    System.out.println(list.get(i));
}

// for-each 구문
for (Integer i : list) {
    System.out.println(i);
}

// 람다식
list.forEach(i -> System.out.println(i));

// 메소드 참조
list.forEach(System.out::println);
```

## Map

- 많은 데이터 중에서 원하는 데이터를 빠르게 찾을 수 있는 자료 구조
- 맵은 사전과 같은 자료 구조(파이썬에서 딕셔너리와 비슷)

Map은 인터페이스...  
Map을 구현하는 클래스 사용  
가장 일반적으로 HashMap, TreeMap를 사용

```java
Map mapA = new HashMap();  
Map mapB = new TreeMap();  

Map<String, MyObject> map = new HashMap<String, MyObject>();

for (MyObject anObject : map.values()) {
	System.out.println(anObject);	// 값 출력
}

for (String key : map.keySet()) {
	System.out.println(key);	// 키 출력
	MyObject value = map.get(key)
}

// 요소 삽입
map.put("key1", "element1");
map.put("key2", "element2");
map.put("key3", "element3");
/*
객체만 삽입 가능
기본 값을 키 또는 값으로 전달하는 경우 기본 값은 매개 변수로 전달되기 전에 오토박스로 표시된다.
*/
map.put("key", 123); // 123: Integer
```

```java
Map<String, Integer> items = new HashMap<>();

items.put("A", 10);
items.put("B", 20);
items.put("C", 30);
items.put("D", 40);
items.put("E", 50);
items.put("F", 60);

items.forEach((k,v) -> System.out.println("Item: " + k + " Count: " + v));

items.forEach((k,v) -> {
	System.out.println("Item: " + k + " Count: " + v);
	if ("E".equals(k)) {
		System.out.println("Hello E");
	}
});
```

## Collections 클래스

Collections 클래스 알고리즘

- 정렬(Sorting)
- 섞기(Shuffling)
- 탐색(Searching)

### 정렬

```java
String[] sample = {"i", "walk", "the", "line"};
List<String> list = Arrays.asList(sample);  // 배열을 리스트로 변경
Collections.sort(list);
System.out.println(list);
```

### 람다식을 이용한 정렬

```java
List<Student> studentlist = new ArrayList<Student>();

studentlist.add(new Student("Jon", 22, 1001));
studentlist.add(new Student("Steve", 19, 1003));
studentlist.add(new Student("Kevin", 23, 1005));
studentlist.add(new Student("Ron", 20, 1010));

studentlist.forEach((s) -> System.out.println(s));
studentlist.sort((Student s1, Student s2) -> s1.age - s2.age);
studentlist.forEach((s) -> System.out.println(s));
```

### 섞기

```java
List<String> list = Arrays.asList("A", "B", "C", "D", "1", "2", "3");

System.out.println(list);
Collections.shuffle(list);
System.out.println(list);
```

### 탐색

```java
int key = 50;
List<Integer> list = new ArrayList<Integer>();

for (int i=0;i<100;i++) {
	list.add(i);
}
int index = Collections.binarySearch(list, key);
System.out.println("탐색의 반환값 = " + index);
```

## Java 8

### JAVA Stream

```java
myShapesCollection.stream()
.filter(e -> e.getColor() == Color.RED)
.forEach(e -> System.out.println(e.getName()));
```

- 객체 컬렉션을 처리하는 데 사용
- 스트림은 원하는 결과를 생성하기 위해 파이프 라인 될 수 있는 다양한 메소드를 지원하는 오브젝트의 시퀀스

```java
List<String> list = Arrays.asList("kiwi", "banana", "apple");
List<String> result = list.stream()
.filter(s -> !s.equals("apple"))
.collect(Collectors.toList());

result.forEach(System.out::println);
```

#### filter

필터 메소드는 인수로 전달된 Predicate에 따라 요소를 선택하는 데 사용

```java
List names = Arrays.asList("Reflection", "Collection", "Stream");
List result = names.stream()
.filter(s -> s.startsWith("S"))
.collect(Collectors.toList());
```

#### map

map() 메소드는 인수로 전달된 Predicate에 따라 컬렉션의 항목을 다른 객체에 매핑하는데 사용

```java
List number = Arrays.asList(2,3,4,5);
List square = number.stream()
.map(x -> x*x)
.collect(Collectors.toList());
```

#### sorted

sorted() 메소드는 스트림을 정렬하는데 사용

```java
List names = Arrays.asList("Reflection", "Collection", "Stream");
List result = names.stream().sorted().collect(Colletors.toList());
```

#### collect

collect() 메소드는 스트림에서 중간 작업의 결과를 반환하는데 사용

```java
List number = Arrays.asList(2,3,4,5,3);
Set square = number.stream()
.map(x -> x*x)
.collect(Collectors.toSet());
```