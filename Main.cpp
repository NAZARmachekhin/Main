#include <bits/stdc++.h>
using namespace std;

struct twonum
{
	long long min = 200000;
	long long max = -200000;
};


twonum tree[400000];


void build(int left, int right, int current)
{
	if (left == right)
	{
		long long arg = left + 1;
		tree[current].max = (arg*arg)%(long long)12345+(arg*arg*arg)%(long long)23456;
		tree[current].min = tree[current].max;
		return;
	}
	int median = ((left + right) >> 1);
	build(left, median, (current << 1));
	build(median + 1, right, (current << 1) | 1);
	twonum arg1 = tree[current << 1];
	twonum arg2 = tree[(current << 1) | 1];
	tree[current].min = min(arg1.min, arg2.min);
	tree[current].max = max(arg1.max, arg2.max);
}

void update(int left, int right, int current, int index, int value)
{
	if (left == right)
	{
		tree[current].max = value;
		tree[current].min = value;
		return;
	}
	int median = (left + right) >> 1;
	if (index <= median) update(left, median, current << 1, index, value);
	else update(median + 1, right, (current << 1) + 1, index, value);
	twonum arg1 = tree[current << 1];
	twonum arg2 = tree[(current << 1) | 1];
	tree[current].min = min(arg1.min, arg2.min);
	tree[current].max = max(arg1.max, arg2.max);
}


twonum request(int left, int right, int reqLeft, int reqRight, int current)
{
	twonum def;
	if (reqLeft > reqRight)return def;
	if (reqLeft == left && reqRight == right) return tree[current];
	int median = ((left + right) >> 1);
	twonum arg1 = request(left, median, reqLeft, min(reqRight, median), current << 1);
	twonum arg2 = request(median + 1, right, max(median + 1, reqLeft), reqRight, (current << 1) | 1);
	twonum res;
	res.min = min(arg1.min, arg2.min);
	res.max = max(arg1.max, arg2.max);
	return res;
}


int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int tests;
	cin >> tests;
	build(0, 99999, 1);
	for (int i = 0; i < tests; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x > 0)
		{
			twonum res = request(0, 99999, x-1, y-1, 1);
			cout << res.max - res.min << "\n";
		}
		else update(0, 99999, 1, abs(x)-1, y);
	}
	cout << "\n";
}