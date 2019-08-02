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
	ListNode* rotateRight(ListNode* head, int k)
	{
		if (!head || !head->next || k == 0)
			return head;

		int cnt = 0;
		auto ptr = head;
		auto end = ptr;
		while (ptr)
		{
			end = ptr;
			++cnt;
			ptr = ptr->next;
		}

		if (cnt == 1)
			return head;

		k = k % cnt;
		if (!k)
			return head;

		int move = cnt - k;
		auto pre = head;
		ptr = head;
		while (move--)
		{
			pre = ptr;
			ptr = ptr->next;
		}

		pre->next = nullptr;
		end->next = head;
		
		return ptr;
	}
};