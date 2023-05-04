#include <iostream>
using namespace std;

int SMC(char *s1, char *s2) { return 0; }

int main() {
  int t;
  cin >> t;
  while (t--) {
    char *s1 = (char *)malloc(sizeof(char) * 100);
    char *s2 = (char *)malloc(sizeof(char) * 100);
    cin >> s1 >> s2;
    cout << SMC(s1, s2) << '\n';
    free(s1);
    free(s2);
  }
  return 0;
}
