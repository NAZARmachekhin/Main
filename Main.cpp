#include <bits/stdc++.h>
using namespace std;

void fill_arr(long long m[1001][1001], int& isize, int& jsize)
{
    cin >> isize >> jsize;
    for (int i = 0; i < isize; i++)
    {
        for (int j = 0; j < jsize; j++)
            cin >> m[i][j];
    }
}

void build_route(long long dp[1001][1001], int isize, int jsize)
{
    for (int i = 0; i < isize; i++)
    {
        for (int j = 0; j < jsize; j++)
        {
            if (!i && j)dp[i][j] += dp[i][j - 1];
            if (i && !j)dp[i][j] += dp[i-1][j];
            if (i && j) dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

void find_route(long long dp[1001][1001], int isize, int jsize, int route[3000][2])
{
    int i = isize-1, j = jsize-1;
    while (i >0 || j >0)
    {
        route[i + j][0] = i + 1;
        route[i + j][1] = j + 1;
        if (!i && j)j--;
        else if (i && !j)i--;
        else if (i && j)
        {
            if (dp[i][j - 1] > dp[i - 1][j])i--;
            else j--;
        }
    }
    route[0][0] = 1;
    route[0][1] = 1;
}

void cout_route(long long dp[1001][1001], int isize, int jsize)
{
    cout << dp[isize - 1][jsize - 1] << "\n";
    cout << isize + jsize - 1 << "\n";
    int route[3000][2];
    find_route(dp, isize, jsize, route);
    for (int i = 0; i < isize + jsize - 1; i++)
        cout << route[i][0] << " " << route[i][1] << "\n";
}

long long dp[1001][1001] = { {0} };

int main()
{
    cin.tie(0); 
    cout.tie(0); 
    ios_base::sync_with_stdio(0);
    int isize, jsize;
    fill_arr(dp, isize, jsize);
    build_route(dp, isize, jsize);
    cout_route(dp, isize, jsize);
}