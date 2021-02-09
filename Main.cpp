#include <bits/stdc++.h>
using namespace std;

int phrase_end(string& s, int& beg)
{
    while (!isalpha(s[beg]) && !isalnum(s[beg]) && s[beg] != ' ' && beg < s.size())beg++;
    for (int i = beg; i < s.size(); i++)
    {
        if (s[i] == '!' || s[i] == '.' || s[i] == '?')
        {
            return i;
        }
    }
    return s.size();
}

void cut_spaces_forward(string& s, int& end)
{
    while (end > 0 && s[end] == ' ')--end;
}

bool polindrom(string& s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        while (s[i] == ' ' && i < s.size() - 1)i++;
        while (s[j] == ' ' && j > 0)j--;
        if (i < j && toupper(s[i]) != toupper(s[j]))return false;
        i++;
        j--;
    }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("palindrom.in", "r", stdin);
    freopen("palindrom.out", "w", stdout);
    string line, phrase;
    bool excist = false;
    while (getline(cin, line))
    {
        int beg = 0, end = 0;
        while (end < line.size() - 1)
        {
            end = phrase_end(line, beg);
            cut_spaces_forward(line, end);
            phrase = line.substr(beg, end - beg);
            beg = end + 1;
            if (polindrom(phrase) && phrase != "")
            {
                excist = true;
                cout << phrase << "\n";
            }
        }
    }
    if (!excist)cout << "-1\n";
}