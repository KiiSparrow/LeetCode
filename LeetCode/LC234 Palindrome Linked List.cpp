#include "LeetCode.h"
using namespace std;


static const auto ioSyncOff = []()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return 0;
}();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	bool isPalindrome(ListNode* head)
	{
		if (!head)
			return true;

		ListNode* fast = head;
		ListNode* slow = head;
		ListNode* tmp = nullptr;
		ListNode* left = nullptr;

		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			tmp = slow->next;

			slow->next = left;
			left = slow;

			slow = tmp;
		}

		if (!fast->next)
			return isEqual(left, slow->next);

		tmp = slow->next;
		slow->next = left;
		left = slow;
		slow = tmp;

		return isEqual(left, slow);
	}

	inline bool isEqual(ListNode* a, ListNode*b)
	{
		while (a && b)
		{
			if (a->val != b->val)
				return false;
			a = a->next;
			b = b->next;
		}

		return true;
	}
};