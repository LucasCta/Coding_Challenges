#include <iostream>
#define modulo 1000000007
using namespace std;

int fat[(50000 * 26) + 1];

int mMod(int a, int b) {
  unsigned long long la = a, lb = b;
  return (la * lb) % modulo;
}

int fatorial(int n) {
  if (n == 1 || n == 0)
    fat[n] = 1;
  if (fat[n] == -1)
    fat[n] = mMod(n, fatorial(n - 1));
  return fat[n];
}

int MDCE(int a, int b, unsigned long long int *x, unsigned long long int *y) {
  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  } else {
    unsigned long long int *xt, *yt;
    xt = (unsigned long long int *)malloc(sizeof(unsigned long long int));
    yt = (unsigned long long int *)malloc(sizeof(unsigned long long int));
    int d = MDCE(b, a % b, xt, yt);
    *x = *yt;
    *y = *xt - ((a / b) * (*yt));
    free(yt);
    free(xt);
    return d;
  }
}

int invMod(int b) {
  unsigned long long int *x, *y;
  x = (unsigned long long int *)malloc(sizeof(unsigned long long int));
  y = (unsigned long long int *)malloc(sizeof(unsigned long long int));
  MDCE(b, modulo, x, y);
  return (*x + modulo) % modulo;
}

int main() {

  for (int i = 0; i <= 50000 * 26; i++)
    fat[i] = -1;

  for (int i = 0; i <= 50000 * 26; i += 1000)
    fatorial(i);

  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int *a = (int *)malloc(sizeof(int) * k);
    int n = 0, N, Q = 1, iQ;
    for (int i = 0; i < k; i++) {
      cin >> a[i];
      n += a[i];
      Q = mMod(Q, fatorial(a[i]));
    }
    N = fatorial(n);
    iQ = invMod(Q);
    cout << mMod(N, iQ) << "\n";
    free(a);
  }

  return 0;
}
