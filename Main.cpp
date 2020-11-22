#include <bits/stdc++.h>
using namespace std;

const int Nmax = 100000;

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

void multiply_halflong_abs(Tlong& a, int b)
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
}

void to_long(Tlong& n, int a)
{
    if (a >= 0)n.sign = '+';
    else n.sign = '-';
    n.len = to_string(a).size();
    for (int i = 1; i <= n.len; i++)
    {
        n.num[Nmax - i] = a % 10;
        a /= 10;
    }
}

Tlong res, start;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    res.len = 1;
    res.num[Nmax - 1] = 1;
    int sidek, siden;
    cin >> sidek >> siden;
    to_long(res, siden);
    for (int i = siden-1; i >= siden-sidek+1; i--)
    {
        multiply_halflong_abs(res, i);
    }
    out_long(res);
}
