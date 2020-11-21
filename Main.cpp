#include <bits/stdc++.h>
using namespace std;

const int Nmax = 500;

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


void out_long(Tlong& n)
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
        if (a.len > b.len) return 1 * sign;
        return -1 * sign;
    }
    for (int i = 0; i < a.len; i++)
    {
        if (a.num[Nmax - a.len + i] > b.num[Nmax - b.len + i]) return 1 * sign;
        if (a.num[Nmax - a.len + i] < b.num[Nmax - b.len + i])  return -1 * sign;
    }
    return 0;
}




void divide_halflong_abs(Tlong &a, int b, Tlong& result)
{
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
}



Tlong cell1, cell2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int gen;
    cin >> gen;
    input_long(cell1);
    input_long(cell2);
    int comp_res = compare(cell1,cell2);
    while (comp_res)
    {
        if (comp_res == -1)swap(cell1, cell2);
        divide_halflong_abs(cell1, 2, cell1);
        comp_res = compare(cell1, cell2);
    }
    out_long(cell1);
}
