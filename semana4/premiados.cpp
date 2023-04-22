#include <iostream>
using namespace std;

unsigned long long MMC(unsigned int x, unsigned int y, int nx, int ny) {
  if (nx * x == ny * y)
    return nx * x;
  if (nx * x < ny * y)
    return MMC(x, y, nx + 1, ny);
  return MMC(x, y, nx, ny + 1);
}

unsigned long long bilhetes(unsigned long long n, unsigned int a,
                            unsigned int b, unsigned int c) {
  unsigned long long int total = 0;
  total += n / a;
  total += n / b;
  total += n / c;
  total -= n / MMC(a, b, 1, 1);
  total -= n / MMC(a, c, 1, 1);
  unsigned long long bc = MMC(b, c, 1, 1);
  total -= n / bc;
  total += n / MMC(a, bc, 1, 1);
  return total;
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    unsigned long long n;
    unsigned int a, b, c;
    cin >> n >> a >> b >> c;
    cout << bilhetes(n, a, b, c) << "\n";
  }
  return 0;
}
