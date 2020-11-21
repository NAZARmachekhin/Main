#include <bits/stdc++.h>
using namespace std;

const int Nmax = 2700;

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

void plusplus(Tlong& n)
{
    int cnt = Nmax-1;
    while(n.num[cnt]==9)
    {
        n.num[cnt] = 0;
        cnt--;
    }
    n.num[cnt]++;
    if (n.num[Nmax - n.len- 1])n.len++;
}


void multiply_halflong_abs(Tlong& a, int b)
{
    int next = 0;
    int multiply = 0;
    for (int i = 1; i <= Nmax; i++)
    {
        multiply=(a.num[Nmax - i] * b + next);
        a.num[Nmax - i] = multiply % 10;
        next = multiply / 10;
        if (a.num[Nmax - i])a.len = i;
    }
}





void factorial(int a, Tlong& res)
{
    res.len = 1;
    res.num[Nmax - 1] = 1;
    res.sign = '+';
    while (a != 0)
    {
        multiply_halflong_abs(res, a);
        a--;
    }
}

Tlong num;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> a;
    factorial(a, num);
    out_long(num);
}
