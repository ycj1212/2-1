# 2. 제어 구조와 배열

```c++
#include <iostream>
using namespace std;

int main() {
    bool b;
    b = (1 == 2);
    
    cout << std::boolalpha;
    cout << b << endl;

    return 0;
}
```

- b를 출력할 때 b가 true이면 1, false이면 0을 출력하는데 std::boolalpha 를 사용하면 "true"나 "false"를 출력한다.

## continue 문장 예제
```c++
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    do {
        i++;
        cout << "continue 문장 전에 있는 문장" << endl;
        continue;
        cout << "continue 문장 후에 있는 문장" << endl;
    } while (i<3);

    return 0;
}
```

- continue는 continue 뒤에 있는 문장들을 실행하지 않고 조건문으로 스킵되기 때문에, continue 문장 전에 있는 문장만 출력된다.

## C++에는 for-each 반복문도 있다.

```c++
#include <iostream>
using namespace std;

int main() {
    int list[] = {1,2,3,4,5,6,7,8,9,10};

    for (int i : list) {
        cout << i << " ";
    }
    cout << endl;
}
```