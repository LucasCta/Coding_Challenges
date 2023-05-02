#include <iostream>
#include <string.h>
using namespace std;

char avaliaPolinomio(char *p, unsigned long long int k) {
  unsigned long long int acc = 0, b = 1;
  for (int i = strlen(p) - 1; i >= 0; i--) {
    acc += ((p[i] - '0') * b) % k;
    b *= 10;
  }
  if (acc % k == 0)
    return 'S';
  return 'N';
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    unsigned long long int k;
    char *n = (char *)malloc(sizeof(char) * 1000001);
    cin >> n >> k;
    cout << avaliaPolinomio(n, k) << '\n';
    free(n);
  }
  return 0;
}
