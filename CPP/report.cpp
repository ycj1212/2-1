#include <iostream>
#include <string>
#include <math.h>

/* 단어사전을 구축하라 : 적어도 30개 이상 단어 포함(파일 입출력 가능)
   사용자의 실패 시도 횟수를 6으로 제한
   사용자가 시도한 알파벳 나열
   게임반복
*/

using namespace std;

int main()
{
  char ch;
  
  string solution;
  string list[] = 
  {
    "the",
    "c++",
    "programming",
    "language"
  };
  int n = rand() % 4;
  solution = list[n];

  string guess(solution.length(), '_');

  int life = 6;
  bool failed;
  string let = "";

  while(1)
  {
    cout << "The word now looks like this: " << guess << endl;
    cout << "you have " << life << " guesses left (tried letters:" << let << ")\n" << endl;

    cout << "Guess a letter: ";
    cin >> ch;
    cout << "You guessed: " << ch << endl;

    let = let + " " + ch;
    failed = true;

    for(int i=0; i<solution.length(); i++)
    {
      if(ch == solution[i])
      {
        guess[i] = ch;
        failed = false;
      }
    }

    if(failed == true)
      life--;
    
    if(life <= 0)
    {
      cout << "실패하였습니다!";
      break;
    }
    
    if(solution == guess)
    {
      cout << solution << endl;
      cout << "성공하였습니다!";
      break;
    }
  }

  return 0;
}
