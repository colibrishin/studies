#include <iostream>
#include <queue>

using Bitmask = int;
Bitmask classroom[12]{};
Bitmask dp[12][1 << 12]{};
using Seatinfo = std::pair<Bitmask, int>;

int row(const int i, Bitmask previous_bitmask, int m, int n)
{
	if(i == n)
	{
		return 0;
	}

	if(dp[i][previous_bitmask] != -1)
	{
		return dp[i][previous_bitmask];
	}

	Bitmask& ret = dp[i][previous_bitmask];
	ret = 0;

	std::deque<Seatinfo> q;

	Bitmask current = 0;
	int count = 0;

	q.emplace_back(0, 0);
	if(!(classroom[i + 1] & 1) && !(previous_bitmask & 2))
	{
		q.emplace_back(1, 1);
	}

	int row_seat_idx = 1;

	while(!q.empty() && row_seat_idx < m)
	{
		const size_t q_size = q.size();

		for(size_t s = 0; s < q_size; ++s)
		{
			const auto& [curr_bitmask, curr_cnt] = q.front(); 
			q.push_back(q.front());
			q.pop_front();

			const bool ceil_check = row_seat_idx > 0;
			const bool floor_check = row_seat_idx < m;
			const Bitmask right = 1 << (row_seat_idx - 1);
			const Bitmask left = 1 << (row_seat_idx + 1);

			if(classroom[i + 1] & (1 << row_seat_idx))
			{
				// seat itself is unavailable.
				continue;
			}
			if(ceil_check && previous_bitmask & right)
			{
				// right side seat is unavailable.
				// we are subtracting due to bitmask is reverse order.
				continue;
			}
			if(floor_check && previous_bitmask & left)
			{
				// left side seat is unavailable.
				continue;
			}
			if(!(curr_bitmask & 1 << (row_seat_idx - 1)))
			{
				// my "current" right side seat is available.
				q.emplace_back(curr_bitmask | 1 << row_seat_idx, curr_cnt + 1);
			}
		}

		row_seat_idx++;
	}

	while(!q.empty())
	{
		const auto& [previous_mask, cnt] = q.front();
		q.pop_front();
		ret = std::max(ret, row(i + 1, previous_mask, m, n) + cnt);
	}

	return ret;
}


int main(void)
{
	int c;
	std::cin >> c;

	while(c--)
	{
		std::fill_n(classroom, 12, 0);

		int class_no, seat_cnt;
		std::cin >> class_no >> seat_cnt;

		for(int i = 1; i <= class_no; ++i)
		{
			classroom[i] = 0;

			for(int j = 1; j <= seat_cnt; ++j)
			{
				char ch;
				std::cin >> ch;
				classroom[i] += (ch == '.' ? 0 : 1 << (j - 1));
			}
		}

		std::fill_n(std::begin(dp[0]), 12 * (1 << 12), -1);
		std::cout << row(0, 0, seat_cnt, class_no) << std::endl;
	}
}