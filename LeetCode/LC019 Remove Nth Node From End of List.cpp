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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode *ptr = head;
		for (int i = 0; i < n; ++i)
		{
			ptr = ptr->next;
		}

		if (ptr == nullptr)
		{
			return head->next;
		}
		else
		{
			ptr = ptr->next;
		}

		ListNode *ans = head;
		ListNode *rePtr = head;
		while (ptr != nullptr)
		{
			rePtr = rePtr->next;
			ptr = ptr->next;
		}
		rePtr->next = rePtr->next->next;

		return ans;
	}
};