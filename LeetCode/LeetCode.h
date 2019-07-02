#pragma once

/*Head Files*/
#include <iostream>
#include <sstream>

#include <vector>
#include <string>
#include <tuple>

#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <numeric>


/*Struct*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL)
	{
	}
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
	}
};

class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node()
	{
	}

	Node(int _val, Node* _left, Node* _right, Node* _next)
	{
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};
