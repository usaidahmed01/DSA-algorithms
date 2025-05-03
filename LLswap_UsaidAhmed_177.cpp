#include <bits/stdc++.h>
using namespace std;

//					Singular Linked List

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
    ptr->next = nullptr;

    if (start == nullptr)
    {
        start = ptr;
    }
    else
    {
        linkedList *current = start;

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = ptr;
    }
}

void search()
{
    linkedList *current = start;
    int toSearch;
    bool flag = false;

    cout << "Enter the Value that you are searching for" << endl;
    cin >> toSearch;

    while (current != nullptr)
    {
        if (current->data == toSearch)
        {
            cout << toSearch << ". Value Found";
            flag = true;
        }
        current = current->next;
    }
    if (!flag)
        cout << "Value not found";
}

void print()
{
    linkedList *current = start;

    cout << "Your List: " << endl;
    while (current != nullptr)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

void deleteItem()
{
    cout << "Enter Value You wanna delete : \n";
    int toDel;
    cin >> toDel;

    if (start->data == toDel)
    {
        linkedList *temp = start;
        start = start->next;

        cout << "Your Given Value has been deleted. ";

        free(temp); // deallocate the memory
    }
    else
    {
        linkedList *prev = start;
        linkedList *current = start->next;

        while (current != nullptr)
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

void swap()
{
    cout << "Enter First Value: ";
    int val1;
    cin >> val1;

    cout << "Enter Second Value: ";
    int val2;
    cin >> val2;

    if (start->data == val1)
    {
        linkedList *temp;
        linkedList *perv = start;
        linkedList *current = start->next;
        linkedList *ptr2, *pervVal;

        while (current != nullptr)
        {
            if (current->data == val2)
            {
                ptr2 = current;
                pervVal = perv;
                break;
            }
            perv = perv->next;
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Inputted value is not exist in the list.";
            return;
        }
            
        start->next = ptr2->next;
        ptr2->next = temp;
        pervVal->next = start;
        
        // Update start pointer if swapping first element
        start = ptr2;


    }
    else
    {

        linkedList *current = start->next;
        linkedList *prev = start;
        linkedList *ptr1, *ptr2, *temp, *prevVal1, *prevVal2;

        while (current != nullptr)
        {
            if (current->data == val1)
            {
                ptr1 = current;
                prevVal1 = prev;
            }
            if (current->data == val2)
            {
                ptr2 = current;
                prevVal2 = prev;
                break;
            }
            prev = prev->next;
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Inputted value is not exist in the list.";
        }

        prevVal1->next = ptr2;
        prevVal2->next = ptr1;

        temp = ptr1->next;
        ptr1->next = ptr2->next;
        ptr2->next = temp;
    }
}

//																					 Conditional List

// struct linkedList
// {
//    int data;
//    linkedList *next;
// };
// linkedList *start = nullptr;

// void insert()
// {
//    linkedList *ptr = (linkedList *)(malloc(sizeof(linkedList)));

//    cout << "Enter Value: \n";
//    cin >> ptr->data;
//    ptr->next = nullptr;

//    if (start == nullptr){
//     if(ptr->data % 3 == 1){
//         start = ptr;
//         linkedList *current = start; // to insert copy value

//         linkedList *newptr = (linkedList *)(malloc(sizeof(linkedList)));
//         newptr->data = ptr->data;
//         newptr->next = nullptr;

//         current->next = newptr;

//     }else if(ptr->data % 3 == 2){
//         start = ptr;
//         linkedList *current = start; // to insert copy value

//         linkedList *newptr1 = (linkedList *)(malloc(sizeof(linkedList)));
//         newptr1->data = ptr->data;
//         newptr1->next = nullptr;

//         current->next = newptr1;

//         linkedList *newptr2 = (linkedList *)(malloc(sizeof(linkedList)));
//         newptr1->data = ptr->data;
//         newptr1->next = nullptr;

//         current = current->next;
//         current->next = newptr2;

//     }
//     else{
//         start = ptr;
//     }
//    }
//    else
//    {
//        linkedList *current = start;

//        while (current->next != nullptr)
//        {
//            current = current->next;
//        }

//        if(ptr->data % 3 == 0){
//         current->next = ptr;
//        }
//        if(ptr->data % 3 == 1){
//            current->next = ptr;

//         // create new pointer that can store the copy
//         linkedList *newptr = (linkedList*)(malloc(sizeof(linkedList)));
//         newptr->data = ptr->data;
//         newptr->next = nullptr;

//         current = current->next;
//         current->next = newptr; // the copy of element is inserted
//        }
//        if(ptr->data % 3 == 2){
//            current->next = ptr;

//         linkedList *newptr1 = (linkedList*)(malloc(sizeof(linkedList)));
//         linkedList *newptr2 = (linkedList*)(malloc(sizeof(linkedList)));

//         newptr1->data = ptr->data;
//         newptr1->next = nullptr;
//         current = current->next;
//         current->next = newptr1;

//         newptr2->data = ptr->data;
//         newptr2->next = nullptr;
//         current = current->next;
//         current->next = newptr2;

//        }
//    }
// }

// void search(){
// 	linkedList *current = start;
// 	int toSearch;
// 	bool flag = false;

// 	cout<<"Enter the Value that you are searching for"<<endl;
// 	cin>> toSearch;

// 	while(current != nullptr){
// 		if(current->data == toSearch){
// 			cout<< toSearch << ". Value Found";
// 			flag = true;
//             break;
// 		} current = current->next;
// 	}
// 		if(!flag) cout<< "Value not found";

// }

// void print()
// {
//    linkedList *current = start;

//    while (current != nullptr)
//    {
//         cout<<"Your List: "<<endl;
//        cout << current->data << endl;
//        current = current->next;
//    }
// }

main()
{
    cout << "Welcome To Linked List: " << endl;
    cout << "Press 1 to Insert Value: \n Press 2 to Search Value: \n Press 3 to Print Value: \n Press 4 to Delete Value: \n Press 5 to Exit the program: \n";
    int InpVal;
    cin >> InpVal;
    while (InpVal < 6)
    {
        if (InpVal == 1)
        {

            insert();
            InpVal = 6;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n  Press 5 to Swap two Values: \n Press 6 to Exit the program: \n";
            cin >>
                InpVal;
        }

        if (InpVal == 2)
        {

            search();
            InpVal = 6;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n  Press 5 to Swap two Values: \n Press 6 to Exit the program: \n";
            cin >>
                InpVal;
        }
        if (InpVal == 3)
        {

            print();
            InpVal = 6;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n  Press 5 to Swap two Values: \n Press 6 to Exit the program: \n";
            cin >>
                InpVal;
        }
        if (InpVal == 4)
        {

            deleteItem();
            InpVal = 6;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n  Press 5 to Swap two Values: \n Press 6 to Exit the program: \n";
            cin >>
                InpVal;
        }
        if (InpVal == 5)
        {

            swap();
            InpVal = 6;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n  Press 5 to Swap two Values: \n Press 6 to Exit the program: \n";
            cin >>
                InpVal;
        }
    }
}
