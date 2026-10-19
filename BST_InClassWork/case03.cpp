
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
    Node *root = new Node(45);
    root->left = new Node(25);
    root->right = new Node(65);
    root->left->left = new Node(15);
    root->left->right = new Node(35);
    root->right->left = new Node(55);
    root->right->right = new Node(75);
    root->left->right->left = new Node(30);
    root->right->left->right = new Node(60);

    // Print before deletion
    cout << "Before: ";
    printInorder(root);
    cout << " (root = " << root->data << ")" << endl;

    // Case 3: delete a node with ONE child.
    // First remove 50 so that 60 has only one child (70).
    //delete root->left->right;
    //root->left->right = nullptr;
    //cout << "Middle: ";
    //printInorder(root);
    //cout << " (60 now has one child, 70)" << endl;
    // 1. search for 60, remembering its parent
    Node *parent = nullptr;
    Node *cur = root;
    int key = 35;
    while (cur != nullptr && cur->data != key)
    {
        parent = cur;
        if (key < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    // 2. its only child takes its place
    Node *child = (cur->left != nullptr) ? cur->left : cur->right; // 70
    if (parent->left == cur)
        parent->left = child;
    else
        parent->right = child; // 40->right = 70
    delete cur;

    // Print after deletion
    cout << "After: ";
    printInorder(root);
    cout << " (root = " << root->data << ")" << endl;

    // Free memory
    freeTree(root);

    return 0;
}
