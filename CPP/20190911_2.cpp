#include <iostream>
#include <string>
using namespace std;

int main()
{
	int me, com;
	string res;

	do {
		cout << "Enter your choice(scissors:0, rock:1, paper:2, exit:3) : ";
		cin >> me;

		com = rand() % 3;

		if (me < 0 || me > 3)
			res = "Try again!";
		else if (me == 3)
			res = "Exit!";
		else if (me == com)
			res = "Tie!";
		else if (me == 0 && com == 2)
			res = "You Win!";
		else if (me == 2 && com == 0)
			res = "You Lose!";
		else if (me > com)
			res = "You Win!";
		else
			res = "You Lose!";

		cout << "me = " << me << ", com = " << com << endl;
		cout << res << endl;

	} while (me != 3);

	return 0;
}