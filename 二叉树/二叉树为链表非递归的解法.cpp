/********************************************************************
* 二叉树，原地将它展开为链表 题目出自 leetcode
* https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
* xiao 成
**********************************************************************/
#include<iostream>
#include<stack>
#include<string>
#include<vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::stack;
/****************************************
 * Definition for a binary tree node.
 ****************************************/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		// 这道题我是用的是非递归的解法
		// 使用要给栈作为辅助的空间
		void flatten(TreeNode* root) {
			// 如果当前的指针的头节点为空, 直接退出
			if (root == nullptr) {
				return ;
			}

			std::stack<TreeNode*> st;
			auto curr = root;
			// 如果当前右子树不为空, 将右子树推入栈
			if (root ->right!= nullptr) {
				st.push(root->right);
			}

			// 如果当前的左子树不为空, 将左子树推入栈中
			if (root->left != nullptr) {
				st.push(root->left);
			}

			// 遍历栈
			for (; !st.empty(); ) {
				// 弹出栈顶元素
				auto node = st.top();
				auto n = node;
				st.pop();
				// 使用一个指示的指针, 保存当前的左子树和右子树
				auto left = node->left;
				auto right = node->right;

				curr->left = nullptr; // 将指示的左子树置空
				curr->right = n; // 右子树指向当前的结点
				n->left =nullptr; // 左右子树都要指控
				n->right = nullptr; // 所以上面需要临时保存 left, 和 right

				curr = curr->right; // 更新尾部指示器

				// 将当前之前的有指针入栈
				if (right!=nullptr) {
					st.push(right);
				}

				// 再将当前指向的作指针入栈
				if (left != nullptr) {

					st.push(left);
				}

			}
			// 前序非递归遍历二叉树完毕
		}
};

// 前序遍历二叉树
vector<string> preOrderTraverse(TreeNode *root) {
	std::vector<string>vec;
	if (root == nullptr) {
		return vec;
	}
	// 使用栈作为辅助空间
	std::stack<TreeNode * > st;
	st.push(root);
	// 如果当前的栈不为空, 一直做循环操作
	while(!st.empty()) {
		auto node = st.top();
		st.pop();
		if (node == nullptr) {
			vec.push_back("null");
			continue;
		}
		// 前序遍历当前的结点
		vec.push_back(std::to_string(node->val));

		// 如果右子树不为空
		if (node->right != nullptr) {
			st.push(node->right);
		}
		// 如果左子树不为空
		if (node->left!=nullptr) {
			st.push(node->right);
		}
	}
}
int main(void) {
	cout<< "hello world"<<endl;

	// 	构造二叉树
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	TreeNode e(5);
	TreeNode f(6);


	a.left = &b;
	b.left= &c;
	b.right = &d;
	a.right = &e;
	e.right = &f;


	Solution().flatten(&a);
	auto afterVec = preOrderTraverse(&a);
	cout<<"after:"<<endl;
	for (auto c:afterVec) {
		cout<< c<< " , ";

	}

	cout<<endl;


}
