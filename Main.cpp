#include <bits/stdc++.h>
using namespace std;

const int Nmax = 2000;

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

int max_long(Tlong arr[], int len)
{
    int max = 0;
    for (int i = 1; i < len; i++)
    {
        if (compare(arr[max], arr[i]) == -1)max = i;
    }
    return max;
}

Tlong groups[200];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int groups_cnt, score_cnt, score;
    cin >> groups_cnt >> score_cnt;
    for (int i = 0; i < groups_cnt; i++)
    {
        groups[i].len = 1;
        groups[i].num[Nmax - 1] = 1;
        groups[i].sign = '+';
        for (int j = 0; j < score_cnt; j++)
        {
            cin >> score;
            multiply_halflong_abs(groups[i], score);
        }
    }
    cout << max_long(groups, groups_cnt)+1 << "\n";
}
