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
	ListNode* swapPairs(ListNode* head)
	{
		if (!head || !head->next)
			return head;

		auto rest = head->next->next;
		auto ans = head->next;
		ans->next = head;
		head->next = swapPairs(rest);

		return ans;	

		//auto root = new ListNode(0);
		//root->next = head;
		//
		//auto pre = root;

		//while (pre && pre->next && pre->next->next)
		//{
		//	auto cur1 = pre->next;
		//	auto cur2 = cur1->next;
		//	auto tmp = cur2->next;;

		//	pre->next = cur2;
		//	cur2->next = cur1;
		//	cur1->next = tmp;
		//	
		//	pre = cur1;
		//}

		//auto ans = root->next;
		//delete root;

		//return ans;
	}
};