#include <iostream>
#include <array>

using namespace std;

void insertionSort( array<int, 5> &arr, int n) // n is the size of the array
{
    int i, key, j;          // i is the index of the element to be inserted, key is the element to be inserted, j is the index of the element to be compared
    for (i = 1; i < n; i++) // i starts at 1 because the first element is already sorted
    {
        key = arr[i];                  // key is the element to be inserted
        j = i - 1;                     // j is the index of the element to be compared
        while (j >= 0 && arr[j] > key) // while the element to be compared is greater than the element to be inserted
        {
            arr[j + 1] = arr[j]; // shift the element to the right
            j = j - 1;           // decrement j
        }
        arr[j + 1] = key; // insert the element
    }
}

int main()
{
    array<int, 5> arr = {18, 23, 13, 47, 2};

    insertionSort(arr, 5);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
