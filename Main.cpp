#include <bits/stdc++.h>
using namespace std;


void fill_vector(vector<int> & a, int &n,int &k)
{
    cin >> n >> k;
    int el = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> el;
        a.push_back(el);
    }
}

void out_set(multiset<int> a)
{
    for (multiset<int>::iterator it = a.begin(); it != a.end(); ++it)
    {
        cout << (*it) << " ";
    }
    cout << "\n";
}

void fill_first_k(vector<int> a, multiset<int>& b, int k)
{
    for (int i = 0; i < k; i++)
    {
        b.insert(a[i]);
    }
}



vector<int> nums;
multiset<int> sub_seq;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    fill_vector(nums, n, k);
    fill_first_k(nums, sub_seq, k);
    for (int i = 0; i < n - k; i++)
    {
        int j = i + k;
        cout << (*sub_seq.begin()) << " ";
        sub_seq.erase(sub_seq.find(nums[i]));
        sub_seq.insert(nums[j]);
    }
    cout << (*sub_seq.begin()) << "\n";
}