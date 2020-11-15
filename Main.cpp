#include <bits/stdc++.h>
using namespace std;

const int Nmax = 10001;

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
        if (s[1] != '0')n.sign = s[0];
        else n.sign = '+';
        s.erase(0, 1);
    }
    else n.sign = '+';
    n.len = (s.size());
    for (int i = 0; i < s.size(); i++)
    {
        n.num[Nmax - n.len + i] = s[i] - 48;
    }
}


void out_long(Tlong n)
{
    if (n.sign == '-') cout << '-';
    for (int i = 0; i < n.len; i++)
    {
        cout << n.num[Nmax - n.len + i];
    }
    cout << "\n";
}


int compare(Tlong a, Tlong b)
{
    if (a.sign != b.sign)
    {
        if (a.sign == '+') return 1;
        return -1;
    }
    int sign = 1 - 2 * int(a.sign == '-');
    if (a.len != b.len)
    {
        if (a.len > b.len) return 1*sign;
        return -1*sign;
    }
    for (int i = 0; i < a.len; i++)
    {
        if (a.num[Nmax - a.len + i] > b.num[Nmax - b.len + i]) return 1 * sign;
        if (a.num[Nmax - a.len + i] < b.num[Nmax - b.len + i])  return -1 * sign;
    }
    return 0;
}

Tlong substract_abs(Tlong dec, Tlong sub)
{
    Tlong res;
    dec.sign = '+';
    sub.sign = '+';
    if (compare(dec, sub) == 0)
    {
        res.len = 1;
        res.num[Nmax - 1] = 0;
        return res;
    }
    if (compare(dec, sub) == -1)
    {
        res.sign = '-';
        swap(dec, sub);
    }
    res.len = dec.len;
    for (int i = 1; i <= dec.len; i++)
    {
        if (dec.num[Nmax - i] < sub.num[Nmax - i])
        {
            dec.num[Nmax - i - 1]--;
            dec.num[Nmax - i]+=10;
        }
        res.num[Nmax - i] = dec.num[Nmax - i] - sub.num[Nmax - i];
    }
    while (res.num[Nmax - res.len] == 0) res.len--;
    return res;

}

Tlong decreasing, subtractor;
int main()
{
    input_long(decreasing);
    input_long(subtractor);
    out_long(substract_abs(decreasing, subtractor));
}
