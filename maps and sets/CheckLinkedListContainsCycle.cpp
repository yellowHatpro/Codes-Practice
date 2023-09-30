// We can also use Floyd Algorithm
// We will use here a unordered map
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
  Node *next;
  int data;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

void insertInLLHead(Node *&head, int data) {
  if (head == NULL) {
    head = new Node(data);
    return;
  }
  Node *newNode = new Node(data);
  newNode->next = head;
  head = newNode;
  return;
}

bool containsCycle(Node *head) {
  unordered_map<Node *, bool> m;

  Node *temp = head;
  while (temp != NULL) {
    if (m.count(temp) != 0) {
      return true;
    }
    m[temp] = true;
    temp = temp->next;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  Node *head = NULL;
  insertInLLHead(head, 1);
  insertInLLHead(head, 2);
  insertInLLHead(head, 22);
  insertInLLHead(head, 2222);
  insertInLLHead(head, 1);
  Node *temp = head->next->next->next->next;
  temp->next = head;
  if (containsCycle(head)) {
    cout << "tru vai" << endl;
  } else {
    cout << "ono cap" << endl;
  }

  return 0;
}
