#include <bits/stdc++.h>
#define MAX_NUM 100000000000
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

int contaSolucoes(int n, int np, int *P) {
  int nSol = 0, in = 1, fi = 1, acc = P[in];
  while (P[fi] <= n) {
    if (acc == n)
      nSol += 1;
    if (acc <= n) {
      fi += 1;
      acc += P[fi];
    } else {
      acc -= P[in];
      in += 1;
    }
  }
  return nSol;
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
    int n;
    cin >> n;
    if (contaSolucoes(n, np, P) % 2)
      cout << "Joana\n";
    else
      cout << "Bruno\n";
  }

  return 0;
}
