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
	ListNode* reverseList(ListNode* head)
	{
		ListNode* ans = nullptr;
		ListNode* cur = head;

		while (cur)
		{
			head = head->next;
			cur->next = ans;
			ans = cur;
			cur = head;
		}

		return ans;
	}
};