
// Using double linkedlist
// 1. Insert Node
// 2. Delete Node
// 3. Print Nodes

// Find Min & move it to first Node...
// Find Max & move it to last Node...
// Find total no. of Nodes...
// Find the middle value of the linkedlist...




#include <iostream>
using namespace std;

struct dLinkedList
{
    int data;
    dLinkedList *next;
    dLinkedList *prev;
};
dLinkedList *startDLL = nullptr;

void insert(int val)
{
    dLinkedList* ptr = new dLinkedList();
    ptr->data = val;
    ptr->next = nullptr;
    ptr->prev = nullptr;

    if(startDLL == nullptr){
        startDLL = ptr;
        cout<<"Value has inserted."<<endl;
        return;
    }

    dLinkedList* crnt = startDLL;
    while (crnt->next != nullptr)
    {
        crnt = crnt->next;
    }
    crnt->prev = crnt;
    crnt->next = ptr;
    cout<<"Value has inserted."<<endl;

    
}

void deleteNode(int val)
{
    if(startDLL == nullptr){
        cout<<"Please insert first "<<endl;
        return;
    }

    dLinkedList *crnt = startDLL;
    while(crnt != nullptr){
        if(crnt->data == val){
            crnt->prev->next = crnt->next;
            crnt->next->prev = crnt->prev;
            free(crnt);
            cout<<"Your Given Value has been Deleted."<<endl;
            return;
        }
        crnt = crnt->next;
    }
    cout<<"Value Not found."<<endl;



}

void findMin(){
    dLinkedList* minNode = startDLL;

    dLinkedList* crnt = startDLL;

    while(crnt != nullptr){
        if(crnt->data < minNode->data){
            minNode = crnt;
        }
        crnt = crnt->next;
    }

    swap(minNode->data , startDLL->data);

}

void findMaxAndMiddle(){
    int totalNodes = 1;
    dLinkedList* lastNode = startDLL;
    while (lastNode->next != nullptr)
    {
        lastNode = lastNode->next;
        totalNodes++;
    }

    dLinkedList* maxNode = lastNode;

    dLinkedList* crnt = startDLL;

    while(crnt != nullptr){
        if(crnt->data > maxNode->data){
            maxNode = crnt;
        }
        crnt = crnt->next;
    }

    swap(maxNode->data , lastNode->data);

    dLinkedList* middleNode = startDLL;
    for(int i = 1 ; i <= totalNodes / 2 ; i++){
        middleNode = middleNode->next;
    }

    cout<<"Total Nodes are "<<totalNodes<<endl;
    cout<<"Middle Node is "<<middleNode->data<<endl;

}

void print()
{
    dLinkedList *crnt = startDLL;

    while (crnt != nullptr)
    {
        cout << crnt->data << " ";
        crnt = crnt->next;
    }
}


int main()
{
    insert(60);
    insert(22);
    insert(12);
    insert(78);
    insert(20);

    // findMin();
    // findMaxAndMiddle();

    print();
    return 0;
}

