#include <bits/stdc++.h>
using namespace std;

int pieceTypeL(const std::vector<int> &columns, int base, int occurrencesBase,
               int basePosition) {
  int nodesMinHeight = *std::min_element(columns.begin(), columns.end());

  if (occurrencesBase == 1 && columns[basePosition - 1] == 2) {
    return 0; // No lines can be completed
  } else if (occurrencesBase == 1) {
    return 0; // No lines can be completed
  } else {
    int columnsBetween = basePosition - 1;
    int linesCompleted = std::min(columnsBetween, occurrencesBase);
    return linesCompleted;
  }
}

int pieceTypeJ(const std::vector<int> &columns, int base, int occurrencesBase,
               int basePosition) {
  if (occurrencesBase == 2 && (columns[basePosition + 1] == base ||
                               columns[basePosition - 1] == base)) {
    return 1; // Can complete 1 line
  } else if (occurrencesBase == 1) {
    int borderMinHeight =
        std::min(columns[basePosition - 1], columns[basePosition + 1]);
    int nodesMinHeight = *std::min_element(columns.begin(), columns.end());
    if (nodesMinHeight >= borderMinHeight) {
      return 1; // Can complete 1 line
    } else {
      return 0; // No lines can be completed
    }
  } else {
    return 0; // No lines can be completed
  }
}

int pieceTypeI(const std::vector<int> &columns, int base, int occurrencesBase) {
  if (occurrencesBase == 1) {
    int minHeight = *std::min_element(columns.begin(), columns.end());
    return minHeight; // Can complete 'minHeight' lines
  } else {
    return 0; // No lines can be completed
  }
}

int TetrisMove(std::vector<std::string> &strArr) {
  std::string piece = strArr[0];
  std::vector<int> columns(strArr.begin() + 1, strArr.end());

  int base = *std::min_element(columns.begin(), columns.end());
  int occurrencesBase = std::count(columns.begin(), columns.end(), base);

  int basePosition = std::distance(
      columns.begin(), std::find(columns.begin(), columns.end(), base));

  if (occurrencesBase >= 1 && occurrencesBase < 3) {
    if (piece == "L") {
      return pieceTypeL(columns, base, occurrencesBase, basePosition);
    } else if (piece == "J") {
      return pieceTypeJ(columns, base, occurrencesBase, basePosition);
    } else if (piece == "I") {
      return pieceTypeI(columns, base, occurrencesBase);
    } else {
      return 0; // No lines can be completed for other piece types
    }
  } else {
    return 0; // No lines can be completed
  }
}

int main() {
  std::vector<std::string> inputL = {"L", "3", "4", "4", "5", "6", "2",
                                     "0", "6", "5", "3", "6", "6"};
  std::vector<std::string> inputI = {"I", "2", "4", "3", "4", "5", "2",
                                     "0", "2", "2", "3", "3", "3"};
  std::vector<std::string> inputO = {"O", "4", "3", "2", "3", "5", "1",
                                     "0", "1", "2", "4", "3", "4"};

  std::cout << "Output for inputL: " << TetrisMove(inputL) << std::endl;
  std::cout << "Output for inputI: " << TetrisMove(inputI) << std::endl;
  std::cout << "Output for inputO: " << TetrisMove(inputO) << std::endl;

  return 0;
}
