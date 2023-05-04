#include <iostream>
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

int carros(int *t, int n, int k) {
  long int *men = (long int *)malloc(sizeof(long int) * n);
  men[0] = t[0];
  for (int i = 1; i < k; i++)
    men[i] = MAX(men[i - 1], t[i]);
  for (int i = k; i < n; i++) {
    int bigT = t[i];
    men[i] = men[i - 1] + bigT;
    for (int j = i; j > i - k && j >= 0; j--) {
      bigT = MAX(bigT, t[j]);
      men[i] = MIN(men[i], men[j - 1] + bigT);
    }
  }
  long int tmp = men[n - 1];
  free(men);
  return tmp;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int *tempo = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
      cin >> tempo[i];
    cout << carros(tempo, n, k) << '\n';
    free(tempo);
  }
  return 0;
}
