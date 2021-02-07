#include <bits/stdc++.h>
using namespace std;

string invertion(string s)
{
    for (long long i = 0; i < s.length() / 2; i++)
    {
        swap(s[i], s[s.length() - i - 1]);
    }
    return s;
}


bool hight_year(int year)
{
    if (year % 400 == 0)return true;
    if (year % 100 != 0 && year % 4 == 0)return true;
    return false;
}

int days_in_month(int month, int year)
{
    if (month == 2)
    {
        if (hight_year(year))return 29;
        return 28;
    }
    if (month <= 7)return 30 + month % 2;
    return 30 + 1 - month % 2;
}

int to_int(string s, int beg, int cnt)
{
    int res = 0;
    for (int i = beg; i < beg + cnt; i++)
    {
        res *= 10;
        res += (s[i] - '0');
    }
    return res;
}

bool check_date(string s)
{
    int month = to_int(s, 2, 2);
    int day = to_int(s,0,2);
    int year = to_int(s,4,4);
    if (month > 12 || month == 0 || day==0 || day>days_in_month(month, year))return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string date;
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> date;
        date.erase(2, 1);
        date.erase(4, 1);
        date = invertion(date);
        if (check_date(date))cout << "YES\n";
        else cout << "NO\n";
    }
}