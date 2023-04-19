#include <iostream>
using namespace std;

unsigned long long comb(int n, int p) {
  if (n == p)
    return 1;
  else
    return (n * comb(n - 1, p)) / (n - p);
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;
    cout << comb(n, p) << "\n";
  }
  return 0;
}
