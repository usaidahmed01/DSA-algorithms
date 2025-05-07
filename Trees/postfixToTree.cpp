#include<iostream>
using namespace std;

struct tree {
    tree* left;
    tree* right;
    tree* next;
    char data;
};

tree* top = nullptr;

void dpush(tree* temp) {
    cout << "push : " << temp->data << endl;
    temp->next = top;
    top = temp;
}

tree* dpop() {
    if (top == nullptr) {
        cout << "Stack is empty.\n";
        return nullptr;
    } else {
        tree* crnt = top;
        top = top->next;
        crnt->next = nullptr;  
        return crnt;
    }
}

tree* tree2(string exp) {
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '%') {
            tree* temp = new tree();
            temp->data = exp[i];
            temp->left = temp->right = nullptr;
            dpush(temp);
        } else {
            tree*   temp = new tree();
            temp->data = exp[i];
            temp->right = dpop();
            temp->left = dpop();
            dpush(temp);
        }
    }
    
    return dpop();
}

void postOrder(tree* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

int main() {
    string exp;
    cout << "Exp : ";
    cin >> exp;

    tree* root = tree2(exp);
    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;

    return 0;
}