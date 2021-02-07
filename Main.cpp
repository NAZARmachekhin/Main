#include <bits/stdc++.h>
using namespace std;

string formating(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '%')s[i] = '5';
        if (s[i] == '&')s[i] = '6';
        if (s[i] == '~')s[i] = '1';
        if (s[i] == '@')s[i] = '2';
        if (s[i] == '#')s[i] = '3';
        if (s[i] == '$')s[i] = '4';
    }
    return s;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string order;
    while (cin>>order)
    {
        string stack = "";
        order = formating(order);
        stack += order[0];
        for (int i = 1; i < order.size(); i++)
        {
            if (stack[stack.size() - 1] + 1 == order[i])stack.erase(stack.size() - 1, 1);
            else stack += order[i];
        }
        if (stack=="")cout << "OK\n";
        else cout << "WRONG\n";
    }
}