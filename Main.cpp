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

Tlong a, b;
int main()
{
    input_long(a);
    input_long(b);
    out_long(a);
    if (compare(a, b) == 1)cout << ">";
    else if (compare(a, b) == -1)cout << "<";
    else cout << "=";
    out_long(b);
    cout << "\n";
}
