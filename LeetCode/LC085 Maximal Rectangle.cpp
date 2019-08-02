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
	int maximalRectangle(vector<vector<char>>& matrix)
	{
		if (matrix.empty() || matrix[0].empty())
			return 0;

		int m = matrix[0].size();
		vector<int> height(m, 0);
		vector<int> left(m, 0);
		vector<int> right(m, m);
		
		int maxRec = 0;
		for (int i = 0; i < matrix.size(); ++i)
		{
			int curLeft = 0;
			for (int j = 0; j < m; ++j)
			{
				if (matrix[i][j] == '1')
				{
					++height[j];
					left[j] = max(left[j], curLeft);
				}
				else
				{
					height[j] = 0;
					left[j] = 0;
					curLeft = j + 1;
				}
			}

			int curRight = m;
			for (int j = m - 1; j >= 0; --j)
			{
				if (matrix[i][j] == '1')
				{
					right[j] = min(right[j], curRight);
					maxRec = max(maxRec, height[j] * (right[j] - left[j]));
				}
				else
				{
					right[j] = m;
					curRight = j;
				}
			}
		}		

		return maxRec;
	}
};

int main()
{
	vector<vector<char>> matrix{
		{ '1','0','1','0','0' },
		{ '1','0','1','1','1' },
		{ '1','1','1','1','1' },
		{ '1','0','0','1','0' } };
	Solution su;
	cout << su.maximalRectangle(matrix) << endl;

	return 0;
}