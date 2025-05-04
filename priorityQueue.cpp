#include<iostream>
using namespace std;

struct pQueue{
    int data;
    pQueue*next;
    pQueue*prev;

};
pQueue* front = nullptr;
pQueue* rear = nullptr;

void push(int value){
    pQueue* ptr = new pQueue();
    ptr->data = value;
    ptr->next = ptr->next =  nullptr;

    if(front == nullptr){
        front = ptr;
        rear = front;
    }
    else{
        rear->next = ptr;
        rear->prev = rear;
        rear = rear->next;

    }

    pQueue* maxSort = rear;

        while(maxSort != nullptr){
            if(maxSort->data > maxSort->prev->data){
                pQueue* temp = maxSort->prev;
                maxSort->prev = maxSort->next;
                maxSort->next = maxSort->prev;

            }
                maxSort = maxSort->prev;
        }

    

}
int pop(){
    pQueue* temp = front;
    int value = temp->data;
    front = front->next;
    free(temp);
    cout<<value<<endl;
    return value;

}
main(){
    push(56);
    push(1);
    push(12);
    push(85);

    pop();
    pop();
    pop();
    pop();

}