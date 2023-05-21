#include <iostream>
#define big 1000000007
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
using namespace std;

int cortar(int *cuts, int n) {

  int **m = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++)
    m[i] = (int *)calloc(n, sizeof(int));

  for (int d = 1; d < n; d++)
    for (int i = 1; i < n - d; i++) {
      int j = i + d;
      m[i][j] = big;
      for (int k = i; k < j; k++) {
        int v = m[i][k] + m[k + 1][j] + cuts[j] - cuts[i - 1];
        m[i][j] = MIN(m[i][j], v);
      }
    }

  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << m[i][j] << ' ';
    cout << '\n';
  }*/

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
    int l, n;
    cin >> l >> n;
    int *cortes = (int *)malloc(sizeof(int) * (n + 2));
    cortes[0] = 0;
    for (int i = 1; i <= n; i++)
      cin >> cortes[i];
    cortes[n + 1] = l;
    cout << cortar(cortes, n + 2) << '\n';
    free(cortes);
  }
  return 0;
}
