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

void preOrder( bst *node , vector<int> &treeVec)
{
    if (node != nullptr)
    {
        treeVec.push_back(node->data);
        preOrder(node->left , treeVec);
        preOrder(node->right , treeVec);
    }
}

bool equality(bst *node1, bst *node2 , vector<int> &tree1Vec , vector<int> &tree2Vec)
{
    preOrder(node1 , tree1Vec);
    preOrder(node2 , tree2Vec);


    if(tree1Vec.size() != tree2Vec.size()) return false;

    for (int i = 0; i < tree1Vec.size(); i++)
    {
        if (tree1Vec[i] != tree2Vec[i])
        {
            return false;
        }
    }

    return true;
}

main()
{

    vector<int> tree1Vec;
    vector<int> tree2Vec;

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

    answer = equality(tree1, tree2 , tree1Vec , tree2Vec);

    if (!answer)
        cout << " Trees are Unequal. ";
        
    else
        cout << "Trees are Equal. ";

    cout<<endl;
    descendingSort(tree1Vec);
    cout<<endl;
    descendingSort(tree2Vec);


}