#include <iostream>
#define modulo 1000000007
using namespace std;

// T(p,n) = T(p,n-p) + T(p-1,n).
unsigned long long int particoes(int p, int n, int k) { return 0; }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, m;
    cin >> n >> k >> m;
    n -= k * m;
    cout << particoes(n, n, k) << '\n';
  }
  return 0;
}
