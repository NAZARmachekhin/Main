#include <bits/stdc++.h>
using namespace std;

struct point {
    double x = 0, y = 0;
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


int line_contain(point a, point b, point n)
{
    if ((n.x - a.x) * (b.y - a.y) == (n.y - a.y) * (b.x - a.x))return 0;
    if ((n.x - a.x) * (b.y - a.y) > (n.y - a.y) * (b.x - a.x)) return 1;
    if ((n.x - a.x) * (b.y - a.y) < (n.y - a.y) * (b.x - a.x)) return -1;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    point base1, base2, point1, point2;
    cin >> base1 >> base2 >> point1 >> point2;
    int res=0;
    if (line_contain(base1, base2, point1) == 0)res += 1;
    if (line_contain(base1, base2, point2) == 0)res += 2;
    if (res > 0)cout << res << "\n";
    else
    {
        res += line_contain(base1, base2, point1) + line_contain(base1, base2, point2);
        if (res == 0)cout << "-2\n";
        else cout << "-1\n";
    }
}