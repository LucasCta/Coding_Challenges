#include <iostream>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

int verificaDentro(int p0[2], int p1[2], int *a) {
  return p1[1] <= a[1] && a[1] <= p0[1] && p0[0] <= a[0] && a[0] <= p1[0];
}

int areaMax(int p0[2], int p1[2], int **arv, int n) {
  if (n == -1)
    return (p0[1] - p1[1]) * (p1[0] - p0[0]);
  int *a = arv[n];
  if (!verificaDentro(p0, p1, a))
    return areaMax(p0, p1, arv, n - 1);
  else {
    int a1, a2, a3, a4;
    int tmp[2];
    tmp[0] = p0[0];
    tmp[1] = a[1];
    a1 = areaMax(tmp, p1, arv, n - 1);
    tmp[0] = a[0];
    tmp[1] = p0[1];
    a2 = areaMax(tmp, p1, arv, n - 1);
    tmp[0] = a[0];
    tmp[1] = p1[1];
    a3 = areaMax(p0, tmp, arv, n - 1);
    tmp[0] = p1[0];
    tmp[1] = a[1];
    a4 = areaMax(p0, tmp, arv, n - 1);
    return MAX(a1, MAX(a2, MAX(a3, a4)));
  }
}

int main() {

  int t;
  cin >> t;
  while (t--) {

    int L, A;
    cin >> L >> A;

    int p0[2], p1[2];
    p0[0] = 0;
    p0[1] = A;
    p1[0] = L;
    p1[1] = 0;

    int n;
    cin >> n;
    int **arvores = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
      arvores[i] = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < n; i++) {
      cin >> arvores[i][0];
      cin >> arvores[i][1];
    }

    cout << areaMax(p0, p1, arvores, n - 1) << "\n";
  }

  return 0;
}
