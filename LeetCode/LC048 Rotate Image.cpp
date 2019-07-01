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
	void rotate(vector<vector<int>>& matrix)
	{
		int n = matrix.size() - 1;

		for (int i = 0; i <= n / 2; ++i)
		{
			for (int step = 0; step < n - 2 * i; ++step)
			{
				swap(matrix[i][i + step], matrix[i + step][n - i]);
				swap(matrix[n - i - step][i], matrix[n - i][n - i - step]);
				swap(matrix[i][i + step], matrix[n - i][n - i - step]);
			}
		}
	}
};