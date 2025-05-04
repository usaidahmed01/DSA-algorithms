#include <iostream>
#include <vector>
using namespace std;

struct bst
{
    int data;
    bst *left;
    bst *right;
};

bst *bstTree(bst *node, int val)
{

    if (node == nullptr)
    {
        bst *ptr = new bst();
        ptr->data = val;
        ptr->left = ptr->right = nullptr;
        node = ptr;
        return node;
    }
    if (val > node->data)
    {
        node->right = bstTree(node->right, val);
    }
    if (val < node->data)
    {
        node->left = bstTree(node->left, val);
    }
    return node;
}


void descendingSort(vector<int> &tree)
{

    for (int i = 0; i < tree.size(); i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < tree.size(); j++)
        {

            if (tree[j] > tree[maxIndex])
            {
                maxIndex = j;
            }
        }
        swap(tree[maxIndex] , tree[i]);
    }

    for(int i = 0 ; i < tree.size() ; i++){
        cout<<tree[i]<<" ";
        cout<<endl;
    }

}

vector<int> preOrder(bst *node)
{
    vector<int> tree;
    if (node != nullptr)
    {
        tree.push_back(node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
    return tree;
}

bool equality(bst *node1, bst *node2)
{
    vector<int> tree1 = preOrder(node1);
    vector<int> tree2 = preOrder(node2);
    descendingSort(tree1); // Directly gives the descending order.
    descendingSort(tree2);


    if(tree1.size() != tree2.size()) return false;

    for (int i = 0; i < tree1.size(); i++)
    {
        if (tree1[i] != tree2[i])
        {
            return false;
        }
    }

    return true;
}

main()
{
    bool answer = false;
    bool flag = false;
    bst *tree1 = nullptr;
    bst *tree2 = nullptr;

    cout << "Insertion for first Tree." << endl;
    while (!flag)
    {
        cout << "Enter Value ";
        int val;
        cin >> val;

        tree1 = bstTree(tree1, val);

        cout << "Press x to Complete the Tree. ";
        char br;
        cin >> br;

        if (br == 'x')
            flag = true;
    }

    cout << "Insertion for second Tree." << endl;
    while (flag)
    {
        cout << "Enter Value ";
        int val;
        cin >> val;

        tree2 = bstTree(tree2, val);

        cout << "Press x to Complete the Tree. ";
        char br;
        cin >> br;

        if (br == 'x')
            flag = false;
    }

    answer = equality(tree1, tree2);

    if (!answer)
        cout << " Trees are Unequal. ";
    else
        cout << "Trees are Equal. ";

}