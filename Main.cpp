#include <bits/stdc++.h>
using namespace std;






int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("expression_1.in", "r", stdin);
    freopen("expression_1.out", "w", stdout);
    string expr, a, b;
    char sign;
    double res;
    while (getline(cin, expr))
    {
        if (expr != "")
        {
            a = expr.substr(0, expr.find_first_of("+-/* ", 2));
            b = expr.substr(a.size() + 1, expr.size() - a.size());
            sign = expr[expr.find_first_of("+-/*", 2)];
            if (stod(b) ==0 && sign == '/')cout << "Error\n";
            else
            {
                if (sign == '+')res = stod(a) + stod(b);
                if (sign == '-')res = stod(a) - stod(b);
                if (sign == '*')res = stod(a) * stod(b);
                if (sign == '/')res = stod(a) / stod(b);
                if (res == round(res))cout << fixed << setprecision(0) << res << "\n";
                else cout << fixed << setprecision(4) << res << "\n";
            }
        }
        else cout << "NULL\n";
    }
}