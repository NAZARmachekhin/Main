#include <bits/stdc++.h>
using namespace std;








bool empty(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))return false;
    }
    return true;
}

string open_brackets(string s)
{
    char curr='+';
    char mod='+';
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='+' || s[i]=='-')
            curr=s[i];
        else if (s[i] == '(')
        {
            s.erase(i, 1);
            while (s[i] != ')' && i < s.size())
            {
                if (s[i] == '+' || s[i] == '-')
                    mod = s[i];
                if (s[i] == '+' || s[i] == '-')
                {
                    if (curr == mod)s[i] = '+';
                    else s[i] = '-';
                }
                i++;
            }
            s.erase(i, 1);
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        while (s[i] != '-' && s[i] != '+' && i < s.size())i++;
        if ((s[i] == '+' || s[i] == '-') && (s[i+1] == '+' || s[i+1] == '-') && i + 1 < s.size())
            s.erase(i, 1);
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("expression_3.in", "r", stdin);
    freopen("expression_3.out", "w", stdout);
    string line;
    while (getline(cin, line))
    {
        if (empty(line)) cout << "NULL\n";
        else
        {
            int beg = 0;
            int end = 0;
            long long res = 0;
            line = open_brackets(line);
            //cout << line << "\n";
            while (beg < line.size())
            {
                if (line[beg] == '+' || line[end] == '-')end++;
                while (line[end] != '-' && line[end] != '+' && end < line.size())end++;
                res += stoll(line.substr(beg,end-beg));
                beg = end;
            }
            cout << res << "\n";
        }
    }
    return 0;
}