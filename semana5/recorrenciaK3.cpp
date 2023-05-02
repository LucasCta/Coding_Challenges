#include <iostream>
#define modulo 1000000007
using namespace std;

int multMod(int a, int b) {
  unsigned long long int la = a, lb = b;
  return (la * lb) % modulo;
}

int **multMat(int **A, int **B) {
  int **mat = (int **)malloc(sizeof(int *) * 3);
  for (int i = 0; i < 3; i++)
    mat[i] = (int *)calloc(3, sizeof(int));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int z = 0; z < 3; z++)
        mat[i][j] += multMod(A[i][z], B[z][j]);
  return mat;
}

int **expMat(int **M, int n) {
  if (n == 0) {
    int **mat = (int **)malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++) {
      mat[i] = (int *)calloc(3, sizeof(int));
      mat[i][i] = 1;
    }
    return mat;
  }
  if (n % 2 != 0)
    return multMat(expMat(M, n - 1), M);
  else {
    int **X = expMat(M, n / 2);
    return multMat(X, X);
  }
}

int multMatVet(int **M, int *V) {
  unsigned long long int acc = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      // cout << "M: " << M[i][j] << '\n';
      // cout << "V: " << V[j] << '\n';
      acc += multMod(M[i][j], V[j]);
    }
  return acc;
}

void printMat(int **M) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      cout << M[i][j];
    cout << '\n';
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {

    int n;
    cin >> n;

    int **mat = (int **)malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++) {
      mat[i] = (int *)calloc(3, sizeof(int));
      cin >> mat[0][i];
      if (i > 0)
        mat[i][i - 1] = 1;
    }

    int *t = (int *)malloc(sizeof(int) * 3);
    for (int i = 2; i >= 0; i--)
      cin >> t[i];

    /*printMat(mat);
    cout << "-----" << '\n';
    printMat(expMat(mat, n - 2));
    cout << "-----" << '\n';
    */
    cout << multMatVet(expMat(mat, n - 3), t) << '\n';

    for (int i = 0; i < 3; i++)
      free(mat[i]);
    free(mat);
  }

  return 0;
}
