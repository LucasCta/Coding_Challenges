#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i];
  int a = 0, b = 0;
  bool af = 1, bf = 0;
  for (int i = 0; i < N; i++) {
    if (V[i] == af + 1) {
      a += 1;
      af = !af;
    }
    if (V[i] == bf + 1) {
      b += 1;
      bf = !bf;
    }
  }
  cout << max(a, b) << '\n';
  return 0;
}
