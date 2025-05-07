#include <iostream>
using namespace std;

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];

    // pivot right postion
    int countSmallElements = 0 ;
    for (int i = left + 1; i <= right; i++){
        if (arr[i] <= pivot) {
            countSmallElements++;
        }
    }

    int pivotIndex = left + countSmallElements;
    // swap pivot element with element at pivotIndex
    swap(arr[left], arr[pivotIndex]);

    // for Left and Right Element of the pivot at the right place:
    int i = left  , j = right ;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] > arr[pivotIndex]){
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
}

void quickSort(int arr[], int left, int right)
{
    // pivot at the right position (all smallers and greaters are at left and right positions respectively)
    int pivot = partition(arr, left, right);

    if (left >= right)
        return;

    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
}

main()
{
    int arr[] = {34, 12, 65, 45, 10};
    int size = (sizeof(arr) / sizeof(arr[0]));
    int left = 0;
    int right = size - 1;
    quickSort(arr, left, right);
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
