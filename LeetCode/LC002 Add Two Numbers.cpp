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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* ans = new ListNode(0);
		ListNode* head = ans;
		int k = 0;

		while (l1 != nullptr && l2 != nullptr)
		{
			k += l1->val + l2->val;
			ans->next = new ListNode(k % 10);
			ans = ans->next;
			k /= 10;
			l1 = l1->next;
			l2 = l2->next;
		}

		ListNode* lt = l1;
		if (l1 == nullptr)
		{
			lt = l2;
		}

		while (lt != nullptr)
		{
			k += lt->val;
			ans->next = new ListNode(k % 10);
			ans = ans->next;
			k /= 10;
			lt = lt->next;
		}

		if (k)
		{
			ans->next = new ListNode(k);
		}

		return head->next;
	}
};