#include <bits/stdc++.h>
using namespace std;

struct point {
    double x = 0, y = 0;
};




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double aside, bside, cside;
    cin >> aside >> bside >> cside;
    double phalf = (aside + bside + cside) / 2;
    cout << fixed << setprecision(3) << (2 / aside) * (sqrt(phalf * (phalf - aside) * (phalf - bside) * (phalf - cside))) << "\n";
    cout << fixed << setprecision(3) << (2 / bside) * (sqrt(phalf * (phalf - aside) * (phalf - bside) * (phalf - cside))) << "\n";
    cout << fixed << setprecision(3) << (2 / cside) * (sqrt(phalf * (phalf - aside) * (phalf - bside) * (phalf - cside))) << "\n";

}
