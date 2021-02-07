#include <bits/stdc++.h>
using namespace std;

long long to_long(string s)
{
    long long res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        res *= 10;
        res += (s[i] - 48);
    }
    return res;
}

bool is_prime(long long n)
{
    if (n < 2)return false;
    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)return false;
    }
    return true;
}

bool num_check(string s)
{
    for (long long i = 0; i < s.size(); i++)
    {
        if (s[i] > '9' || s[i] < '0')return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("prime.in", "r", stdin);
    freopen("prime.out", "w", stdout);
    string word;
    int status = -1;
    while (cin >> word)
    {
        if (num_check(word))
        {
            if (is_prime(to_long(word)))
            {
                status = 1;
                cout << word << "\n";
            }
        }
    }
    if (status == -1 && word.size() != 0)cout << "-1\n";
    else if (word.size() == 0)cout << "NULL\n";
}