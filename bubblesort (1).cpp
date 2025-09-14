#include <iostream>
using namespace std;

// Function to perform bubble sort on an array of comparable items
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Flag to check if any swaps were made in this pass

        for (int j = 0; j < n - 1 - i; j++) {
            // Compare adjacent elements and swap if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps were made in this pass, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << std::endl;

    bubbleSort(arr, n);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << std::endl;

    return 0;
}

