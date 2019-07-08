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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode* pa = headA;
		ListNode* pb = headB;

		while (pa != pb)
		{
			pa = (pa ? pa->next : headB);
			pb = (pb ? pb->next : headA);
		}

		return pa;
	}
};