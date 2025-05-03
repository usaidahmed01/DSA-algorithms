// Construct two binary search trees and check if they are
// • Equal
// • Have same structure
// • sort the nodes in descending order

#include <iostream>
using namespace std;

struct bst
{
    int key;
    bst *left;
    bst *right;

    bst(int value)
    {
        key = value;
        left = right = nullptr;
    }
};

bst *insert(bst *node, int key)
{
    if (node == nullptr)
    {
        bst* root = new bst();
        root->key = key;
        root->left = root->right = nullptr;
        return root;
    }

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

void inorder(bst *node)
{
    if (node != nullptr)
    {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}

int main()
{
    bst* root = nullptr;
    while (true)
    {
        cout << "1.Insert() \n 2.Print()" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout<<"Enter Value: ";
            int key;
            cin>>key;
            root = insert(root , key);
        }
        if (choice == 2)
        {
            inorder(root);
        }
    }
    return 0;
}