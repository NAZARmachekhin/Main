#include <bits/stdc++.h>
using namespace std;


int location(string s)
{
    int res=s[0]-'(';
    for (int i = 1; i < s.size(); i++)
    {
        if ((int)(s[i] - '(') == res)return -1;
        res = s[i] - '(';
    }
    if (s[0]==')')return -1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string route;
    cin >> route;
    int loc=location(route);
    if (loc == 0)cout << "INSIDE\n";
    else if (loc == 1)cout << "OUTSIDE\n";
    else cout << "ERROR\n";
}