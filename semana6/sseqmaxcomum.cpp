#include <iostream>
#include <string.h>
using namespace std;

int qntCSMC(int **l, int **m, int *m1, int *m2, char *s1, char *s2, int i,
            int j, int sss) {
  int nletters = 0;
  if (sss == 0 || m[i][j] == 1)
    return 0;
  if (s1[i - 1] == s2[j - 1]) {
    if (m1[i - 1] == 0)
      nletters += 1;
    if (m2[j - 1] == 0)
      nletters += 1;
    m1[i - 1] = 1;
    m2[j - 1] = 1;
  }
  m[i][j] = 1;
  if (s1[i - 1] == s2[j - 1])
    nletters += qntCSMC(l, m, m1, m2, s1, s2, i - 1, j - 1, sss - 1);
  if (l[i - 1][j] == sss)
    nletters += qntCSMC(l, m, m1, m2, s1, s2, i - 1, j, sss);
  if (l[i][j - 1] == sss)
    nletters += qntCSMC(l, m, m1, m2, s1, s2, i, j - 1, sss);
  return nletters;
}

int SMC(char *s1, char *s2) {
  int size1 = strlen(s1);
  int size2 = strlen(s2);
  int **letters = (int **)malloc(sizeof(int *) * (size1 + 1));
  for (int i = 0; i <= size1; i++)
    letters[i] = (int *)malloc(sizeof(int) * (size2 + 1));
  for (int i = 0; i <= size1; i++)
    letters[i][0] = 0;
  for (int i = 0; i <= size2; i++)
    letters[0][i] = 0;
  for (int i = 1; i <= size1; i++)
    for (int j = 1; j <= size2; j++) {
      if (s1[i - 1] == s2[j - 1])
        letters[i][j] = letters[i - 1][j - 1] + 1;
      else
        letters[i][j] = max(letters[i - 1][j], letters[i][j - 1]);
    }
  int *m1 = (int *)calloc(size1, sizeof(int));
  int *m2 = (int *)calloc(size2, sizeof(int));
  int **marked = (int **)malloc(sizeof(int *) * (size1 + 1));
  for (int i = 0; i <= size1; i++)
    marked[i] = (int *)calloc(size2 + 1, sizeof(int));
  int result = qntCSMC(letters, marked, m1, m2, s1, s2, size1, size2,
                       letters[size1][size2]);
  for (int i = 0; i <= size1; i++) {
    free(letters[i]);
    free(marked[i]);
  }
  free(m1);
  free(m2);
  free(marked);
  free(letters);
  return result;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    char *s1 = (char *)malloc(sizeof(char) * 1001);
    char *s2 = (char *)malloc(sizeof(char) * 1001);
    cin >> s1 >> s2;
    cout << SMC(s1, s2) << '\n';
    free(s1);
    free(s2);
  }
  return 0;
}

