#include <iostream>
#define big 1000000007
using namespace std;

int numQuadrados(int **mat, int n, int m) {

  for (int a = 0; a < n; a++) {
    for (int b = a; b < m; b++) {

      if (a == b)
        continue;

      int min, min1 = big, min2 = big;

      for (int k = 0; k <= b / 2; k++) {
        int cut = mat[a][k] + mat[a][b - k - 1];
        min1 = min1 < cut ? min1 : cut;
      }

      if (a > 0) {
        for (int k = 0; k <= a / 2; k++) {
          int cut = mat[k][b] + mat[a - k - 1][b];
          min2 = min2 < cut ? min2 : cut;
        }
      }

      min = min1 < min2 ? min1 : min2;

      mat[a][b] = min;
      if (b < n)
        mat[b][a] = min;
    }
  }

  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << mat[i][j] << ' ';
    cout << '\n';
  } */

  return mat[n - 1][m - 1];
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (n > m) {
      int temp = n;
      n = m;
      m = temp;
    }
    int **mat = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
      mat[i] = (int *)calloc(m, sizeof(int));
      mat[i][i] = 1;
    }
    cout << numQuadrados(mat, n, m) << '\n';
  }
  return 0;
}
