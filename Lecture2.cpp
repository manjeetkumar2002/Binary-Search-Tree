// 1: Check BST: https://www.geeksforgeeks.org/problem...[]=0&category[]=Binary%20Search%20Tree&sortBy=submissions
// 2: Minimum Distance Between BST Nodes: https://leetcode.com/problems/minimum...
// 3: Sum of k smallest elements in BST: https://geeksforgeeks.org/problems/su...
// 4: Kth largest element in BST: https://www.geeksforgeeks.org/problem...
// 5: Kth Smallest Element: https://www.interviewbit.com/problems...
// 6: Array to BST: https://www.geeksforgeeks.org/problem...
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

// check tree is binary search tree

// Problem1
// method1
// find the inorder traversal , we know it is in ascending order
void inorder(Node *root, vector<int> &ans){
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
bool isBST(Node *root){
    vector<int> ans;
    inorder(root, ans);

    // check all element are in correct order
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] <= ans[i - 1])
        {
            return 0;
        }
    }
    return 1;
}
// method2 :
bool check(Node *root, int &prev)
{
    if (!root)
        return 1;
    // check left subtree is bst
    bool l = check(root->left, prev);

    if (l == 0)
        return 0;
    // check for the current node
    if (root->data <= prev)
    {
        return 0;
    }

    prev = root->data;
    // check the right subtree is bst
    return check(root->right, prev);
}
bool isBST(Node *root)
{
    int prev = INT64_MIN;
    return check(root, prev);
}

//Problem2 : Minimum Distance Between BST Nodes
void find(Node *root, int &ans, int &prev)
{
    if (!root)
        return;

    find(root->left, ans, prev);
    if (prev != INT64_MAX)
    {
        ans = min(ans, abs(root->data - prev));
    }
    prev = root->data;
    find(root->right, ans, prev);
}
int minDiffInBST(Node *root){
    int ans = INT64_MAX;

    int prev = INT64_MAX;

    find(root, ans, prev);
    return ans;
}

// Problem3: Sum of k smallest elements in BST
void find(Node*root,int& k,int& sum){
        if(!root) return;
        
        
        find(root->left,k,sum);
        k--;
        if(k>=0){
            sum+=root->data;
        }
        else{
            return;
        }
        
        find(root->right,k,sum);
    }
int sum(Node* root, int k) {
        // code here
        int sum = 0;
        find(root,k,sum);
        
        return sum;
    }

// 4: Kth largest element in BST
int find(Node*root,int &k){
        if(!root) return -1;
        int ans = find(root->right,k);
        if(ans!=-1) return ans;
        k--;
        if(k==0) return root->data;
        
        return find(root->left,k);
    }
int kthLargest(Node *root, int k) {
        // code here
        
        // right node left
        
        return find(root,k);
    }
//problem5 : Kth Smallest Element
void find(Node *root, int &k, int &ans){
    if (!root)
        return;

    find(root->left, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    find(root->right, k, ans);
}
int kthSmallest(Node *root, int k){
    // code here
    int ans = -1;
    find(root, k, ans);
    return ans;
}

//problem6: Array to BST:
Node * create(vector<int>& arr,int start,int end){
        if(start>end){
            return nullptr;
        }
        int mid = (start+end)/2;
        
        Node * root = new Node(arr[mid]);
        
        root->left = create(arr,start,mid-1);
        root->right = create(arr,mid+1,end);
        
        return root;
    }
Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        return create(arr,0,arr.size()-1);
    }