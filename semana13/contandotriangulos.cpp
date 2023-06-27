#include <bits/stdc++.h>
using namespace std;

struct reta {
  long double a, b, c;
};

bool comparaDouble(double a, double b) {
  if (fabs(a - b) <= 0.000001)
    return 1;
  return 0;
}

long double calcAreaTri(int p1[2], int p2[2], int p3[2]) {
  long double a = p1[0] * (p2[1] - p3[1]);
  long double b = p2[0] * (p3[1] - p1[1]);
  long double c = p3[0] * (p1[1] - p2[1]);
  long double area = (a + b + c) / 2.0;
  return area < 0 ? -area : area;
}

reta calcLadosTri(int p1[2], int p2[2], int p3[2]) {
  long double l1 = sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
  long double l2 = sqrt(pow(p2[0] - p3[0], 2) + pow(p2[1] - p3[1], 2));
  long double l3 = sqrt(pow(p3[0] - p1[0], 2) + pow(p3[1] - p1[1], 2));
  reta lados;
  if (l1 > l2 && l1 > l3) {
    lados.c = l1;
    lados.a = l2;
    lados.b = l3;
  } else if (l2 > l1 && l2 > l3) {
    lados.c = l2;
    lados.a = l1;
    lados.b = l3;
  } else {
    lados.c = l3;
    lados.a = l1;
    lados.b = l2;
  }
  return lados;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    int **pontos = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++) {
      pontos[i] = (int *)malloc(sizeof(int) * 2);
      for (int j = 0; j < 2; j++)
        cin >> pontos[i][j];
    }
    int NR = 0, NA = 0, NO = 0;
    for (int i = 0; i < N - 2; i++)
      for (int j = i + 1; j < N - 1; j++)
        for (int k = j + 1; k < N; k++) {
          if (comparaDouble(calcAreaTri(pontos[i], pontos[j], pontos[k]), 0))
            continue;
          reta r = calcLadosTri(pontos[i], pontos[j], pontos[k]);
          if (comparaDouble(r.a * r.a + r.b * r.b, r.c * r.c))
            NR++;
          else if (r.a * r.a + r.b * r.b < r.c * r.c)
            NO++;
          else
            NA++;
        }
    cout << NR << ' ' << NA << ' ' << NO << '\n';
  }
  return 0;
}
