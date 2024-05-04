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
Node *insertIntoBST(Node *root, int data)
{
    // Empty tree
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    // Not empty tree
    if (root->data > data)
    {
        // insert into left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}
// To print the tree level wise
void levelOrderTraversal(Node *root)
{
    // Empty tree
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // Push the root in queue
    q.push(root);
    q.push(NULL);
    // Run the loop until queue becomes empty
    while (!q.empty())
    {
        // Fetch front node and then pop
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // go to the next line
            cout << endl;
            // Marking for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // left child exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // right child exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void preOrederTraversal(Node *root)
{
    // NLR
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrederTraversal(root->left);
    preOrederTraversal(root->right);
}
void InorderTraversal(Node *root)
{
    // LNR
    if (root == NULL)
        return;
    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}
void PostOrderTraversal(Node *root)
{
    // LRN
    if (root == NULL)
        return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    cout << "enter the data for Node" << endl;
    takeInput(root);
    
    cout << "printing the tree" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "printing Inorder :" << endl;
    InorderTraversal(root);
    cout << endl;

    cout << "printing preorder :" << endl;
    preOrederTraversal(root);
    cout << endl;

    cout << "printing postorder :" << endl;
    PostOrderTraversal(root);
    return 0;
}