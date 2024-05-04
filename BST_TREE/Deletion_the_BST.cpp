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
Node *findNodeInBST(Node *root, int target)
{
    // Base case
    if (root == NULL)
        return NULL;
    if (root->data == target)
        return root;
    // Left
    else if (root->data > target)
    {
        return findNodeInBST(root->left, target);
    }
    // Right
    else
    {
        return findNodeInBST(root->right, target);
    }
}
int Findmaxval(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
        return -1;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}
Node *deleteNodeInBST(Node *root, int target)
{
    // base case
    if (root == NULL)
        return root;

    // STEP 1
    Node *temp = findNodeInBST(root, target);
    // temp  is the node delete
    // I want to delete temp
    if (temp->left == NULL && temp->right == NULL)
    {
        isko delete karna
        // leaf node
        delete temp;
        return NULL;
    }
    else if (temp->left == NULL && temp->right != NULL)
    {
        Node *child = temp->right;
        delete temp;
        return child;
    }
    else if (temp->left != NULL && temp->right == NULL)
    {
        Node *child = temp->left;
        delete temp;
        return child;
    }
    else if(taget  > root -> data){
       // right jana chiya 
       return deleteNodeInBST(root -> right , target);
    }
    else if (target < root -> data){
        // left jana chaiye 
        return deleteNodeInBST(root -> left , target)
    }
    else
    {
        // dono child exists karte h
        // inorder precessor of left subtree -> left subtree me max value
        int inorderpre = Findmaxval(temp->left);
        temp->data = inorderpre;
        temp -> left = deleteNodeInBST(temp->left, inorderpre);
        return root;
    }
}
int main()
{
    Node *root = NULL;
    cout << "enter the data for Node" << endl;
    takeInput(root);
    
    cout << "printing the tree" << endl;
    levelOrderTraversal(root);
    cout << endl;
    
    deleteNodeInBST(root , 150);
    levelOrderTraversal(root);
    
    return 0;
}