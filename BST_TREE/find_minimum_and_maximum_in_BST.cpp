#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // write a constructer
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        // this is first node we have to create
        root = new Node(data);
        return root;
    }

    // no the first node

    if (root->data > data)
    {
        // insert at the left
        root->left = insertIntoBST(root->left, data);
    }

    else
    {
        // insert at the right
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

    // Run the loop until queue becomes empty

    while (!q.empty())
    {
        // Fetch front node and then pop
        Node *temp = q.front();
        q.pop();
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

int minVal(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}
int maxVal(Node *root){
    Node* temp = root;
    if(temp == NULL)
    {
        return -1;
    }
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

int main()
{
    Node *root = NULL;
    cout << "enter the data for Node" << endl;
    takeInput(root);

    cout << "printing the tree" << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << endl
         << "Minimum value is :" << minVal(root) << endl;
     cout<< endl
         <<"Maximum value is :" << maxVal(root) << endl;    
    return 0;
}