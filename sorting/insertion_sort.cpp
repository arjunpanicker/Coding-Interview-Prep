#include <iostream>
#include <string>

using namespace std;

template <typename T>
void insertionSort(T* arr, int m) {
    for (int i = 0; i < m; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        swap(arr[j+1], key);
    }
}

template <typename T>
void print(T* arr, int m) {
    for (int i = 0; i < m; i++)
        cout << arr[i] << " ";
}

int main() {
    int intArraySize, stringArraySize;

    int arr[] = {9 ,2, 4, 1, 6, 8, 8};
    string sarr[] = {"handball", "basketball", "cricket", "badminton"};

    intArraySize = sizeof(arr) / sizeof(arr[0]);
    stringArraySize = sizeof(sarr) / sizeof(sarr[0]);

    cout << "Integer Array Sorting" << endl;
    cout << "---------------------" << endl;
    cout << "Before sorting: ";    
    print<int>(arr, intArraySize);

    insertionSort<int>(arr, intArraySize);

    cout << endl << "After sorting: ";  
    print<int>(arr, intArraySize);
    
    
    cout << endl << endl << "String Array Sorting" << endl;
    cout << "---------------------" << endl;
    cout << "Before sorting: ";    
    print<string>(sarr, stringArraySize);

    insertionSort<string>(sarr, stringArraySize);

    cout << endl << "After sorting: ";  
    print<string>(sarr, stringArraySize);

    cout << endl << endl << "Completed!";

    return 0;
}