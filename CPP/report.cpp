#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

void read_file(string str[], int n);
int check_continue();

int main()
{
	char ch;

	string list[50];
	read_file(list, 50);

	string solution;
	int n = rand() % 50;
	solution = list[n];

	string guess(solution.length(), '_');

	int life = 6;
	bool failed;
	string let = "";

	while (1)
	{
		cout << "The word now looks like this: " << guess << endl;
		cout << "you have " << life << " guesses left (tried letters:" << let << ")\n" << endl;

		cout << "Guess a letter: ";
		cin >> ch;
		cout << "You guessed: " << ch << endl;

		let = let + " " + ch;
		failed = true;

		for (int i = 0; i < solution.length(); i++)
		{
			if (ch == solution[i])
			{
				guess[i] = ch;
				failed = false;
			}
		}

		if (failed == true)
			life--;

		if (life <= 0)
		{
			cout << "Fail!";
			if (check_continue() == 1)
			{
				n = rand() % 4;
				solution = list[n];
				guess = "";
				for (int i = 0; i < solution.length(); i++)
				{
					guess += '_';
				}
				life = 6;
				let = "";
			}
			else
				break;
		}

		if (solution == guess)
		{
			cout << solution << endl;
			cout << "Success!";
			if (check_continue() == 1)
			{
				n = rand() % 4;
				solution = list[n];
				guess = "";
				for (int i = 0; i < solution.length(); i++)
				{
					guess += '_';
				}
				life = 6;
				let = "";
			}
			else
				break;
		}
	}
	
	return 0;
}

void read_file(string str[], int n) {
	ifstream is("dic.txt", ios::in);

	if (!is)
	{
		cerr << "file open error" << endl;
		exit(1);
	}

	int idx = 0;

	while (!is.eof())
	{
		getline(is, str[idx++]);
	}
}

int check_continue()
{
	char ch;

	while (1)
	{
		cout << "To be continue? (y/n): ";
		cin >> ch;

		if (ch == 'y')
			return 1;
		else if (ch == 'n')
			return 0;
		else
			cout << "Check again!" << endl;
	}
}