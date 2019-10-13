1. 다음 수들을 오름차순으로 정렬하고자 한다. 퀵 정렬 방법을 적용하였을 때, 이동 회수를 구하라. 정렬 과정을
단계별로 보이면서 이동 회수를 카운팅하는 과정을 보여라: (4, 7, 1, 8, 6, 2, 5, 3)

```c
int partition(int list[], int left, int right) {
    int pivot;
    int low, high;
    
    low = left;
    high = right+1;
    pivot = list[left];
    
    do {
        do {
            low++;
        } while(list[low] < pivot);
        do {
            right--;
        } while(list[high] > pivot);
        if(low < high)  swap(&list[low], &list[high]);  // 이동
    } while(low < high);

    swap(&list[high], &list[left]); // 이동

    return high;
}

quickSort(int list[], int left, int right) {
    if(left < right) {
        int p = partition(list, left, right);
        quickSort(list, left, p-1);
        quickSort(list, p+1, right);
    }
}
```

int list[] = { 4, 7, 1, 8, 6, 2, 5, 3 };
left = 0;
right = 7;

1. quickSort(list, 0, 7);

    4 7 1 8 6 2 5 3
    pivot: 4, low: list[1]=7 , high: list[7]=3
    / swap(7, 3)

    4 3 1 8 6 2 5 7
    pivot: 4, low: list[2]=1 , high: list[6]=5

    4 3 1 8 6 2 5 7
    low: list[3]=8 , high: list[5]=2
    / swap(8, 2)

    4 3 1 2 6 8 5 7
    low: list[4]=6 , high: list[4]=6

    low: list[4]=6 , high: list[3]=2

    swap(list[left]=4, list[high]=2);

    2 3 1 4 6 8 5 7
    high = 3;

2. quickSort(list, 0, 3-1); left: 0 , right: 2
3. quickSort(list, 3+1, 7); left: 4 , right: 7

    *2.*

    2 3 1
    pivot: 2, low: list[1]=3, high: list[2]=1
    / swap(3, 1)

    2 1 3
    low: list[2]=3, high: list[1]=1
    
    swap(list[left]=2, list[high]=1);

    1 2 3
    high = 1;

    *3.*

    6 8 5 7
    pivot: 6, low: list[5]=8, high: list[7]=7

    6 8 5 7
    low: list[5]=8, high: list[6]=5
    / swap(8, 5)

    6 5 8 7
    low: list[6]=8, high: list[5]=5

    swap(list[left]=6, list[high]=5);

    5 6 8 7
    high = 5;

list = 1 2 3 4 5 6 8 7

4. quickSort(list, 0, 1-1); // XX
5. quickSort(list, 1+1, 2); // XX
6. quickSort(list, 4, 5-1); // XX
7. quickSort(list, 5+1, 7);

    *7.*

    8 7
    pivot: 8, low: list[7]=7, right: list[7]=7

    swap(list[left]=8, list[high]=7)

    7 8
    high = 7;

list = 1 2 3 4 5 6 7 8