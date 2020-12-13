#include <bits/stdc++.h>
using namespace std;

const int Nmax = 1001;

struct Tlong
{
    int len = 0;
    char sign = '+';
    int num[Nmax] = { 0 };
};


Tlong multiply_abs(Tlong a, Tlong b)
{
    Tlong res;
    res.len = a.len + b.len + 11;
    for (int i = 1; i <= a.len; ++i)
        for (int j = 1; j <= b.len; ++j)
            res.num[Nmax - i - j + 1] += a.num[Nmax - i] * b.num[Nmax - j];
    for (int i = 1; i < res.len; ++i)
    {
        res.num[Nmax - i - 1] += res.num[Nmax - i] / 10;
        res.num[Nmax - i] %= 10;
    }
    while (res.num[Nmax - res.len] == 0 && res.len > 1)--res.len;
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
void out_long(Tlong n)
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

Tlong substract_abs(Tlong dec, Tlong sub)
{
    Tlong res;
    res.len = dec.len;
    for (int i = 1; i <= dec.len; i++)
    {
        if (dec.num[Nmax - i] < sub.num[Nmax - i])
        {
            dec.num[Nmax - i - 1]--;
            dec.num[Nmax - i] += 10;
        }
        res.num[Nmax - i] = dec.num[Nmax - i] - sub.num[Nmax - i];
    }
    while (res.num[Nmax - res.len] == 0 && res.len > 1) --res.len;
    return res;

}


void tenmult(Tlong& a)
{
    if (comp_zero(a))++a.len;
    for (int i = a.len; i > 0; --i) a.num[Nmax - i - 1] = a.num[Nmax - i];
    a.num[Nmax - 1] = 0;
}


Tlong divide_abs(Tlong a, Tlong b)
{
    Tlong res, temp;
    res.len = a.len;
    int cnt = a.len;
    while (cnt)
    {
        if (compare(temp, b) == -1)
        {
            tenmult(temp);
            temp.num[Nmax - 1] = a.num[Nmax - cnt];
            --cnt;
        }
        while (compare(temp, b) != -1)
        {
            temp = substract_abs(temp, b);
            ++res.num[Nmax - cnt - 1];
        }
    }
    while (res.num[Nmax - res.len] == 0 && res.len > 1)--res.len;
    return res;
}

Tlong mod_abs(Tlong a, Tlong b)
{
    Tlong temp;
    int cnt = a.len;
    while (cnt)
    {
        if (compare(temp, b) == -1)
        {
            tenmult(temp);
            temp.num[Nmax - 1] = a.num[Nmax - cnt];
            --cnt;
        }
        while (compare(temp, b) != -1)
        {
            temp = substract_abs(temp, b);
        }

    }
    return temp;
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



Tlong add_abs(Tlong a, Tlong b)
{
    Tlong res;
    res.len = max(a.len, b.len) + 1;
    for (int i = 0; i < res.len; i++)
    {
        res.num[Nmax - i - 1] = (a.num[Nmax - i - 1] + b.num[Nmax - i - 1]) % 10;
        a.num[Nmax - i - 2] += (a.num[Nmax - i - 1] + b.num[Nmax - i - 1]) / 10;
    }
    if (res.num[Nmax - res.len] == 0)res.len--;
    return res;
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

void zero(Tlong& n)
{
    for (int i = 1; i <= n.len; ++i)
    {
        n.num[Nmax - i] = 0;
    }
    n.len = 1;
}

void left(Tlong& a)
{
    for (int i = a.len; i > 0; --i) a.num[Nmax - i - 1] = a.num[Nmax - i];
    a.num[Nmax - 1] = 0;
    ++a.len;
}


Tlong natural_fraction(Tlong& mod, Tlong& div)
{
    Tlong res;
    int res_len=0;
    while (div.num[Nmax - 1] % 2 == 0)
    {
        if (mod.num[Nmax - 1] % 2 >0)
        {
            left(mod);
            ++res_len;
        }
        mod = divide_halflong_abs(mod, 2);
        div = divide_halflong_abs(div, 2);
    }
    while (div.num[Nmax - 1] % 5 == 0)
    {
        if (mod.num[Nmax - 1] % 5>0)
        {
            left(mod);
            ++res_len;
        }
        mod = divide_halflong_abs(mod, 5);
        div = divide_halflong_abs(div, 5);
    }
    res = divide_abs(mod,div);
    res.len = res_len;
    mod = mod_abs(mod, div);
    return res;
}

Tlong endless_fraction(Tlong mod, Tlong div)
{
    Tlong res, etalon = mod;
    do
    {
        left(mod);
        left(res);
        res = add_abs(res, divide_abs(mod, div));
        mod = mod_abs(mod, div);
    } while (compare(mod, etalon) != 0);
    return res;
}

Tlong divider,mod,base;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input_long(base);
    input_long(divider);
    out_long(divide_abs(base, divider));
    mod = mod_abs(base, divider);
    if (comp_zero(mod))
    {
        cout << ".";
        out_long(natural_fraction(mod,divider));
        if (comp_zero(mod))
        {
            cout << "(";
            out_long(endless_fraction(mod, divider));
            cout << ")\n";
        }
    }
}
