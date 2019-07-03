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
	vector<int> grayCode(int n)
	{
		int m = pow(2, n);
		vector<vector<int>> binCode(m, vector<int>(n, 0));

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; j += 2 * (i + 1))
			{
				int k = i + 1;
				while (k--)
				{
					binCode[j][i] = 1;
					++j;
				}
			}
		}

		vector<int> ans(m, 0);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				ans[i] += pow(2, j) * binCode[i][j];
			}
		}

		return ans;
	}
};

int main()
{
	int n = 2;
	Solution res;
	res.grayCode(n);

	return 0;
}