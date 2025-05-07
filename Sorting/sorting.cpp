#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min_idx = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubble_sort(int arr[], int n) {
    for(int i = n - 1; i >= 1; i--) {
        int swapped = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0) {
            break;
        }
    }
}

void insertion_sort(vector<int> &arr, int n) {
    for (int i = 1; i < n; i++) {
        int hold = arr[i];
        int j = i - 1;

        // Shift larger elements to the right
        while (j >= 0 && arr[j] > hold) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert hold in the correct position
        arr[j + 1] = hold;
    }
}

void merge(vector<int> &arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}



void merge_sort(vector<int> &arr, int low, int high) {
    if(low >= high) return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}


int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Values: ";
        cin >> arr[i];
    }
    // selection_sort(arr, n);
    // bubble_sort(arr,n);
    insertion_sort(arr, n);
    // merge_sort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}