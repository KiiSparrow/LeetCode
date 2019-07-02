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
	bool hasCycle(ListNode *head)
	{
		auto fast = head, slow = head;

		while (fast)
		{
			fast = fast->next;
			if (fast == slow)
				return true;

			if (fast)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}

		return false;


		/*if (!head)
			return false;

		auto slow = head;
		auto fast = head;

		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				return true;
		}

		return false;*/
	}
};