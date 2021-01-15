
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
    double p = (dist(a, b) + dist(b, c) + dist(a, c)) / 2;
    return sqrt(p * (p - dist(a, b)) * (p - dist(b, c)) * (p - dist(a, c)));
}

void fill_arr(point m[], int& len)
{
    for (int i = 0; i < len; i++)
    {
        cin >> m[i].x >> m[i].y;
    }
}

bool inside_triangle(point tops[], point n)
{
    double s = heron(tops[0],tops[1],tops[2]);
    s -= heron(tops[0], tops[1], n);
    s -= heron(tops[1], tops[2], n);
    s -= heron(tops[2], tops[0], n);
    return abs(s) <=0.00001;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int len = 3;
    point tops[3],curr;
    fill_arr(tops, len);
    int count, answ=0;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> curr.x >> curr.y;
        if (inside_triangle(tops, curr))answ++;
    }
    cout << answ << "\n";
}