#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int x, y;
} Ponto;

int SentidoPercurso(Ponto p1, Ponto p2, Ponto p3) {
  long long a, b, c, d;
  a = p2.x - p1.x;
  b = p3.y - p1.y;
  c = p3.x - p1.x;
  d = p2.y - p1.y;
  a = a * b - c * d;
  if (a > 0)
    return 1;
  else if (a < 0)
    return -1;
  else
    return 0;
}

int PoligonoConvexo(Ponto *pol, int n) {
  int s, i;
  s = SentidoPercurso(pol[n - 2], pol[n - 1], pol[0]);
  if (s != SentidoPercurso(pol[n - 1], pol[0], pol[1]))
    return 0;
  for (i = 0; i < n - 2; i++)
    if (s != SentidoPercurso(pol[i], pol[i + 1], pol[i + 2]))
      return 0;
  return 1;
}

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
  while (t--) {
    Ponto *pol = (Ponto *)malloc(sizeof(Ponto) * 5);
    for (int i = 0; i < 5; i++) {
      cin >> pol[i].x;
      cin >> pol[i].y;
    }
    Ponto comb[5][5] = {{pol[0], pol[1], pol[2], pol[3], pol[0]},
                        {pol[0], pol[1], pol[2], pol[4], pol[0]},
                        {pol[0], pol[1], pol[3], pol[4], pol[0]},
                        {pol[0], pol[2], pol[3], pol[4], pol[0]},
                        {pol[1], pol[2], pol[3], pol[4], pol[1]}};
    double mArea = 0;
    for (int i = 0; i < 5; i++) {
      Ponto arr[4][5] = {
          {comb[i][0], comb[i][1], comb[i][2], comb[i][3], comb[i][4]},
          {comb[i][0], comb[i][1], comb[i][3], comb[i][2], comb[i][4]},
          {comb[i][0], comb[i][2], comb[i][1], comb[i][3], comb[i][4]},
          {comb[i][0], comb[i][2], comb[i][3], comb[i][1], comb[i][4]}};
      for (int j = 0; j < 4; j++)
        if (PoligonoConvexo(arr[j], 4))
          mArea = max(mArea, abs(AreaPoligono(arr[j], 4)));
    }
    cout << mArea << '\n';
    free(pol);
  }
  return 0;
}
