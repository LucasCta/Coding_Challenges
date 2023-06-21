#include <bits/stdc++.h>
using namespace std;

void calculaTri(long long *tri) {
  tri[4] = 1;
  long long par = 0, imp = 1;
  for (int i = 4; i <= 1000000; i++) {
    if (i % 2 == 0) {
      par += i - 2;
      if (i > 4)
        tri[i] = tri[i - 1] + imp;
    } else {
      imp += i - 2;
      if (i > 4)
        tri[i] = tri[i - 1] + par;
    }
  }
}
int main() {
  int t;
  cin >> t;
  long long *tri = (long long *)malloc(sizeof(long long) * 1000001);
  calculaTri(tri);
  while (t--) {
    int N;
    cin >> N;
    cout << tri[N] << '\n';
  }
  return 0;
}
