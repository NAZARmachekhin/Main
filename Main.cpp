#include <bits/stdc++.h>
using namespace std;

struct point {
    double x = 0, y = 0;
};


double dist(point a, point b)
{
    return  sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void fill_arr(point m[], int& len)
{
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> m[i].x >> m[i].y;
    }
}

double max_dist(point m[], int len, point beg)
{
    double etalon = 0;
    for (int i = 0; i < len; i++)
    {
        if (etalon < dist(beg, m[i]))etalon = dist(beg, m[i]);
    }
    return etalon;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    point m[10001], beg;
    int len;
    fill_arr(m, len);
    double max_d = max_dist(m, len, beg);
    for (int i = 0; i < len; i++)
    {
        if (dist(beg, m[i]) == max_d)cout << m[i].x << " " << m[i].y << "\n";
    }
}
