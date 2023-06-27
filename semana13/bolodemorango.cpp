#include <bits/stdc++.h>
using namespace std;

const double QZERO = 0.000000001;

struct ponto {
  double x, y;
};

struct reta {
  double a, b, c;
};

struct boolponto {
  bool ret;
  ponto p;
};

double DistPontos(ponto p1, ponto p2) {
  return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}

long double calcAreaTri(ponto p1, ponto p2, ponto p3) {
  long double a = p1.x * (p2.y - p3.y);
  long double b = p2.x * (p3.y - p1.y);
  long double c = p3.x * (p1.y - p2.y);
  long double area = (a + b + c) / 2.0;
  return area;
}

reta PontosParaReta(ponto p1, ponto p2) {
  reta r;
  if (p1.x == p2.x) {
    r.a = 1;
    r.b = 0;
    r.c = -p1.x;
  } else {
    r.b = 1;
    r.a = -(p1.y - p2.y) / (p1.x - p2.x);
    r.c = -(r.a * p1.x) - (r.b * p1.y);
  }
  return r;
}

reta PontoTangenteParaReta(ponto p, double tang) {
  reta r;
  r.a = -tang;
  r.b = 1;
  r.c = -(r.a * p.x + r.b * p.y);
  return r;
}

reta RetaPerpendicular(ponto p1, reta r1) {
  ponto p2;
  reta r2;
  if (fabs(r1.b) <= QZERO) {
    r2.a = 0;
    r2.b = 1;
    r2.c = -p1.y;
  } else if (fabs(r1.a) <= QZERO) {
    r2.a = 1;
    r2.b = 0;
    r2.c = -p1.x;
  } else
    r2 = PontoTangenteParaReta(p1, 1 / r1.a);
  return r2;
}

bool Paralelas(reta r1, reta r2) {
  return ((fabs(r1.a - r2.a) <= QZERO) && (fabs(r1.b - r2.b) <= QZERO));
}

bool MesmaReta(reta r1, reta r2) {
  return (Paralelas(r1, r2) && (abs(r1.c - r2.c) <= QZERO));
}

boolponto PontoIntersecao(reta r1, reta r2) {
  boolponto bp;
  bp.ret = true;
  if (Paralelas(r1, r2) || MesmaReta(r1, r2))
    bp.ret = false;
  else {
    bp.p.x = (r2.b * r1.c - r1.b * r2.c) / (r2.a * r1.b - r1.a * r2.b);
    if (fabs(r1.b) > QZERO)
      bp.p.y = -(r1.a * bp.p.x + r1.c) / r1.b;
    else
      bp.p.y = -(r2.a * bp.p.x + r2.c) / r2.b;
    if (fabs(bp.p.x) < QZERO)
      bp.p.x = 0; // Para evitar -0.00
    if (fabs(bp.p.y) < QZERO)
      bp.p.y = 0; // Para evitar -0.00
  }
  return bp;
}

int main() {
  int t;
  cin >> t;
  cout << fixed << setprecision(2);
  while (t--) {
    int N;
    cin >> N;
    ponto *pontos = (ponto *)malloc(sizeof(ponto) * N);
    for (int i = 0; i < N; i++)
      cin >> pontos[i].x >> pontos[i].y;
    long double menorDistancia = 100000000;
    for (int i = 0; i < N - 1; i++)
      for (int j = i + 1; j < N; j++) {
        long double distTot = 0;
        reta r = PontosParaReta(pontos[i], pontos[j]);
        for (int k = 0; k < N; k++)
          if (k != i && k != j) {
            reta rp = RetaPerpendicular(pontos[k], r);
            boolponto pr = PontoIntersecao(r, rp);
            if (calcAreaTri(pontos[i], pontos[j], pontos[k]) > 0)
              distTot += DistPontos(pontos[k], pr.p);
            else
              distTot -= DistPontos(pontos[k], pr.p);
          }
        if (fabs(distTot) < fabs(menorDistancia))
          menorDistancia = distTot;
      }
    cout << fabs(menorDistancia) << '\n';
    free(pontos);
  }
  return 0;
}
