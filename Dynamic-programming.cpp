#include<iostream>
#include<chrono>
#define MAX 100
using namespace std;

void print_opt_paren(int s[][MAX], int i, int j){
	if (i == j)
		cout << "A" << i;
	else {
		cout << "(";
		print_opt_paren(s, i, s[i][j]);
		print_opt_paren(s, s[i][j] + 1, j);
		cout << ")";
	}
}

void matrix_chain_order(int p[], int n) {
	int m[MAX][MAX], s[MAX][MAX];

	for (int i = 1; i <= n; i++)
		m[i][i] = 0;

	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	cout << "\nOptimal Cost is : " << m[1][n];
	print_opt_paren(s, 1, n);
}

int main() {
	int p[] = { 10, 20, 30, 40, 30 };
	int n = (sizeof(p) / sizeof(p[0])) - 1;
	matrix_chain_order(p, n);

	int p2[] = { 4, 10, 3, 12, 20, 7 };
	int z = (sizeof(p2) / sizeof(p2[0])) - 1;
	matrix_chain_order(p2, z);

	return 0;
}
