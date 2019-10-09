```c
swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

selectionSort(int a[], int n) {
    int i, j, least;
    for(i=0; i<n-1; i++) {          // n-1번 반복
        least = i;
        for(j=i+1; j<n; j++) {      // n-1, n-2, n-3, ..., 1
            if(a[j] < a[least]) {   // 비교: n(n-1)/2 번
                least = j;
            }
        }
        swap(a[least], a[i]);       // 이동: (n-1)*3 번
    }
}

insertionSort(int a[], int n) {
    int i, j, key;
    for(i=1; i<n; i++) {            // n-1번 반복
        key = a[i];                 // 이동
        for(j=i-1; j>=0 && a[j]>key; j--) { // 비교 (최선: n-1, 최악: n(n-1)/2)
            a[j+1] = a[j];          // 이동
        }
        a[j+1] = key;               // 이동 (최선: (n-1)*2, 최악: n(n-1)/2 + (n-1)*2)
    }
}

bubbleSort(int a[], int n) {
    int i, j;
    for(i=n-1; i>0; i--) {          // n-1번 반복
        for(j=0; j<i; j++) {        // n-1, n-2, n-3, ..., 1
            if(a[j] > a[j+1]) {     // 비교: n(n-1)/2 번
                swap(a[j], a[j+1]); // 이동 (최선: 0번 , 최악: (n(n-1)/2) * 3)
            }
        }
    }
}

insertionSort_Shell(int a[], int first, int last, int gap) {   // gap만큼씩 정렬
    int i, j, key;
    for(i=first+gap; i<=last; i+=gap) {
        key = a[i];
        for(j=i-gap; j>=first && a[j]>key; j-=gap) {
            a[j+gap] = a[j];
        }
        a[j+gap] = key;
    }
}

shellSort(int a[], int n) {
    int i, gap;
    for(gap=n/2; gap>0; gap/=2) {
        if(gap%2 == 0) {
            gap++;
        }
        for(i=0; i<gap; i++) {
            insertSort_Shell(a, i, n-1, gap);   // 삽입정렬
        }
    }
}
```

알고리듬|비교|이동|최선|평균|최악
:-:|:-:|:-:|:-:|:-:|:-:
선택정렬 | n(n-1)/2 | 3(n-1) | O(n²) | O(n²) | O(n²)
삽입정렬 | 최선: n-1, 최악: n(n-1)/2 | 최선: 2(n-1), 최악: n(n-1)/2 + 2(n-1) | O(n) | O(n²) | O(n²)
버블정렬 | n(n-1)/2 | 최선: 0, 최악: (n(n-1)/2) * 3 | O(n²) | O(n²) | O(n²)
쉘 정렬 | | | O(n) | O(n^1.5) | O(n²)