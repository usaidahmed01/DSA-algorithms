#include<iostream>
#include<array>
using namespace std;

int main (){
    array<int,6>arr = {80 , 45 , 67 ,80 , 90};
    int toSearch , counter{0};

    cin>> toSearch;

    for (int i = 0; i < arr.size() ; i++){
        if (arr[i] == toSearch){
            counter++;
        }
    }
    cout<<counter <<" times Value is present";


    // for (int i = 0; i < arr.size() ; i++)
    // {
    //     if (arr[i] == toSearch)
    //     {
    //         cout << "Element is found at index " << i << endl;
    //         break;
    //     }
        
    // }
    
}