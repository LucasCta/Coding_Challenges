#include <iostream>
using namespace std;

int mochila(int *carros, int c, int l) {
  int *m = (int *)calloc(l, sizeof(int));
  for (int i = 1; i < l; i++)
    m[i] = -1;
  for (int i = 0; i < c; i++)
    for (int j = l - carros[i] - 1; j >= 0; j--)
      if (m[j] >= 0 && m[j + carros[i]] == -1)
        m[j + carros[i]] = i + 1;
  int tMax = 0, p = l - 1;
  while (p > 0) {
    if (m[p] != -1) {
      tMax += carros[m[p] - 1];
      p -= carros[m[p] - 1];
    } else
      p--;
  }
  return tMax;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int c, l;
    cin >> c >> l;
    int total = 0;
    int *carros = (int *)malloc(sizeof(int) * c);
    for (int i = 0; i < c; i++) {
      cin >> carros[i];
      total += carros[i];
    }
    if (total - mochila(carros, c, l + 1) <= l)
      cout << "S" << '\n';
    else
      cout << "N" << '\n';
  }
  return 0;
}
