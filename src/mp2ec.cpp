#include "vector"
#include <iostream>
#include <string>
using namespace std;

enum CellStatus {
  Building,
  Infected,
  NewlyInfected,
  Uninfected,
};

CellStatus translateStatus(char);
string translateStatus(CellStatus);

void printMatrix(vector<vector<CellStatus>>);
void simulatePlague(vector<vector<CellStatus>> &, int);
void infectSingularCell(vector<vector<CellStatus>> &, int, int);

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
  cout << "\033[2J";

  cout << "Hour 0" << endl;
  printMatrix(matrix);
  cout << endl;

  cout << "After Hour " << T << endl;
  simulatePlague(matrix, T);

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

string translateStatus(CellStatus c) {
  if (c == Infected) {
    return "\033[0;31mP\033[0m ";
  } else if (c == NewlyInfected) {
    return "\033[0;33mP\033[0m ";
  } else if (c == Building) {
    return "\033[0;34mB\033[0m ";
  } else {
    return "\033[0m.\033[0m ";
  }
}

void printMatrix(vector<vector<CellStatus>> v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout << translateStatus(v.at(i).at(j));
    }
    cout << endl;
  }
  cout << endl;
}

void simulatePlague(vector<vector<CellStatus>> &v, int end_hour) {
  for (int hour = 1; hour <= end_hour; hour++) {
    if (hour % 2 != 0)
      continue;

    vector<vector<CellStatus>> temp_clone = v;
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v[i].size(); j++) {
        if (v[i][j] == Infected || v[i][j] == NewlyInfected) {
          infectSingularCell(temp_clone, i, j);
        }
      }
    }

    v = temp_clone;
  }
}

void infectSingularCell(vector<vector<CellStatus>> &v, int i, int j) {
  CellStatus infectedCell = v[i][j];

  if (i > 0 && v.at(i - 1).at(j) == Uninfected) {
    v.at(i - 1).at(j) = NewlyInfected;
  }

  if (j > 0 && v.at(i).at(j - 1) == Uninfected) {
    v.at(i).at(j - 1) = NewlyInfected;
  }

  if (i < v.size() - 1 && v.at(i + 1).at(j) == Uninfected) {
    v.at(i + 1).at(j) = NewlyInfected;
  }

  if (j < v.size() - 1 && v.at(i).at(j + 1) == Uninfected) {
    v.at(i).at(j + 1) = NewlyInfected;
  }
}
