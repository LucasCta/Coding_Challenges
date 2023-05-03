#include <iostream>
#define modulo 1000000007
using namespace std;

int multMod(long int a, long int b) {
  unsigned long long int la = a, lb = b;
  return (la * lb) % modulo;
}

int somaMod(long int a, long int b) {
  unsigned long long int la = a, lb = b;
  return (la + lb) % modulo;
}

long int **multMat(long int **A, long int **B) {
  long int **mat = (long int **)malloc(sizeof(long int *) * 3);
  for (int i = 0; i < 3; i++)
    mat[i] = (long int *)calloc(3, sizeof(long int));
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int z = 0; z < 3; z++)
        mat[i][j] = somaMod(mat[i][j], multMod(A[i][z], B[z][j]));
  return mat;
}

long int **expMat(long int **M, int n) {
  if (n <= 0) {
    long int **mat = (long int **)malloc(sizeof(long int *) * 3);
    for (int i = 0; i < 3; i++) {
      mat[i] = (long int *)calloc(3, sizeof(long int));
      mat[i][i] = 1;
    }
    return mat;
  }
  if (n % 2 != 0) {
    long int **e = expMat(M, n - 1);
    long int **mlt = multMat(e, M);
    for (int i = 0; i < 3; i++)
      free(e[i]);
    free(e);
    return mlt;
  } else {
    long int **X = expMat(M, n / 2);
    long int **mlt = multMat(X, X);
    for (int i = 0; i < 3; i++)
      free(X[i]);
    free(X);
    return mlt;
  }
}

int findTn(long int **M, long int *V) {
  int acc = 0;
  for (int i = 0; i < 3; i++)
    acc = somaMod(acc, multMod(M[0][i], V[i]));
  return acc;
}

int main() {
  int t;
  cin >> t;
  while (t--) {

    long int n;
    cin >> n;

    long int **mat = (long int **)malloc(sizeof(long int *) * 3);
    for (int i = 0; i < 3; i++) {
      mat[i] = (long int *)calloc(3, sizeof(long int));
      cin >> mat[0][i];
      if (i > 0)
        mat[i][i - 1] = 1;
    }

    long int *t = (long int *)malloc(sizeof(long int) * 3);
    for (int i = 2; i >= 0; i--)
      cin >> t[i];

    long int **e = expMat(mat, n - 2);
    cout << findTn(e, t) << '\n';

    for (int i = 0; i < 3; i++)
      free(e[i]);
    free(e);
    for (int i = 0; i < 3; i++)
      free(mat[i]);
    free(mat);
    free(t);
  }

  return 0;
}
