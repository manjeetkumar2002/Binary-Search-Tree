// implementation of BST

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * left,*right;
    Node(int value){
        data = value;
        left = right = nullptr;
    }
};
Node * insert(Node *root,int value){
    if(!root){
        return new Node(value);
    }

    if(value<=root->data){
        root->left = insert(root->left,value);
    }
    else{
        root->right = insert(root->right,value);
    }
    return root;
}

void inorder(Node *root){
    if(!root) return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int arr[] = {3,4,7,1,6,8};
    Node * root = NULL;
    for(int i=0;i<6;i++){
        root = insert(root,arr[i]);
    }

    inorder(root);
}