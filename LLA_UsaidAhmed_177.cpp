
//  Conditional List

#include<iostream>
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
   ptr->next = nullptr;

   if (start == nullptr){
    if(ptr->data % 3 == 1){
        start = ptr;
        linkedList *current = start; // to insert copy value

        linkedList *newptr = (linkedList *)(malloc(sizeof(linkedList)));
        newptr->data = ptr->data;
        newptr->next = nullptr;

        current->next = newptr;


    }else if(ptr->data % 3 == 2){
        start = ptr;
        linkedList *current = start; // to insert copy value

        linkedList *newptr1 = (linkedList *)(malloc(sizeof(linkedList)));
        newptr1->data = ptr->data;
        newptr1->next = nullptr;
        
        current->next = newptr1;

        linkedList *newptr2 = (linkedList *)(malloc(sizeof(linkedList)));
        newptr1->data = ptr->data;
        newptr1->next = nullptr;

        current = current->next;
        current->next = newptr2;

    }
    else{
        start = ptr;
    }
   }
   else
   {
       linkedList *current = start;

       while (current->next != nullptr)
       {
           current = current->next;
       }

       if(ptr->data % 3 == 0){
        current->next = ptr;
       }
       if(ptr->data % 3 == 1){
           current->next = ptr;

        // create new pointer that can store the copy
        linkedList *newptr = (linkedList*)(malloc(sizeof(linkedList)));
        newptr->data = ptr->data;
        newptr->next = nullptr;

        current = current->next; 
        current->next = newptr; // the copy of element is inserted
       }
       if(ptr->data % 3 == 2){
           current->next = ptr;

        linkedList *newptr1 = (linkedList*)(malloc(sizeof(linkedList)));
        linkedList *newptr2 = (linkedList*)(malloc(sizeof(linkedList)));
        

        newptr1->data = ptr->data;
        newptr1->next = nullptr;
        current = current->next;
        current->next = newptr1;

        newptr2->data = ptr->data;
        newptr2->next = nullptr;
        current = current->next;
        current->next = newptr2;
           
       }
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
            break;
		} current = current->next;	
	}
		if(!flag) cout<< "Value not found";
	
}

void print()
{
   linkedList *current = start;

   while (current != nullptr)
   {
        cout<<"Your List: "<<endl;
       cout << current->data << endl;
       current = current->next;
   }
}



main()
{
    cout << "Welcome To Linked List: " << endl;
    cout << "Press 1 to Insert Value: \n Press 2 to Search Value: \n Press 3 to Print Value: \n Press 4 to Exit the program: \n";
    int InpVal;
    cin >> InpVal;
    while (InpVal < 4)
    {
        if (InpVal == 1)
        {

            insert();
            InpVal = 5;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n Press 4 to Exit the program: \n";
            cin >>
                InpVal;
        }

        if (InpVal == 2)
        {

            search();
            InpVal = 5;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n Press 4 to Exit the program: \n";
            cin >>
                InpVal;
        }
        if (InpVal == 3)
        {

            print();
            InpVal = 5;
            cout << endl
                 << endl
                 << "Choose Operation: \n  Press 1 to Insert Value : \n Press 2 to Search Value : \n Press 3 to Print Value : \n Press 4 to Exit the program: \n";
            cin >>
                InpVal;
        }
    }
}