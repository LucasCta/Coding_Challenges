#include <bits/stdc++.h>
using namespace std;

int main() {

  int V, P;
  cin >> V >> P;
  int R = V % P;

  for (int i = 0; i < P; i++)
    if (R-- > 0)
      cout << V / P + 1 << '\n';
    else
      cout << V / P << '\n';

  return 0;
}
