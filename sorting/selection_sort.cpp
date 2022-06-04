#include <iostream>
#include <string>

using namespace std;

template <typename T>
void selectionSort(T* arr, int m) {
    int minPos = 0;
    

    for (int i = 0; i < m-1; i++) {
        minPos = i;

        for (int j = i + 1; j < m; j++) {
            if (arr[j] < arr[minPos])
                minPos = j;
        }

        swap(arr[i], arr[minPos]);
    }
}

template <typename T>
void printArray(T* arr, int m) {
    for (int i = 0; i < m; i++)
        cout << arr[i] << " ";
}

int main() {
    int intArraySize, stringArraySize;

    // Get the size of the array
    // cout << "Enter array size: "; 
    // cin >> intArraySize;

    int arr[] = {9 ,2, 4, 1, 6, 8, 8};
    string sarr[] = {"handball", "basketball", "cricket", "badminton"};

    // cout << "Enter the array elements (space separated): ";
    // for (int i = 0; i < m; i++)
    //     cin >> arr[i];

    intArraySize = sizeof(arr) / sizeof(arr[0]);
    stringArraySize = sizeof(sarr) / sizeof(sarr[0]);
    
    cout << "Integer Array Sorting" << endl;
    cout << "---------------------" << endl;
    cout << "Before sorting: ";    
    printArray<int>(arr, intArraySize);

    selectionSort<int>(arr, intArraySize);

    cout << endl << "After sorting: ";  
    printArray<int>(arr, intArraySize);
    
    
    cout << endl << endl << "String Array Sorting" << endl;
    cout << "---------------------" << endl;
    cout << "Before sorting: ";    
    printArray<string>(sarr, stringArraySize);

    selectionSort<string>(sarr, stringArraySize);

    cout << endl << "After sorting: ";  
    printArray<string>(sarr, stringArraySize);

    cout << endl << endl << "Completed!";
    
    return 0;
}