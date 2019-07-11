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
	bool canAttendMeetings(vector<vector<int>>& intervals)
	{
		if (intervals.empty() || intervals.size() == 1)
			return true;

		sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b)
		{
			return a[0] < b[0];
		});

		for (int i = 0; i < intervals.size() - 1; ++i)
		{
			if (intervals[i][1] > intervals[i + 1][0])
				return false;
		}

		return true;
	}
};