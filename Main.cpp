#include <bits/stdc++.h>
using namespace std;

void get_string(string& s)
{
    string line;
    getline(cin, s);
    while (getline(cin, line))
        s += "\n" + line;
}

bool count_symb(string s, long long m[])
{
    bool present = false;
    for (long long i = 0; i < s.length(); ++i)
    {
        if (isalpha(s[i]))
        {
            present = true;
            m[tolower(s[i]) - 'a']++;
        }
    }
    return present;
}

void out_arr(long long m[])
{
    for (int i = 0; i < 26; i++)
    {
        cout << (char)toupper(i + 'a') << " " << m[i]<<"\n";
    }
}

long long symbol[26]={0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("analiz.in", "r", stdin);
    freopen("analiz.out", "w", stdout);
    string text;
    get_string(text);
    if (count_symb(text, symbol))
        out_arr(symbol);
    else cout << "-1\n";
}