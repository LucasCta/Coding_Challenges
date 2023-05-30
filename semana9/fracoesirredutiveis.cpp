#include <bits/stdc++.h>
#define MAX_NUM 1000000000000000
using namespace std;

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

long long int pegaFatores(long long int val, int np, int *P, int &nf, int *F) {
  for (int i = 1; i <= np; i++)
    if (val % P[i] == 0) {
      if (val == P[i])
        return val;
      else
        return P[i];
    }
  return val;
}

int main() {

  int np = 0, crivo_sz = sqrt(MAX_NUM) + 3;
  int *C = (int *)malloc(sizeof(int) * crivo_sz);
  int *P = (int *)malloc(sizeof(int) * crivo_sz);
  geraCrivo(crivo_sz - 2, C);
  geraPrimos(crivo_sz - 2, np, C, P);

  int t;
  cin >> t;
  while (t--) {

    long long int n;
    cin >> n;

    int nf = 1;
    long long int *F = (long long int *)malloc(sizeof(long long int) * 100);
    F[nf] = maiorFator(n, np, P);
    while (F[nf] != n) {
      n = n / F[nf];
      F[++nf] = maiorFator(n, np, P);
    }

    int acc = 0;
    for (int i = 1; i <= nf; i++)
      acc += 1;

    for (int i = 1; i <= nf; i++)
      cout << F[i] << ' ';
    cout << '\n';

    free(F);
  }

  return 0;
}
