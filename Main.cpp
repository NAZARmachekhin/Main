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

void fill_arr(point m[], int& len)
{
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> m[i];
    }
}

bool line_side(point a, point b, point n)
{
    return (n.x - a.x) * (b.y - a.y) > (n.y - a.y) * (b.x - a.x);
}

bool opuklyy(point m[], int len)
{
    bool side = line_side(m[len-1], m[0], m[1]);
    for (int i = 0; i < len - 2; i++)
    {
        if (side != line_side(m[i], m[i + 1], m[i + 2]))return false;
    }
    return true;
}

point m[100001];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int len;
    fill_arr(m, len);
    if (opuklyy(m, len))cout << "YES\n";
    else cout << "NO\n";
}