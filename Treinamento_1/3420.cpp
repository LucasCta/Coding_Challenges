#include <bits/stdc++.h>
using namespace std;

/*
long long unsigned int somaNaturais(int N) {
   * 1 + 2 + 3 + 4 + 5 = (1 + 5) * 5 / 2
   * (n^2 + n)/ 2
}

long long unsigned int somaPares(int N) {
  * 2 + 4 + 6 + 8 + 10 = (1 + 5) *2 * 5 / 2 = (1 + 5) * 5
   * n^2 + n
} */

/*
 *  total de pares =  n^2 + n + (n-1^2  + n-1)/2
 *  2 * totalCartas + 1 = 2*n^2 + 3n + (n-1)^2
 *  2 * totalCartas + 1 = n^2 + n^2 + 3n + (n-1) * (n-1)
 *  2 * totalCartas + 1 = n^2 + n^2 + 3n + n^2 -2n + 1
 *  2 * totalCartas = 3n^2 + n
 *  3n^2 + n - 2*totalCartas = 0
 */

long long unsigned int bhaskara(long long unsigned int total) {
  long long unsigned int delta = 1 + (24 * total);
  long long unsigned int raiz = (-1 + sqrt(delta)) / 6;
  return raiz;
}

int main() {

  int t;
  cin >> t;
  long long unsigned int val;

  while (t--) {
    cin >> val;
    cout << bhaskara(val) << '\n';
  }

  return 0;
}
