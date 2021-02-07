#include <bits/stdc++.h>
using namespace std;



bool is_polyndrom_num(string s)
{
    if (s.size() % 2 == 1 && isalpha(s[s.size() / 2]))return false;
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])return false;
        if (isalpha(s[i]) || isalpha(s[s.size() - 1 - i]))return false;
    }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string word;
    bool excist = false;
    while (cin >> word)
    {
        if (is_polyndrom_num(word))
        {
            excist = true;
            cout << word << "\n";
        }
    }
    if (!excist)cout << "The notepad is clean.\n";
}