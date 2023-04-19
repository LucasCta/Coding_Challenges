#include <iostream>
using namespace std;

int a, b, c;
int main() {

  int nJogos;
  cin >> nJogos;
  for (int i = 0; i < nJogos; i++) {
    cin >> a >> b >> c;
    if (a != b && a != c)
      cout << 1 << endl;
    else if (b != a && b != c)
      cout << 2 << endl;
    else if (c != a && c != b)
      cout << 3 << endl;
    else
      cout << 0 << endl;
  }
}
