#include <iostream>
using namespace std;


// Custom function to swap two elements
void customSwap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first unsorted element is the smallest

        // Find the index of the smallest element in the unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the smallest element with the first unsorted element
        if (minIndex != i) {
            customSwap(arr[i], arr[minIndex]);
        }
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

    selectionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}