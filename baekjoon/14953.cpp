#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
int dp[100001]{};
std::vector<std::vector<int>> vertices(100001, std::vector<int>());

int dfs(int pos)
{
    if(dp[pos] != 0)
    {
	    return dp[pos];
    }

    int& local_sum = dp[pos];
    local_sum++;

    // All cities of the list are distinct, 
    // i.e., ci ≠ cj if i ≠ j, ci and ci+1 are neighbors to 
    // each other, and the number of neighbors of ci+1 is 
    // greater than the number of neighbors of ci for i = 0,
    // 1, …, m-2.

    // 1. path should travel unique nodes.
    // 2. each node should be connected in some way. (travable.)
    // 3. some node should have more connected vertices.
    // (e.g., 2 -> 5 -> 4 -> (stop) <- 5 -> 1 -> (stop))

    for (const auto& nextV : vertices[pos]) 
    {
        if (vertices[pos].size() < vertices[nextV].size())
        {
            local_sum = std::max(local_sum, dfs(nextV) + 1);
        }
    }

    return local_sum;
}

int main(void) 
{
    std::cin >> n >> m;
    int max = 0;

    for (int i = 0; i < m; ++i) 
    {
        int a, b;
        std::cin >> a >> b;
        // There is at most one road between a pair of cities. Every road is bidirectional.
        vertices[a].push_back(b);
        vertices[b].push_back(a);
    }

    for (int i = 0; i < n; ++i)
    {
	   max = std::max(max, dfs(i));
	}

    std::cout << max;
}