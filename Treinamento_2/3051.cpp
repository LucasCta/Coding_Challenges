#include <bits/stdc++.h>
using namespace std;

int main() {

  long long N, K;
  cin >> N >> K;
  vector<long> R(N);
  for (int i = 0; i < N; i++)
    cin >> R[i];

  long long total = 0;
  long long acc = R[0];
  long long i = 0, j = 0;

  while (i < N) {

    if (acc <= K) {
      long long tempT = 0;
      if (acc == K) {
        long long tempI = i;
        long long tempACC = acc;
        do {
          tempT += 1;
          acc -= R[i];
          i++;
        } while (acc == K && i <= j);
        i = tempI;
        acc = tempACC;
        total += tempT;
        // cout << "ENCONTROU: " << total << '\n';
        while (++j < N) {
          acc += R[j];
          if (acc == K) {
            if (R[j] == 0 && K == 0)
              tempT += 1;
            total += tempT;
            // cout << "ENCONTROU: " << total << '\n';
          } else {
            acc -= R[j];
            j--;
            break;
          }
        }
      }
      if (++j < N)
        acc += R[j];
      else
        break;
    }

    else {
      acc -= R[i];
      i++;
      if (i > j && i < N) {
        acc += R[i];
        j++;
      }
    }
    // cout << "i: " << i << " j: " << j << '\n';
  }

  cout << total << '\n';

  return 0;
}
