#include <iostream>
#include <string>

using namespace std;

class Character {
private:
	string name;
	int x, y;
	int HP;

public:
	Character(string n, int xx = 0, int yy = 0, int hp = 0) {
		name = n;
		x = xx;
		y = yy;
		HP = hp;
	}
	void set_x(int xx) { x = xx; }
	void set_y(int yy) { y = yy; }
	void set_hp(int hp) { HP = hp; }
	string get_name() { return name; }
	int get_x() { return x; }
	int get_y() { return y; }
	int get_hp() { return HP; }
	void print() { cout << "Name: " << get_name() << ", Coordinate: (" << get_x() << ", " << get_y() << "), HP: " << get_hp() << endl; }
};

int main() {
	Character c1("Yang"), c2("Song", 2, 2, 100);

	c1.print();
	c2.print();

	c1.set_x(4);
	c1.set_y(5);
	c1.set_hp(70);

	c2.set_x(3);
	c2.set_y(4);
	c2.set_hp(50);

	cout << "---------------변경 후---------------" << endl;

	c1.print();
	c2.print();

	return 0;
}