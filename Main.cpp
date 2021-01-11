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
    cout << fixed << setprecision(3) << (2 / (bside+cside)) * (sqrt(bside*cside*phalf * (phalf-aside))) << "\n";
    cout << fixed << setprecision(3) << (2 / (aside+cside)) * (sqrt(aside*cside*phalf * (phalf-bside))) << "\n";
    cout << fixed << setprecision(3) << (2 / (bside+aside)) * (sqrt(bside*aside*phalf * (phalf-cside))) << "\n";

}
