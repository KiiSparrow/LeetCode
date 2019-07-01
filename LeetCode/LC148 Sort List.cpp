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
	ListNode* sortList(ListNode* head)
	{
		if (!head || !head->next)
		{
			return head;
		}

		auto tmp = findMid(head);
		auto mid = tmp->next;
		tmp->next = nullptr;

		auto p1 = sortList(head);
		auto p2 = sortList(mid);
		auto ans = merge(p1, p2);

		return ans;
	}

	ListNode* merge(ListNode* &p1, ListNode* &p2)
	{
		auto head = new ListNode(0);
		auto cur = head;

		while (p1 && p2)
		{
			if (p1->val <= p2->val)
			{
				cur->next = p1;
				p1 = p1->next;	
			}
			else
			{
				cur->next = p2;
				p2 = p2->next;
			}
			cur = cur->next;
		}
		
		if (p1)
		{
			cur->next = p1;
			p1 = p1->next;
			cur = cur->next;
		}
		if (p2)
		{
			cur->next = p2;
			p2 = p2->next;
			cur = cur->next;
		}

		return head->next;
	}

	inline ListNode* findMid(ListNode* head)
	{
		auto fastPtr = head;
		auto midPtr = head;

		while (fastPtr->next && fastPtr->next->next)
		{
			fastPtr = fastPtr->next->next;
			midPtr = midPtr->next;
		}

		return midPtr;
	}
};