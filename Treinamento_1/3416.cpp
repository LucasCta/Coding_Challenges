#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, L, D;
  cin >> N >> L >> D;

  float T = N * D / 1000.0;
  cout << ceil(T / L) * L << '\n';

  return 0;
}
