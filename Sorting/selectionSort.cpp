#include<iostream>
#include<array>

using namespace std;

int main (){
    array<int, 5> arr = {18, 23, 13, 47 , 2};

    for(int i = 0 ; i < arr.size() ; i++){
        int minIndex = i;
        for(int j = i + 1 ; j < arr.size(); j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[minIndex] , arr[i]);
    }
    
}