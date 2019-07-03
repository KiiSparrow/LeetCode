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
		int len = pow(2, n);
		vector<int> ans(len, 0);
		vector<vector<int>> bin{ {0}, {1} };

		for (int i = 1; i < n; ++i)
		{
			int m = pow(2, i);
			for (int j = m - 1; j >= 0; --j)
			{
				auto temp = bin[j];
				bin.push_back(temp);
			}

			int j;
			for (j = 0; j < m; ++j)
			{
				bin[j].push_back(0);
			}
			for (; j < 2 * m; ++j)
			{
				bin[j].push_back(1);
			}
		}
		
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				ans[i] += pow(2, j) * bin[i][j];
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