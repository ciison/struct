#include<iostream>
#include<vector>
using namespace std;


struct TrieTree {
	int val;
	std::vector<TrieTree*> child;
	explicit TrieTree(int val):val(val),child(std::vector<TrieTree*>(0)) {
		// todo something
	};
	~TrieTree() {
		// Ðé¹¹º¯Êý
	}

	void static  visit(TrieTree *root) {
		// todo
		std::cout<<root->val << "  ";

		if (root->child.empty()) {
			cout<<" end "<<endl;
		}

		for (auto c: root->child ) {
			visit(c);
		}
	}

};

int main (void) {
	TrieTree root(1);
	TrieTree a(2);
	TrieTree b(3);
	root.child.push_back(&a);
	TrieTree c(4);
	root.child.push_back(&c);
	a.child.push_back(&b);
	TrieTree::visit(&root);
	return 0;
}

