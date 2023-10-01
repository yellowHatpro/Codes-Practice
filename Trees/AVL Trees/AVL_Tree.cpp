// AVL tree implementation in C++

#include <iostream>
using namespace std;

// AVL Node Class
class Node {
public:
  int key;
  Node *left;
  Node *right;
  int height;
};

// Calculate height
int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}
// custom max function
int max(int a, int b) { return (a > b) ? a : b; }

Node *newNode(int key) {
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}

// Rotate left
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}
// Rotate left and right
Node *leftRightRotate(Node *z) {
  z->left = leftRotate(z->left);
  return rightRotate(z);
}

// Rotate right and left
Node *rightLeftRotate(Node *z) {
  z->right = rightRotate(z->right);
  return leftRotate(z);
}

// Get the balance factor of each node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert a node
Node *insertNode(Node *node, int key) {
  // If the tree is empty, return a new node
  if (node == NULL)
    return (newNode(key));
  // Otherwise, recur down the tree
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;
  // Update height of this ancestor node
  node->height = 1 + max(height(node->left), height(node->right));
  int balanceFactor = getBalanceFactor(node);
  // If this node becomes unbalanced, then there are 4 cases

  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }

  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

Node *minNode(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

Node *deleteNode(Node *root, int key) {
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      Node *temp = minNode(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  root->height = 1 + max(height(root->left), height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

// Print the tree
void printTree(Node *root) {
  if (root != NULL) {
    printTree(root->left);
    cout << root->key << endl;
    printTree(root->right);
  }
}
void preOrder(Node *root) {
  if (root == NULL)
    return;
  cout << root->key << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node *root) {
  if (root == NULL)
    return;
  inOrder(root->left);
  cout << root->key << " ";
  inOrder(root->right);
}

void postOrder(Node *root) {
  if (root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->key << " ";
}

int main() {
  cout << "AVL Tree Implementation" << endl;
  int choice, key;
  Node *root = NULL;
  while (1) {
    cout << "Press 1 to insert a node" << endl;
    cout << "Press 2 to delete a node" << endl;
    cout << "Press 3 to print the tree" << endl;
    cout << "Press 4 to print the tree in preorder" << endl;
    cout << "Press 5 to print the tree in inorder" << endl;
    cout << "Press 6 to print the tree in postorder" << endl;
    cout << "Press 7 to exit" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter the key to be inserted" << endl;
      cin >> key;
      root = insertNode(root, key);
      break;
    case 2:
      cout << "Enter the key to be deleted" << endl;
      cin >> key;
      root = deleteNode(root, key);
      break;
    case 3:
      printTree(root);
      break;
    case 4:
      preOrder(root);
      break;
    case 5:
      inOrder(root);
      break;
    case 6:
      postOrder(root);
      break;
    case 7:
      exit(0);
      break;
    default:
      cout << "Invalid choice" << endl;
      break;
    }
  }
}
