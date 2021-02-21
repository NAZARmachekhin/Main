#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("expression_2.in", "r", stdin);
    freopen("expression_2.out", "w", stdout);
    string expr, num;
    long long res;
    int beg = 0;
    bool overfill = false;
    while (getline(cin, expr))
    {
        overfill = false;
        res = 0;
        beg = 0;
        long long prev = 0;
        if (expr != "")
        {
            while (beg != -1 && !overfill)
            {
                prev = res;
                if (beg != 0)beg++;
                num = expr.substr(beg, expr.find_first_of("+-", beg) - beg);
                if (beg != 0)
                {
                    if (expr[beg - 1] == '+')
                    {
                        res += stoll(num);
                        if (prev >= 0 && res < 0)overfill = true;
                    }
                    else
                    {
                        res -= stoll(num);
                        if (prev <= 0 && res>0)overfill = true;
                    }
                }
                else
                {
                    res = stoll(num);
                }
                beg = expr.find_first_of("+-", beg);
            }
            if (overfill)cout << "Error\n";
            else cout << res << "\n";
        }
        else cout << "NULL\n";
    }
}