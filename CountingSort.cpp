#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
using namespace std;

void PrintArray(int array[], int size){
    for (int i = 0; i < size; i ++){
        cout << array[i] << " ";
        cout << endl;
    }
};

void countSort(int array[], int size){
    
    int out[10];
    int count[10];
    int maximum = array[0];

    for (int i = 1; i < size; i++){
        if (array[i] > maximum){
            maximum = array[i];
        }
    }

    for (int j = 0; j <= maximum; j++){
        count[j] = 0;
    }

    for(int k = 0; k < size; k++){
        count[array[k]++];
    }

    for (int l = 1; l <= maximum; l++){
        count[l] += count[l - 1];
    }

    for (int m = size - 1; m >= 0; m--){
        out[count[array[m]] - 1] = array[m];
        count[array[m]]--;
    }

    for (int n = 0; n < size; n++){
        array[n] = out[n];
    }
}

int main(){
    int array1[] = {2, 0, 1, 0};

    int z = sizeof(array1)/ sizeof(array1[0]);

    auto start1 = chrono::high_resolution_clock::now();

    countSort(array1, z);
    PrintArray(array1, z);
    auto end1 = chrono::high_resolution_clock::now();
    cout << "     Time for Counting Sort: ";
	double time_taken1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
	time_taken1 *= 1e-9;
	cout << time_taken1 << endl;
}