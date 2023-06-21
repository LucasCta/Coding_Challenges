#include <bits/stdc++.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int C, L, R1, R2;
    cin >> C >> L >> R1 >> R2;
    if (MAX(R1 * 2, R2 * 2) > MIN(C, L)) {
      cout << "N\n";
      continue;
    }
    long int R = R1 + R2;
    long int a = L - R1 - R2;
    long int b = C - R1 - R2;
    if (R * R <= a * a + b * b)
      cout << "S\n";
    else
      cout << "N\n";
  }
  return 0;
}
