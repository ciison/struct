/****************************************************************
* ��Ŀ���� leetcode:
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
		// ����⿼�����ʵ�Ƕ�����ÿһ������һ��Ԫ��
		// ʹ���ǿ�����ȵ�����
		// ��Ҫ��¼ÿһ��Ľ��
		vector<int> rightSideView(TreeNode* root) {
			vector<int> vec;
			// ʹ��һ��pair ����¼��ǰ�Ĳ��
			std::queue<std::pair<TreeNode*, int > > q;
			if (root != nullptr) {
				q.push(std::make_pair(root, 0));
			}

			while(!q.empty()) {
				auto par = q.front();
				q.pop();
				auto node = par.first;
				// �����ǰ��һ���µĲ��, ����Ҫ���������һ���µ�����
				if (par.second >= vec.size()) {
					vec.push_back(node->val);
				} else {
					// �����ǰ��Ԫ�ز��ǵ�һ��Ԫ��, ��Ҫ���µ�ǰ��Ԫ�ؾͺ�
					vec[par.second] = node->val;
				}

				// �����ǰ�����㲻Ϊ��, �ѵ�ǰ�����������, ���Ҫ�ڵ�ǰ�Ļ����ϼ�һ
				if (node ->left != nullptr) {
					q.push(std::make_pair(node->left, par.second +1));
				}

				if (node ->right != nullptr) {
					// �����ǰ���ҽ�㲻Ϊ��, ���ҽ�������, ���Ҫ�ڵ�ǰ���ҽ��Ļ����ϼ�һ
					q.push(std::make_pair(node -> right , par.second +1));
				}

			}
			return vec;
		}
};

int main(void) {
	cout<<"hello world "<<endl;

// 	���������
	TreeNode a( 1);
	TreeNode b( 2);
	TreeNode c( 3);
	TreeNode d( 4);
	TreeNode e( 5);

	a.	left = &b;
	b.right = &e;
	a.right = &c;
	c.right = &d;
	// ��������ͼ
	auto vec = Solution().rightSideView(&a);

	for ( auto c : vec) {
		cout<< c <<"  ";
	}
	cout<<endl;

	return 0 ;
}
