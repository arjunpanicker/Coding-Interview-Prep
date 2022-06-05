#include <iostream>
#include <string>

using namespace std;

template <typename T>
int partition(T* arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            if (i != j)
                swap(arr[j], arr[i]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSort(T* arr, int low, int high) {
    if (low >= high)
        return;

    int pi = partition<T>(arr, low, high);
    quickSort<T>(arr, low, pi - 1);
    quickSort<T>(arr, pi + 1, high);
}

template <typename T>
void print(T* arr, int m) {
    for (int i = 0; i < m; i++)
        cout << arr[i] << " ";
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

    quickSort<int>(arr, 0, intArraySize - 1);

    cout << endl << "After sorting: ";  
    print<int>(arr, intArraySize);
    
    
    cout << endl << endl << "String Array Sorting" << endl;
    cout << "---------------------" << endl;
    cout << "Before sorting: ";    
    print<string>(sarr, stringArraySize);

    quickSort<string>(sarr, 0, stringArraySize - 1);

    cout << endl << "After sorting: ";  
    print<string>(sarr, stringArraySize);

    cout << endl << endl << "Completed!";

    return 0;
}