#include <bits/stdc++.h>
using namespace std;

struct number
{
    int num = 0;
    bool first_half = true;
};

number m[100000];

void fill_arr(number m[], int& n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i].num;
        if (i >= n / 2) m[i].first_half = false;
    }
}

void out_arr(number m[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << m[i].num << " ";
    }
    cout << "\n";
}

bool comporator(number a, number b)
{
    if (a.first_half && !b.first_half) return true;
    if (a.first_half && b.first_half && a.num < b.num) return true;
    if (!a.first_half && !b.first_half && a.num > b.num) return true;
    return false;
}

int main()
{
    int n;
    fill_arr(m, n);
    sort(m, m + n, comporator);
    out_arr(m, n);
}
