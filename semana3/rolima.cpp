#include <iostream>
#define MAX(a, b) ((a) > (b)) ? (a) : (b)
using namespace std;

int n, m;
int mComp;
int **patio;
int **mcomp;
int **existe;
void comprimento(int i, int j) {
  int melhor = 0;
  for (int a = i - 1; a <= i + 1; a += 2)
    if (a >= 0 && a < n)
      if (patio[a][j] < patio[i][j]) {
        if (!existe[a][j])
          comprimento(a, j);
        melhor = MAX(melhor, mcomp[a][j]);
      }
  for (int a = j - 1; a <= j + 1; a += 2)
    if (a >= 0 && a < m)
      if (patio[i][a] < patio[i][j]) {
        if (!existe[i][a])
          comprimento(i, a);
        melhor = MAX(melhor, mcomp[i][a]);
      }
  existe[i][j] = 1;
  mcomp[i][j] = 1 + melhor;
  mComp = MAX(mComp, mcomp[i][j]);
}

int main() {

  int t;
  cin >> t;
  while (t--) {

    mComp = -1;
    cin >> n >> m;
    patio = (int **)malloc(sizeof(int *) * n);
    mcomp = (int **)malloc(sizeof(int *) * n);
    existe = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
      patio[i] = (int *)malloc(sizeof(int) * m);
      mcomp[i] = (int *)malloc(sizeof(int) * m);
      existe[i] = (int *)calloc(m, sizeof(int));
      for (int j = 0; j < m; j++)
        cin >> patio[i][j];
    }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (!existe[i][j])
          comprimento(i, j);
    cout << mComp << "\n";
    for (int i = 0; i < n; i++) {
      free(patio[i]);
      free(mcomp[i]);
      free(existe[i]);
    }
    free(patio);
    free(mcomp);
    free(existe);
  }

  return 0;
}
