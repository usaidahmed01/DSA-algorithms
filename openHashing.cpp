#include <bits/stdc++.h>
using namespace std;

struct hashing {
    int data;
    hashing* next;
};

int hashFunc(int key) {
    return key % 5;
}

void insert(hashing* arr[], int key) {
    int index = hashFunc(key);
    hashing* ptr = new hashing();
    ptr->data = key;
    ptr->next = nullptr;

    if (arr[index] == nullptr) {
        arr[index] = ptr;
    } else {
        hashing* temp = arr[index];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void search(hashing* arr[], int key) {
    int index = hashFunc(key);
    hashing* temp = arr[index];

    while (temp != nullptr) {
        if (temp->data == key) {
            cout << key << " Value is found" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << endl << "Value IS NOT Found." << endl;
}

int main() {
    hashing* arr[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    int key;
    while (true) {
        cout << "Enter Value (or -1 to exit): " << endl;
        cin >> key;
        if (key == -1) break;
        insert(arr, key);

        for (int i = 0; i < 5; i++) {
            hashing* temp = arr[i];
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << " | "; 
        }
        cout << endl;

        cout << "Search Value" << endl;
        int toSearch;
        cin >> toSearch;
        search(arr, toSearch);
    }


    return 0;
}
