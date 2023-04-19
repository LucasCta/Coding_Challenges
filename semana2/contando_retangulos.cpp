#include <iostream>
using namespace std;

unsigned long long rows(int n, int m) {
  if (n == 1)
    return m;
  else
    return n * m + rows(n - 1, m);
}

unsigned long long columns(int n, int m) {
  if (m == 0 || n == 0)
    return 0;
  else
    return rows(n, m) + columns(n, m - 1);
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    cout << columns(n, m) << "\n";
  }
  return 0;
}
