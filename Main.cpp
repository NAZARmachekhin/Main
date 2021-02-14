#include <bits/stdc++.h>
using namespace std;

int power(int n, int p) {
    int res = 1;
    while (p)
        if (p %2) {
            res *= n;
            --p;
        }
        else {
            n *= n;
            p/=2;
        }
    return res;
}


long long decimal(string s, int base)
{
    long long res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[s.size() - i - 1]-'0' >= base && isdigit(s[s.size() - 1 - i])) || (s[s.size() - i - 1] - 'A' + 10 >= base && isalpha(s[s.size() - 1 - i])))
        {
            return -1;
        }
        if (isdigit(s[s.size()-i-1])) res += (s[s.size() - i - 1] - '0') * power(base, i);
        else res += (s[s.size() - i - 1] - 'A' + 10) * power(base, i);
    }
    return res;
}

int base(string a, string b, string c)
{
    for (int i = 36; i > 1; i--)
    {
        if (decimal(a, i) + decimal(b, i) == decimal(c, i) && decimal(a, i - 1) + decimal(b, i - 1) != decimal(c, i - 1))return i;
        
    }
    return - 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string numa,numb,numc;
    long long sum;
    getline(cin, numa, '+');
    getline(cin, numb, '=');
    getline(cin, numc);
    cout << base(numa, numb, numc) << "\n";
}