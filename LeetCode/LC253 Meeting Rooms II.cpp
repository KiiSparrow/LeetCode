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
	int minMeetingRooms(vector<vector<int>>& intervals)
	{
		const int len = intervals.size();
		vector<int> start(len);
		vector<int> end(len);
		for (int i = 0; i < len; ++i)
		{
			start[i] = intervals[i][0];
			end[i] = intervals[i][1];
		}

		sort(start.begin(), start.end());
		sort(end.begin(), end.end());

		int ans = 0;
		int sptr = 0, eptr = 0;
		for (; sptr < len; ++sptr)
		{
			if (start[sptr] < end[eptr])
			{
				++ans;
			}
			else
			{
				++eptr;
			}
		}
		
		return ans;
	}
};