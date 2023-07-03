#include <bits/stdc++.h>
using namespace std;

typedef struct {
  int x, y;
} Ponto;

typedef struct {
  Ponto p, q;
} Segmento;

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

int Intercepta(Segmento s1, Segmento s2) {
  // calcula interseção dos retângulos
  // calcula os 4 sentidos do percurso
  if ((max(s1.p.x, s1.q.x) >= min(s2.p.x, s2.q.x)) &&
      (max(s2.p.x, s2.q.x) >= min(s1.p.x, s1.q.x)) &&
      (max(s1.p.y, s1.q.y) >= min(s2.p.y, s2.q.y)) &&
      (max(s2.p.y, s2.q.y) >= min(s1.p.y, s1.q.y)) &&
      (SentidoPercurso(s1.p, s1.q, s2.p) * SentidoPercurso(s1.p, s1.q, s2.q) <=
       0) &&
      (SentidoPercurso(s2.p, s2.q, s1.p) * SentidoPercurso(s2.p, s2.q, s1.q) <=
       0))
    return 1;
  else
    return 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    int a, b, c, d;
    Segmento *segJoao = (Segmento *)malloc(sizeof(Segmento) * N);
    for (int i = 0; i < N; i++) {
      cin >> a >> b >> c >> d;
      segJoao[i] = {a, b, c, d};
    }
    Segmento *segOponente = (Segmento *)malloc(sizeof(Segmento) * N);
    for (int i = 0; i < N; i++) {
      cin >> a >> b >> c >> d;
      segOponente[i] = {a, b, c, d};
    }
    int iJoao = 0, iOponente = 0;
    for (int i = 0; i < N; i++)
      for (int j = i + 1; j < N; j++) {
        iJoao += Intercepta(segJoao[i], segJoao[j]);
        iOponente += Intercepta(segOponente[i], segOponente[j]);
      }
    if (iJoao > iOponente)
      cout << "+\n";
    else if (iJoao == iOponente)
      cout << "x\n";
    else
      cout << "-\n";
  }
  return 0;
}
