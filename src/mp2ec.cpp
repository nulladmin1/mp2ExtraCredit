#include "vector";
#include <iostream>;
#include <string>;
using namespace std;

enum CellStatus {
  Building,
  Infected,
  Uninfected,
};

CellStatus transpileStatus(char);
char transpileStatus(CellStatus);

void printMatrix(vector<vector<CellStatus>>);

int main() {
  int S;
  cin >> S;

  int T;
  cin >> T;

  vector<vector<CellStatus>> matrix(S);

  for (int i; i < S; i++) {
    string input;
    cin >> input;

    for (int j; j < S; j++) {
      matrix.at(i).at(j) = transpileStatus(input[j]);
    }
  }

  printMatrix(matrix);
  return 0;
}

CellStatus transpileStatus(char c) {
  if (c == 'P')
    return Infected;
  else if (c == 'B') {
    return Building;
  } else {
    return Uninfected;
  }
}

char transpileStatus(CellStatus c) {
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
    for (int j = 0; j < v.size(); j++) {
      cout << transpileStatus(v.at(i).at(j)) << " ";
    }
    cout << endl;
  }
}
