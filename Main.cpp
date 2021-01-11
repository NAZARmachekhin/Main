#include <bits/stdc++.h>
using namespace std;

struct point {
    double x = 0, y = 0;
};


double dist(point a, point b)
{
    return  sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    point curr , prev, first;
    int count = 0;
    double p=0;
    cin >> count;
    cin >> first.x >> first.y;
    curr = first;
    for (int i = 0; i < count-1; i++)
    {
        prev = curr;
        cin >> curr.x >> curr.y;
        p += dist(prev, curr);
    }
    p += dist(curr, first);
    cout << fixed << setprecision(3) << p << "\n";
}
