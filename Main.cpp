#include <bits/stdc++.h>
using namespace std;

void fill_arr(int m[], int& len)
{
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> m[i];
    }
}

int find_short(int m[], int dp[], int len)
{
    int dplen = 2;
    if (len == 2)return m[1] - m[0];
    dp[0] = m[1] - m[0];
    dp[1] = m[2] - m[0];
    for (int i = 2; i < len-1; i++)
    {
        dp[dplen] = m[i + 1] - m[i] + min(dp[dplen - 2], dp[dplen - 1]);
        dplen++;
    }
    return dp[dplen - 1];
}

int dp[10001];

int main()
{
    cin.tie(0); 
    cout.tie(0); 
    ios_base::sync_with_stdio(0);
    int len, points[101];
    fill_arr(points, len);
    sort(points, points + len);
    cout << find_short(points, dp, len) << "\n";
}