// Single Template
template <typename T> class Pair {
  T x;
  T y;

public:
  // creating setters and getters
  void setX(T x) { this->x = x; }
  T getX() { return x; }

  void setY(T y) { this->y = y; }
  T getY() { return y; }
};

// Multiple template

template <typename T, typename V>
// Here two templates have been used T and V , whose data types will be defined
// at the type of object creation

class MultiTypePair {
  T x;
  V y;

public:
  void setX(T x) { this->x = x; }
  T getX() { return x; }

  void setY(V y) { this->y = y; }
  V getY() { return y; }
};
