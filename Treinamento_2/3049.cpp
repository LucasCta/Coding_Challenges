#include <bits/stdc++.h>
using namespace std;

int main() {

  int B, T;
  cin >> B >> T;
  if (B < T) {
    int temp = B;
    B = T;
    T = temp;
  }

  int base = 160, altura = 70;
  int areaNota = base * altura;

  int areaFelix2 = (T * 70 * 2) + ((B - T) * 70);

  if (areaNota < areaFelix2) {
    cout << 1 << '\n';
  } else if (areaNota == areaFelix2) {
    cout << 0 << '\n';
  } else {
    cout << 2 << '\n';
  }

  return 0;
}
