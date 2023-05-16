#include <iostream>
using namespace std;

int mochila(int *dist, int *div, int n, int d) {
  int *m = (int *)calloc(d, sizeof(int));
  int *v = (int *)calloc(d, sizeof(int));
  for (int i = 1; i < d; i++)
    m[i] = -1;

  for (int i = 0; i < n; i++)
    for (int j = d - 1; j >= dist[i]; j--)
      if (m[j - dist[i]] >= 0)
        if (v[j - dist[i]] + div[i] > v[j]) {
          m[j] = i + 1;
          v[j] = v[j - dist[i]] + div[i];
        }

  int vMax = 0;
  for (int i = 0; i < d; i++)
    vMax = vMax > v[i] ? vMax : v[i];

  return vMax;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, d;
    cin >> n >> d;
    int *distancia = (int *)malloc(sizeof(int) * n);
    int *divida = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n * 2; i++) {
      if (i % 2 == 0) {
        cin >> distancia[i / 2];
        distancia[i / 2] *= 2;
      } else
        cin >> divida[i / 2];
    }
    cout << mochila(distancia, divida, n, d + 1) << '\n';
  }
  return 0;
}
