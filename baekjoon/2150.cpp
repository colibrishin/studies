#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

int dp[10001]{};
std::vector<int> map[10001];
std::stack<int> s;
std::vector<std::vector<int>> scc;
bool discovered[10001]{};
int idx = 0;

int dfs(int c)
{
	dp[c] = ++idx;
	s.push(c);

	int result = dp[c];

	for(const auto& next : map[c])
	{
		if(dp[next] == 0)
		{
			result = std::min(result, dfs(next));
		}
		else if(!discovered[next])
		{
			result = std::min(result, dp[next]);
		}
	}

	if(result == dp[c])
	{
		std::vector<int> local_scc;

		while(!s.empty())
		{
			int tmp = s.top();
			s.pop();

			local_scc.push_back(tmp);
			discovered[tmp] = true;
			if(tmp == c)
			{
				break;
			}
		}

		std::sort(local_scc.begin(), local_scc.end());
		scc.push_back(local_scc);
	}

	return result;
}

int main()
{
	int v, e;

	std::cin >> v >> e;

	for(int i = 0; i < e; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		map[a].push_back(b);
	}

	for(int i = 1; i <= v; ++i)
	{
		if(dp[i] == 0)
		{
			dfs(i);
		}
	}

	std::sort(scc.begin(), scc.end());

	std::cout << scc.size() << std::endl;

	for(const auto& vec : scc)
	{
		for(const auto& vertex : vec)
		{
			std::cout << vertex << ' ';
		}
		std::cout << -1;
		std::cout << std::endl;
	}
}
