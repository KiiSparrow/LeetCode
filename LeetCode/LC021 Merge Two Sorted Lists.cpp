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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode *head = new ListNode(0);
		ListNode *t = head;

		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val < l2->val)
			{
				t->next = l1;
				l1 = l1->next;
			}
			else
			{
				t->next = l2;
				l2 = l2->next;
			}

			t = t->next;
		}

		if (l1)
		{
			t->next = l1;
		}
		else if (l2)
		{
			t->next = l2;
		}

		return head->next;
	}
};