#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];

  int distance = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      distance = max(distance, A[i] + A[j] + j - i);
    }
  }

  cout << distance << '\n';

  return 0;
}
