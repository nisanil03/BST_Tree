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

Node *BST_Using_Inorder(int inorder[], int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    int element = inorder[mid];
    Node *root = new Node(element);

    root->left = BST_Using_Inorder(inorder, s, mid - 1);
    root->right = BST_Using_Inorder(inorder, mid + 1, e);

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
Node *sorted_Linkedlist_into_BST(Node *&head, int n)
{
    // base case

    if (n <= 0 || head == NULL)
        return NULL;
    // Getting left subtree
    // Node* leftSubtree = sortedLLIntoBST(head,n-1-n/2);
    Node *leftsubTree = sorted_Linkedlist_into_BST(head, n / 2);

    Node *root = head;
    // Attach root to left subtree
    root->left = leftsubTree;

    head = head->right;
    // Getting right subtree
    // Head points to one node ahead of mid and hence is updated head
    // root->right = sortedLLIntoBST(head,n/2);
    root->right = sorted_Linkedlist_into_BST(head, n - 1 - n / 2 );
    return root;
}
void pribntLinklist(Node *head)
{
    Node *temp = head;
    cout << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        // next pointer is right pointer
        temp = temp->right;
    }
    cout << endl;
}
int main()
{
    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = 0;
    int e = 8;

    Node *root = BST_Using_Inorder(inorder, s, e);
    levelOrderTraversal(root);

    Node *head = NULL;
    convertIntoSortedDLL(root, head);
    cout << endl;
    cout << "Printing Sorted Doubly Linked List" << endl;
    pribntLinklist(head);
    Node *root1 = NULL;

    root1 = sorted_Linkedlist_into_BST(head, 9);
    cout << endl
         << "Doing level order traversal for root 1" << endl;
    levelOrderTraversal(root1);
}