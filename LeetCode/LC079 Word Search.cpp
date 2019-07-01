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
	Solution()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
	}

	bool exist(vector<vector<char>>& board, string word)
	{
		vector<vector<bool>> is(board.size(), vector<bool>(board[0].size(), true));
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (board[i][j] == word[0])
				{
					if (find(board, is, word, 1, i, j))
						return true;
				}
			}
		}

		return false;
	}

	bool find(vector<vector<char>>& board, vector<vector<bool>>& is, string& word, int next, int i, int j)
	{
		if (!is[i][j])
			return false;
		is[i][j] = false;

		if (word.size() == next)
			return true;

		if (j - 1 >= 0 && is[i][j - 1] && board[i][j - 1] == word[next])
		{
			if (find(board, is, word, next + 1, i, j - 1))
				return true;
		}

		if (j + 1 < board[0].size() && is[i][j + 1] && board[i][j + 1] == word[next])
		{
			if (find(board, is, word, next + 1, i, j + 1))
				return true;
		}

		if (i - 1 >= 0 && is[i - 1][j] && board[i - 1][j] == word[next])
		{
			if (find(board, is, word, next + 1, i - 1, j))
				return true;
		}

		if (i + 1 < board.size() && is[i + 1][j] && board[i + 1][j] == word[next])
		{
			if (find(board, is, word, next + 1, i + 1, j))
				return true;
		}

		is[i][j] = true;
		return false;
	}
};