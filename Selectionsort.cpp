#include <iostream>
#include<chrono>
using namespace std;

void swap(int *ptr, int *ptr2){
    int temp = *ptr;
    *ptr = *ptr2;
    *ptr2 = temp;
};

void selectionsort(int arr[], int x){
    int  A, B, min;

    for (A = 0; A<x-1; A++){
        min = A;
        for (B = A+1; B<x; B++){
            if(arr[B]<arr[min]){
                min = B;

            if (min != A){
                swap(&arr[min], &arr[A]);
            }
            }
        }
    }
}

void display(int arr[], int size){
    int A;
    for (A = 0; A < size; A++){
        cout << arr[A] << " ";
    }
}

int main() {
    int arr1[] = { 1, 2, 4, 7, 9, 10 ,12, 13, 15 ,18, 20 , 23 };
    int arr2[] = {1, 2, 3, 4, 5, 20, 7, 6, 12, 13, 15, 11};
    int arr3[] = {11,10,9,8,7,6, 4, 3, 2, 1 };

    int n = sizeof(arr1)/sizeof(arr1[0]);
    auto start = std::chrono::steady_clock::now();
    selectionsort(arr1, n);
    cout << "sorted array 1:  ";
    display(arr1, n);
    cout << endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Time: " << elapsed_seconds.count() << "s\n";
    cout << endl;
    

    int f = sizeof(arr2)/sizeof(arr2[0]);
    auto start2 = std::chrono::steady_clock::now();
    selectionsort(arr2, f);
    cout << "sorted array 2: ";
    display(arr2, n);
    cout << endl;
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2-start2;
    std::cout << "Time: " << elapsed_seconds2.count() << "s\n";
    cout << endl;

    int g = sizeof(arr3)/sizeof(arr3[0]);
    auto start3 = std::chrono::steady_clock::now();
    selectionsort(arr3, g);
    cout << "sorted array 3:  ";
    display(arr3, g);
    cout << endl;
    auto end3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds3 = end3-start3;
    std::cout << "Time: " << elapsed_seconds3.count() << "s\n";
    cout<< endl;


    return 0;
}