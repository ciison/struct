/*
* 栈的使用, 括号匹配的检验
* [()()] 表示匹配的括号
* [[)(] 表示不匹配的括号
* 如果遇到左括号, 将左括号入栈, 如果遇到右括号, 将栈顶的括号出栈, 如果左右括号不匹配,
* 如果栈为空, 遇到右括号, 表示括号不匹配
* 如果栈不为空, 遇到右括号, 出栈进行匹配
*/
#include<stack>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

bool check(queue<char> q) {
	// 如果最后的栈不为空, 表示没有更过的右括号和左括号匹配
	// 如果遇到左括号, 将左括号入栈, 如果遇到右括号, 将栈顶的元素和当前的右括号匹配, 如果不匹配, 直接返回
	stack<char> s;

	for (; !q.empty(); ) {
		char c = q.front();
		//cout << " c == " << c << " " << s.empty() << endl;;
		q.pop();

		// 将左括号入站, 
		if (c == '(' || c == '[') {
			s.push(c);
			continue;
		}

		// 对比右括号和当前的栈顶元素
		if (c == ']') {
			if (s.empty()) {
				return false;
			}

			auto b = s.top();

			if (b != '[') {
				return false;
			}
			s.pop();
			continue;
		}

		if (c == ')') {
			if (s.empty()) {
				return false;
			}

			auto b = s.top();

			if (b != '(') {
				return false;
			}
			s.pop();
			continue;
		}
	}

	// 如果栈不为空, 表示没有更多的右括号和当前的左括号匹配
	if (s.empty()) {
		return true;
	}
	return false;
}

int main(void) {
	queue<char> q;
	q.push('(');
	q.push('[');
	q.push(']');
	q.push(')');

	cout << check(q) << endl; // true || 1 

	queue<char> qb;
	qb.push('(');
	qb.push('[');
	qb.push(')');
	cout << check(qb) << endl; // false || 0 
	return 0;
}