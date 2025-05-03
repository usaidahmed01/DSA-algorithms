#include<iostream>
#include<array>

using namespace std;

int main (){
    array<int, 9> arr = {98, 56, 35, 78 , 68 , 8 , 5 , 12, 888 };

    for(int i = 1 ; i < arr.size() - 1 ; i++){
        for(int j = 0; j < arr.size(); j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j] , arr[j + 1]);
            }
        }
    }

    

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

}


