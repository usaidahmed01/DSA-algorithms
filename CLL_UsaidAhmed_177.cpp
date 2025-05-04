//  Circular Linked List

#include <bits/stdc++.h>
using namespace std;

struct linkedList
{
    int data;
    linkedList *next;
};
linkedList *start = nullptr;

void insert()
{
    linkedList *ptr = (linkedList *)(malloc(sizeof(linkedList)));

    cout << "Enter Value: \n";
    cin >> ptr->data;

    if (start == nullptr)
    {
        start = ptr;
    }
    else
    {
        linkedList *current = start;

        while (current->next != start)
        {
            current = current->next;
        }
        current->next = ptr;
    }
    ptr->next = start;
}

void search()
{
    linkedList *current = start;
    int toSearch;
    bool flag = false;

    cout << "Enter the Value that you are searching for" << endl;
    cin >> toSearch;

    do
    {
        if (current->data == toSearch)
        {
            cout << toSearch << ". Value Found";
            flag = true;
        }
        current = current->next;

    } while (current != start);
    if (!flag)
        cout << "Value not found";
}

void print()
{
    linkedList *current = start;

    do
    {
        cout << current->data << endl;
        current = current->next;

    } while (current != start);
}

void deleteItem()
{
    cout << "Enter Value You wanna delete : \n";
    int toDel;
    cin >> toDel;

    if (start->data == toDel)
    {
        linkedList *temp = start;
        linkedList *last = start;
        
        do
        {
            last = last->next;
        } while (last->next != start); // get last value so that we can link the last item with the first element.
        start = start->next;
        last->next = start;

        cout << "Your Given Value has been deleted. ";

        free(temp); // deallocate the memory
    }
    else
    {
        linkedList *prev = start;
        linkedList *current = start->next;

        while (current != start)
        {
            if (current->data == toDel)
            {
                prev->next = current->next; // Link previous next with current next because current is to be deleted

                free(current);
                cout << "Your Given Value has been deleted. ";
                return;
            }
            prev = prev->next;
            current = current->next;
        }
        cout << "Your Deleted value is not present in the list. ";
    }
}

main()
{
    cout << "Welcome To Circular Linked List: " << endl;
    cout << "Press 1 to Insert Value: \n Press 2 to Search Value: \n Press 3 to Print Value: \n Press 4 to Delete Value: \n Press 5 to Exit the program: \n";
    int InpVal;
    cin >> InpVal;
    while (InpVal < 5)
    {
        if (InpVal == 1)
        {

            insert();
            InpVal = 5;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n Press 5 to Exit the program: \n";
            cin >>
                InpVal;
        }

        if (InpVal == 2)
        {

            search();
            InpVal = 5;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n Press 5 to Exit the program: \n";
            cin >>
                InpVal;
        }
        if (InpVal == 3)
        {

            print();
            InpVal = 5;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n Press 5 to Exit the program: \n";
            cin >>
                InpVal;
        }
        if (InpVal == 4)
        {

            deleteItem();
            InpVal = 5;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n Press 5 to Exit the program: \n";
            cin >>
                InpVal;
        }
    }
}