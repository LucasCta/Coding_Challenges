#include <iostream>
using namespace std;

int main() {

  int nTestes;
  cin >> nTestes;
  for (int i = 0; i < nTestes; i++) {

    int n, s;
    cin >> n >> s;

    int vet[n];
    for (int j = 0; j < n; j++)
      cin >> vet[j];

    int cont = 0;
    int c = 0, f = n - 1;
    while (f > c) {
      if (vet[c] + vet[f] == s) {
        c++;
        cont++;
      } else if (vet[c] + vet[f] < s) {
        c++;
      } else if (vet[c] + vet[f] > s) {
        f--;
      }
    }

    cout << cont << endl;
  }
}
