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
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		if (matrix.empty() || matrix[0].empty())
			return false;
		if (target < matrix[0][0] || target > *(matrix.rbegin()->rbegin()))
			return false;

		int left = 0;
		int right = matrix.size() - 1;
		int mid = (left + right) / 2;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (matrix[mid][0] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}

		int row = left - 1;
		left = 0;
		right = matrix[row].size() - 1;
		mid = (left + right) / 2;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (matrix[row][mid] == target)
				return true;

			if (matrix[row][mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}

		return false;
	}
};