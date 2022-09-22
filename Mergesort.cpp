
#include <iostream>
#include <chrono>
using namespace std;


void merge(int array[], int const left, int const mid,
		int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];


	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne
		= 0, 
		indexOfSubArrayTwo
		= 0; 
	int indexOfMergedArray
		= left;


	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}


void mergeSort(int array[], int const start, int const finish)
{
	if (start >= finish)
		return; 

	auto middle = start + (finish - start) / 2;
	mergeSort(array, start, middle);
	mergeSort(array, middle + 1, finish);
	merge(array, start, middle, finish);
}

void printArray(int Arr[], int size)
{
	for (auto j = 0; j < size; j++)
		cout << Arr[j] << " ";
}


int main()
{
	int arr[] = { 1, 2, 4, 7, 9, 10 ,12, 13, 15 ,18, 20 , 23 };
    int arr2[] = {1, 2, 3, 4, 5, 20, 7, 6, 12, 13, 15, 11};
    int arr3[] = {11,10,9,8,7,6, 4, 3, 2, 1 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);
    auto arr_size2 = sizeof(arr2) / sizeof(arr2[0]);
    auto arr_size3 = sizeof(arr3) /sizeof(arr3[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);
    auto start1 = std::chrono::steady_clock::now();
	mergeSort(arr, 0, arr_size - 1);
	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
    cout<< endl;
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double>seconds1 = end1-start1;
    std::cout << "elapsed time: " <<seconds1.count() << "s\n";
    cout<< endl;


    cout << "Given array is \n";
	printArray(arr2, arr_size);
    auto start2 = std::chrono::steady_clock::now();
	mergeSort(arr2, 0, arr_size2 - 1);
	cout << "\nSorted array is \n";
	printArray(arr2, arr_size2);
	cout <<endl;
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double>seconds2 = end2-start2;
    std::cout << "elapsed time: " << seconds2.count() << "s\n";
	cout <<endl;



    cout << "Given array is \n";
	printArray(arr3, arr_size3);
    auto start3 = std::chrono::steady_clock::now();
	mergeSort(arr3, 0, arr_size3 - 1);
	cout << "\nSorted array is \n";
	printArray(arr3, arr_size3);
    cout <<endl;
    auto end3 = std::chrono::steady_clock::now();
    std::chrono::duration<double>seconds3 = end3-start3;
    std::cout << "elapsed time: " << seconds3.count() << "s\n";

	return 0;
}


