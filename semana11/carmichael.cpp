#include <cmath>
#include <iostream>
#define SIZE 200005
using namespace std;

long long multMod(long long a, long long b, long long n) {
  return ((a % n) * (b % n)) % n;
}

long long fastExpMod(long long a, long long b, long long n) {
  if (b == 0)
    return 1;
  else if (b % 2 == 1)
    return multMod(fastExpMod(a, b - 1, n), a, n);
  else {
    long long x = fastExpMod(a, b / 2, n);
    return multMod(x, x, n);
  }
}

long long bigMod(char *a, int n) {
  long long m = 0;
  for (int i = 0; a[i] != '\0'; i++)
    m = ((m * 10) + (a[i] - '0')) % n;
  return m;
}

void geraCrivo(int n, int *C) {
  for (int i = 1; i <= n; i += 2) {
    C[i] = i;
    C[i + 1] = 2;
  }
  int rq = sqrt(n);
  for (int i = 3; i <= rq; i += 2)
    if (C[i] == i)
      for (int t = i * i; t <= n; t += 2 * i)
        if (C[t] == t)
          C[t] = i;
}

void geraCarmichael(int n, int *CR, int *CA) {
  for (int i = 1; i <= n; i++) {
    CA[i] = CA[i - 1];
    if (CR[i] == i)
      continue;
    int isDiff = false;
    for (int j = 2; j < i; j++)
      if ((isDiff = j % i != fastExpMod(j, i, i)))
        break;
    if (!isDiff)
      CA[i]++;
  }
}

int main() {

  int *CRIVO = (int *)malloc(sizeof(int) * SIZE);
  geraCrivo(SIZE - 2, CRIVO);

  int *CARMICHAEL = (int *)calloc(SIZE, sizeof(int));
  geraCarmichael(SIZE - 2, CRIVO, CARMICHAEL);

  int t;
  cin >> t;
  while (t--) {
    long long p, q;
    cin >> p >> q;
    cout << CARMICHAEL[q] - CARMICHAEL[p] << '\n';
  }
  return 0;
}
