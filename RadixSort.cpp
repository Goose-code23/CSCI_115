#include<iostream>
using namespace std;

int getMax(int array[], int x){
    int max =array[0];
    for (int j = 1; j < x; j++){
        if (array[j] > max){
            max = array[j];
        }
    }
}

void CountSort( int array[], int x, int e){
    int output[x];
    int j, count[10] = {0};

    for (j = 0; j < x; j++){
        count[(array[j]/e) % 10]++;
    }

    for(j=1; j< 10; j++){
        count[j] += count[j-1];
    }

    for(j= x -1; j>=0; j--){
        output[count[(array[j]/e) % 10] - 1] = array[j];
        count[(array[j]/e) % 10]--;
    }

    for(j=0; j<x; j++){
        array[j] = output[j];
    }
}

void radixSort(int array[], int x){
    int z = getMax(array, x);

    for(int e = 1; z/e > 0; e *= 10){
        CountSort(array, x, e);
    }
}

void printArray(int array[], int x){
    for(int i = 0; i < x; i++){
        cout << array[i] << " ";
    }
}

int main(){
    int array[] = { 1,5,6,7,9,5,3,7,8 };
    int x = sizeof(array)/sizeof(array[0]);
    radixSort(array, x);
    printArray(array, x);
    return 0;
}