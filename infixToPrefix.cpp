#include <iostream>
using namespace std;

struct stack
{
    stack *next;
    char data;
};

stack *top = nullptr;

void push(char x)
{
    stack *temp = new stack();
    temp->data = x;
    temp->next = top;
    top = temp;
    // cout << "Value pushed. " << endl;
}

char pop()
{
    if (top == nullptr)
    {
        cout << "Stack empty.\n";
        return 0;
    }
    else
    {
        char val = top->data;
        stack *temp = top;
        top = top->next;
        delete temp;
        // cout << "Value has popped. " << endl;
        return val;
    }
}

string switchToPost(string exp)
{

    //	int mul = 2, int div = 2, int mod = 2;
    //	int add = 1, int sub = 1;

    string postfix = "";

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*')
        {

            // stack *temp = top;

            if (top == nullptr)
            {
                push(exp[i]);
            }
            else
            {
                if (exp[i] == '*' or exp[i] == '/')
                {

                        while ((top != nullptr) && (top->data == '*' or top->data == '/'))
                        {
                            postfix += pop();
                        }
                        push(exp[i]);

                }
                else if (exp[i] == '+' or exp[i] == '-')
                {
                    while ((top != nullptr) && (top->data == '*' or top->data == '/' or top->data == '+' or top->data == '-'))
                    {
                        postfix += pop();
                    }
                    push(exp[i]);
                }

            }
        }
        else
        { // constant direct push into postfix
            postfix += exp[i];
        }
    }

    while (top != nullptr)
    {
        postfix += pop();
    }
    return postfix;
}

string reverseExp(string exp) {
    // string tempPrefix = switchToPost(exp);
    string reversedExp = "";
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        reversedExp += exp[i];
    }
    return reversedExp;
}

int main()
{

    string exp;
    cout << "enter an infix expression : ";
    cin >> exp;
    string reversedInfix = reverseExp(exp);
    cout << "Reversed Infix: " << reversedInfix << endl;
    string postfix = switchToPost(reversedInfix);
    cout << "Postfix: " << switchToPost(exp) << endl;
    cout << "Prefix: " << reverseExp(postfix);

}