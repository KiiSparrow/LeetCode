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
	ListNode *detectCycle(ListNode *head)
	{
		unordered_set<ListNode*> st;

		while (head)
		{
			if (st.count(head))
				return head;
			st.insert(head);
			head = head->next;
		}

		return nullptr;
	}

	ListNode *detectCycle_Floyd(ListNode *head)
	{
		/**/
		return nullptr;
	}
};