// 1: Largest BST: https://www.geeksforgeeks.org/problem...
// 2: Maximum Sum BST in Binary Tree: https://leetcode.com/problems/maximum...
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// problem 1 :Largest BST
class Box
{
public:
    bool BST;
    int size;
    int min, max;
    Box()
    {
        BST = 1;
        size = 0;
        min = INT64_MAX;
        max = INT64_MIN;
    }
};
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};
Box* find(Node *root, int &Totalsize)
{
    // root not exist
    if (!root)
    {
        Totalsize = max(Totalsize, 1);
        return new Box();
    }
    // root exist
    Box *lefthead = find(root->left, Totalsize);
    Box *righthead = find(root->right, Totalsize);
    if (lefthead->BST && righthead->BST && root->data > lefthead->max && root->data < righthead->min)
    {
        Box *head = new Box();
        head->size = 1 + lefthead->size + righthead->size;
        Totalsize = max(Totalsize, head->size);
        head->min = min(lefthead->min, root->data);
        head->max = max(righthead->max, root->data);
        return head;
    }
    else
    {
        lefthead->BST = 0;
        return lefthead;
    }
}
int largestBst(Node *root)
{
    // code here
    int Totalsize = 0;
    find(root, Totalsize);
    return Totalsize;
}
// problem 2: Maximum Sum BST in Binary Tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Box
{
public:
    bool BST;
    int sum;
    int min, max;
    Box()
    {
        BST = 1;
        sum = 0;
        min = INT64_MAX;
        max = INT64_MIN;
    }
};
Box *find(TreeNode *root, int &maxSum)
{
    // root not exist
    if (!root)
    {
        return new Box();
    }
    // root exist
    Box *lefthead = find(root->left, maxSum);
    Box *righthead = find(root->right, maxSum);
    if (lefthead->BST && righthead->BST && root->val > lefthead->max && root->val < righthead->min)
    {
        Box *head = new Box();
        head->sum = root->val + lefthead->sum + righthead->sum;
        maxSum = max(maxSum, head->sum);
        head->min = min(lefthead->min, root->val);
        head->max = max(righthead->max, root->val);
        return head;
    }
    else
    {
        lefthead->BST = 0;
        lefthead->sum = 0;
        return lefthead;
    }
}
int maxSumBST(TreeNode *root)
{
    int maxSum = 0;
    find(root, maxSum);
    return maxSum;
}