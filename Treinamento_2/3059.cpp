#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, I, F;
  cin >> N >> I >> F;
  vector<int> V(N);
  for (int i = 0; i < N; i++)
    cin >> V[i];

  int total = 0;
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      if (V[i] + V[j] >= I && V[i] + V[j] <= F)
        total++;

  cout << total << '\n';

  return 0;
}
