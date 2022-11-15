#include<iostream>
#include<iomanip>
#include<chrono>
using namespace std;

void print_opt_parens(int s[][10], int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        print_opt_parens(s, i, s[i][j]);
        print_opt_parens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void matrix_chain_order(int p[], int n)
{
    int m[10][10], s[10][10];
    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << "Optimal Parenthesization is : ";
    print_opt_parens(s, 1, n - 1);
    cout << endl;
    cout << "Optimal Cost is : " << m[1][n - 1];
}