#include <bits/stdc++.h>
using namespace std;

int m[100000];

void fill_arr(int m[], int& n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
}

void out_arr(int m[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << m[i] << " ";
    }
    cout << "\n";
}

bool comporator(int a, int b)
{
    if (a > b) return true;
    return false;
}

int main()
{
    int n;
    fill_arr(m, n);
    sort(m, m + n/2);
    sort(m + n / 2, m + n, comporator);
    out_arr(m, n);
}