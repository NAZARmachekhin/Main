#include <bits/stdc++.h>
using namespace std;

struct number
{
    int num = 0;
    int id = 0;
};

number m[100001];

void fill_arr(number m[], int& n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i].num;
        m[i].id = i;
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

void divide_groups(number m[], int n)
{
    swap(m[0], m[1]);
    for (int i = 1, j = 3; j<n; i ++, j +=2)
    {
        swap(m[i], m[j]);
    }
}

bool comporator(number a, number b)
{
    if (a.num < b.num)return true;
    return false;
}

bool sort_by_id(number a, number b)
{
    if (a.id < b.id) return true;
    return false;
}

void restore_id(number m[], int n)
{
    for (int i = n / 2, cnt = 0; i < n; i++, cnt += 2)
    {
        m[i].id = cnt;
    }
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    fill_arr(m, n);
    divide_groups(m, n);
    sort(m + n / 2, m + n, comporator);
    restore_id(m, n);
    sort(m, m + n, sort_by_id);
    out_arr(m, n);
}


