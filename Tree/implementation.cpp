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

int main() {

  node *root = NULL;

  root = buildtree(root);
  cout << endl;

  levelordertraversal(root);

  return 0;
}