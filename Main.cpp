
#include <bits/stdc++.h>
using namespace std;

struct point {
    int x = 0, y = 0;
};

istream& operator>>(istream& in, point& a)
{
    in >> a.x >> a.y;
    return in;
}

ostream& operator<< (ostream& out, point& a)
{
    out << a.x << ' ' << a.y << ' ';
    return out;
}

double dist(point a, point b)
{
    return  sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


void fill_arr(point m[], int& len)
{
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> m[i];
    }
}

long double haus(point tops[], int len)
{
    long double res = 0;
    for (int i = 0; i < len - 1; i++)
    {
        res += (double)(tops[i].x * tops[i + 1].y - tops[i + 1].x * tops[i].y)/2;
    }
    res += (double)(tops[len-1].x * tops[0].y - tops[0].x * tops[len-1].y)/2;
    res = abs(res);
    return res;
}

point tops[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int len;
    fill_arr(tops, len);
    cout << fixed << setprecision(7) << haus(tops, len) << "\n";
}