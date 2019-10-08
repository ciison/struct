/********************************************************************
* ��������ԭ�ؽ���չ��Ϊ���� ��Ŀ���� leetcode
* https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
* xiao ��
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
		// ����������õ��Ƿǵݹ�Ľⷨ
		// ʹ��Ҫ��ջ��Ϊ�����Ŀռ�
		void flatten(TreeNode* root) {
			// �����ǰ��ָ���ͷ�ڵ�Ϊ��, ֱ���˳�
			if (root == nullptr) {
				return ;
			}

			std::stack<TreeNode*> st;
			auto curr = root;
			// �����ǰ��������Ϊ��, ������������ջ
			if (root ->right!= nullptr) {
				st.push(root->right);
			}

			// �����ǰ����������Ϊ��, ������������ջ��
			if (root->left != nullptr) {
				st.push(root->left);
			}

			// ����ջ
			for (; !st.empty(); ) {
				// ����ջ��Ԫ��
				auto node = st.top();
				auto n = node;
				st.pop();
				// ʹ��һ��ָʾ��ָ��, ���浱ǰ����������������
				auto left = node->left;
				auto right = node->right;

				curr->left = nullptr; // ��ָʾ���������ÿ�
				curr->right = n; // ������ָ��ǰ�Ľ��
				n->left =nullptr; // ����������Ҫָ��
				n->right = nullptr; // ����������Ҫ��ʱ���� left, �� right

				curr = curr->right; // ����β��ָʾ��

				// ����ǰ֮ǰ����ָ����ջ
				if (right!=nullptr) {
					st.push(right);
				}

				// �ٽ���ǰָ�����ָ����ջ
				if (left != nullptr) {

					st.push(left);
				}

			}
			// ǰ��ǵݹ�������������
		}
};

// ǰ�����������
vector<string> preOrderTraverse(TreeNode *root) {
	std::vector<string>vec;
	if (root == nullptr) {
		return vec;
	}
	// ʹ��ջ��Ϊ�����ռ�
	std::stack<TreeNode * > st;
	st.push(root);
	// �����ǰ��ջ��Ϊ��, һֱ��ѭ������
	while(!st.empty()) {
		auto node = st.top();
		st.pop();
		if (node == nullptr) {
			vec.push_back("null");
			continue;
		}
		// ǰ�������ǰ�Ľ��
		vec.push_back(std::to_string(node->val));

		// �����������Ϊ��
		if (node->right != nullptr) {
			st.push(node->right);
		}
		// �����������Ϊ��
		if (node->left!=nullptr) {
			st.push(node->right);
		}
	}
}
int main(void) {
	cout<< "hello world"<<endl;

	// 	���������
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
