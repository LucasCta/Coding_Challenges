#include <bits/stdc++.h>
using namespace std;

int main() {

  int K;
  long long unsigned int L, R;
  cin >> K >> L >> R;

  string num = "";
  long long unsigned int X = L;
  while (num.size() <= R - L)
    num += to_string(X++);
  num.erase(num.length() - (num.length() - R + L - 1));

  // cout << num << '\n';

  long long unsigned int ma = 0;
  for (int i = 0; i < K; i++) {
    long long unsigned tempmax = -1;
    for (int j = 0; j < 10; j++) {
      long long unsigned int r = ma * 10 + j;
      long long int index = num.find(to_string(r));
      if (index != string::npos)
        if (index <= R - L - K + 1)
          tempmax = r;
    }
    ma = tempmax;
  }

  cout << ma << '\n';

  return 0;
}
