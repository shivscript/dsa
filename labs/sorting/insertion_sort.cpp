#include <iostream>
using namespace std;

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // The element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Insert the key at the correct position
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {7, 3, 5, 2, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
