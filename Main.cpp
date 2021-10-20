#include <bits/stdc++.h>
using namespace std;

struct node
{
	long long weight = 0;
	int ammount = 0;
};

node tree[4000001];


void build(int left, int right, int current, int input[])
{
	if (left == right)
	{
		tree[current].weight = input[left];
		tree[current].ammount = 1;
		return;
	}
	int median = ((left + right) >> 1);
	build(left, median, (current << 1), input);
	build(median + 1, right, (current << 1) | 1, input);
	tree[current].ammount = tree[current << 1].ammount+ tree[(current << 1) | 1].ammount;
	tree[current].weight = tree[current << 1].weight+ tree[(current << 1) | 1].weight;
}

void update(int left, int right, int current, int index, int value)
{
	if (left == right)
	{
		tree[current].weight = value;
		return;
	}
	int median = (left + right) >> 1;
	if (index <= median) update(left, median, current << 1, index, value);
	else update(median + 1, right, (current << 1) + 1, index, value);
	tree[current].weight = tree[current << 1].weight + tree[(current << 1) + 1].weight;
}

long long request(int left, int right, long long &weight,int current)
{
	if (left > right || weight<=0)return 0;
	if (left == right && weight - tree[current].weight < 0)
	{
		weight = 0;
		return 0;
	}
	if (left == right || weight>=tree[current].weight)
	{
		weight -= tree[current].weight;
		return tree[current].ammount;
	}
	int median = ((left + right) >> 1);
	return request(left, median, weight, current << 1)+request(median + 1, right, weight, (current << 1) | 1);
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
	cin >> tests;
	build(0, len - 1, 1, input);
	for (int i = 0; i < tests; i++)
	{
		long long param1,param2;
		int req;
		cin >>req>> left >> right;
		if (req == 1)
		{
			cin >> param1;
			cout << request(0, len - 1, param1, 1) << "\n";
			//cout << param1 << "-----\n";
		}
		else
		{
			cin >> param1 >> param2;
			update(0, len - 1, 1, param1-1, param2);
		}
	}
}