#include <bits/stdc++.h>
using namespace std;

const int Nmax = 1001;

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

void left(Tlong& a)
{
    for (int i = a.len; i > 0; --i) a.num[Nmax - i - 1] = a.num[Nmax - i];
    a.num[Nmax - 1] = 0;
    ++a.len;
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




Tlong num, base, mod;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input_long(num);
    input_long(base);
    string res = "";
    while (comp_zero(num))
    {
        mod = mod_abs(num, base);
        num = divide_abs(num, base);
        if (mod.len > 1)res = ']' + res;
        for (int i = 1; i <= mod.len; ++i)
        {
            res = to_string(mod.num[Nmax - i]) + res;
        }
        if (mod.len > 1)res = '[' + res;
    }
    cout << res << "\n";
}
