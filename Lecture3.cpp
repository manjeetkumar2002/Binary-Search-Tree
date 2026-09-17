// 1: Construct Binary Search Tree from Preorder Traversal: https://leetcode.com/problems/constru...
// 2: Construct BST from Postorder: https://www.geeksforgeeks.org/problem...
// 3: Preorder Traversal and BST: https://www.geeksforgeeks.org/problem...
// 4: Preorder to PostOrder: https://www.geeksforgeeks.org/problem...
#include <iostream>
#include <vector>
using namespace std;


class Node{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

//1: Construct Binary Search Tree from Preorder Traversal:
Node * createFromPreorder(vector<int> &preorder,int& index,int& lower,int& upper){

    if(index==preorder.size()) return nullptr;

    // agar range me nhi h to iss node ko as a child of root nhi kar sakte create
    if(preorder[index]<lower or preorder[index]>upper) return nullptr;

    // if current preorder node lies in the range (lower,upper) create it
    Node * root = new Node(preorder[index]);
    index++;
    root->left = createFromPreorder(preorder,index,lower,root->data);
    root->right = createFromPreorder(preorder,index,root->data,upper);
    return root;
}

Node* bstFromPreorder(vector<int>& preorder) {
    int lower = INT64_MIN;
    int upper = INT64_MAX;
    int index = 0;
    return createFromPreorder(preorder,index,lower,upper);
}
// 2: Construct BST from Postorder:
Node * createFromPostorder(vector<int> &postorder,int& index,int& lower,int& upper){

    if(index<0) return nullptr;

    // agar range me nhi h to iss node ko as a child of root nhi kar sakte create
    if(postorder[index]<lower or postorder[index]>upper) return nullptr;

    // if current preorder node lies in the range (lower,upper) create it
    Node * root = new Node(postorder[index]);
    index--;
    root->right = createFromPostorder(postorder,index,root->data,upper);
    root->left = createFromPostorder(postorder,index,lower,root->data);
    return root;
}

Node* bstFromPostorder(vector<int>& postorder) {

    int lower = INT64_MIN;
    int upper = INT64_MAX;
    int index = postorder.size()-1;
    return createFromPostorder(postorder,index,lower,upper);
}
 //3: Preorder Traversal and BST:
void checkBST(vector<int> &preorder,int& index,int& lower,int& upper){
      if(index==preorder.size()) return;

      if(preorder[index]<lower or preorder[index]>upper) return;

      // if current preorder node lies in the range (lower,upper) create it
      int value = preorder[index];
      index++;
      checkBST(preorder,index,lower,value);
      checkBST(preorder,index,value,upper);
}
bool canRepresentBST(vector<int> &pre) {
        // code here
        int lower = INT64_MIN;
        int upper = INT64_MAX;
        int index = 0;
        checkBST(pre,index,lower,upper);

        if(index==pre.size()) return true;
        else return false;
}