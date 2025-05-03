#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *leftChild;
    BSTNode *rightChild;
};

BSTNode *insert(BSTNode *node, int val)
{
    if (node == nullptr)
    {
        BSTNode *ptr = new BSTNode();
        ptr->data = val;
        ptr->leftChild = nullptr;
        ptr->rightChild = nullptr;
        return ptr;
    }
    if (val > node->data)
    {
        node->rightChild = insert(node->rightChild, val);
    }
    else
    {
        node->leftChild = insert(node->leftChild, val);
    }
    return node;
}

void printBST(BSTNode *node)
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        printBST(node->leftChild);
        printBST(node->rightChild);
    }
}

void search(BSTNode *node, int val)
{
    if (node != nullptr)
    {
        if (node->data == val)
        {
            cout << "Value found";
            return;
        }
        if (val > node->data)
        {
            search(node->rightChild, val);
        }
        else
        {
            search(node->leftChild, val);
        }
    }
}

BSTNode *deleteNode(BSTNode *node, int val)
{
    // base case if tree is empty
    if (node == nullptr) {
        cout << "Value not found!";
        return nullptr;
    }

    if(node->data == val) {
        // having no child
        if (node->leftChild == nullptr && node->rightChild == nullptr)
        {
            cout << node->data << " deleted!" << endl;
            delete node;
            return nullptr;
        }
        // having 1 child
        if (node->leftChild == nullptr)
        {
            BSTNode *temp = node->rightChild;
            cout << node->data << " deleted!" << endl;
            delete node;
            return temp;
        }
        if (node->rightChild == nullptr)
        {
            BSTNode *temp = node->leftChild;
            cout << node->data << " deleted!" << endl;
            delete node;
            return temp;
        }
        // having 2 children
        if (node->leftChild != nullptr && node->rightChild != nullptr)
        {
            // finding minimum value from right subtree
            BSTNode *temp = node->rightChild;
            while (temp->leftChild != nullptr)
            {
                temp = temp->leftChild;
            }
            node->data = temp->data;
            node->rightChild = deleteNode(node->rightChild, temp->data);
            return node;
        }
    } else if (val > node->data) {
        node->rightChild = deleteNode(node->rightChild, val);
    } else {
        node->leftChild = deleteNode(node->leftChild, val);
    }
}

int main()
{
    BSTNode *root = nullptr;
    int choice;
    do
    {
        cout << "1. Insert into BST\n2. Display\n3. Search Value\n4. Delete a value\n5. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int val;
            cout << "Enter data: ";
            cin >> val;
            root = insert(root, val);
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << endl;
            printBST(root);
            cout << endl << endl;
        }
        else if (choice == 3)
        {
            int val;
            cout << "Enter value to search";
            cin >> val;
            search(root, val);
            cout << endl;
        }
        else if (choice == 4)
        {
            int val;
            cout << "Enter value to delete it from BST: ";
            cin >> val;
            root = deleteNode(root, val);
            cout << endl << endl;
        }
        else if (choice == 5)
        {
            cout << "Exiting Program!";
            cout << endl;
        }
        else
        {
            cout << "Invalid Choice!";
        }
    } while (choice != 5);
}