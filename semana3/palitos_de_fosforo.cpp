#include <iostream>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;

int n, k;
int **existe;
unsigned long long int **total;
void qntPalitos(int q, int a) {
  unsigned long long int tot = 0;
  for (int i = 2; i <= 7; i++) {
    if (q - i >= 0) {
      if (!existe[a - 1][q - i])
        qntPalitos(q - i, a - 1);
      if (i == 5 || i == 6)
        tot += 3 * total[a - 1][q - i];
      else
        tot += total[a - 1][q - i];
    }
  }
  total[a][q] = tot;
  existe[a][q] = 1;
}

int main() {

  total =
      (unsigned long long int **)malloc(sizeof(unsigned long long int *) * 19);
  existe = (int **)malloc(sizeof(int *) * 19);
  for (int i = 0; i < 19; i++) {
    total[i] =
        (unsigned long long int *)malloc(sizeof(unsigned long long int) * 127);
    existe[i] = (int *)calloc(127, sizeof(int));
  }

  for (int i = 0; i < 19; i++) {
    existe[i][0] = 1;
    existe[i][1] = 1;
    total[i][0] = 0;
    total[i][1] = 0;
  }
  for (int i = 0; i < 127; i++) {
    existe[0][i] = 1;
    total[0][i] = 1;
  }

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (n > 126)
      n = 126;
    qntPalitos(n, k);
    if (k == 1)
      cout << total[k][n] << "\n";
    else
      cout << total[k][n] - total[MAX(0, k - 1)][MAX(0, n - 6)] << "\n";
  }
  return 0;
}
