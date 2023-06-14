#include <cmath>
#include <iostream>
#define SIZE 100000000
using namespace std;

int MDCE(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    long long x_, y_;
    long long d = MDCE(b, a % b, x_, y_);
    x = y_;
    y = x_ - ((a / b) * y_);
    return d;
  }
}

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

void geraCrivo(int n, int *C) {
  for (int i = 1; i <= n; i += 2) {
    C[i] = i;
    C[i + 1] = 2;
  }
  int rq = sqrt(n);
  for (int i = 3; i <= rq; i += 2)
    if (C[i] == i)
      for (int t = i * i; t <= n; t += 2 * i)
        if (C[t] == t)
          C[t] = i;
}

void geraPrimos(int n, int &np, int *C, int *P) {
  for (int i = 2; i <= n; i++)
    if (C[i] == i)
      P[++np] = i;
}

void geraFatores(long long int q, int np, int &nf, int *P, long long int *F) {
  int rq = sqrt(q) + 1;
  for (int i = 1; i <= np; i++) {
    while ((q % P[i]) == 0) {
      F[++nf] = P[i];
      q = q / P[i];
    }
    if (q == 1 || P[i] >= rq)
      break;
  }
  if (q != 1)
    F[++nf] = q;
}

int main() {

  int np = 0, crivo_sz = sqrt(SIZE) + 3;
  int *C = (int *)malloc(sizeof(int) * crivo_sz);
  int *P = (int *)malloc(sizeof(int) * crivo_sz);
  geraCrivo(crivo_sz - 2, C);
  geraPrimos(crivo_sz - 2, np, C, P);

  int t;
  cin >> t;
  while (t--) {

    long long e, n;
    long long msg;
    cin >> e >> n;
    cin >> msg;

    int nf = 0;
    long long int *F = (long long int *)malloc(sizeof(long long int) * 100);
    geraFatores(n, np, nf, P, F);

    long long x, y;
    long long t = (F[1] - 1) * (F[2] - 1);
    MDCE(e, t, x, y);
    long long d = (x + t) % t;
    cout << fastExpMod(msg, d, n) << '\n';
  }
  return 0;
}
