#include <iostream>
#include <chrono>
#include <iomanip>
#include <functional>

using namespace std;



int method1(int f) {
	if (f == 0 || f == 1) {
		return f;
	}
	return method1(f - 1) + method1(f - 2);
}
int method2(int f) {
	
	int last = 0;
	int current= 1;
	int new_item;

	for (int i = 2; i <= f; i++) {
		new_item = last + current;
		last = current;
		current = new_item;
	}
	return current;
}

int main() {
	int d = 12;
	int g = 35;
	int y = 120;


	cout << "f = 12" << endl;
	auto first = chrono::high_resolution_clock::now();
	cout << "Method1: " << method1(d) << endl;
	auto end = chrono::high_resolution_clock::now();
	cout << "Time taken: ";
	double time_taken1 = chrono::duration_cast<chrono::nanoseconds>(end - first).count();
	time_taken1 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken1 << endl;
	cout << endl;

	auto second = chrono::high_resolution_clock::now();
	cout << "Method2: " << method2(d) << endl;
	auto end2 = chrono::high_resolution_clock::now();
	cout << "Time taken for Variables method: ";
	double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - second).count();
	time_taken2 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken2 << endl;
	cout << endl;

	cout << "f = 35" << endl;
	auto third = chrono::high_resolution_clock::now();
	cout << "Method1: " << method1(g) << endl;
	auto end3 = chrono::high_resolution_clock::now();
	cout << "Time taken: ";
	double time_taken3 = chrono::duration_cast<chrono::nanoseconds>(end3 - third).count();
	time_taken1 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken1 << endl;
	cout << endl;

	auto fourth = chrono::high_resolution_clock::now();
	cout << "Method2: " << method2(g) << endl;
	auto end4 = chrono::high_resolution_clock::now();
	cout << "Time taken for Variables method: ";
	double time_taken4 = chrono::duration_cast<chrono::nanoseconds>(end4 - fourth).count();
	time_taken2 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken2 << endl;
	cout << endl;

	cout << "f = 120" << endl;
	auto fifth = chrono::high_resolution_clock::now();
	cout << "Method2: " << method2(y) << endl;
	auto end5 = chrono::high_resolution_clock::now();
	cout << "Time taken: ";
	double time_taken5 = chrono::duration_cast<chrono::nanoseconds>(end5 - fifth).count();
	time_taken1 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken1 << endl;
	cout << endl;

	auto sixth = chrono::high_resolution_clock::now();
	cout << "Method1: " << method1(y) << endl;
	auto end6 = chrono::high_resolution_clock::now();
	cout << "Time taken for Variables method: ";
	double time_taken6 = chrono::duration_cast<chrono::nanoseconds>(end6 - sixth).count();
	time_taken2 *= 1e-9;
	cout << std::fixed << std::setprecision(6) << time_taken2 << endl;
	cout << endl;

	return 0;
}