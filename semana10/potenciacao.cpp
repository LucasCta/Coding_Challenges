#include <iostream>
using namespace std;

long long multMod(long long a, long long b, long long n) {
  return ((a % n) * (b % n)) % n;
}

long long fastExpMod(long long a, long long b, long long n) {
  if (b == 0)
    return 1;
  else if (b % 2 == 1)
    return multMod(fastExpMod(a, b - 1, n), a, n);
  else {
    long long x = fastExpMod(a, b / 2, n);
    return multMod(x, x, n);
  }
}

long long bigMod(char *a, int n) {
  long long m = 0;
  for (int i = 0; a[i] != '\0'; i++)
    m = ((m * 10) + (a[i] - '0')) % n;
  return m;
}

long long bigExp(char *ca, char *b, int n) {
  long long a = bigMod(ca, n);
  long long m = 1;
  for (int i = 0; b[i] != '\0'; i++)
    m = (fastExpMod(m, 10, n) * fastExpMod(a, b[i] - '0', n)) % n;
  return m;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    char *a, *b;
    a = (char *)malloc(sizeof(char) * 100001);
    b = (char *)malloc(sizeof(char) * 100001);
    cin >> a >> b >> n;
    cout << bigExp(a, b, n) << '\n';
    free(a);
    free(b);
  }
  return 0;
}
