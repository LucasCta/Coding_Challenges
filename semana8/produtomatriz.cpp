#include <iostream>
#define inf 1000000007
using namespace std;

int minMultMat(int *mat, int n) {

  int **m = (int **)malloc(sizeof(int *) * n);

  for (int i = 0; i < n; i++)
    m[i] = (int *)calloc(n, sizeof(int));

  for (int d = 1; d < n; d++)
    for (int i = 0; i < n - d; i++) {
      int j = i + d;
      m[i][j] = inf;
      for (int k = i; k < j; k++)
        if (m[i][k] + m[k + 1][j] + mat[i - 1] * mat[k] * mat[j] < m[i][j])
          m[i][j] = m[i][k] + m[k + 1][j] + mat[i - 1] * mat[k] * mat[j];
    }

  /*
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++)
      cout << m[i][j] << ' ';
    cout << '\n';
  } */

  int r = m[1][n - 1];
  for (int i = 0; i < n; i++)
    free(m[i]);
  free(m);
  return r;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int *mat = (int *)malloc(sizeof(int) * ++n);
    for (int i = 0; i < n; i++)
      cin >> mat[i];
    cout << minMultMat(mat, n) << '\n';
    free(mat);
  }
  return 0;
}
