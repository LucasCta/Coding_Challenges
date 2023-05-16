#include <iostream>
using namespace std;

void mochila(int *dominos, int n, int s) {
  int *m = (int *)calloc(s, sizeof(int));
  for (int i = 1; i < s; i++)
    m[i] = -1;
  for (int i = 0; i < n * 2; i += 2) {
    for (int j = s - 1; j >= 0; j--) {
      if (m[j] >= 0) {
        if (j + dominos[i] < s)
          if (m[j + dominos[i]] == -1)
            m[j + dominos[i]] = i + 1;
        if (j + dominos[i + 1] < s)
          if (m[j + dominos[i + 1]] == -1)
            m[j + dominos[i + 1]] = i + 1;
      }
    }
  }
  for (int i = 0; i < s; i++)
    cout << m[i] << ' ';
  if (m[s - 1] != -1)
    cout << "S\n";
  else
    cout << "N\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    int *dominos = (int *)malloc(sizeof(int) * n * 2);
    for (int i = 0; i < n * 2; i++)
      cin >> dominos[i];
    mochila(dominos, n, s + 1);
  }
  return 0;
}
