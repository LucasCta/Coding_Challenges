#include <iostream>
using namespace std;

int jogar(int *jg, int n) {

  int *acc = (int *)malloc(sizeof(int) * n);
  acc[0] = jg[0];
  for (int i = 1; i < n; i++)
    acc[i] = jg[i] + acc[i - 1];

  int **m = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    m[i] = (int *)calloc(n, sizeof(int));
    m[i][i] = jg[i];
  }

  for (int d = 1; d < n; d++)
    for (int i = 0; i < n - d; i++) {
      int j = i + d;
      m[i][j] = acc[j];
      if (i > 0)
        m[i][j] -= acc[i - 1];
      // cout << m[i][j] << ' ';
      for (int k = i; k < j; k++) {
        int val = acc[k] - m[k + 1][j];
        if (i > 0)
          val -= acc[i - 1];
        m[i][j] = val > m[i][j] ? val : m[i][j];
        // cout << val << ' ';
      }
      for (int k = j; k > i; k--) {
        int val = acc[j] - acc[k - 1] - m[i][k - 1];
        m[i][j] = val > m[i][j] ? val : m[i][j];
        // cout << val << ' ';
      }
      // cout << '\n' << "AAAAAAAA" << '\n';
    }

  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << m[i][j] << ' ';
    cout << '\n';
  }*/
  int r = m[0][n - 1];
  for (int i = 0; i < n; i++)
    free(m[i]);
  free(m);
  free(acc);

  return r;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int *jogo;
    jogo = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
      cin >> jogo[i];
    cout << jogar(jogo, n) << '\n';
    free(jogo);
  }
  return 0;
}
