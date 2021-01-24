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

double dist(point a, point b)
{
    return  sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    point sw,ne,human;
    cin >> sw >> ne>>human;
    if (human.y > ne.y) cout << "N";
    else if (human.y<sw.y)cout << "S";
    if (human.x > ne.x)cout << "E";
    else if (human.x < sw.x)cout << "W";
    cout << "\n";
}