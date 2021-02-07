#include <bits/stdc++.h>
using namespace std;


int sum_of_digits(string s)
{
    int res=0;
    for (int i = 0; i < s.size(); i++)res += s[i] - '0';
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string money;
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> money;
        if (sum_of_digits(money) % 3 == 0)cout << "YES\n";
        else cout << "NO\n";
    }
}