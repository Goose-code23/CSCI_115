#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Heap {
    private:
    vector<int> n;

    int parent( int z){
        return (z-1)/2;
    }
    int left( int z){
        return (2 * z + 1);
    }
    int right( int z){
        return (2 * z + 2);
    }

public:

void printArray(vector<int> n, int z){
    for (int j=0; j<n.size(); j++){
        cout << " " << n[j] << endl;
    }
    cout << endl;
}

 void Max_heapify(vector<int>& n, int z, int j){
   int first = left(z);
   int second = right(z);
   int largest = j;

   if( first < z && n[first] > n[j]){
    largest = first;
   }
   if( second < z && n[second] > n[j]){
    largest = second;
   }
   if( largest != j){
    swap(n[j], n[largest]);
    Max_heapify(n, z, largest);
   }
 }

 void buildMaxHeap(vector<int>& n, int z){
    for(int j = z/2 -1; j>=0; j--){
        Max_heapify(n, z, j);
    }
 }

 void AscendingHeapSort(vector<int>& n, int z){
    buildMaxHeap(n, z);
    int size = z;
    for(int j = z-1; j>=0; j--){
        swap(n[0], n[j]);
        size--;
        Max_heapify(n, j, 0);
    }
}

void  instert_value_maxHeap(vector<int>& n, int z, int d){
    n.push_back(d);
    Max_heapify(n, z, 0);
}

void modifyValMax(vector<int>& n, int z, int newval){
    n[z] = newval;
    Max_heapify(n, z, 0);
}
int extract_maximum(vector<int>& n, int z){
    int t = n.back();
    n.pop_back();
    return t;
}
int getMaxVal(vector<int>& n, int z){
    int t = n.back();
    return t;
}
void min_heapify(vector<int>& n, int z, int j){
    int first = left(z);
    int second = right(z);
    int smallest = j;

    if( first < z && n[first] < n[j]){
        smallest = first;
    }
    if(second < z && n[second] < n[j]){
        smallest = second;
    }
    if(smallest != j){
        swap(n[j], n[smallest]);
        min_heapify(n, z, smallest );
    }
    }

    void buildMinHeap(vector<int>& n, int z){
        for(int j = z/2 -1; j>=0; j--){
            min_heapify(n, z, j);
        }
    }

    void descendingHeapSort(vector<int>& n, int z){
        buildMinHeap(n, z);
        int size = z;
        for(int j = z-1; j>=0; j--){
            swap(n[0], n[j]);
            size--;
            min_heapify(n, j, 0);
        }
    }
    void instert_value_minHeap(vector<int>& n, int z, int d){
        n.push_back(d);
        min_heapify(n, z, 0);
    }

    void modifyValMin(vector<int>& n, int z, int newval){
        n[z] = newval;
        min_heapify(n, z, 0);
    }

    int extract_minimum(vector<int>& n, int z){
        int t = n.back();
        n.pop_back();
        return t;
    }

    int getMin(vector<int>& n, int z){
        int t = n.back();
        return t;
    }
};

int main(){
    Heap h;
    vector<int>a = {4, 3, 2, 6};
    int n = a.size();
    int num;
    cin >> num;

    cout << "Press 0 for Ascending HeapSort" <<endl;
    cout << "Press 1 for Descending HeapSort" <<endl;
    cout << "Press 2 to exit" <<endl;

    if(num == 0){
        cout << "Input: ";
        h.printArray(a, n);
        cout << "Input element 7" <<endl;
        h.instert_value_maxHeap(a, n, 7);
        h.AscendingHeapSort(a, n);
        cout << "Sorted Heap: ";
        h.printArray(a, n);
        cout<< "Max Value: ";
        cout << h.extract_maximum(a, n) <<endl;
        cout << "Sorted Heap: ";
        h.printArray(a, n);
        return main();
    }

    if( num == 1){
        cout << "Input: ";
        h.printArray(a, n);
        cout << "Input Element 7" << endl;
        h.instert_value_minHeap(a, n, 7);
        h.descendingHeapSort(a, n);
        cout <<"Sorted Heap: ";
        h.printArray(a, n);
        cout << "Min Value: ";
        cout << h.extract_minimum(a, n) <<endl;
        cout << "Sorted Heap: ";
        h.printArray(a, n);
        return main();
    }
    if( num == 2){
        cout << "Exit Program" << endl;
        return 0;
    }
    else{
        cout << "Invalid Input" << endl;
        return main();
    }

}

