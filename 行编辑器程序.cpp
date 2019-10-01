/*
* 行编辑器程序: 用户接受从终端输入的程序获取数据, 并存入用户的数据区. 由于用户在终端上进行输入时, 不能保证不出差错
* 因此, 若在编辑程序中, "每接受一个字符即存入用户数据区" 的做法显然不是最恰当的. 较好的做法是, 设立一个输入缓冲区, 
* 用以接受用户输入的一行字符, 然后逐行存入用户数据区. 允许用户输入差错, 并在发现有误的情况下可以及时更正. 例如用户发现
* 刚刚输入的一个字符是错误的时, 可以进行补进一个 "#", 以前的一个字符无效, 如果发现当前键入的行有较多的或者难以补救是, 则可以输入一个退行符
* 表示当前的行无效
*/


// 解题思路是使用 栈来保存已经输入的有效的字符, 
// 如果遇到 # 将栈顶弹出
// 如果遇到 @ 直接退出

#include<string>
#include<stack>
#include<iostream>

using namespace std; // 这里使用的是 std::stack, std::cout, std::cin, std::string, std::endl;

// 这里来检查字符串是否有误,
string check(string str) {
	stack<char> s;
	// 遍历输入的行字符串
	for (auto i = 0; i < str.length(); i++) {
		auto c = str[i];
		// 如果当前的 字符是 @ 表示整行作废
		if (c == '@') {
			return "";
		}
		// 如果当前的字符是 # 表示输入的前一个字符作废, 
		// 如果没有前一个字符直接返回 空串
		if (c == '#') {
			if (s.empty()) {
				return "";
			}
			// 弹出栈顶的元素
			s.pop(); 
			continue;
		}
		// 如果当前输入的字符没有问题, 直接将字符推入栈中
		s.push(c);

	}
	string st;
	// 遍历当前的字符串, 将串拼接到当前的串中, 直到栈为空为止
	for (; !s.empty();) {
		auto c = s.top();
		s.pop();
		st = (c) + st;
	}
	return st;
}

int main(void ) {
	string str = "nihao#";
	cout << check(str) << endl; // niha
	cout << check(string("nihao#@")) << endl; // ""
	return 0; 
}