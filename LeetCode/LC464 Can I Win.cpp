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
	bool canIWin(int maxChoosableInteger, int desiredTotal)
	{
		if (maxChoosableInteger >= desiredTotal)
			return true;
		if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal)
			return false;
		
		unordered_map<int, bool> log;

		return canWin(maxChoosableInteger, desiredTotal, 0, log);
	}
	
	bool canWin(int maxChoose, int total, int used, unordered_map<int, bool>& log)
	{
		if (log.count(used))
			return log[used];

		for (int i = 0; i < maxChoose; ++i)
		{
			int cur = (1 << i);
			if ((cur & used) == 0)
			{
				if (total <= i + 1 || !canWin(maxChoose, total - (i + 1), used | cur, log))
				{
					log[used] = true;
					return true;
				}
			}
		}
		
		log[used] = false;
		return false;
	}
};