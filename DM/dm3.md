## **3. 알고리즘(Algorithm)**

***3.1 알고리즘***

* 알고리즘 - 문제를 해결하기 위한 절차

* 알고리즘의 표시
    * 자연어 : 한글, 영어
    * 프로그래밍 언어 : C, Java, Python 등
    * Pseudo-code(의사코드)

* 알고리즘의 특징
    * 명확성 - 알고리즘의 각 단계는 명확히 정의되어야한다.
    * 정확성 - 알고리즘의 각 입력값에 대해 정확한 출력값을 만들어야 한다.
    * 유한성 - 알고리즘은 집합에 있는 어떤 입력에 대해서도 유한한 수의 단계를 거친 후 원하는 출력이 나와야 한다.
    * 효율성 - 알고리즘의 각 단계를 유한한 양의 시간 안에 수행될 수 있어야 한다.
    * 일반성 - 프로시저는 단지 특정한 입력값에 대해서만 아니라 요구하는 모든 형태의 문제에 적용될 수 있어야 한다.

```
- 유한 수열의 최대값을 찾는 알고리즘

procedure max(a1, a2,...,an : integer)
max := a1
for i := 2 to n
    if max < ai then max := ai
return max{max is the largest element}
```

* 탐색 알고리즘(Searching Algorithm) - 리스트(배열, 집합)에서 특정 원소를 찾는 문제
    * **선형 탐색** - 리스트를 구성하는 원소들을 순서대로 비교하여 특정 원소를 찾는 방법

    ```
    - 선형 탐색 알고리즘

    procedure linearSearch(x:integer, a1,a2,...,an : distinct integers)
    i := 1
    while(i<=n and x!=ai)
        i := i + 1
    if i<=n then location := i
    else location := 0
    return location
    ```

    * **이진 탐색**
        * 리스트의 원소들이 정렬되어 있는 경우에 사용
        * 리스트의 중앙에 위치한 원소와 찾고자 하는 원소를 비교
            * 찾고자 하는 원소가 중앙의 원소보다 크면 리스트의 오른쪽 영역을 탐색
            * 찾고자 하는 원소가 중앙의 원소보다 작으면 리스트의 왼쪽 영역을 탐색
        * 리스트의 오른쪽 또는 왼쪽 영역을 탐색할 경우도 마찬가지 방법을 적용
            * 리스트의 탐색 영역이 절반으로 축소
        
    ```
    - 이진 탐색 알고리즘
    
    procedure binary search(x : integer, a1, a2,...,an : increasing integers)
    i := 1{i is left endpoint of search interval}
    j := n{j is right endpoint of search interval}
    while i < j
        m := ⎣(i+j)/2⎦
        if m > am then i := m + i
        else j := m
    if x = ai then location := i
    else location := 0
    return location
    ```

* 정렬 알고리즘
    * **버블 정렬**
        * 계속해서 인접 원소와 비교하여 순서에 맞지 않으면 서로 교환
        * 기포가 떠 오르듯, 작은 원소가 큰 원소와 위치가 바뀌어 위로 떠오르고 큰 원소는 바닥으로 가라앉음.
    
    ```
    - 버블 정렬 알고리즘

    procedure bubblesort(a1,...,an : real numbers with n>=2)
    for i := 1 to n-1
        for j := 1 to n-i
            if aj > aj+1 then interchange aj and aj+1
    ```

    * **삽입 정렬** - 리스트의 원소 하나하나를, 완전 정렬 되었을 때 들어가야 할 위치에 삽입

    ```
    - 삽입 정렬 알고리즘

    procedure insertion sort(a1, a2,...,an : real numbers with n>=2)
    for j := 2 to n
        i := 1
        while aj > ai
            i := i + 1
        m := aj
        for k := 0 to j-i-1
            aj-k := aj-k-1
        ai := m
    ```

3.1 연습문제

3. 리스트에 있는 모든 정수의 합을 구하는 알고리즘을 작성
```
procedure sum(a1, a2,...,an : integer)
sum := 0
for i := 1 to n
    sum := sum + ai;
return sum
```

6. n개의 정수를 갖는 리스트를 입력받아 리스트에서 음의 정수의 개수를 찾는 알고리즘 작성
```
procedure minus(a1, a2,...,an : integer)
count := 0
for i := 1 to n
    if ai < 0 then
        count := count + 1
return count
```

7. n개의 정수를 갖는 리스트를 입력받아 리스트에서 마지막 짝수의 위치를 출력하거나 리스트에 짝수가 없을 경우 0을 출력하는 알고리즘
```
procedure even_place(a1, a2,...,an : integer)
ep := 0
for i := 1 to n
    if (ai % 2) = 0
        ep := i
return ep
```

