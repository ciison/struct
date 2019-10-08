// 输出二叉树,
// 题目来自于: https://leetcode-cn.com/problems/print-binary-tree/submissions/
//
// 解题思路:
// 先是计算二叉树的高度
// 然后生成矩阵, 使用 '' vector
// 最后在对应的位置填充数字
//

// 另外一种方法
// 使用的是广度遍历
// 每一次都是记录当前结点的 坐标, 如果是根节点记为 1,1
// 如果是树的左结点 深度加一, 如果是左结点 记为 (2,1) (2, 2) 其他的如此类推
#include<string>
#include<iostream>
#include<queue>
#include<cmath>
#include<utility>

using std::queue;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::pow;
using std::make_pair;


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
		vector<vector<string>> printTree(TreeNode* root) {
			// 这里首先计算这个数的深度
			int depth = 0;
			// 计算树的深度
			calDepth(root, depth, 0);

			// 还要计算元素的个数,
			// 计算元素的位置, 然后使用公式 2 * i + 1 || 2 * i + 2 ? 可能是这个公式
			// 然后计算出空间的大小( 2 ^ n ) - 1 个 vector<string> 的空间
			// vector< vector<string>> 的空间的 大小为 树的深度

			vector<vector<string>> vec;
			int col = std::pow(2 , depth) -1;
			for (int i = 0 ; i<depth ; i ++ ) {
				vec.push_back(vector<string>(col));
			}
			fill(root, vec, 0 , 0 , col);
			// 返回矩阵值
			return vec;
		}

	private:
		// 计算树的高度
		void calDepth(TreeNode *root , int &depth , int s) {
			if ( root == nullptr) {
				return ;
			}

			if ( s + 1 > depth) {
				depth = s+1;
			}

			calDepth(root ->left, depth, s +1);
			calDepth(root ->right , depth, s +1);
		}

		// 填充数值
		// 好像刚好符合二叉查找树
		void fill(TreeNode *root , vector<vector<string>> &vec,int row, int beg, int end ) {
			if ( root == nullptr || end <= beg) {
				return ;
			}

			if ( end - beg == 1 ) {
				vec[row][beg] = std::to_string(root->val);
			} else {
				int mid = (end - beg ) /2 + beg;
				vec[row][mid] = std::to_string(root ->val);
				fill(root->left, vec, row +1, beg, mid);
				fill(root->right, vec,row +1, mid +1, end);
			}


		}
};
int main(void) {
	cout<<"hello world"<<endl;

	// 	构造二叉树
	TreeNode a( 1);
	TreeNode b( 2);
	TreeNode c( 3);
	TreeNode d( 4);


	a.left = &b;
	b.right= &d;
	a.right = &c;
	// 生成右视图
	auto vec = Solution().printTree(&a);

	for( auto c : vec) {
		cout<<"[ ";
		for ( auto subc:c) {
			if (subc == "") {
				cout<< ""<< ", ";
			} else {
				cout<<subc<<", ";
			}
		}
		cout<<" ]"<<endl;
	}
	return 0;
}
