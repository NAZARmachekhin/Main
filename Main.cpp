#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    unsigned long long plus, Xor;
    cin >> plus >> Xor;
    if ((plus - Xor) & 1) cout << -1<<"\n";
    else cout << ((plus - Xor) >> 1) << " "<<plus- ((plus - Xor) >> 1) <<"\n";
}


