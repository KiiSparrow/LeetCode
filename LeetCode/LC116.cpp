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
	Node* connect(Node* root)
	{
		if (!root)
			return nullptr;

		if (root->left && root->right)
			root->left->next = root->right;

		if (root->right && root->next)
			root->right->next = root->next->left;

		connect(root->left);
		connect(root->right);

		return root;
	}
};