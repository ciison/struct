/****************************************************************
* 题目来自 leetcode:
* https://leetcode-cn.com/problems/binary-tree-right-side-view/
*****************************************************************/
#include<iostream>

#include<vector>
#include<queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
	public:
		// 这道题考查的其实是二叉树每一层的最后一个元素
		// 使用是宽度优先的搜索
		// 需要记录每一层的结点
		vector<int> rightSideView(TreeNode* root) {
			vector<int> vec;
			// 使用一个pair 来记录当前的层次
			std::queue<std::pair<TreeNode*, int > > q;
			if (root != nullptr) {
				q.push(std::make_pair(root, 0));
			}

			while(!q.empty()) {
				auto par = q.front();
				q.pop();
				auto node = par.first;
				// 如果当前是一个新的层次, 则需要向后面推送一个新的数据
				if (par.second >= vec.size()) {
					vec.push_back(node->val);
				} else {
					// 如果当前的元素不是第一个元素, 需要更新当前的元素就好
					vec[par.second] = node->val;
				}

				// 如果当前的左结点不为空, 把当前的左结点入队列, 层次要在当前的基础上加一
				if (node ->left != nullptr) {
					q.push(std::make_pair(node->left, par.second +1));
				}

				if (node ->right != nullptr) {
					// 如果当前的右结点不为空, 把右结点入队列, 层次要在当前的右结点的基础上加一
					q.push(std::make_pair(node -> right , par.second +1));
				}

			}
			return vec;
		}
};

int main(void) {
	cout<<"hello world "<<endl;

// 	构造二叉树
	TreeNode a( 1);
	TreeNode b( 2);
	TreeNode c( 3);
	TreeNode d( 4);
	TreeNode e( 5);

	a.	left = &b;
	b.right = &e;
	a.right = &c;
	c.right = &d;
	// 生成右视图
	auto vec = Solution().rightSideView(&a);

	for ( auto c : vec) {
		cout<< c <<"  ";
	}
	cout<<endl;

	return 0 ;
}
