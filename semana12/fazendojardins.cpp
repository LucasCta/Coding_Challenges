#include <bits/stdc++.h>
using namespace std;

long double sperimetroTriangulo(int a, int b, int c) {
  return (long double)(a + b + c) / 2;
}

long double areaTriangulo(int a, int b, int c, long double s) {
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

long double areaCirculoInscrito(int a, int b, int c, long double s) {
  return acos(-1) * ((s - a) * (s - b) * (s - c)) / s;
}

long double areaCirculoCircunscrito(int a, int b, int c, long double s) {
  return (a * a) / (s - a) * (b * b) / (s - b) * (c * c) / (s - c) * acos(-1) /
         s / 16.0;
}

int main() {
  int t;
  cin >> t;
  cout << fixed << setprecision(2);
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    long double sT, aT, ac, aC;
    sT = sperimetroTriangulo(a, b, c);
    aT = areaTriangulo(a, b, c, sT);
    ac = areaCirculoInscrito(a, b, c, sT);
    aC = areaCirculoCircunscrito(a, b, c, sT);
    cout << aC - aT << ' ' << aT - ac << ' ' << ac << '\n';
  }
  return 0;
}
