#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long int a, b, c;
    cin >> a >> b >> c;
    double f0, f1, f2;
    f0 = c;
    f1 = f0 + a + b;
    f2 = f1 + a * 2 + b;
    double x, y, z;
    z = c;
    x = (f2 - (2 * f1) + f0) / 2;
    y = f1 - x - z;
    cout << x << ' ' << y << ' ' << z << '\n';
  }
  return 0;
}
