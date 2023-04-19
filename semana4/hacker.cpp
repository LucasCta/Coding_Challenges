#include <iostream>
#define modulo 1000000007
using namespace std;

int multMod(int a, int b) {
  unsigned long long la = a, lb = b;
  return (la * lb) % modulo;
}

int exp(int a, int b) {
  if (b == 0)
    return 1;
  if (a == 1 || b == 1)
    return a;
  else if (b % 2 == 0) {
    int tmp = exp(a, b / 2);
    return multMod(tmp, tmp);
  } else
    return multMod(a, exp(a, b - 1));
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    int k, n;
    cin >> k >> n;
    cout << exp(k, n) << "\n";
  }

  return 0;
}
