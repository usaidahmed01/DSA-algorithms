#include <bits/stdc++.h>
using namespace std;

struct dstack
{
    int data;
    dstack *next;
};
dstack *top = nullptr;

void push(int value)
{
    dstack *userptr = (dstack *)malloc(sizeof(dstack));
    userptr->data = value;
    userptr->next = top;
    top = userptr;
}

int pop()
{
    if (top == nullptr)
    {
        return 0;
    }
    else
    {
        int value = top->data;
        dstack *temp = top;
        top = top->next;

        free(temp);

        return value;
    }
}

void print()
{
    dstack *current = top;

    if (top == nullptr)
    {
        cout << "Stack is Empty.";
        return ;
    }

    cout << "Your List: " << endl;
    //    cout<<current->data<<endl;
    //    cout<<current->next->data;
    while (current != nullptr)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

main()
{
    cout << "Welcome To Stack" << endl;
    cout << "Press 1 to Push a Value: \n Press 2 to Pop a Value: \n Press 3 to Print Value: \n Press 4 to Exit the program: \n";
    int InpVal;
    cin >> InpVal;
    while (InpVal < 4)
    {
        if (InpVal == 1)
        {
            cout << "Enter Value ";
            int val;
            cin >> val;

            push(val);
            InpVal = 4;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Push a value : \n Press 2 to Pop a value: \n Press 3 to Print Value : \n Press 4 to Exit the program: \n";
            cin >>
                InpVal;
        }

        if (InpVal == 2)
        {

            InpVal = 4;
            int popVal = pop();
            (popVal == 0 ) ? (cout << "Stack is Empty.")
                :
                 (cout<<"Popped Value is " << popVal);
                cout << endl
                     << endl
                     << "Choose Operation: \n  Press 1 to Push a Value : \n Press 2 Pop a Value :\n Press 3 to Print Value : \n Press 4 to Exit the program: \n";
                cin >>
                    InpVal;
        }

        if (InpVal == 3)
        {

            print();
            InpVal = 4;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Push a Value : \n Press 2 Pop a Value :\n Press 3 to Print Value : \n Press 4 to Exit the program: \n";
            cin >>
                InpVal;
        }
    }
}