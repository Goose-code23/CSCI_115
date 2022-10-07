#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
using namespace std;

void PrintArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
};

void countSort(int array[], int size) {

    int out[10];
    int count[10];
    int maximum = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }

    for (int j = 0; j <= maximum; j++) {
        count[j] = 0;
    }

    for (int k = 0; k < size; k++) {
        count[array[k]]++;
    }

    for (int l = 1; l <= maximum; l++) {
        count[l] += count[l - 1];
    }

    for (int m = size - 1; m >= 0; m--) {
        out[count[array[m]] - 1] = array[m];
        count[array[m]]--;
    }

    for (int n = 0; n < size; n++) {
        array[n] = out[n];
    }
}

int main() {
    int a[] = { 1,5,6,7,9,5,3,7,8 };

    int n = sizeof(a) / sizeof(a[0]);

    cout << "Before sorting: ";
    PrintArray(a, n);
    cout << endl;
    auto start1 = std::chrono::steady_clock::now();
    cout << "After sorting:";
    countSort(a, n);
    PrintArray(a, n); 
    cout << endl;
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double>seconds1 = end1 - start1;
    cout << "Time for Counting Sort: ";
    std::cout << seconds1.count() << "s\n";
}
