// 1: Sorted Link List to BST : https://www.geeksforgeeks.org/problem...
// 2: Merge two BST: https://www.geeksforgeeks.org/problem...
// 3: Fixing Two nodes of a BST : https://www.geeksforgeeks.org/problem...
#include <iostream>
#include<stack>
#include <vector>
using namespace std;
class LNode {
public:
    int data;
    LNode* next;

    LNode(int x) {
        data = x;
        next = nullptr;
    }
};

// Tree Node
class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode(int x) {
        data = x;
        left = right = nullptr;
    }
};
// problem 1 : sorted LL to BST Approach 1 : using array TC(n) SC(n)
TNode * createBST(vector<int>arr,int start,int end){
        if(start>end) return NULL;

        int mid = (start+end+1)/2;
        TNode * root = new TNode(arr[mid]);
        root->left = createBST(arr,start,mid-1);
        root->right = createBST(arr,mid+1,end);
        return root;
    }
TNode *sortedListToBST(LNode *head) {
        // convert linked list to array because find middle takes O(1) time
        vector<int> arr;
        while(head){
            arr.push_back(head->data);
            head = head->next;
        }

        return createBST(arr,0,arr.size()-1);
}

// problem 1 : sorted LL to BST Approach 1 : using inorder traversal TC(n) SC(logn)

int countNodes(LNode *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

TNode *buildTree(LNode *&headRef, int n)
{
    if (n <= 0)
        return nullptr;

    // Build left subtree
    TNode *left = buildTree(headRef, n / 2);

    // Create root node
    TNode *root = new TNode(headRef->data);
    root->left = left;

    // Move list head forward
    headRef = headRef->next;

    // Build right subtree
    root->right = buildTree(headRef, n - n / 2 - 1);

    return root;
}

TNode *sortedListToBST(LNode *head)
{
    int n = countNodes(head);
    return buildTree(head, n);
}