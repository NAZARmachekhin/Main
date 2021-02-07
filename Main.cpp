#include <bits/stdc++.h>
using namespace std;

int search(string m[], int len, string a)
{
    for (int i = 0; i < len; i++)
        if (m[i] == a)return i;
    return -1;
}

string decode(string pass, string alpha[])
{
    string answ;
    char symb;
    for (int i = 0; i < pass.size(); i += 10)
    {
        symb = search(alpha, 10, pass.substr(i, 10)) + '0';
        if (!isalnum(symb))return "-1";
        else answ += symb;
    }
    return answ;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string pass;
    string alpha[10];
    cin >> pass;
    for (int i = 0; i < 10; i++)cin >> alpha[i];
    cout << decode(pass, alpha) << "\n";
}