#include <bits/stdc++.h>
using namespace std;



string translate(int num)
{
    string alpha = "MDCLXVI";
    int value[7] = { 1000, 500, 100, 50, 10, 5, 1 };
    string rome = "";
    for (int i = 0; i < alpha.size(); i++)
    {
        for (; num / value[i];)
        {
            rome += alpha[i];
            num -= value[i];
        }
        if (i < alpha.size() - 2 && num / value[i + 2] == 9)
        {
            rome += alpha[i + 2];
            rome += alpha[i];
            num -= 9 * value[i+2];
        }
        if (i!=alpha.size()-1 && num / value[i + 1] == 4)
        {
            rome += alpha[i+1];
            rome += alpha[i];
            num -= 4 * value[i + 1];

        }

    }
    return rome;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
    cin >> num;
    cout << translate(num) << "\n";
}