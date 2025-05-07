// maxheap
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &heap)
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " \n";
    }
}
void insert(int value, vector<int> &heap)
{
    heap.push_back(value);
    int j = heap.size() - 1;

    while (j > 0)
    {
        if (heap[(j - 1) / 2] < heap[j])
        {
            int temp = heap[(j - 1) / 2];
            heap[(j - 1) / 2] = heap[j];
            heap[j] = temp;
            j = (j - 1) / 2;
        }
        else
        {
            break;
        }
    }
    print(heap);
}
void DeleteHeap(vector<int> &heap)
{
    if (heap.size() == 0)
    {
        cout << "Heap is empty!\n";
        return;
    }

    int last = heap.size() - 1;
    swap(heap[0], heap[last]); // Swap root with last
    heap.pop_back();           // Remove last

    int i = 0;
    int size = heap.size();

    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest])
        {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            i = largest;
        }
        else
        {
            break;
        }
    }

    print(heap);
}
// void heapSort(vector<int> &heap){
//     vector<int>sortedHeap;

//     int i = 0;
//     for(int k = 0 ; k < heap.size() ; k++){

//         int last = heap.size() - 1;
//         sortedHeap.push_back(heap[i]);
//         swap(heap[i], heap[last]); // Swap root with last
//         heap.pop_back();           // Remove last

//         int size = heap.size();

//         while (true)
//         {
//             int left = 2 * i + 1;
//             int right = 2 * i + 2;
//             int largest = i;

//             if (left < size && heap[left] > heap[largest])
//             {
//                 largest = left;
//             }
//             if (right < size && heap[right] > heap[largest])
//             {
//                 largest = right;
//             }

//             if (largest != i)
//             {
//                 swap(heap[i], heap[largest]);
//                 i = largest;
//             }
//             else
//             {
//                 break;
//             }
//         }

//     }

//     for(int i = 0 ; i < heap.size() ; i++){
//         cout<<sortedHeap[i]<<" ";
//     }

// }

void Heapfiy(vector<int> &heap, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && heap[left] > heap[largest])
    {
        largest = left;
    }
    if (right < n && heap[right] > heap[largest])
    {
        largest = right;
    }
    if (largest != i )   
    {
        swap(heap[i], heap[largest]);
        Heapfiy(heap, n, largest);
    }
}

void heapSort(vector<int> &heap, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(heap[0], heap[i]);
        Heapfiy(heap, i, 0);
    }

    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
}

int main()
{
    vector<int> heap;
    int value;
    int choice = 0;

    cout << "Welcome to Heap " << endl;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Heap Sort\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(value, heap);
            break;
        case 2:
            DeleteHeap(heap);
            break;
        case 3:
            heapSort(heap, heap.size());
            break;
        case 4:
            cout << "Exiting... Thank you!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}