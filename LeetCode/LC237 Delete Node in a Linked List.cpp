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
	void deleteNode(ListNode* node)
	{
		node->val = node->next->val;
		node->next = node->next->next;
	}
};