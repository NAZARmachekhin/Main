#include <bits/stdc++.h>
using namespace std;

const int Nmax = 300;

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
    if (n.sign == '-')
    {
        cout << '-';
    }
    for (int i = 0; i < n.len; i++)
    {
        cout << n.num[Nmax - n.len + i];
    }
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
        while (result.num[Nmax - result.len] == 0 && result.len)result.len--;
    }
    return result;
}

int mod_halflong_abs(Tlong& a, int b)
{
    int res;
    if (b == 0) res = 0;
    else
    {
        int dif = 0;
        for (int i = 0; i < a.len; i++)
        {
            dif = dif * 10 + a.num[Nmax - a.len + i];
            dif = dif % b;
        }
        res = dif;
    }
    return res;
}

bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (!n % i)return false;
    }
    return true;
}

int next_prime(int start)
{
    start++;
    while (!is_prime(start)) start++;
    return start;
}

void split(Tlong& a, int primes[])
{
    int div = 2;
    while (!(a.len==1 && a.num[Nmax-1]==1))
    {
        while (!mod_halflong_abs(a, div))
        {
            a=divide_halflong_abs(a, div);
            primes[div]++;
        }
        div=next_prime(div);
    }
}

void out_primes(int p[])
{
    bool first = true;
    for (int i = 0; i < 500000; i++)
    {
        if (p[i])
        {
            for (int j = i; j>0; j /= 10)cout << " ";
            if (p[i] > 1)cout << p[i];
            cout << " ";
        }
    }
    cout << "\n";
    for (int i = 0; i < 500000; i++)
    {
        if (p[i])
        {
            if (first)first = false;
            else cout << "*";
            cout << i;
            if (p[i] > 1) for (int j = p[i]; j > 0; j /= 10) cout << " ";
        }
    }
    cout << "\n";
}

Tlong a,b,res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input_long(a);
    input_long(b);
    out_long(res);
}
