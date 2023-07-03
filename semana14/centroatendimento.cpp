#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int x, y;
} Ponto;

typedef struct {
  Ponto a, b;
} Retangulo;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    int a, b, c, d;
    Retangulo *grupo = (Retangulo *)malloc(sizeof(Retangulo) * N);
    for (int i = 0; i < N; i++) {
      cin >> a >> b >> c >> d;
      grupo[i] = {a, b, c, d};
    }
    int A = -1;
    Retangulo conc = grupo[0];
    for (int i = 1; i < N; i++) {
      conc.a.x = max(conc.a.x, grupo[i].a.x);
      conc.a.y = max(conc.a.y, grupo[i].a.y);
      conc.b.x = min(conc.b.x, grupo[i].b.x);
      conc.b.y = min(conc.b.y, grupo[i].b.y);
      if (conc.a.x >= conc.b.x || conc.a.y >= conc.b.y) {
        A = 0;
        break;
      }
    }
    if (A == 0) {
      cout << "0\n";
    } else {
      A = (conc.b.x - conc.a.x) * (conc.b.y - conc.a.y);
      cout << A << '\n';
    }
  }
  return 0;
}
