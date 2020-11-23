#include <bits/stdc++.h>
using namespace std;

const int Nmax = 1000001;

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
    int cnt = Nmax - 1;
    for (; n.num[cnt]==9; --cnt)
    {
        n.num[cnt] = 0;
    }
    ++n.num[cnt];
    if (n.num[Nmax - n.len - 1])++n.len;
}




Tlong num;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        input_long(num);
        num.num[Nmax-num.len - 1] = 0;
        plusplus(num);
        out_long(num);
        cout << "\n";
    }
}
