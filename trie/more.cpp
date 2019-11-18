/******************************************************
* 实现一棵 trie 树, 
* 已经实现的功能点: 
* 1. trie 树的初始化
* 2. tire 树的插入数据
* 3. trie 树的前序遍历
* 4. trie 树的判断 prefix 
* 5... 等你来添加
* @author 784457618@qq.com
* @date 2019年11月14日
*******************************************************/
#include<vector>
#include<string>
#include<iostream>
#define TRIE_MAX_CHAR_NUM 26
#define ll long long 

#ifdef  ll 
	#define x first
	#define y second 
#endif //  ll 

struct TrieNode
{
	TrieNode* child[TRIE_MAX_CHAR_NUM]; // trie 的孩子节点
	bool is_end; // 判断是否是一个单词

	// 构造函数, 将 is_end 对象初始化为 false
	TrieNode() :is_end(false) {
		
		for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
			child[i] = 0;
		}
	}
};

// 前序遍历trie 树
void preorder_trie(TrieNode* node, int layer) {
	for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
		if (node->child[i]) {
			for (int j = 0; j < layer; j++) {
				printf("--");
			}

			printf("%c", i + 'a');
			// 如果是单词, 就打印输出
			if (node->child[i]->is_end) {
				printf("<end>");
			}
			printf("\n");

			preorder_trie(node->child[i], layer + 1); // 递归遍历 trie 树
		}
		
	}
}

// 在 trie 树中获取全部的单词
void get_all_word_from_tree(TrieNode* node, std::string& word, std::vector<std::string>& word_list) {
	for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
		if (node->child[i]) {
			// 将当前的字符入栈
			word.push_back( i + 'a');
			if (node->child[i]->is_end) {
				word_list.push_back(word);
			}

			get_all_word_from_tree(node->child[i], word, word_list);
			word.erase(word.length() - 1, 1); // 清除最后一个字母
		}
		
	}
}


class TreeTree {
public:
	TreeTree() {

	}

	~TreeTree() {
		for (int i = 0; i < _node_vec.size(); i++) {
			delete _node_vec[i]; // 析构函数
		}
	}

	// 这里是插入一个单词
	void insert(const char* word) {
		auto ptr = &_root;

		// 如果当前的单词没有
		while (*word)
		{
			auto pos = *word - 'a'; // 获取当前的单词
			if (!ptr->child[pos]) {
				ptr->child[pos] = new_node();
			}

			ptr = ptr->child[pos];
			word++;
		}
		// 最后这里标志这是已经是一个单词了
		ptr->is_end = true;
	}

	// 搜索单词是否存在 trie 树
	bool search(const char* word) {
		auto ptr = &_root;

		while (*word) 
		{
			auto pos = *word - 'a';
			// 如果对应的 trie 的子节点为空, break 
			if (!ptr->child[pos]) {
				break;
			}
			ptr = ptr->child[pos];
			word++;
		}
		// 判断这个不是 break 推出的循环的
		return ptr->is_end && *word == 0;
	}
	// trie 树的前缀查询
	bool startwith(const char* prefix) {
		auto ptr = &_root;

		while (*prefix) {
			auto pos = *prefix - 'a';
			if (!ptr->child[pos]) {
				break;
			}

			ptr = ptr->child[pos];
			prefix++;
		}




		// 判断这个前缀是不是已经走完了
		return *prefix == 0;
	}

	TrieNode* root() {
		return &_root;
	}
private:
	TrieNode* new_node() {
		auto node = new TrieNode();
		// 这里就是为了方便释放节点的空间才将节点放入到 vector 中
		_node_vec.push_back(node);
		return node;
	}

	std::vector<TrieNode*> _node_vec;
	TrieNode _root;
};


using namespace std;
int main(void) {



	TreeTree trie_tree;
	trie_tree.insert("abcd");
	trie_tree.insert("abc");
	trie_tree.insert("func");
	trie_tree.insert("funtion");
	trie_tree.insert("enjoy");
	trie_tree.insert("e");

	trie_tree.insert("hello");

	preorder_trie(trie_tree.root(), 0); 

	cout << "search func" << trie_tree.search("enjoy") << endl;
	cout << "has prefix fun" << trie_tree.startwith("fun") << endl;
	cout << "has prefix dc" << trie_tree.startwith("dc") << endl;

	return 0;
}
