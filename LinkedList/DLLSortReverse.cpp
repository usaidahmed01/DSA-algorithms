// #include<iostream>
// using namespace std;

// struct linkedList
// {
//    int data;
//    linkedList *next;
//    linkedList *prev;
//    int index = 0;
// };
// linkedList *start = nullptr;
// linkedList* lastNode = start;

// int partition(int left , int right){
//     int pivot = start->data;
//     int startIndex = left;
//     int end = right;


//     linkedList*crnt = start;
//     while(startIndex < end && crnt != nullptr && lastNode != nullptr){
//         while(crnt->data < pivot){
//             crnt = crnt->next;
//             startIndex++;
//         }
//         while(lastNode->data > pivot){
//             lastNode = lastNode->prev;
//             end--;
//         }
//         if(startIndex < end && crnt != nullptr && lastNode != nullptr) swap(crnt->data , lastNode->data);
//     }
//     swap(pivot , lastNode->data);
//     return lastNode->index;
// }
// void quickSort(int left , int right){
//     int pivot = partition(left , right);

//     if(left >= right) return;

//     quickSort(left , pivot - 1);
//     quickSort(pivot + 1 , right);

// }

// void insert()
// {
//    linkedList *ptr = (linkedList *)(malloc(sizeof(linkedList)));
	    

//    cout << "Enter Value: \n";
//    cin >> ptr->data;
//    ptr->next = nullptr;
//    ptr->prev = nullptr;
   
//    if (start == nullptr)
//    {
//        start = ptr;
//        start->index = 0;
//     }
//     else
//     {
//         linkedList *current = start;
        
//         while (current->next != nullptr)
//         {
//             current = current->next;
//         }
//         current->prev = current;
//         current->next = ptr;
//         current->next->index = current->index + 1;
//         lastNode = current->next;

//         quickSort(0 ,lastNode->index);
//     }

// }


// void print()
// {
//     linkedList* current = start;

//     while (current != nullptr){
//         cout << current->data <<" index " << current->index << endl;
//         current = current->next;
//     }
    
// }

// main(){
//     insert();
//     insert();
//     insert();
//     insert();
//     cout<<endl;

//     print();


// }






















#include<iostream>
using namespace std;

struct linkedList {
    int data;
    linkedList *next;
    linkedList *prev;
};

linkedList *start = nullptr;
linkedList* lastNode = nullptr;

// Function to partition the list
linkedList* partition(linkedList* left, linkedList* right) {
    int pivot = left->data;
    linkedList* i = left;
    linkedList* j = right;

    while (i != j) {
        while (i != j && j->data >= pivot)
            j = j->prev;
        while (i != j && i->data <= pivot)
            i = i->next;
        if (i != j)
            swap(i->data, j->data);
    }

    swap(left->data, i->data); // Place pivot at its correct position
    return i;
}

void quickSort(linkedList* left, linkedList* right) {
    if (left == nullptr || right == nullptr || left == right || right->next == left)
        return;

    linkedList* pivot = partition(left, right);
    if (pivot != nullptr && pivot->prev != nullptr)
        quickSort(left, pivot->prev);
    if (pivot != nullptr && pivot->next != nullptr)
        quickSort(pivot->next, right);
}

void insert() {
    linkedList *ptr = new linkedList();
    cout << "Enter Value: \n";
    cin >> ptr->data;
    ptr->next = nullptr;

    if (start == nullptr) {
        start = ptr;
        lastNode = ptr;
    } else {
        lastNode->prev = lastNode;
        lastNode->next = ptr;
        lastNode = lastNode->next;

        // ptr->prev = lastNode;
        // lastNode = ptr;
    }

    // Sort after every insertion
    quickSort(start, lastNode);
}

void print() {
    linkedList* current = start;
    int index = 0;
    while (current != nullptr) {
        cout << current->data << " index " << index++ << endl;
        current = current->next;
    }
}

void copyReverseList(){
    cout<<"Reverse."<<endl;
    linkedList* reverseList = new linkedList();
    reverseList->data = lastNode->data;
    reverseList->next = reverseList->prev = nullptr;

    
    linkedList *crnt = reverseList;
    linkedList *crntLast = lastNode->prev;  
    
    while(crntLast != nullptr){

        while(crnt->next != nullptr){
            crnt = crnt->next;
        }
        linkedList*ptr = new linkedList();
        ptr->data = crntLast->data;
        ptr->next = ptr->prev = nullptr;

        crnt->prev = crnt;
        crnt->next = ptr;

        crntLast = crntLast->prev;

    }

    // Print 

    linkedList* crntFP = reverseList;
    while(crntFP != nullptr){
        cout<<crntFP->data<<" ";
        crntFP = crntFP->next;
    }
}

void reverseMain(){
    linkedList *crnt = start;
    linkedList *temp = nullptr;

    while(crnt != nullptr){
        temp = crnt->prev;
        crnt->prev = crnt->next;
        crnt->next = temp;

        crnt = crnt->prev;
    }
    if(temp != nullptr) start = temp->prev;

    // print

    linkedList* crntFP = start;
    while(crntFP != nullptr){
        cout<<crntFP->data<<" ";
        cout<<endl;
        crntFP = crntFP->next;
    }
}


int main() {
    insert();
    insert();
    insert();
    insert();
    cout << endl;
    print();
    cout << endl;
    // copyReverseList();
    // reverseMain();

    return 0;
}

