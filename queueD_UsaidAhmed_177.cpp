#include <bits/stdc++.h>
using namespace std;

struct dqueue
{
    int data;
    dqueue *next;
};
dqueue *front = nullptr;
dqueue *rear = nullptr;

void enQueue(int value)
{
    dqueue *userptr = (dqueue *)malloc(sizeof(dqueue));
    userptr->data = value;
    userptr->next = nullptr;

    if (front == nullptr)
    {
        front = userptr;
        rear = userptr;
    }
    else
    {
        rear->next = userptr;
        rear = rear->next;
    }
}

int deQueue()
{
    if (front == nullptr)
    {
        return 0;
    }
    else
    {
        int value = front->data;
        dqueue *temp = front;
        front = front->next;
        

        free(temp);

        return value;
    }
}

void print()
{
    dqueue *current = front;

    if (front == nullptr)
    {
        cout << "Queue is Empty";
        return;
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
    cout << "Welcome To Queue" << endl;
    cout << "Press 1 to EnQueue a Value: \n Press 2 to DeQueue a Value: \n Press 3 to Print Value: \n Press 4 to Exit the program: \n";
    int InpVal;
    cin >> InpVal;
    while (InpVal < 4)
    {
        if (InpVal == 1)
        {
            cout << "Enter Value ";
            int val;
            cin >> val;

            enQueue(val);
            InpVal = 4;
            cout << endl
                 << endl
                 << "Choose Operation: \n Press 1 to EnQueue a Value: \n Press 2 to DeQueue a Value: \n Press 3 to Print Value: \n Press 4 to Exit the program: \n";
            cin >>
                InpVal;
        }

        if (InpVal == 2)
        {

            InpVal = 4;
            int deque = deQueue();
            (deque == 0) ? (cout << "Queue is Empty")
                    :
                    (cout<< "The DeQueue value is "<< deque);
                    cout << endl
                         << endl
                         << "Choose Operation: \n Press 1 to EnQueue a Value: \n Press 2 to DeQueue a Value: \n Press 3 to Print Value: \n Press 4 to Exit the program: \n";
                    cin >>
                        InpVal;
        }

        if (InpVal == 3)
        {

            print();
            InpVal = 4;
            cout << endl
                 << endl
                 << "Choose Operation: \n Press 1 to EnQueue a Value: \n Press 2 to DeQueue a Value: \n Press 3 to Print Value: \n Press 4 to Exit the program: \n";
            cin >>
                InpVal;
        }
    }
}