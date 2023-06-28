#include <algorithm>
#include <iostream>
#include <vector>

struct Node
{
	int idx;
	int value;
};

void update(int current, int left, int right, int target, long long* tree)
{
	// 음수는 여기서 필터링
	if(target < left || target > right)
	{
		return;
	}

	if(left == right)
	{
		tree[current] += 1;
		return;
	}

	const auto mid = (left + right) / 2;
	update(current * 2, left, mid, target, tree);
	update(current * 2 + 1, mid + 1, right, target, tree);

	tree[current] = tree[current * 2] + tree[current * 2 + 1];
}

long long query(int current, int left, int end, int range_left, int range_right, long long* tree)
{
	if(range_left > end || range_right < left)
	{
		return 0;
	}

	if(range_left <= left && range_right >= end)
	{
		return tree[current];
	}

	const auto mid = (left + end) / 2;

	long long l = query(current * 2, left, mid, range_left, range_right, tree);
	long long r = query((current * 2) + 1, mid + 1, end, range_left, range_right, tree);
	return l + r;
}

int main(void)
{
	int n;
	std::cin >> n;

	Node arr[500000 + 1]{};
	long long tree[(500000 * 4) + 1]{};

	for(int i = 1; i <= n; ++i)
	{
		std::cin >> arr[i].value;
		arr[i].idx = i;
	}

	std::sort(arr + 1, arr + n + 1, [](const Node& a, const Node& b)
	{
		if(a.value < b.value)
		{
			return true;
		}

		if(a.value == b.value)
		{
			if(a.idx < b.idx)
			{
				return true;
			}
		}

		return false;
	});

	long long cnt = 0;

	for(int i = 1; i <= n; ++i)
	{
		const auto& [idx, _] = arr[i];
		cnt += query(1, 1, n, idx + 1, n, tree);
		update(1, 1, n, idx, tree);
	}

	std::cout << cnt;
}