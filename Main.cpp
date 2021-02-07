#include <bits/stdc++.h>
using namespace std;

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

int time_min(string s)
{
    return to_int(s, 0, 2) * 60 + to_int(s,3, 2);
}

string time_str(int t)
{
    t %= 1440;
    string time="";
    if (t / 60<10)time += '0';
    time+= to_string(int(t / 60))+':';
    if (t % 60 < 10)time += '0';
    time += to_string(t % 60);
    return time;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("hedgehog.dat", "r", stdin);
    //freopen("hedgehog.res", "w", stdout);
    string start;
    cin >> start;
    int len,next=0;
    cin >> len;
    int clock = time_min(start);
    for (int i = 0; i < len; i++)
    {
        clock += next;
        cout << time_str(clock)<<"\n";
        cin >> next;
    }
}