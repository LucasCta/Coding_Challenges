#include <iostream>
using namespace std;

int eqCubes(char a[6], char b[6]) {
  for (int i = 0; i < 6; i++)
    if (a[i] != b[i])
      return false;
  return true;
}

int testCubes() {

  char c1[6], c2[6];
  cin >> c1;
  cin >> c2;

  int temp;
  for (int r1 = 0; r1 < 4; r1++) {
    for (int r2 = 0; r2 < 4; r2++) {
      for (int r3 = 0; r3 < 4; r3++) {

        if (eqCubes(c1, c2))
          return true;

        temp = c1[0];
        c1[0] = c1[2];
        c1[2] = c1[5];
        c1[5] = c1[3];
        c1[3] = temp;
      }

      temp = c1[0];
      c1[0] = c1[1];
      c1[1] = c1[5];
      c1[5] = c1[4];
      c1[4] = temp;
    }

    temp = c1[1];
    c1[1] = c1[2];
    c1[2] = c1[4];
    c1[4] = c1[3];
    c1[3] = temp;
  }

  return false;
}

int main() {

  int nTestes;
  cin >> nTestes;
  for (int i = 0; i < nTestes; i++) {
    if (testCubes())
      cout << "S" << endl;
    else
      cout << "N" << endl;
  }
}
