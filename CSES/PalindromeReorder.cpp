#include <iostream>
#include <map>
#include <string>
int main(int argc, char *argv[]) {
  std::string possiblePalindrome;
  std::cin >> possiblePalindrome;
  int n = possiblePalindrome.size();
  std::map<char, int> m;
  for (int i = 0; i < n; i++) {
    m[possiblePalindrome[i]]++;
  }
  int oddCnt = 0;
  std::string outputStr;
  for (auto itr : m) {
    if (itr.second % 2) {
      oddCnt++;
      outputStr.insert(outputStr.size() / 2, itr.second, itr.first);
      if (oddCnt > 1) {
        std::cout << "NO SOLUTION";
        return 0;
      }
    } else {
      outputStr.insert(0, itr.second / 2, itr.first);
      outputStr.append(itr.second / 2, itr.first);
    }
  }
  std::cout << outputStr;
  return 0;
}
