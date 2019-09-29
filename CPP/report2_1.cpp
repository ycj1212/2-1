#include <iostream>

using namespace std;

class Circle {
private:
	int radius;

public:
	Circle() { radius = 0; }
	void set(int r) { radius = r; }
	double getArea() {
		return (( 3.14 * radius * radius ) > 100);
	}
};

int main() {
	Circle c[10];
	int n;
	int r;
	int count = 0;

	cout << "원의 개수 >> ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r;
		c[i].set(r);
		if (c[i].getArea() == 1)
			count++;
	}

	cout << "면적이 100보다 큰 원은 " << count << "개 입니다" << endl;

	return 0;
}