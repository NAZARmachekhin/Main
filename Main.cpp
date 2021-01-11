#include <bits/stdc++.h>
using namespace std;

struct point {
    double x = 0, y = 0;
};


double dist(point a, point b)
{
    return  sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double heron(point a, point b, point c)
{
    double p=(dist(a,b)+dist(b,c)+dist(a,c))/2;
    return sqrt(p * (p - dist(a, b)) * (p - dist(b, c)) * (p - dist(a, c)));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    point apoint, bpoint, cpoint;
    cin >> apoint.x>>apoint.y;
    cin >> bpoint.x>>bpoint.y;
    cin >> cpoint.x>>cpoint.y;
    cout << fixed << setprecision(3) << heron(apoint, bpoint, cpoint) << "\n";
}
