#include <bits/stdc++.h>
#define MAX_NUM 10000000
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

int menorFator(int val, int n, int *C) {
  int mFat;
  for (mFat = C[val]; val / C[val] != 1; val /= C[val]) {
    val = val / C[val];
    mFat = C[val] < mFat ? C[val] : mFat;
  }
  return mFat;
}

int main() {

  int crivo_sz = MAX_NUM + 3;
  int *C = (int *)malloc(sizeof(int) * crivo_sz);
  geraCrivo(crivo_sz - 2, C);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (long long int)menorFator(n, crivo_sz - 2, C) * n << '\n';
  }

  return 0;
}
