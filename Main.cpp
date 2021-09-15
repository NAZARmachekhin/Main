#include <bits/stdc++.h>
using namespace std;


void fill_arr(int m[], int& len)
{
	cin >> len;
	for (int i = 1; i <= len; i++)
	{
		cin >> m[i];
		m[i] += m[i - 1];
	}
}

int input[1000001] = { 0 };

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int len, tests;
	fill_arr(input, len);
	cin >> tests;
	for (int i = 0; i < tests; i++)
	{
		int left, right;
		cin >> left >> right;
		cout << input[right]-input[left-1] << "\n";
	}
}