#include <bits/stdc++.h>
using namespace std;

const int Nmax = 10000;

struct Tlong
{
    int len = 0;
    char sign;
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


void out_long(Tlong& n)
{
    if (n.sign == '-') cout << '-';
    for (int i = 0; i < n.len; i++)
    {
        cout << n.num[Nmax - n.len + i];
    }

}

void add_abs(Tlong a, Tlong b, Tlong& res)
{
    res.len = max(a.len, b.len) + 1;
    for (int i = 0; i < res.len; i++)
    {
        res.num[Nmax - i - 1] = (a.num[Nmax - i - 1] + b.num[Nmax - i - 1]) % 10;
        a.num[Nmax - i - 2] += (a.num[Nmax - i - 1] + b.num[Nmax - i - 1]) / 10;
    }
    if (res.num[Nmax - res.len] == 0)res.len--;
}

void zero(Tlong& n)
{
    for (int i = Nmax - n.len; i < Nmax; i++)n.num[i] = 0;
    n.len = 1;
    n.sign = '+';
}

Tlong fib1, fib2, fib3;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    zero(fib1);
    zero(fib2);
    zero(fib3);
    fib2.num[Nmax - 1] = 1;
    int cnt, curr;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> curr;
        fib1 = fib2;
        fib2 = fib3;
        if (curr) add_abs(fib1, fib2, fib3);
        else
        {
            zero(fib3);
        }
    }
    out_long(fib3);
}
