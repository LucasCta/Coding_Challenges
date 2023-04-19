#include <iostream>
using namespace std;

int d, s;
int *escada;
int *valoresMax;
int *existe;
void degraus(int pos) {
  int oPos = pos;
  int maior = -10000000;
  while (++pos < d && pos - oPos <= s) {
    if (!existe[pos])
      degraus(pos);
    maior = (maior > valoresMax[pos]) ? (maior) : (valoresMax[pos]);
  }
  valoresMax[oPos] = escada[oPos] + maior;
  existe[oPos] = 1;
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    cin >> d >> s;
    escada = (int *)malloc(sizeof(int) * d);
    valoresMax = (int *)malloc(sizeof(int) * d);
    existe = (int *)calloc(d, sizeof(int));
    for (int i = 0; i < d; i++)
      cin >> escada[i];
    valoresMax[d - 1] = escada[d - 1];
    existe[d - 1] = 1;
    degraus(0);
    cout << valoresMax[0] << "\n";
    free(escada);
    free(valoresMax);
  }

  return 0;
}
