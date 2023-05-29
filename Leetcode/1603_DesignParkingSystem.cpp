#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class ParkingSystem {
public:
    int big;
    int medium;
    int small;
    ParkingSystem(int big, int medium, int small) {
      this->big = big;
      this->medium = medium;
      this->small = small;
    }
    
    bool addCar(int carType) {
      if (carType == 1){
        if (big==0) return false;
        else {
          big--;
          return true;
      } 
    } else if (carType == 2){
          if (medium == 0) return false;
          else {
            medium--;
            return true;
        }
      } else {
        if (small == 0) return false;
        else {
          small--;
          return true;
        }
      }
    }
};
