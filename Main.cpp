#include <bits/stdc++.h>
using namespace std;

void fill_arr(int m[], int& n)
{
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> m[i];
}

bool checker(int m[], int n, int i)
{
    if (2 * i <= n && m[i] > m[2 * i]) return false;
    if (2 * i + 1 <= n && m[i] > m[2 * i + 1]) return false;
    return true;
}


bool check_heap(int m[], int len)
{
    for (int i = 1; i <= len; i++)
        if (!checker(m, len, i))return false;
    return true;
}

int m[100001] = { 0 };
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int len;
    fill_arr(m, len);
    if (check_heap(m,len))cout << "YES\n";
    else cout << "NO\n";
}