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

Tlong gcd(Tlong a, Tlong b)
{
    while (comp_zero(a) && comp_zero(b))
    {
        if (compare(a, b) == 1)a = mod_abs(a, b);
        else b = mod_abs(b, a);

    }
    if (comp_zero(a))return a;
    return b;
}

Tlong lcm(Tlong a, Tlong b)
{
    return divide_abs(multiply_abs(a, b), gcd(a, b));
}

void fill_arr(int m[], int& n)
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> m[i];
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

Tlong cycle(int m[], bool used[], int len)
{
    Tlong res,cycle_len;
    zero(res);
    res.num[Nmax - 1] = 1;
    int current=0;
    for (int i = 0; i < len; ++i)
    {
        if (!used[i])
        {
            zero(cycle_len);
            current = m[i];
            do
            {
                used[current - 1] = true;
                current = m[current - 1];
                plusplus(cycle_len);
            } while (current != m[i]);
            res = lcm(res, cycle_len);
        }
    }
    return res;
}

Tlong res,n1,n2;
int hides[15001]={0};
bool used[15001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int len;
    fill_arr(hides,len);
    out_long(cycle(hides, used,len));
}
