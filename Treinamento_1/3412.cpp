#include <bits/stdc++.h>
using namespace std;

int main() {

  int t;
  cin >> t;
  cin.ignore();
  cout << fixed << setprecision(1);

  while (t--) {

    string nomeAluno;
    getline(cin, nomeAluno);

    string notasAluno;
    getline(cin, notasAluno);
    istringstream iss(notasAluno);

    float notas[4];
    int qntNotas = 0;
    while (iss >> notas[qntNotas])
      qntNotas++;

    float mediaFinal;
    if (qntNotas <= 3) {
      float sumNotas = 0;
      for (int i = 0; i < qntNotas; i++)
        sumNotas += notas[i];
      if (qntNotas == 1)
        qntNotas += 1;
      mediaFinal = sumNotas / qntNotas;
    } else {
      float *menorNota = min_element(notas, notas + 3);
      if (*menorNota < notas[3])
        *menorNota = notas[3];
      mediaFinal = (notas[0] + notas[1] + notas[2]) / 3;
    }

    cout << nomeAluno << ": " << mediaFinal << '\n';
  }

  return 0;
}
