#include<iostream>
#include<vector>
using namespace std;

struct heapNode{
    float data;
};

void minHeap(float val , vector<heapNode*>&heap){
    heapNode*ptr = new heapNode();
    ptr->data = val;
    heap.push_back(ptr);

    int index = heap.size() - 1;
    while(index > 0){
        if(heap[index]->data < heap[(index - 1) / 2]->data){
            swap(heap[index] , heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        else{
            break;
        }
    }

    //Print

    for(int i = 0 ; i < heap.size() ; i++){
        cout<<i<<" "<<heap[i]->data<<endl;
    }
}
void mirrorHeap(vector<heapNode*>&heap){
    int i = 0;
    int size = heap.size();

    while(i < size){
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(right == size){
            heapNode*ptr = new heapNode();
            ptr->data = heap[left]->data;
            heap[left]->data = 0;
            heap.push_back(ptr);
            break;
    
        }

        heapNode* temp = heap[left];
        heap[left] = heap[right];
        heap[right] = temp;



        i++;

        
    }


    for(int i = 0 ; i < heap.size() ; i++){
        if(heap[i]->data == 0){
            continue;
        } else{
            cout<<i <<" "<<heap[i]->data<<endl;
        }
    }
}

main(){
    vector<heapNode*>heap;
    bool flag = false;

    while(!flag){
        cout<<"Enter Value ";
        float val;
        cin>>val;
        minHeap(val , heap);

        cout<<"press x to break ";
        char ch;
        cin>>ch;
        if(ch == 'x') flag = true;
    }
    mirrorHeap(heap);

}