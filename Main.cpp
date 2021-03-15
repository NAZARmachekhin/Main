#include <bits/stdc++.h>
using namespace std;

void add(int m[], int& len, int n)
{
    m[len + 1] = n;
    len++;
    int son = len;
    while (son / 2 >= 1)
    {
        int father = son / 2;
        if (m[son] > m[father])
        {
            swap(m[son], m[father]);
            son = father;
        }
        else
            son = 1;
    }
}

void rebuild(int m[], int father, int last)
{
    int son;
    while (father <= last / 2)
    {
        son = 2 * father;
        if (2 * father + 1 <= last && m[son] < m[son+1])
        {
            son++;
        }
        if (m[son] > m[father])
        {
            swap(m[son], m[father]);
            father = son;
        }
        else
        {
            father = last;
        }
    }
}

int del(int m[], int& len)
{
    swap(m[1], m[len]);
    rebuild(m, 1, len - 1);
    return m[len--];
}

int m[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt, len = 0, num, cmd;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> cmd;
        if (!cmd)
        {
            cin >> num;
            add(m, len, num);
        }
        else
            cout << del(m, len) << '\n';
    }
    cout << '\n';
    return 0;
}