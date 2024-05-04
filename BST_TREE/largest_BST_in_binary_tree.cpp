#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class NodeData
{
public:
    int size;
    int minval;
    int maxval;
    bool validBST;
     NodeData()
    {
    }

    NodeData(int size, int max, int min, bool valid)
    {
        this->size = size;
        minval = min;
        maxval = max;
        validBST = valid;
    }
};

NodeData findLargestBST(Node *root, int &ans)
{
    // base case
    if (root == NULL)
    {
        NodeData temp(0, INT_MIN, INT_MAX, true);
        return temp;
    }
    // First find left subtree answer
    NodeData leftAns = findLargestBST(root->left, ans);
    
    // Then find right subtree answer
    NodeData rightAns = findLargestBST(root->right, ans);

    /// Checking starts here
    NodeData currNodeAns;

    currNodeAns.size = leftAns.size + rightAns.size + 1;

    currNodeAns.maxval = max(root->data, rightAns.maxval);
    currNodeAns.minval = min(root->data, leftAns.minval);

    // check bst hai ki nahi
    if (leftAns.validBST && rightAns.validBST && (root->data > leftAns.maxval && root->data < rightAns.minval))
    {
        currNodeAns.validBST = true;
    }
    else
    {
        currNodeAns.validBST = false;
    }
    if (currNodeAns.validBST)
    {
        ans = max(ans, currNodeAns.size);
    }
    return currNodeAns;
}

int main()
{
    Node *root = new Node(50);
    Node *first = new Node(30);
    Node *second = new Node(60);
    Node *third = new Node(5);
    Node *fourth = new Node(20);
    Node *fifth = new Node(30);
    Node *sixth = new Node(60);
    Node *seventh = new Node(5);
    Node *eight = new Node(20);
    
    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;
    second ->left = fifth;
    second ->right = sixth;
    sixth ->left = seventh;
    sixth -> right = eight;


    cout << "Printing the tree" << endl;
    // levelOrderTraversal(root);
    int ans = 0;
    findLargestBST(root, ans);
    cout << "Largest BST ka size " << ans << endl;
    return 0;
}