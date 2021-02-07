#include <bits/stdc++.h>
using namespace std;

int formate(char s)
{
    if (s == 'I') return 1;
    if (s == 'V') return 5;
    if (s == 'X') return 10;
    if (s == 'L') return 50;
    if (s == 'D') return 500;
    if (s == 'C') return 100;
    if (s == 'M') return 1000;
}

long long translate_rome(string s)
{
    long long res = 0;
    int curr = 0;
    for (int i = 0; i < s.size()-1; i++)
    {
        curr = formate(s[i]);
        if (curr < formate(s[i + 1]))curr *= -1;
        res += curr;
    }
    res += formate(s[s.size() - 1]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string date;
    cin >> date;
    cout << translate_rome(date) << "\n";
}