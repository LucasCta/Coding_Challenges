#include <iostream>
#define modulo 1000000007
using namespace std;

int mod(int a, int b, int m) {
  unsigned long long la = a, lb = b;
  return (la * lb) % m;
}

int perm(int n, int k) {
  if (n == k)
    return 1;
  else
    return mod(n, perm(n - 1, k), modulo);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << perm(n, k) << "\n";
  }
  return 0;
}
