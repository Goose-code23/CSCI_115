

#include <iostream>
using namespace std;


int getMax(int array[], int x)
{
	int max = array[0];
	for (int j = 1; j < x; j++)
		if (array[j] > max)
			max = array[j];
	return max;
}

void countSort(int array[], int x, int e)
{
	int output[x]; 
	int i, count[10] = { 0 };


	for (i = 0; i < x; i++)
		count[(array[i] / e) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = x - 1; i >= 0; i--) {
		output[count[(array[i] / e) % 10] - 1] = array[i];
		count[(array[i] / e) % 10]--;
	}

	for (i = 0; i < x; i++)
		array[i] = output[i];
}


void radixsort(int array[], int x)
{

	int m = getMax(array, x);

	for (int e = 1; m / e > 0; e *= 10)
		countSort(array, x, e);
}


void print(int array[], int x)
{
	for (int j = 0; j < x; j++)
		cout << array[j] << " ";
}

int main()
{
	int array[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int x = sizeof(array) / sizeof(array[0]);
	
	
	radixsort(array, x);
	print(array, x);
	return 0;
}
