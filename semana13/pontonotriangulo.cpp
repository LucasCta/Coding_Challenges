#include <bits/stdc++.h>
using namespace std;

long double calcAreaTri(int p1[2], int p2[2], int p3[2]) {
  long double a = p1[0] * (p2[1] - p3[1]);
  long double b = p2[0] * (p3[1] - p1[1]);
  long double c = p3[0] * (p1[1] - p2[1]);
  long double area = (a + b + c) / 2.0;
  return area < 0 ? -area : area;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int tri[3][2];
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 2; j++)
        cin >> tri[i][j];
    int mouse[2];
    cin >> mouse[0] >> mouse[1];
    long double areaTriangulo = calcAreaTri(tri[0], tri[1], tri[2]);
    long double areaP1 = calcAreaTri(tri[0], mouse, tri[1]);
    long double areaP2 = calcAreaTri(tri[1], mouse, tri[2]);
    long double areaP3 = calcAreaTri(tri[2], mouse, tri[0]);
    if (areaTriangulo == (areaP1 + areaP2 + areaP3))
      cout << 'S' << '\n';
    else
      cout << 'N' << '\n';
  }
  return 0;
}
