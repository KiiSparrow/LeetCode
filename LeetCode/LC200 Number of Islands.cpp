#include "LeetCode.h"
using namespace std;


static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

class Solution
{
public:
	int numIslands(vector<vector<char>>& grid)
	{
		int ans = 0;

		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == '1')
				{
					++ans;
					spread(grid, i, j);
				}
			}
		}

		return ans;
	}

	void spread(vector<vector<char>>& grid, int x, int y)
	{
		grid[x][y] = '0';

		if (x - 1 >= 0 && grid[x - 1][y] == '1')
			spread(grid, x - 1, y);
		if (x + 1 < grid.size() && grid[x + 1][y] == '1')
			spread(grid, x + 1, y);
		if (y - 1 >= 0 && grid[x][y - 1] == '1')
			spread(grid, x, y - 1);
		if (y + 1 < grid[0].size() && grid[x][y + 1] == '1')
			spread(grid, x, y + 1);
	}
};