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
// problem 1 :insert value in BST
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

// inorder traversal gave the ascending order
void inorder(Node *root){
    if(!root) return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// searching in BST

bool search(Node * root,int target){
    if(!root) return false;

    if(root->data == target)
    return true;

    else if(root->data>target)
    return search(root->left,target);

    else 
    return search(root->right,target);
}
Node * minValueNode(Node * root){
        Node *current = root;
        while(current && current->left!=NULL){
            current = current->left;
        }
        return current;
}
Node* delNode(Node* root, int x) {
    // code here
        if(!root) return nullptr;
        
        if(x<root->data){
            root->left = delNode(root->left,x);
        }
        else if(x>root->data){
            root->right = delNode(root->right,x);
        }
        else{
            //case 1 and 2 : node have no childrens or 1 child
            // no children exist
            if(!root->left and !root->right){
                delete root;
                return nullptr;
            }
            // right child exist
            if(!root->left){
                Node * temp = root->right;
                delete root;
                return temp;
            }
            // left child exist
            if(!root->right){
                Node * temp = root->left;
                delete root;
                return temp;
            }
            
            // both child exist
            // 1.change root data with (min node from right subtree)
            // 2.delete the inorder successor
            
            Node * temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = delNode(root->right,temp->data);
            
        }
        return root;
}
int main(){
    int arr[] = {3,4,7,1,6,8};
    Node * root = NULL;
    for(int i=0;i<6;i++){
        root = insert(root,arr[i]);
    }

    inorder(root);
}