#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 5> arr = {18, 23, 13, 47, 2};

    for (int i = 1; i < arr.size(); i++)
    {
        int hold = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > hold)
            {
                arr[j + 1] = arr[j];
                arr[j] = hold;
            }else{
                break;
            }
        }

    }

    for(int i = 0 ; i < arr.size() ; i++){
        cout<<arr[i]<<" ";
    }
}