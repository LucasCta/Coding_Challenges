#include <iostream>
using namespace std;

int t, n, i;
struct arvore {
  int id;
  int valor;
  int esquerda;
  int direita;
} familia[1000001];

void maior(int i, int v) {
  if (v > familia[0].valor || (v == familia[0].valor && i < familia[0].id)) {
    familia[0].id = i;
    familia[0].valor = v;
  }
}

int patrimonio(arvore fml) {

  if (fml.esquerda)
    fml.valor += patrimonio(familia[fml.esquerda]);
  if (fml.direita)
    fml.valor += patrimonio(familia[fml.direita]);

  maior(fml.id, fml.valor);
  return fml.valor;
}

int main() {

  cin >> t;
  while (t--) {

    cin >> n;
    int num = n;
    int *leafs = (int *)calloc(n + 1, sizeof(int));
    while (n--) {
      cin >> i;
      familia[i].id = i;
      cin >> familia[i].valor;
      cin >> familia[i].esquerda;
      cin >> familia[i].direita;
      leafs[familia[i].esquerda] = 1;
      leafs[familia[i].direita] = 1;
    }

    for (int j = 1; j < num + 1; j++) {
      if (!leafs[j]) {
        patrimonio(familia[j]);
        cout << familia[0].id << "\n";
        familia[0].valor = -100000000;
        free(leafs);
        break;
      }
    }
  }

  return 0;
}
