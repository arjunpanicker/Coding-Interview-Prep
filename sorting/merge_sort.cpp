#include <iostream>
#include <string>

using namespace std;

template <typename T>
void print(T* arr, int m) {
    for (int i = 0; i < m; i++)
        cout << arr[i] << " ";
}

template <typename T>
void merge(T* arr, int const left, int const mid, int const right) {
    int const sizeLeftArray = mid - left + 1;
    int const sizeRightArray = right - mid;

    T leftArray[sizeLeftArray];
    T rightArray[sizeRightArray];

    // Copy the data to the two temp arrays
    for (int i = 0; i < sizeLeftArray; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < sizeRightArray; j++)
        rightArray[j] = arr[mid + 1 + j];

    // Compare and copy to the merged array
    int mergedArrayIdx = left, leftArrayIdx = 0, rightArrayIdx = 0;

    while (leftArrayIdx < sizeLeftArray && rightArrayIdx < sizeRightArray) {
        if (leftArray[leftArrayIdx] <= rightArray[rightArrayIdx]) {
            arr[mergedArrayIdx++] = leftArray[leftArrayIdx++];
        }
        else {
            arr[mergedArrayIdx++] = rightArray[rightArrayIdx++];
        }
    }

    // Copy over any remaining elements from the temp sub arrays
    while (leftArrayIdx < sizeLeftArray) {
        arr[mergedArrayIdx++] = leftArray[leftArrayIdx++];
    }
    while (leftArrayIdx < sizeLeftArray) {
        arr[mergedArrayIdx++] = rightArray[rightArrayIdx++];
    }
}

template <typename T>
void mergeSort(T* arr, int const begin, int const end) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort<T>(arr, begin, mid);
    mergeSort<T>(arr, mid + 1, end);

    merge<T>(arr, begin, mid, end);
}

int main() {
    int intArraySize, stringArraySize;

    int arr[] = {9 ,2, 4, 1, 8, 6, 15};
    string sarr[] = {"handball", "basketball", "cricket", "badminton"};

    intArraySize = sizeof(arr) / sizeof(arr[0]);
    stringArraySize = sizeof(sarr) / sizeof(sarr[0]);

    cout << "Integer Array Sorting" << endl;
    cout << "---------------------" << endl;
    cout << "Before sorting: ";    
    print<int>(arr, intArraySize);

    mergeSort<int>(arr, 0, intArraySize - 1);

    cout << endl << "After sorting: ";  
    print<int>(arr, intArraySize);
    
    
    cout << endl << endl << "String Array Sorting" << endl;
    cout << "---------------------" << endl;
    cout << "Before sorting: ";    
    print<string>(sarr, stringArraySize);

    mergeSort<string>(sarr, 0, stringArraySize - 1);

    cout << endl << "After sorting: ";  
    print<string>(sarr, stringArraySize);

    cout << endl << endl << "Completed!";

    return 0;
}