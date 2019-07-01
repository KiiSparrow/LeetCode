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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		TreeNode* root;
		unordered_map<int, int> inmap;
		for (int i = 0; i < inorder.size(); ++i)
		{
			inmap[inorder[i]] = i;
		}
		root = create(inmap, preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);

		return root;
	}

	TreeNode* create(unordered_map<int, int>& inmap, vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
	{
		if (pl > pr)
			return nullptr;

		TreeNode* root = new TreeNode(preorder[pl]);

		if (pl == pr)
			return root;

		int idex = inmap[preorder[pl]];
		root->left = create(inmap, preorder, inorder, pl + 1, pl + (idex - il), il, idex - 1);
		root->right = create(inmap, preorder, inorder, pl + 1 + (idex - il), pr, idex + 1, ir);

		return root;
	}
};