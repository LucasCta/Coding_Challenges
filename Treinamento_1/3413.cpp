#include <bits/stdc++.h>
using namespace std;

int main() {

  int T, M;
  cin >> T >> M;

  vector<double> A(M);
  for (int i = 0; i < M; i++)
    cin >> A[i];

  complex<double> R(0, sqrt(4 * T - 1));

  double ma = *max_element(A.begin(), A.end());

  complex<double> total = ma;
  for (int i = 0; i < M; i++)
    if (A[i] != ma)
      total -=
          1.0 / R * (pow((1.0 + R / 2.0), A[i]) - pow((1.0 - R / 2.0), A[i]));

  cout << total.real() << '\n';
  return 0;
}
