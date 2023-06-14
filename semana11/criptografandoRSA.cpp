#include <iostream>
using namespace std;

int MDCE(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long x_, y_;
    long long d = MDCE(b, a % b, x_, y_);
    x = y_;
    y = x_ - ((a / b) * y_);
    return d;
  }
}

long long multMod(long long a, long long b, long long n) {
  return ((a % n) * (b % n)) % n;
}

long long fastExpMod(long long a, long long b, long long n) {
  if (b == 0)
    return 1;
  else if (b % 2 == 1)
    return multMod(fastExpMod(a, b - 1, n), a, n);
  else {
    long long x = fastExpMod(a, b / 2, n);
    return multMod(x, x, n);
  }
}

long long bigMod(char *a, int n) {
  long long m = 0;
  for (int i = 0; a[i] != '\0'; i++)
    m = ((m * 10) + (a[i] - '0')) % n;
  return m;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long p, q, e;
    long long msg;
    cin >> p >> q >> e >> msg;
    long long n = p * q;
    long long t = (p - 1) * (q - 1);
    long long x, y;
    MDCE(e, t, x, y);
    long long d = (x + t) % t;
    cout << fastExpMod(msg, d, n) << '\n';
  }
  return 0;
}
