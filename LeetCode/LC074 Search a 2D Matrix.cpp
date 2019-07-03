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
		int left = 0;
		int right = matrix.size();
		int mid = (left + right) / 2;
		while (matrix[mid][0] > target || target >= matrix[mid+1][0])
		{
			mid = (left + right) / 2;
			if (matrix[mid][0] > target)
				right = mid;
			else
				left = mid;
		}

		int row = mid;
		left = 0;
		right = matrix[mid].size();
		mid = (left + right) / 2;
		while (left < right)
		{
			if (matrix[row][mid] == target)
				return true;
			if (matrix[row][mid] < target && target < matrix[row][mid + 1])
				return false;

			if (matrix[row][mid] > target)
				right = mid;
			else
				left = mid;
		}

		return false;
	}
};