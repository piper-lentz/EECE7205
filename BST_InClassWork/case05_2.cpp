
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Inorder (Left, Node, Right) prints a BST in sorted order
void printInorder(Node *node)
{
    if (node == nullptr)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

// Free every node (postorder: children before parent)
void freeTree(Node *node)
{
    if (node == nullptr)
        return;

    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

int main()
{
    // Build tree T
    Node* root = nullptr;

    // Print before deletion
    //cout << "Before: ";
    //printInorder(root);
    //cout << " (root = " << root->data << ")" << endl;

    // Case 5: the key is not in the tree (delete 25).

    Node *parent = nullptr;
    Node *cur = root;
    int key = 20;
    if (root == nullptr)
    {
        cout << "the tree is empty" << endl;
        return 0;
    }
    while (cur != nullptr && cur->data != key)
    {
        parent = cur; // remember the parent
        if (key < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if (cur == nullptr) // not found: insert here
    {
        Node *n = new Node(key);
        if (parent == nullptr)
            root = n; // empty tree
        else if (key < parent->data)
            parent->left = n; // 30->left = 25
        else
            parent->right = n;
    }
    else
        cout << key << " is already in the tree" << endl;

    // Print after deletion
    cout << "After: ";
    printInorder(root);
    cout << " (root = " << root->data << ")" << endl;

    // Free memory
    freeTree(root);

    return 0;
}
