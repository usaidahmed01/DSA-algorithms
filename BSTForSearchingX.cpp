// Predecessor And Successor


#include <iostream>
#include<vector>
using namespace std;

void minHeap(float val , vector<float> &heap){
    heap.push_back(val);
    int j = heap.size() - 1;

    while(j > 0){
        if(heap[j] < heap[(j - 1) / 2]){
            swap(heap[(j - 1) / 2] , heap[j]);
            j = (j - 1) / 2;
        }
        else{
            break;
        }
    }
    
    // Print

    for(int i = 0 ; i < heap.size() ; i++){
        cout<<i<< " " <<heap[i]<<endl;
    }

}
int findVal(float val , vector<float>&heap){
    for(int i = 0 ; i < heap.size() ; i++){
        if(val == heap[i]){
            cout<<"Value Found at "<<i<<endl;
            return i;
        } 
    }
    cout<<"Value not found"<<endl;
    return -1;
}


main(){
    vector<float>heap;
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
    cout<<"Total Number of Nodes "<<heap.size()<<endl;
    cout<<"Enter Value for its exsistence ";
    float toSearch;
    cin>>toSearch;
    int xValue =  findVal(toSearch , heap);

    if(xValue == 0) cout<<"no Predecessor."<<endl;
    cout<<"Predecessor of "<<heap[xValue]<< " "<<heap[xValue - 1]<<endl;

    if(xValue == heap.size() - 1) cout<<"No Successor."<<endl;
    cout<<"Successor of "<<heap[xValue]<< " "<<heap[xValue + 1]<<endl;

}