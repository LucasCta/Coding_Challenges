#include <iostream>
#define modulo 1000000007
using namespace std;

int multMod(int a, int b) {
  unsigned long long int la = a, lb = b;
  return (a * b) % modulo;
}

int somaMod(int a, int b) {
  unsigned long long int la = a, lb = b;
  return (a + b) % modulo;
}

void printMat(int **M, int R, int T) {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < T; j++)
      cout << M[i][j] << ' ';
    cout << '\n';
  }
}
int programas(int **M, int l, int c) {
  int acc = 0;
  for (int j = 1; j < c; j++)
    for (int i = 1; i <= l; i++)
      M[i][j] = somaMod(M[i - 1][j - 1], M[i + 1][j - 1]);
  // printMat(M,l+2,c);
  for (int i = 1; i <= l; i++)
    acc = somaMod(acc, M[i][c - 1]);
  return acc;
}

int main() {
  int t;
  cin >> t;
  while (t--) {

    int T, M, N, R;
    cin >> T >> M >> N;
    R = N - M + 3;

    int **mat = (int **)malloc(sizeof(int *) * R);
    for (int i = 0; i < R; i++) {
      mat[i] = (int *)calloc(T, sizeof(int));
      if (i != 0 && i != R - 1)
        mat[i][0] = 1;
    }

    // printMat(mat,R,T);

    cout << programas(mat, R - 2, T) << '\n';

    for (int i = 0; i < R; i++)
      free(mat[i]);
    free(mat);
  }
  return 0;
}
