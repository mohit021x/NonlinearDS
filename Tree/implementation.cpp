#include <iostream>
#include <queue>
using namespace std;

class node {
public:
  int data;
  node *left;
  node *right;

  node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

node *buildtree(node *root) {
  int data;
  cout << "Enter the data: ";
  cin >> data;

  if (data == -1) {
    return NULL;
  }

  root = new node(data);

  cout << "Enter the data for left of " << data << endl;
  root->left = buildtree(root->left);

  cout << "Enter the data for right of " << data << endl;
  root->right = buildtree(root->right);

  return root;
}

void levelordertraversal(node *root) {
  queue<node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    node *temp = q.front();
    q.pop();

    if (temp == NULL) {
      cout << endl;
      if (!q.empty()) {
        q.push(NULL);
      }
    }

    else {
      cout << temp->data << " ";

      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
}

void inordertraversal(node *root) {
  // base case
  if (root == NULL) {
    return;
  }

  inordertraversal(root->left);
  cout << root->data << " ";
  inordertraversal(root->right);
}

void preordertraversal(node *root) {
  // base case
  if (root == NULL) {
    return;
  }

  cout << root->data << " ";
  preordertraversal(root->left);
  preordertraversal(root->right);
}

void postordertraversal(node *root) {
  // base case
  if (root == NULL) {
    return;
  }

  postordertraversal(root->left);
  postordertraversal(root->right);
  cout << root->data << " ";
}

int main() {

  node *root = NULL;

  root = buildtree(root);
  cout << endl;

  cout << "Level Order Traversal: " << endl;
  levelordertraversal(root);
  cout << endl;

  cout << "Inorder Traversal: ";
  inordertraversal(root);
  cout << endl;

  cout << "Preorder Traversal: ";
  preordertraversal(root);
  cout << endl;

  cout << "Postorder Traversal: ";
  postordertraversal(root);

  return 0;
}