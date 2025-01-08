#include "vector"
#include <iostream>
#include <string>
using namespace std;

// Enum to house the status of a cell
enum CellStatus {
  Building,
  Infected,
  NewlyInfected,
  Uninfected,
};

// Convert the CellStatus enum from char -> CeellStatus and CellStatus -> string. 
// (The return type for the 2nd one is string because it's only used in the print function)
CellStatus translateStatus(char);
string translateStatus(CellStatus);

// Function to print the matrix
void printMatrix(vector<vector<CellStatus>>);

// Function to solve the thing
void simulatePlague(vector<vector<CellStatus>> &, int);
void infectSingularCell(vector<vector<CellStatus>> &, int, int);


// Main function
int main() {
  // The size of the square grid
  int S;

  // The number of hours the simulation runs for
  int T;

  cin >> S >> T;

  // Initialize a matrix of uninfected cells
  vector<vector<CellStatus>> matrix(S, vector<CellStatus>(S, Uninfected));

  // Input variable
  char input;

  // Counter-controlled while loop to iterate through every element in the matrix
  int counter = 0;
  while (counter < S * S) {
    cin >> input;

    // I lowkey don't know how i came up with that, but it works
    matrix.at((int)(counter / S)).at(counter % S) = translateStatus(input);

    counter++;
  }

  // Clear screen ANSI code
  cout << "\033[2J";

  // The beginning board:
  cout << "Hour 0" << endl;
  printMatrix(matrix);
  cout << endl;

  // The finished board:
  cout << "After Hour " << T << endl;
  simulatePlague(matrix, T);
  printMatrix(matrix);
  
  return 0;
}

// Translate char into CellSatatus
CellStatus translateStatus(char c) {
  if (c == 'P') {
    return Infected;
  } else if (c == 'B') {
    return Building;
  } else {
    return Uninfected;
  }
}

// Translate CellStatus into string. Used primarily in the printMatrix function. 
// String because it has ANSI escape codes for color
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

// Print the matrix by converting CellStatus to string and just print it
void printMatrix(vector<vector<CellStatus>> v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout << translateStatus(v.at(i).at(j));
    }
    cout << endl;
  }
  cout << endl;
}

// Actually solve the thing
void simulatePlague(vector<vector<CellStatus>> &v, int end_hour) {

  // Skip even hours
  for (int hour = 1; hour <= end_hour; hour++) {
    if (hour % 2 != 0)
      continue;

    // Temporarily clone the vector to modify it
    vector<vector<CellStatus>> temp_clone = v;

    // Iterate through each element to find Infected cells
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v[i].size(); j++) {
        // If infected cell, infect the nearby elements using the infectSingularCell function
        if (v[i][j] == Infected || v[i][j] == NewlyInfected) {
          infectSingularCell(temp_clone, i, j);
        }
      }
    }

    // Reassign the vector to the temporary clone
    v = temp_clone;
  }
}

// Infect a singuler cell by its given coordinates
void infectSingularCell(vector<vector<CellStatus>> &v, int i, int j) {
  CellStatus infectedCell = v[i][j];

  // If a surrounding cell is Uninfected, infect it
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
