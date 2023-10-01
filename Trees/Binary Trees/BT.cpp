#include "BinaryTree.h"

BinaryTreeNode<int> *takeInput() {
  int data;
  cin >> data;
  if (data == -1)
    return NULL;
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
  BinaryTreeNode<int> *left = takeInput();
  BinaryTreeNode<int> *right = takeInput();
  root->left = left;
  root->right = right;
  return root;
}

BinaryTreeNode<int> *takeInputLevelWise() {
  int rootData;
  cin >> rootData;
  if (rootData == -1) {
    return NULL;
  }
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (!pendingNodes.empty()) {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    int leftChildData;
    cin >> leftChildData;
    if (leftChildData != -1) {
      BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
      front->left = leftChild;
      pendingNodes.push(leftChild);
    }
    int rightChildData;
    cin >> rightChildData;
    if (rightChildData != -1) {
      BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
      front->left = rightChild;
      pendingNodes.push(rightChild);
    }
  }
  return root;
}

void printBT(BinaryTreeNode<int> *root) {
  if (root == NULL)
    return;
  cout << root->data << ": ";
  if (root->left != NULL)
    cout << "L " << root->left->data << " ";

  if (root->right != NULL)
    cout << "R " << root->right->data << " ";
  cout << endl;
  printBT(root->left);
  printBT(root->right);
}

void printBTLevelWise(BinaryTreeNode<int> *root) {
  if (root == nullptr)
    return;
  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (!pendingNodes.empty()) {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << front->data << " : ";
    cout << "L";
    if (front->left != nullptr) {
      cout << front->left->data << " ";
      pendingNodes.push(front->left);
    }
    cout << "R";
    if (front->right->data) {
      cout << front->right->data;
      pendingNodes.push(front->right);
    }
    cout << endl;
  }
}

int main() {
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
  BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
  BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
  root->left = node1;
  root->right = node2;
  printBT(root);
  delete root;
}
