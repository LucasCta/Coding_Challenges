#include <iostream>
using namespace std;

unsigned int f[1033446];
unsigned int n, k;
int i, j, t;

int main() {

  i = 1;
  n = 0, k = 4000000000;
  f[0] = 0;
  f[1] = 1;
  f[2] = 3;

  int rodando = true;
  while (rodando) {
    for (n = f[i - 1] + 1; rodando && n <= f[i]; n++) {
      f[n] = f[n - 1] + i;
      if (f[n] >= k)
        rodando = false;
    }
    i++;
  }

  cin >> t;
  for (j = 0; j < t; j++) {
    cin >> k;
    for (i = 0; i <= k; i++) {
      if (f[i] >= k) {
        cout << i << endl;
        break;
      }
    }
  }
}
