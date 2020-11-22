#include <bits/stdc++.h>
using namespace std;

const int Nmax = 30001;

struct Tlong
{
    int len = 0;
    char sign = '+';
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



void fibonachi(int n, Tlong& res)
{
    if (n == 0)
    {
        res.len = 1;
        res.num[Nmax - 1] = 1;
    }
    else
    {
        Tlong fib0, fib1;
        fib1.len = 0;
        res.len = 1;
        fib1.num[Nmax - 1] = 1;
        res.num[Nmax - 1] = 1;
        n--;
        while (n)
        {
            fib0 = res;
            add_abs(res, fib1, res);
            fib1 = fib0;
            n--;
        }
    }
}


Tlong res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fibonachi(n + 1, res);
    out_long(res);
}
