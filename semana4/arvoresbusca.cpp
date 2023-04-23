#include <iostream>
using namespace std;

unsigned long long int arv[37];

unsigned long long int arvores(int i) {
  if (i == 0)
    return 1;
  else if (arv[i] != 0)
    return arv[i];
  else {
    unsigned long long int a = 0;
    for (int j = 1; j <= i; j++)
      a += arvores(j - 1) * arvores(i - j);
    arv[i] = a;
    return a;
  }
}

int main() {

  for (int i = 0; i < 37; i++)
    arv[i] = 0;

  arv[0] = 1;
  arvores(36);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << arv[n] << "\n";
  }
  return 0;
}
