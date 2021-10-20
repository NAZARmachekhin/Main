#include <bits/stdc++.h>
using namespace std;

long long tree[4000001] = { 0 };


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
	tree[current] = tree[current << 1]+ tree[(current << 1) | 1];
}

void update(int left, int right, int current, int index, int value)
{
	if (left == right)
	{
		tree[current] = value;
		return;
	}
	int median = (left + right) >> 1;
	if (index <= median) update(left, median, current << 1, index, value);
	else update(median + 1, right, (current << 1) + 1, index, value);
	tree[current] = tree[current << 1] + tree[(current << 1) + 1];
}

long long request(int left, int right, int reqLeft, int reqRight, int current)
{
	if (reqLeft > reqRight)return 0;
	if (reqLeft == left && reqRight == right) return tree[current];
	int median = ((left + right) >> 1);
	return request(left, median, reqLeft, min(reqRight, median), current << 1) + request(median + 1, right, max(median + 1, reqLeft), reqRight, (current << 1) | 1);
}

void fill_arr(int m[], int& len, int &tests)
{
	cin >> len>>tests;
	for (int i = 0; i < len; i++)cin >> m[i];
}

int input[1000001] = { 0 };

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int len, tests;
	fill_arr(input, len,tests);
	build(0, len - 1, 1, input);
	for (int i = 0; i < tests; i++)
	{
		int left, right;
		char req;
		cin >>req>> left >> right;
		if (req == '?')cout << request(0, len - 1, left - 1, right - 1, 1) << "\n";
		else
		{
			update(0, len - 1, 1, left-1, right);

		}
	}
}