#include <bits/stdc++.h>
using namespace std;

const int Nmax = 10001;

struct Tlong
{
    int len = 0;
    char sign='+';
    int num[Nmax] = { 0 };
};




void input_long(Tlong& n)
{
    string s;
    cin >> s;
    if (s[0] == '+' || s[0] == '-')
    {
        n.sign = s[0];
        s.erase(0, 1);
    }
    else n.sign = '+';
    n.len = (s.size());
    for (int i = 0; i < s.size(); i++)
    {
        n.num[Nmax - n.len + i] = s[i] - 48;
    }
}


void out_long(Tlong &n)
{
    if (n.sign == '-')
    {
        cout<<'-';
    }
    for (int i = 0; i < n.len; i++)
    {
        cout << n.num[Nmax - n.len + i];
    }
}

Tlong multiply_halflong_abs(Tlong a, int b)
{
    int next = 0;
    int multiply = 0;
    for (int i = 1; i <= a.len; i++)
    {
        multiply = (a.num[Nmax - i] * b + next);
        a.num[Nmax - i] = multiply % 10;
        next = multiply / 10;
    }
    while (next)
    {
        a.len++;
        multiply = (a.num[Nmax - a.len] * b + next);
        a.num[Nmax - a.len] = multiply % 10;
        next = multiply / 10;
    }
    return a;
}

Tlong multiply_abs(Tlong &a, Tlong &b)
{
    Tlong res;
    int multiply, next = 0;
    for (int i = 1; i <= a.len; ++i)
    {
        for (int j = 1; j <= b.len || next; ++j)
        {
            multiply = a.num[Nmax - i] * b.num[Nmax - j] + next + res.num[Nmax - j - i + 1];
            res.num[Nmax - i - j + 1] = multiply % 10;
            next = multiply / 10;
        }
    }
    res.len = Nmax;
    while (!res.num[Nmax-res.len])--res.len;
    return res;
}


Tlong long_pow(Tlong n, int p)
{
    Tlong res;
    res.len = 1;
    res.num[Nmax - 1] = 1;
    while (p)
    {
        if (p & 1)
        {
            res = multiply_abs(res, n);
            --p;
        }
        else
        {
            n = multiply_abs(n, n);
            p >>= 1;
        }
    }
    return res;
}

Tlong res, num;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int power;
    num.len = 1;
    cin >> num.num[Nmax-num.len]>>power;
    res = long_pow(num, power);
    out_long(res);
}
