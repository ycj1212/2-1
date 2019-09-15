#include <iostream>
using namespace std;

void swap1(int x, int y);
void swap2(int *x, int *y);
void swap3(int &x, int &y);

void selectionSort(int arr[], int n);
void print_array(int arr[], int n);

int main()
{
	/*
	int a = 10, b = 20;

	swap1(a, b);
	
	cout << "값 호출 버전" << endl;
	cout << "a = " << a << ", b = " << b << "\n" << endl;

	swap2(&a, &b);

	cout << "포인터 호출 버전" << endl;
	cout << "a = " << a << ", b = " << b << "\n" << endl;
	
	swap3(a, b);

	cout << "참조자 호출 버전" << endl;
	cout << "a = " << a << ", b = " << b << "\n" << endl;
	*/

	int a[] = { 5, 3, 10, 8, 1, 2, 9, 7, 4, 6 };
    
    print_array(a, 10);
	selectionSort(a, 10);
	print_array(a, 10);

	return 0;
}

void swap1(int x, int y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void swap2(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swap3(int &x, int &y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void selectionSort(int arr[], int n) {
	int least;
	for (int i = 0; i < n - 1; i++) {
		least = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[least] > arr[j]) {
				least = j;
			}
		}
		swap3(arr[i], arr[least]);
	}
}

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}