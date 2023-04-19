#include <iostream>
using namespace std;

int main() {

  int nTestes;
  cin >> nTestes;
  for (int i = 0; i < nTestes; i++) {

    int a, b;
    int l1, l2;
    cin >> a >> b;

    if (a > b) {
      l1 = b / 2;
      while (b * 4 > a)
        b--;
      l2 = b;
    } else {
      l1 = a / 2;
      while (a * 4 > b)
        a--;
      l2 = a;
    }

    if (l1 > l2)
      cout << l1 << endl;
    else
      cout << l2 << endl;
  }
}
