// 1: Lowest Common Ancestor in a BST: https://www.geeksforgeeks.org/problem...
// 2: Print BST elements in given range: https://www.geeksforgeeks.org/problem...
// 3: Check whether BST contains Dead End: https://www.geeksforgeeks.org/problem...
// 4: Find Common Nodes in two BSTs: https://www.geeksforgeeks.org/problem...
#include <iostream>
#include<stack>
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
// problem1: Lowest Common Ancestor in a Bst
Node* findLCA(Node* root, Node* n1, Node* n2) {

        // code here
        if(!root) return NULL;
        
        
        // if both node are less than root go on left
        if(n1->data<root->data and n2->data<root->data){
            return findLCA(root->left,n1,n2);
        }
         // if both node are greater than root go on right
        else if(n1->data>root->data and n2->data>root->data){
            return findLCA(root->right,n1,n2);
        }
        // if both node are diversing then this is the common ancestor 
        else{
            return root;
        }
}
// problem2: Print BST elements in given range:
void find(Node*root,int low,int high,vector<int>&ans){
        if(!root) return;
        if(root->data>low){
            find(root->left,low,high,ans);
        }
        
        
        if(root->data>=low and root->data<=high){
            ans.push_back(root->data);
        }
        
        if(root->data<high){
           find(root->right,low,high,ans); 
        }
    }
vector<int> nodesInRange(Node *root, int low, int high) {
        // code here
        vector<int> ans;
        
        find(root,low,high,ans);
        
        return ans;
}


//problem3: Check whether BST contains Dead End:
bool solve(Node*root,int lower,int upper){
        if(!root){
            return 0;
        }
        
        // left node
        if(!root->left and !root->right){
            if(root->data-lower == 1 and upper-root->data == 1){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        return solve(root->left,lower,root->data) || solve(root->right,root->data,upper);
    }
bool isDeadEnd(Node *root) {
    // Code here
    return solve(root,0,INT64_MAX);
}
// problem4: Find Common Nodes in two BSTs:
// appoach1 
bool search(Node*root,int target){
      if(!root) return false;

      if(root->data==target){
          return true;
      }
      else if(root->data<target){
          search(root->right,target);
      }
      else{
          search(root->left,target);
      }
  }
void inorder(Node *r1,Node* r2,vector<int>& ans){
      if(!r1) return;

      inorder(r1->left,r2,ans);
      if(search(r2,r1->data)){
          ans.push_back(r1->data);
      }
      inorder(r1->right,r2,ans);
  }
vector<int> findCommon(Node* r1, Node* r2) {
          // code here
          vector<int> ans;
          inorder(r1,r2,ans);
          return ans;
  }

// approach 2 : using inorder iterative approach
vector<int> findCommon(Node * r1,Node*r2){
    vector<int> ans;
    stack<Node*> s1,s2;

    while(r1){
        s1.push(r1);
        r1=r1->left;
    }
    
    while(r2){
        s2.push(r2);
        r2=r2->left;
    }

    while(!s1.empty() and !s2.empty()){
        // check top element is common 
        if(s1.top()->data==s2.top()->data){
            ans.push_back(s1.top()->data);
            // move to right side
            r1 = s1.top()->right;
            r2 = s2.top()->right;

            s1.pop();
            s2.pop();
        }
        else if(s1.top()->data<s2.top()->data){
            // move right side of r1
            r1 = s1.top()->right;
            s1.pop();
        }
        else{
            // move right side of r2
            r2 = s2.top()->right;
            s2.pop();
        }
        // push all the left side element of r1 and r2

        while(r1){
            s1.push(r1);
            r1=r1->left;
        }
    
        while(r2){
            s2.push(r2);
            r2=r2->left;
        }
    }
    return ans;
}