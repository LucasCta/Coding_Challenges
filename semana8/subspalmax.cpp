#include <iostream>
#include <string.h>
using namespace std;

int palMax(char *p, int n) {
  int maxPal = 1;
  int **m = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    m[i] = (int *)calloc(n, sizeof(int));
    m[i][i] = 1;
    if (i < n - 1)
      if (p[i] == p[i + 1]) {
        m[i][i + 1] = 1;
        maxPal = 2;
      }
  }
  for (int d = 2; d < n; d++)
    for (int i = 0; i < n - d; i++) {
      int j = i + d;
      if (p[i] == p[j] && m[i + 1][j - 1] == 1) {
        maxPal = maxPal > (j - i + 1) ? maxPal : (j - i + 1);
        m[i][j] = 1;
      }
    }
  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << m[i][j] << ' ';
    cout << '\n';
  }*/
  return maxPal;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    char *pal;
    pal = (char *)malloc(sizeof(char) * 1000);
    cin >> pal;
    cout << palMax(pal, strlen(pal)) << '\n';
  }
  return 0;
}
