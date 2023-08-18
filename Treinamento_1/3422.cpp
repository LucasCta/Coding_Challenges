#include <bits/stdc++.h>
using namespace std;

int main() {

  int t;
  cin >> t;
  while (t--) {

    int n;
    string p;

    cin >> n >> p;

    if (p == "1T") {
      if (n % 46 != n)
        cout << 45 << "+" << n % 45 << '\n';
      else
        cout << n << '\n';
    } else {
      if (n % 46 != n)
        cout << 90 << "+" << n % 45 << '\n';
      else
        cout << n + 45 << '\n';
    }
  }

  return 0;
}
