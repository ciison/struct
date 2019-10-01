/*
* ջ��ʹ��, ����ƥ��ļ���
* [()()] ��ʾƥ�������
* [[)(] ��ʾ��ƥ�������
* �������������, ����������ջ, �������������, ��ջ�������ų�ջ, ����������Ų�ƥ��,
* ���ջΪ��, ����������, ��ʾ���Ų�ƥ��
* ���ջ��Ϊ��, ����������, ��ջ����ƥ��
*/
#include<stack>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

bool check(queue<char> q) {
	// �������ջ��Ϊ��, ��ʾû�и����������ź�������ƥ��
	// �������������, ����������ջ, �������������, ��ջ����Ԫ�غ͵�ǰ��������ƥ��, �����ƥ��, ֱ�ӷ���
	stack<char> s;

	for (; !q.empty(); ) {
		char c = q.front();
		//cout << " c == " << c << " " << s.empty() << endl;;
		q.pop();

		// ����������վ, 
		if (c == '(' || c == '[') {
			s.push(c);
			continue;
		}

		// �Ա������ź͵�ǰ��ջ��Ԫ��
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

	// ���ջ��Ϊ��, ��ʾû�и���������ź͵�ǰ��������ƥ��
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