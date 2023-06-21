#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  cout << fixed << setprecision(2);
  while (t--) {
    long double C, L;
    cin >> C >> L;
    if (C > L) {
      long double temp = C;
      C = L;
      L = temp;
    }

    long double R1 = C / (2 * acos(-1));
    long double V1 = acos(-1) * pow(R1, 2) * (L - 2 * R1);

    long double X = L / (2.0 * (acos(-1) + 1.0));
    long double R2 = (X) < (C / 2.0) ? (X) : (C / 2.0);
    long double V2 = acos(-1) * R2 * R2 * C;

    cout << (V1 > V2 ? V1 : V2) << '\n';
  }
  return 0;
}
