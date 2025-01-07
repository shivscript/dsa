#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) 
            return mid; // Key found

        if (arr[mid] < key)
            left = mid + 1; // Ignore left half
        else
            right = mid - 1; // Ignore right half
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {2, 3, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;

    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}
