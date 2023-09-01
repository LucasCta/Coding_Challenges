#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  vector<float> P(N);
  vector<int> G(N);

  for (int i = 0; i < N; i++)
    cin >> P[i] >> G[i];

  for (int i = 0; i < N; i++)
    P[i] *= (float)1000 / G[i];

  cout << fixed << setprecision(2);
  cout << *min_element(P.begin(), P.end()) << '\n';

  return 0;
}
