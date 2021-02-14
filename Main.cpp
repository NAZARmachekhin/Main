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

int find_num(string text, int beg)
{
    while (!isdigit(text[beg]) && beg < text.size())beg++;
    return beg;
}

int num_len(long long n)
{
    int res = 0;
    while (n != 0)
    {
        n /= 10;
        res++;
    }
    return res;
}

bool armstrong(long long n)
{
    long long res = 0;
    long long etalon = n;
    long long len = num_len(n);
    for (int i = 0; i < len; ++i)
    {
        res += pow(n % 10, len);
        n /= 10;
    }
    return (res == etalon);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("armstrong.in", "r", stdin);
    freopen("armstrong.out", "w", stdout);
    string text,word;
    while (cin >> word)text += " " + word;
    int beg = 0;
    int end = 0;
    bool excist=false;
    while (beg < text.size() && end < text.size())
    {
        beg = find_num(text, beg);
        end = text.find_first_of(" .,:;!?\"[]", beg);
        if (end == -1)end = text.size();
        else
        {
            if (armstrong(to_long(text.substr(beg, end - beg))))
            {
                excist = true;
                cout << text.substr(beg, end - beg) << "\n";
            }
        }
        beg = end;
    }
    if (!excist)cout << "-1\n";
}