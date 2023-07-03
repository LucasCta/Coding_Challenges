#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int x, y;
} Ponto;

double AreaPoligono(Ponto *pol, int n) {
  long long c;
  int i;
  pol[n] = pol[0];
  c = 0;
  for (i = 0; i < n; i++)
    c = c + pol[i].x * pol[i + 1].y - pol[i + 1].x * pol[i].y;
  return c / 2.0;
}

int main() {
  int t;
  cin >> t;
  cout << fixed << setprecision(2);
  while (t--) {
    int N;
    cin >> N;
    Ponto *poligono = (Ponto *)malloc(sizeof(Ponto) * N + 1);
    for (int i = 0; i < N; i++) {
      cin >> poligono[i].x;
      cin >> poligono[i].y;
    }
    long long valorImposto;
    cin >> valorImposto;
    cout << "R$ " << abs(AreaPoligono(poligono, N) * valorImposto) << '\n';
    free(poligono);
  }
  return 0;
}
