#include <iostream>
using namespace std;

// Function to perform selection sort using minimum method
void SelectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // Find the index of the minimum element in the remaining unsorted array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the current element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to perform binary search on a sorted array
int BinarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1; // Search the element in the right half
        } else {
            right = mid - 1; // Search the element in the left half
        }
    }

    return -1; // Element not found
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sort the array using selection sort
    SelectionSort(arr, n);

    int target;
    cout << "Enter the element to search for: ";
    cin >> target;

    // Perform binary search on the sorted array
    int result = BinarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}