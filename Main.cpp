#include <bits/stdc++.h>
using namespace std;

struct number
{
    int num = 0;
    int id = 0;
};

number m[100000];

void fill_arr(number m[], int& n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i].num;
        m[i].id = i;
    }
}

int sum_of_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
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
    int sumA = sum_of_digits(a.num);
    int sumB = sum_of_digits(b.num);
    if (sumA > sumB) return true;
    if (sumA == sumB && a.id < b.id) return true;
    return false;
}

int main()
{
    int n;
    fill_arr(m, n);
    sort(m, m + n, comporator);
    out_arr(m, n);
}
