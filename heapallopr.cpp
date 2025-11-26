#include <iostream>
using namespace std;

class Heap {
    int *arr;
    int capacity;
    int size;
    bool isMinHeap;

    void heapifyDown(int index) {
        int left, right, extremeIndex;
        while (true) {
            left = 2 * index + 1;
            right = 2 * index + 2;
            extremeIndex = index;

            if (left < size && ((isMinHeap && arr[left] < arr[extremeIndex]) || (!isMinHeap && arr[left] > arr[extremeIndex])))
                extremeIndex = left;

            if (right < size && ((isMinHeap && arr[right] < arr[extremeIndex]) || (!isMinHeap && arr[right] > arr[extremeIndex])))
                extremeIndex = right;

            if (extremeIndex == index) break;

            swap(arr[index], arr[extremeIndex]);
            index = extremeIndex;
        }
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && ((isMinHeap && arr[index] < arr[parent]) || (!isMinHeap && arr[index] > arr[parent]))) {
            swap(arr[index], arr[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

public:
    Heap(int maxCapacity, bool minHeapType) {
        capacity = maxCapacity;
        size = 0;
        arr = new int[capacity];
        isMinHeap = minHeapType;
    }

    void insert(int value) {
        if (size == capacity) return;
        arr[size] = value;
        heapifyUp(size++);
    }

    int getTop() {
        if (size == 0) return -1;
        return arr[0];
    }

    int extractTop() {
        if (size == 0) return -1;
        int topValue = arr[0];
        arr[0] = arr[--size];
        heapifyDown(0);
        return topValue;
    }

    bool deleteValue(int value) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) { index = i; break; }
        }
        if (index == -1) return false;

        arr[index] = arr[--size];
        heapifyDown(index);
        heapifyUp(index);
        return true;
    }

    void displayHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void buildHeap(int array[], int n) {
        for (int i = 0; i < n; i++)
            insert(array[i]);
    }

    ~Heap() {
        delete[] arr;
    }
};

int main() {
    // Example: Max Heap
    Heap maxHeap(10, false);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(10);

    cout << "Max Heap: ";
    maxHeap.displayHeap();

    cout << "Top Value: " << maxHeap.getTop() << endl;
    maxHeap.extractTop();
    cout << "After Extract: ";
    maxHeap.displayHeap();

    maxHeap.deleteValue(15);
    cout << "After Deletion of 15: ";
    maxHeap.displayHeap();

    // Heap Sort Example
    int arr[] = {9, 4, 7, 1, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    Heap sortHeap(n, false); // Max Heap for descending sort
    sortHeap.buildHeap(arr, n);

    cout << "Heap Sort (Descending): ";
    for (int i = 0; i < n; i++)
        cout << sortHeap.extractTop() << " ";
    cout << endl;

    // Min Heap example
    Heap minHeap(10, true);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(10);

    cout << "Min Heap: ";
    minHeap.displayHeap();
    cout << "Min Value: " << minHeap.getTop() << endl;

    return 0;
}