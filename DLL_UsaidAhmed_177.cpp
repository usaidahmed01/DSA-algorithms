// Doubling Linked List

#include <bits/stdc++.h>
using namespace std;

struct linkedList
{
   int data;
   linkedList *next;
   linkedList *prev;
};
linkedList *start = nullptr;

void insert()
{
   linkedList *ptr = (linkedList *)(malloc(sizeof(linkedList)));
	    

   cout << "Enter Value: \n";
   cin >> ptr->data;
   ptr->next = nullptr;
   ptr->prev = nullptr;
   
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
        current->prev = current;
        current->next = ptr;
    }
}

void search(){
	linkedList *current = start;
	int toSearch;
	bool flag = false;
	
	cout<<"Enter the Value that you are searching for"<<endl;
	cin>> toSearch;
	
	while(current != nullptr){
		if(current->data == toSearch){
			cout<< toSearch << ". Value Found";
			flag = true;
		} current = current->next;	
	}
		if(!flag) cout<< "Value not found";
	
}

void print()
{
    linkedList* current = start;

    while (current != nullptr){
        cout << current->data << endl;
        current = current->next;
    }
    
}


void deleteItem(){
    cout<< "Enter Value You wanna delete : \n";
    int toDel;
    cin>>toDel;

    if(start->data == toDel){
        linkedList* temp = start;
        start = start->next;

        cout<<"Your Given Value has been deleted. ";
        
        free(temp); // deallocate the memory 
    }else
    {
        // linkedList* prevptr = start;
        linkedList* current = start ->next;

        while (current != nullptr)
        {
            if(current->data == toDel){
                current->prev->next = current->next;
                current->next->prev = current->prev;
                // prevptr->next = current->next; // Link previous next with current next because current is to be deleted
                // current->next->prev = prevptr;

                free(current);
                cout<<"Your Given Value has been deleted. ";
                return;
            }
            // prevptr = prevptr->next;
            current = current->next;
        }
        cout<<"Your Deleted value is not present in the list. ";
        
    }
}

main()
{
    cout << "Welcome To Linked List: " << endl;
    cout << "Press 1 to Insert Value: \n Press 2 to Search Value: \n Press 3 to Print Value: \n Press 4 to Delete Value: \n Press 5 to Exit the program: \n" ;
    int InpVal;
    cin >> InpVal;
    while (InpVal < 5)
    {
        if (InpVal == 1)
        {

        insert();
        InpVal = 6;
        cout <<endl << endl<< "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n Press 5 to Exit the program: \n";
        cin >>
        InpVal;
        }

        if (InpVal == 2)
        {

            search();
            InpVal = 6;
            cout <<endl << endl<< "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n Press 5 to Print the Reverse List: \n Press 6 to Exit the program: \n";
            cin >>
            InpVal;
        }
        if (InpVal == 3)
        {

            print();
            InpVal = 6;
            cout <<endl << endl<< "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n Press 5 to Exit the program: \n";
            cin >>
            InpVal;
        }
        if (InpVal == 4)
        {

            deleteItem();
            InpVal = 6;
            cout <<endl << endl<< "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n  Press 4 to Delete Value: \n Press 5 to Exit the program: \n";
            cin >>
            InpVal;
        }
    }
}

