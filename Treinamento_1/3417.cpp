#include <bits/stdc++.h>
using namespace std;

int tuplas(int *a, int *b, int i, int j, int s) {

  if (s == 3)
    return 1;

  int total = 0;
  for (int k = i + 1; k < j; k++)
    if (a[i] < a[k] && b[i] < b[k])
      total += tuplas(a, b, k, j, s + 1);

  return total;
}

int main() {

  int N;
  cin >> N;

  int *A = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  int *B = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++)
    cin >> B[i];

  int total = 0;
  for (int i = 0; i < N; i++)
    total += tuplas(A, B, i, N, 0);

  int m = pow(10, 8);

  if (total > m) {
    int r = total % m;
    string stuff(floor(log10(m / r)) - 1, '0');
    cout << stuff << r;
  } else {
    cout << total;
  }

  return 0;
}
