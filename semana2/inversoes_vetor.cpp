#include <iostream>
using namespace std;

unsigned long long inversions = 0;
unsigned int *merge(int start, int end, unsigned int *pvet) {

  unsigned int *vet =
      (unsigned int *)malloc(sizeof(unsigned int) * (end - start));

  for (int i = 0; i + start < end; i++)
    vet[i] = pvet[start + i];

  if (start == end - 1)
    return vet;

  int middle = start + (end - start) / 2;
  unsigned int *e = merge(start, middle, pvet);
  unsigned int *d = merge(middle, end, pvet);

  int pe = 0, pd = 0;
  while (pe < middle - start && pd < end - middle) {
    if (e[pe] <= d[pd]) {
      vet[pe + pd] = e[pe];
      pe++;
    } else {
      vet[pe + pd] = d[pd];
      inversions += middle - start - pe;
      pd++;
    }
  }

  if (pe == middle - start)
    do {
      vet[pe + pd] = d[pd];
    } while (pd++ < end - middle);
  else {
    do {
      vet[pe + pd] = e[pe];
    } while (pe++ < middle - start);
  }

  return vet;
}

int main() {

  int t, n;

  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 0) {
      cout << "0\n";
      continue;
    }
    int sz = n;
    unsigned int *vet = (unsigned int *)malloc(sizeof(unsigned int) * n);
    do {
      cin >> vet[sz - n];
    } while (--n);
    vet = merge(0, sz, vet);
    cout << inversions << "\n";
    inversions = 0;
  }

  return 0;
}
