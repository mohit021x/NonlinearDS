#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertintobst(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    //insert in left part
    if(d < root->data){
        root->left = insertintobst(root->left,d);
    }
    //insert in right part
    else{
        root->right = insertintobst(root->right,d);
    }

    return root;
}

void buildtree(Node* &root){
    int d;
    cin>>d;

    while(d != -1){
        root = insertintobst(root,d);
        cin>>d;
    }
}

void levelordertraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
           cout<<temp->data<<" ";

          if(temp->left){
            q.push(temp->left);
          }

          if(temp->right){
            q.push(temp->right);
          }
        }
    }
}

int main(){
    Node* root = NULL;

    cout<<"Enter data for BST: ";
    buildtree(root);

    levelordertraversal(root);

    return 0;
}