#include <iostream>
#include <math.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
using namespace std;

int T[10001];

int quadrados() {
  T[0] = 0;
  for (int i = 1; i < 10001; i++) {
    T[i] = T[i - 1] + 1;
    for (int j = 2; j * j <= i; j++)
      if (T[i - (j * j)] < T[i])
        T[i] = T[i - (j * j)] + 1;
  }
  return 0;
}

int main() {
  int t;
  cin >> t;
  quadrados();
  while (t--) {
    int n;
    cin >> n;
    cout << T[n] << '\n';
  }
  return 0;
}
