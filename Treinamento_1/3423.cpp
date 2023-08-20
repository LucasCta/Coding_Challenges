#include <bits/stdc++.h>
using namespace std;

int N, M;

int cacaPalavra(string &A, vector<string> &B, int c, int i, int j, char dir) {

  bool found = 0;
  int len = A.size();

  while (!found) {

    if (A[c] == B[i][j]) {
      c += 1;
    } else if (B[i][j] == '1') {
      if (dir == 'U')
        dir = 'R';
      else if (dir == 'L')
        dir = 'D';
    } else if (B[i][j] == '2') {
      if (dir == 'U')
        dir = 'L';
      else if (dir == 'R')
        dir = 'D';
    } else if (B[i][j] == '3') {
      if (dir == 'R')
        dir = 'U';
      else if (dir == 'D')
        dir = 'L';
    } else if (B[i][j] == '4') {
      if (dir == 'D')
        dir = 'R';
      else if (dir == 'L')
        dir = 'U';
    } else {
      break;
    }

    if (len == c) {
      found = 1;
      break;
    }

    if (dir == 'U')
      i -= 1;
    else if (dir == 'D')
      i += 1;
    else if (dir == 'L')
      j -= 1;
    else if (dir == 'R')
      j += 1;

    if (i == N || j == M || j == -1 || i == -1)
      break;
  }

  return found;
}

int main() {

  cin >> N >> M;

  vector<string> P(N);

  for (int i = 0; i < P.size(); i++)
    cin >> P[i];

  int Q;
  cin >> Q;

  vector<string> S(Q);

  for (int i = 0; i < Q; i++)
    cin >> S[i];

  char direction[4] = {'U', 'D', 'L', 'R'};

  for (int k = 0; k < Q; k++) {

    char d = 'x';
    int a = 100000, b = 100000;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (P[i][j] == S[k][0])
          for (int z = 0; z < 4; z++)
            if (cacaPalavra(S[k], P, 0, i, j, direction[z])) {
              a = i, b = j, d = direction[z];
              goto end;
            }

  end:
    if (d != 'x')
      cout << a + 1 << ' ' << b + 1 << ' ' << d << '\n';
    else
      cout << ":(" << '\n';
  }

  return 0;
}
