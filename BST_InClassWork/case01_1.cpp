
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Inorder (Left, Node, Right) prints a BST in sorted order
void printInorder(Node* node)
{
    if (node == nullptr)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

// Free every node (postorder: children before parent)
void freeTree(Node* node)
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
    Node* root = new Node(40);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(70);

    // Print before deletion
    cout << "Before: ";
    printInorder(root);
    cout << " (root = " << root->data << ")" << endl;

    // Case 1: delete the root (40). It has two children.
    // 1. Find the inorder predecessor
    Node* parent = root;
    Node* succ = root->left;

    while (succ->right != nullptr)
    {
        parent = succ;
        succ = succ->right;
    }

    // 2. Copy the successor's value into the root
    root->data = succ->data;

    // 3. Remove the successor node
    if (parent == root)
        parent->left = succ->right;
    else
        parent->right = succ->left;

    delete succ;

    // Print after deletion
    cout << "After: ";
    printInorder(root);
    cout << " (root = " << root->data << ")" << endl;

    // Free memory
    freeTree(root);

    return 0;
}
