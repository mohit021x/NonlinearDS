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

Node* deleteanode(Node* root, int target){
    if(root == NULL){
        return NULL;
    }

    if(target > root->data){
        root->right = deleteanode(root->right,target);
        return root;
    }
    else if(target < root->data){
        root->left = deleteanode(root->left,target);
        return root;
    }
    else{
        //leaf node
        if(root->left ==   NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //node with only right child
        else if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //node with only left child
        else if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //node with both left and right node
        else{
            //find the rightmost in the left subtree
            Node* child = root->left;
            Node* parent = root;

            while(child->right != NULL){
                parent = child;
                child = child->right;
            }

            if(parent == root){
                child->right = root->right;
                delete root;
                return child;
            }
            else{
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                return child;
            }
        }
    }
}

int main(){
    Node* root = NULL;

    cout<<"Enter data for BST: ";
    buildtree(root);

    levelordertraversal(root);

    root = deleteanode(root,3);
    levelordertraversal(root);

    return 0;
}