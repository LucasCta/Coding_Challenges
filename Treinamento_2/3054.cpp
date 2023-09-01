#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  char CUP;
  cin >> N >> CUP;

  vector<int> M(N);
  for (int i = 0; i < N; i++)
    cin >> M[i];

  for (int i = 0; i < N; i++) {
    if (M[i] == 1) {
      if (CUP == 'A')
        CUP = 'B';
      else if (CUP == 'B')
        CUP = 'A';
    } else if (M[i] == 2) {
      if (CUP == 'B')
        CUP = 'C';
      else if (CUP == 'C')
        CUP = 'B';
    } else {
      if (CUP == 'A')
        CUP = 'C';
      else if (CUP == 'C')
        CUP = 'A';
    }
  }

  cout << CUP << '\n';
  
  return 0;
}
