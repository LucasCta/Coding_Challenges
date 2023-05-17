#include <iostream>
#define MAX(x, y) (x) > (y) ? (x) : (y)
#define MIN(x, y) (x) < (y) ? (x) : (y)
using namespace std;

int *maxPrats(int *p1, int *p2, int sz1, int sz2, int r) {
  int *max = (int *)calloc(r, sizeof(int));
  for (int i = 0; i < r; i++) {
    int esq = MIN(sz1 - 1, i);
    int dir = (0 > (i - sz1 + 1) ? 0 : (i - sz1 + 1)) - 1;
    while (esq >= -1 && dir < sz2) {
      int v = 0;
      if (esq >= 0)
        v += p1[esq];
      if (dir >= 0)
        v += p2[dir];
      esq--;
      dir++;
      max[i] = MAX(v, max[i]);
    }
  }
  return max;
}

int *maxPrat(int *p, int sz) {
  int *max = (int *)calloc(sz, sizeof(int));
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j <= i + 1; j++) {
      int v = 0;
      for (int esq = 0; esq < j; esq++)
        v += p[esq];
      for (int dir = sz - 1; dir >= sz - 1 - (i - j); dir--)
        v += p[dir];
      max[i] = MAX(v, max[i]);
    }
  }
  return max;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int p, q, r;
    cin >> p >> q >> r;
    int **prat = (int **)malloc(sizeof(int *) * p);
    for (int i = 0; i < p; i++) {
      prat[i] = (int *)malloc(sizeof(int) * q);
      for (int j = 0; j < q; j++)
        cin >> prat[i][j];
      prat[i] = maxPrat(prat[i], q);
    }
    if (p != 1) {
      int *melhores;
      melhores = maxPrats(prat[0], prat[1], q, q, r);
      for (int i = 2; i < p; i++)
        melhores = maxPrats(melhores, prat[i], r, q, r);
      cout << melhores[r - 1] << '\n';
    } else
      cout << prat[0][r - 1] << '\n';
  }
  return 0;
}
