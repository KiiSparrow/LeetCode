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
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		if (!head || k == 1)
			return head;

		auto rest = head;
		for (int i = 0; i < k; ++i)
		{
			if (!rest)
				return head;
			rest = rest->next;
		}

		auto cur = head->next;
		auto pre = head;
		auto bottom = head;
		bottom->next = nullptr;
		while (cur != rest)
		{
			auto tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}

		bottom->next = reverseKGroup(rest, k);
		return pre;
	}
};