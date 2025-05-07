#include<iostream>
#include<array>

using namespace std;

main (){
    array<int, 9> arr = {15, 50, 53, 78 , 80 , 88 , 550 , 1240 , 6877};
    int left = 0 ;
    int right = arr.size() - 1;
    int toSearch;
    cin>> toSearch;
    bool flag = false;

    // bubbleSort(&arr);




    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (toSearch == arr[mid])
        {
            cout<< "Value Found at "<<mid << " index.";
            flag = true;
        }
        

        if (toSearch < arr[mid])
        {
            right = mid - 1;
        }else{
            left = mid + 1;
        }

        
    }
    if(!flag) cout<<"Value is not found";
        
}

// void bubbleSort(array<int , 9>arr){
//     for (int i = 0; i < arr.size() - 1; i++){    
//         for (int j = 0; j < arr.size() - 1; j++){
//            if(arr[j] > arr[j + 1]){
//                 int temp = arr[j + 1];
//                 arr[j + 1] = arr[j];
//                 arr[j] = temp;
//             }
//         }
        
//     }

// }


