#include <bits/stdc++.h>

using namespace std;

bool is_in(char a, string s)
{
    for (int i = 0; i < s.size(); i++)
        if (a == s[i])return true;
    return false;
}

int count_dif_alpha(string s)
{
    int res = 0;
    bool map[40] = { 0 };
    for (int i = 0; i < s.size(); i++)
        if (isalpha(s[i]))map[toupper(s[i]) - 'A'] = 1;
    for (int i = 0; i < 40; i++)
        res += map[i];
    return res;
}

int main()
{
    freopen("maxsymbol.in", "r", stdin);
    freopen("maxsymbol.out", "w", stdout);
    string line,word, res = "";
    int maxS = 0;
    bool empty = true;
    while (getline(cin, line))
    {
        if (line != "")empty=false;
        int beg = 0;
        int end = line.find_first_of(" .,;:!?\"[]", beg);
        while (end != -1&& end < line.size())
        {
            word = line.substr(beg, end - beg);
            while (is_in(line[end], " .,;:!?\"][") && end < line.size())end++;
            beg = end;
            end = line.find_first_of(" .,;:!?\"][", beg);
            if (count_dif_alpha(word) == maxS && maxS > 0)
                res += word + ' ';
            if (count_dif_alpha(word) > maxS)
            {
                maxS = count_dif_alpha(word);
                res = word + ' ';
            }
            
        }
        word = line.substr(beg, line.size() - beg);
        if (count_dif_alpha(word) == maxS && maxS > 0)
            res += word + ' ';
        if (count_dif_alpha(word) > maxS)
        {
            maxS = count_dif_alpha(word);
            res = word + ' ';
        }
    }
    if (empty)cout << "NULL\n";
    else if (maxS == 0)cout << "-1\n";
    else cout << res << "\n";
    return 0;
}