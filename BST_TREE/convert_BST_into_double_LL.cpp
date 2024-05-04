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
Node *bstUsingInorder(int inorder[], int s, int e)
{
    // Base Case
    if (s > e)
    {
        return NULL; // Invalid array and hence NULL tree
    }
    // Find middle node
    int mid = s + (e - s) / 2;

    int element = inorder[mid];
    Node *root = new Node(element);

    // Left subtree creation
    root->left = bstUsingInorder(inorder, s, mid - 1);

    // Right subtree creation
    root->right = bstUsingInorder(inorder, mid + 1, e);

    return root;
}
void convertIntoSortedDLL(Node *root, Node *&head)
{
    // BASE case
    if (root == NULL)
    {
        return;
    }

    // right subtree into LL
    convertIntoSortedDLL(root->right, head);

    // atach root node
    root->right = head;

    if (head != NULL)
        head->left = root;

    // update head
    head = root;

    // left subtree Linkde list
    convertIntoSortedDLL(root->left, head);
}
void pribntLinklist(Node *head)
{
    Node *temp = head;
    cout<<endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        // next pointer is right pointer
        temp = temp->right;
    }
    cout<<endl;
}
int main()
{

    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = 0;
    int e = 8;
    Node *root = bstUsingInorder(inorder, s, e);
    levelOrderTraversal(root);
    
    cout<<endl;
    cout << "Printing Sorted Doubly Linked List" << endl;
    Node *head = NULL;
    convertIntoSortedDLL(root, head);
    pribntLinklist(head);
    return 0;
}