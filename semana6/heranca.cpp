#include <iostream>
using namespace std;

unsigned long long int particoes(int p, int n) {

  unsigned long long int **parts;
  parts = (unsigned long long int **)malloc(sizeof(unsigned long long int) *
                                            (p + 1));
  for (int i = 0; i <= p; i++)
    parts[i] = (unsigned long long int *)malloc(sizeof(unsigned long long int) *
                                                (n + 1));

  for (int i = 0; i <= p; i++)
    parts[i][0] = 1;
  for (int j = 1; j <= n; j++) {
    parts[0][j] = 0;
    for (int i = 1; i <= p; i++) {
      if (j >= i)
        parts[i][j] = parts[i][j - i] + parts[i - 1][j];
      else
        parts[i][j] = parts[i - 1][j];
    }
  }

  unsigned long long int answr = parts[p][n];
  for (int i = 0; i <= p; i++)
    free(parts[i]);
  free(parts);

  return answr;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, m;
    cin >> n >> k >> m;
    n -= k * m;
    cout << particoes(k, n) << '\n';
  }
  return 0;
}
