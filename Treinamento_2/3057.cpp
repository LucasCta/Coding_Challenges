#include <bits/stdc++.h>
using namespace std;

int main() {

  int E, I, V;
  cin >> E >> I >> V;

  vector<int> C(E, 0);
  vector<pair<int, int>> D(E - 1);

  for (int i = 0; i < E - 1; i++)
    cin >> D[i].first >> D[i].second;

  for (int i = 0; i < V; i++) {
    int temp;
    cin >> temp;
    C[temp - 1] = 1;
  }

  for (int i = 0; i < E - 1; i++) {
    if (C[D[i].first - 1])
      C[D[i].second] = 1;
  }

  int cont = 0;
  pair<int, int> ultimo(D[E - 2].first - 1, D[E - 2].second - 1);

  for (int i = E - 2; i >= 0; i++) {

    pair<int, int> novo(D[i].first - 1, D[i].second - 1);

    if (ultimo.second != novo.second) {
      if (cont == 1)
        C[ultimo.first] = 1;
      ultimo = make_pair(novo.first, novo.second);
    }

    if (C[novo.second]) {
      if (C[novo.first] != 1)
        C[D[i].first - 1] = -1;
      cont++;
    } else {
      cont = 0;
    }
  }

  for (int i = 0; i < E; i++)
    cout << i + 1 << '-' << C[i] << ' ';
  cout << '\n';

  return 0;
}
