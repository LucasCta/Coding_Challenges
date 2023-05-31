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

    int nf = 0;
    long long int *F = (long long int *)malloc(sizeof(long long int) * 100);
    geraFatores(n, np, nf, P, F);

    if (nf == 0) {
      cout << "0\n";
      continue;
    }

    F[0] = F[1];
    long long int tot = 1, val = 1;
    for (int i = 1; i <= nf; i++) {
      if (F[i] != F[i - 1]) {
        tot *= val - (val / F[i - 1]);
        val = F[i];
      } else
        val *= F[i];
    }
    tot *= val - (val / F[nf]);

    cout << tot << '\n';

    free(F);
  }

  return 0;
}
