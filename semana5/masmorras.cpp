#include <iostream>
using namespace std;

unsigned long long int particao(int n, int p) {
  if (p == 1 || n == p)
    return 1;
  return particao(n - 1, p) * p + particao(n - 1, p - 1);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;
    cout << particao(n, p) << "\n";
  }
  return 0;
}