10. x는 실수이고 n이 정수일 떄, x^n 을 계산하는 알고리즘을 작성
```
procedure square(x, res : real, n : integer)
res := 1

if n > 0 then
    for i := 1 to n
        res := res * x;

else if n < 0 then
    for i := 1 to -n
        res := res * x;
    res := 1/res;

return res;
```
```
procedure square(x, res : real, n : integer)
res := 1

if n != 0 then
    for i := 1 to |n|
        res := res * x;
if n < 0 then
    res := 1/res;
return res;
```

14. 수열 1,3,4,5,6,8,9,11 에서 7을 찾을 때 사용되는 모든 단계를 열거하라.
```
a) 선형탐색
    1. 1 == 7 false
    2. 3 == 7 false
    3. 4 == 7 false
    4. 5 == 7 false
    5. 6 == 7 false
    6. 8 == 7 false
    7. 9 == 7 false
    8. 11 == 7 false
```
```
b) 이진탐색
    1. 1,3,4,5  /   6,8,9,11
    2. m = 5
    3. 6,8  /   9,11
    4. m = 6
    5. 6    /   8
    6. false
```

16. 유한한 자연수들의 수열에서 가장 작은 정수를 찾는 알고리즘을 작성
```
procedure search_min(min, a1, a2,..., an : natural number)
min := a1
for i := 2 to n
    if min > ai then min := ai
return min
```

18. 유한한 정수들의 리스트에서 가장 작은 원소가 나타나는 마지막 위치를 구하는 알고리즘을 작성, 리스트의 정수들이 반드시 서로 다른 것은 아니다.
```
procedure min_place(min, mp, a1, a2,..., an : integer)
min := a1
mp := 1
for i := 2 to n
    if min >= ai then
        min := ai
        mp := i
return mp
```

20. 유한한 정수들의 수열에서 가장 큰 정수와 가장 작은 정수를 찾는 알고리즘을 작성
```
procedure max_and_min(a1, a2,...,an : integer)
min := a1
max := a1
for i := 2 to n
    if min > ai then min := ai
    if max < ai then max := ai
return max, min
```

34. 버블정렬을 이용하여 6,2,3,1,5,4 를 정렬하라. 각 단계에서 얻어지는 리스트를 보여라
```
    6 2 3 1 5 4
1.  2 6 3 1 5 4 -> 2 3 6 1 5 4 -> 2 3 1 6 5 4 -> 2 3 1 5 6 4 -> 2 3 1 5 4 6
2.  2 3 1 5 4 6 -> 2 1 3 5 4 6 -> 2 1 3 5 4 6 -> 2 1 3 4 5 6
3.  2 1 3 4 5 6 -> 1 2 3 4 5 6
4.  1 2 3 4 5 6
5.  1 2 3 4 5 6
```

38. 삽입정렬을 이용하여 6,2,3,1,5,4 를 정렬하라. 각 단계에서 얻어지는 리스트를 보여라
```
    6 2 3 1 5 4
1.  2 6 3 1 5 4
2.  2 3 6 1 5 4
3.  2 3 1 6 5 4 -> 2 1 3 6 5 4 -> 1 2 3 6 5 4
4.  1 2 3 5 6 4
5.  1 2 3 5 4 6 -> 1 2 3 4 5 6
```

52. 25센트, 10센트, 5센트, 1센트를 사용하여 다음 금액의 거스름돈을 만들기 위해 욕심쟁이 알고리즘을 사용하라.
```
a) 87센트
    - 25*3 + 10*1 + 1*2
b) 49센트
    - 25*1 + 10*2 + 1*4
c) 99센트
    - 25*3 + 10*2 + 1*4
d) 33센트
    - 25*1 + 5*1 + 1*3
```


3.2 연습문제

25. 다음 함수에 대해 가장 좋은 big-O를 추정하라
a) (n^2 + 8)(n + 1)
b) (nlogn + n^2)(n^3 + 2)
c) (n! + 2^n)(n^3 + log(n^2 + 1))

26. 다음의 함수에 big-O를 추정하라. f(x)가 O(g(x))라고 추정이 된다면 g를 가장 낮은 차수의 간단한 함수로 표현하라.
a) (n^3 + n^2logn)(logn + 1) + (17logn + 19)(n^3 + 2)
b) (2^n + n^2)(n^3 + 3^n)
c) (n^n + n*2^n + 5^n)(n! + 5)