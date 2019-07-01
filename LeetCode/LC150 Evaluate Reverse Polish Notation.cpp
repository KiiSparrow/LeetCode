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
	int evalRPN(vector<string>& tokens)
	{
		long long e1, e2;
		long long ans = 0;
		stack<int> st;
		for (auto t : tokens)
		{
			if (t == "+")
			{
				e2 = st.top(); st.pop();
				e1 = st.top(); st.pop();
				ans = e1 + e2;
			}
			else if (t == "-")
			{
				e2 = st.top(); st.pop();
				e1 = st.top(); st.pop();
				ans = e1 - e2;
			}
			else if (t == "*")
			{
				e2 = st.top(); st.pop();
				e1 = st.top(); st.pop();
				ans = e1 * e2;

			}
			else if (t == "/")
			{
				e2 = st.top(); st.pop();
				e1 = st.top(); st.pop();
				ans = e1 / e2;
			}
			else
			{
				ans = stoi(t);
			}
			st.push(ans);
		}

		return ans;
	}
};