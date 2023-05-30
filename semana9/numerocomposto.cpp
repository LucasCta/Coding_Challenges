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
  np = 0;
  for (int i = 2; i <= n; i++)
    if (C[i] == i)
      P[++np] = i;
}

bool testaPrimo(long long int val, int np, int *P) {
  int i;
  for (i = 1; i <= np; i++)
    if (val % P[i] == 0)
      return val == P[i];
  return true;
}

int main() {

  int np, crivo_sz = sqrt(MAX_NUM) + 3;
  int *C = (int *)malloc(sizeof(int) * crivo_sz);
  int *P = (int *)malloc(sizeof(int) * crivo_sz);
  geraCrivo(crivo_sz - 2, C);
  geraPrimos(crivo_sz - 2, np, C, P);

  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (testaPrimo(n, np, P))
      cout << "N\n";
    else
      cout << "S\n";
  }

  return 0;
}
