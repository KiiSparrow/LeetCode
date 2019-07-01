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
	int maxPoints(vector<vector<int>>& points)
	{
		int n = points.size();
		if (n < 3)
			return n;

		map<pair<int, int>, int> kmap;
		int ans = 0;

		for (int i = 0; i < n; ++i)
		{
			kmap.clear();
			int same = 0;
			int cur = 0;
			for (int j = i + 1; j < n; ++j)
			{
				int dx = points[j][0] - points[i][0];
				int dy = points[j][1] - points[i][1];	

				if (!dx && !dy)
				{
					++same;
				}
				else if (!dx)
				{
					kmap[make_pair(0, 1)] += 1;
					cur = max(cur, kmap[make_pair(0, 1)]);
				}
				else if (!dy)
				{
					kmap[make_pair(1, 0)] += 1;
					cur = max(cur, kmap[make_pair(1, 0)]);
				}
				else
				{
					if (dx < 0)
					{
						dx *= -1;
						dy *= -1;
					}
					
					int c = gcd(dx, dy);
					kmap[make_pair(dx / c, dy / c)] += 1;
					cur = max(cur, kmap[make_pair(dx / c, dy / c)]);
				}
			}

			ans = max(ans, same + cur + 1);
		}

		return ans;
	}
};