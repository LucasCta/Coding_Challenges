#include <bits/stdc++.h>
using namespace std;

int main() {
  int M, A, B;
  cin >> M >> A >> B;
  cout << max(max((M - A - B), A), B) << '\n';
  return 0;
}
