#include <bits/stdc++.h>
using namespace std;

const int Nmax = 100001;

struct Tlong
{
    int len = 0;
    char sign = '+';
    int num[Nmax] = { 0 };
};

Tlong add_abs(Tlong a, Tlong b)
{
    Tlong res;
    res.len = max(a.len, b.len) + 1;
    int next = 0;
    for (int i = 0; i < res.len; i++)
    {
        res.num[Nmax - i - 1] = (a.num[Nmax - i - 1] + b.num[Nmax - i - 1]+next) % 10;
        next= (a.num[Nmax - i - 1] + b.num[Nmax - i - 1]) / 10;
    }
    if (res.num[Nmax - res.len] == 0)res.len--;
    return res;
}


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

bool comp_zero(Tlong a)
{
    return !(a.len == 1 && a.num[Nmax - 1] == 0);
}

void out_long(Tlong& n)
{
    if (n.sign == '-')
    {
        cout << '-';
    }
    for (int i = 0; i < n.len; i++)
    {
        cout << n.num[Nmax - n.len + i];
    }
}

void plusplus(Tlong& n)
{
    int cnt = Nmax - 1;
    for (; n.num[cnt] == 9; --cnt)
    {
        n.num[cnt] = 0;
    }
    ++n.num[cnt];
    if (n.num[Nmax - n.len - 1])++n.len;
}

/*
34586767
1234
*/


Tlong multiply_abs(Tlong a, Tlong b)
{
    Tlong res;
    res.len = a.len + b.len+11;
    for (int i = 1; i <=a.len; ++i)
        for (int j = 1; j <=b.len; ++j)
            res.num[Nmax-i-j+1] += a.num[Nmax-i] * b.num[Nmax-j];
    for (int i = 1; i <res.len; ++i)
    {
        res.num[Nmax-i-1] += res.num[Nmax-i]/10;
        res.num[Nmax-i] %= 10;
    }
    while (res.num[Nmax - res.len] == 0 && res.len > 1)--res.len;
    return res;
}

int compare(Tlong a, Tlong b)
{
    if (a.len != b.len)
    {
        if (a.len > b.len) return 1;
        return -1;
    }
    for (int i = 0; i < a.len; i++)
    {
        if (a.num[Nmax - a.len + i] > b.num[Nmax - b.len + i]) return 1;
        if (a.num[Nmax - a.len + i] < b.num[Nmax - b.len + i])  return -1;
    }
    return 0;
}

Tlong divide_halflong_abs(Tlong& a, int b)
{
    Tlong result;
    if (b == 0)
    {
        result.len = 1;
        result.num[Nmax - 1] = 0;
        result.sign = '+';
    }
    else
    {
        int dif = 0;
        for (int i = 0; i < a.len; i++)
        {
            dif = dif * 10 + a.num[Nmax - a.len + i];
            result.num[Nmax - a.len + i] = dif / b;
            dif = dif % b;
        }
        result.len = a.len;
        while (result.num[Nmax - result.len] == 0)result.len--;
    }
    return result;
}

Tlong side_count(Tlong side)
{
    Tlong res;
    res = side;
    plusplus(side);
    res = multiply_abs(side, res);
    res = divide_halflong_abs(res, 2);
    return res;
}


Tlong xlen, ylen, res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input_long(xlen);
    input_long(ylen);
    res = side_count(xlen);
    res = multiply_abs(res, side_count(ylen));
    //res = multiply_abs(xlen, ylen);
    out_long(res);
    cout << "\n";
}
