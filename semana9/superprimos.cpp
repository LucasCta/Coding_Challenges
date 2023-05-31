#include <bits/stdc++.h>
#include <math.h>
#define MAX_NUM 1000000000000000
#define MAX_SUP 10000000
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

void rotacionaNumero(int &val, int dig) {
  int v = val % 10;
  val = val / 10;
  val += v * pow(10, dig);
}

void geraSuperprimos(int n, int *C, int *S) {
  S[0] = 0;
  S[1] = 0;
  for (int i = 2; i <= n; i++) {
    S[i] = S[i - 1];
    int val = i;
    int digits = log10(i);
    int superprimo = C[i] == i;
    for (int j = 0; j < digits; j++) {
      rotacionaNumero(val, digits);
      if (C[val] != val) {
        superprimo = 0;
        break;
      }
    }
    S[i] += superprimo;
  }
}

int main() {

  int crivo_sz = sqrt(MAX_NUM) + 3;
  int *C = (int *)malloc(sizeof(int) * crivo_sz);
  int *S = (int *)malloc(sizeof(int) * crivo_sz);
  geraCrivo(crivo_sz - 2, C);
  geraSuperprimos(MAX_SUP, C, S);

  int val = 2;
  rotacionaNumero(val, log10(val));

  int t;
  cin >> t;
  while (t--) {
    int p, q, sp = 0;
    cin >> p >> q;
    cout << S[q] - S[p - 1] << '\n';
  }

  return 0;
}
