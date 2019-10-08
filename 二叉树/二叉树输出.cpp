// ���������,
// ��Ŀ������: https://leetcode-cn.com/problems/print-binary-tree/submissions/
//
// ����˼·:
// ���Ǽ���������ĸ߶�
// Ȼ�����ɾ���, ʹ�� '' vector
// ����ڶ�Ӧ��λ���������
//

// ����һ�ַ���
// ʹ�õ��ǹ�ȱ���
// ÿһ�ζ��Ǽ�¼��ǰ���� ����, ����Ǹ��ڵ��Ϊ 1,1
// ������������� ��ȼ�һ, ��������� ��Ϊ (2,1) (2, 2) �������������
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
			// �������ȼ�������������
			int depth = 0;
			// �����������
			calDepth(root, depth, 0);

			// ��Ҫ����Ԫ�صĸ���,
			// ����Ԫ�ص�λ��, Ȼ��ʹ�ù�ʽ 2 * i + 1 || 2 * i + 2 ? �����������ʽ
			// Ȼ�������ռ�Ĵ�С( 2 ^ n ) - 1 �� vector<string> �Ŀռ�
			// vector< vector<string>> �Ŀռ�� ��СΪ �������

			vector<vector<string>> vec;
			int col = std::pow(2 , depth) -1;
			for (int i = 0 ; i<depth ; i ++ ) {
				vec.push_back(vector<string>(col));
			}
			fill(root, vec, 0 , 0 , col);
			// ���ؾ���ֵ
			return vec;
		}

	private:
		// �������ĸ߶�
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

		// �����ֵ
		// ����պ÷��϶��������
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

	// 	���������
	TreeNode a( 1);
	TreeNode b( 2);
	TreeNode c( 3);
	TreeNode d( 4);


	a.left = &b;
	b.right= &d;
	a.right = &c;
	// ��������ͼ
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
