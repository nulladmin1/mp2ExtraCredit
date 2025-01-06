#include "vector"
#include <iostream>
#include <string>
using namespace std;

enum CellStatus {
  Building,
  Infected,
  Uninfected,
};

CellStatus translateStatus(char);
char translateStatus(CellStatus);

void printMatrix(vector<vector<CellStatus>>);
void simulatePlague(vector<vector<CellStatus>>);

int main() {
  // The size of the square grid
  int S;

  // The number of hours the simulation runs for
  int T;

  cin >> S >> T;

  vector<vector<CellStatus>> matrix(S, vector<CellStatus>(S, Uninfected));

  char input;

  int counter = 0;

  while (counter < S * S) {
    cin >> input;

    matrix.at((int)(counter / S)).at(counter % S) = translateStatus(input);

    counter++;
  }

  printMatrix(matrix);
  return 0;
}

CellStatus translateStatus(char c) {
  if (c == 'P') {
    return Infected;
  } else if (c == 'B') {
    return Building;
  } else {
    return Uninfected;
  }
}

char translateStatus(CellStatus c) {
  if (c == Infected) {
    return 'P';
  } else if (c == Building) {
    return 'B';
  } else {
    return '.';
  }
}

void printMatrix(vector<vector<CellStatus>> v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout << translateStatus(v.at(i).at(j)) << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void simulatePlague(vector<vector<CellStatus>> v) {}
