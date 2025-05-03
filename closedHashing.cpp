#include <bits/stdc++.h>
using namespace std;

int hashFunc(int key){
    return key % 5;
}

void insert(int arr[] , int key){
    int index = hashFunc(key);
    int index2 = index;
    
        do{
            
            if(arr[index2] == -1){
                arr[index2] = key;
                return;
            }
            index2 ++;
            if(index2 == 5){
                index2 = 0;
            }
        }while(index2 != index );
        cout<<"HASH IS FULL" <<endl;
}

void search (int arr[] , int key){
    int index = hashFunc(key);
    int index2 = index;
    
        do{
            
            if(arr[index2] == key){
                cout<<key << "Value is found"<<endl;
                return;
            }
            index2 ++;
            if(index2 == 5){
                index2 = 0;
            }
        }while(index2 != index);
        cout<<endl<<"Value IS NOT Found." <<endl;
}

main(){
    int arr[5] = { -1 , -1 , -1 , -1 , -1};
    int size = (sizeof(arr) / sizeof(arr[0]));
    int key;
    while(true){
        cout<<"Enter Value: "<<endl;
        cin>>key;
        insert(arr , key);

        for(int i = 0 ; i < size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"Search Value"<<endl;
        int toSearch;
        cin>>toSearch;
        search(arr , toSearch);
    }

}