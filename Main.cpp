#include <bits/stdc++.h>
using namespace std;

int tree[4000001] = { 0 };


void build(int left, int right, int current, int input[])
{
	if (left == right)
	{
		tree[current] = input[left];
		return;
	}
	int median = ((left + right) >> 1);
	build(left, median, (current << 1), input);
	build(median + 1, right, (current << 1) | 1, input);
	tree[current] = min(tree[current << 1], tree[(current << 1) | 1]);
}


int request(int left, int right, int reqLeft, int reqRight, int current)
{
	if (reqLeft > reqRight)return 2000000000;
	//cout << left << " " << right << "    " << reqLeft << " " << reqRight << "\n";
	if (reqLeft == left && reqRight == right) return tree[current];
	int median = ((left + right) >> 1);
	//cout << max(left, median + 1) << "\n";
	return min(request(left, median, reqLeft, min(reqRight, median), current << 1),request(median + 1, right, max(median + 1, reqLeft), reqRight, (current << 1) | 1));
}

void fill_arr(int m[], int& len)
{
	cin >> len;
	for (int i = 0; i < len; i++)cin >> m[i];
}

int input[1000001] = { 0 };

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int len, tests;
	fill_arr(input, len);
	build(0, len - 1, 1, input);
	cin >> tests;
	for (int i = 0; i < tests; i++)
	{
		int left, right;
		cin >> left >> right;
		cout << request(0, len - 1, left - 1, right - 1, 1) << "\n";
	}
}