#include <iostream>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

int tesouro(int **mat, int n, int m) {
  int **val = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++)
    val[i] = (int *)malloc(sizeof(int) * m);
  val[0][0] = mat[0][0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0)
        continue;
      else if (i > 0 && j == 0)
        val[i][j] = mat[i][j] + val[i - 1][j];
      else if (j > 0 && i == 0)
        val[i][j] = mat[i][j] + val[i][j - 1];
      else
        val[i][j] = MAX(val[i - 1][j], val[i][j - 1]) + mat[i][j];
    }
  }
  return val[n - 1][m - 1];
}

int main() {
  int t;
  cin >> t;
  while (t--) {

    int n, m;
    cin >> n >> m;

    int **mat = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
      mat[i] = (int *)malloc(sizeof(int) * m);
      for (int j = 0; j < m; j++)
        cin >> mat[i][j];
    }

    cout << tesouro(mat, n, m) << '\n';

    for (int i = 0; i < n; i++)
      free(mat[i]);
    free(mat);
  }
  return 0;
}
