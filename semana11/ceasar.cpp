#include <cstring>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    char *mc = (char *)malloc(sizeof(char) * 10000);
    char *md = (char *)malloc(sizeof(char) * 10000);
    int ceasar = 0;
    cin >> mc >> md;
    while (strstr(mc, md) == NULL) {
      for (int i = 0; md[i] != '\0'; i++)
        md[i] = (md[i] + 1) > ('z') ? ('a') : (md[i] + 1);
      ceasar += 1;
    }
    for (int i = 0; mc[i] != '\0'; i++)
      mc[i] = (mc[i] - ceasar) < ('a') ? ('z' - ('a' - (mc[i] - ceasar + 1)))
                                       : (mc[i] - ceasar);
    cout << mc << '\n';
    free(mc);
    free(md);
  }
}
