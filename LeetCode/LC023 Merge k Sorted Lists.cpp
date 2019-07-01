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
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		int listN = lists.size();
		ListNode *head = new ListNode(0);
		ListNode *cur = head;
		int minNum = 0;
		int minIter = 0;

		bool flag = true;
		while (true)
		{
			minIter = -1;
			minNum = INT_MAX;
			for (int i = 0; i < listN; ++i)
			{
				if (lists[i] && lists[i]->val < minNum)
				{
					minNum = lists[i]->val;
					minIter = i;
				}
			}
			if (minIter == -1)
				return head->next;
			cur->next = lists[minIter];
			cur = cur->next;
			lists[minIter] = lists[minIter]->next;
		}

		return head->next;
	}
};