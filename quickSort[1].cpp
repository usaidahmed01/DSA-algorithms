#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int start = low;
    int end = high;
    while(start < end) {
        while(arr[start] <= pivot) {
            start++;
        }
        while(arr[end] > pivot) {
            end--;
        }
        if(start < end) {   
        swap(arr[start], arr[end]);
        }
    }
    swap(arr[low], arr[end]);
    return end;
}

void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int partitionIndex = partition(arr, low, high);
        quick_sort(arr, low, partitionIndex - 1);
        quick_sort(arr, partitionIndex + 1, high);
    }

}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << endl;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter data: ";
        cin >> arr[i];
    }
    cout << endl;
    quick_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}