#include<iostream>
#include<stack>
#include<string>
using namespace std;

// ʹ��ջ���������Ƶ�ת��
// ������ѹ��ջ, 
// ����̲�Ϊ��, ��������շת���, ֱ����Ϊ��, Ȼ���ջ 
string oct2obj(int src, int obj){
	stack<int> s;
	
	if ( obj <=0) {
		return "";
	}
	
	do {
		int t = src % obj;
		s.push(t);
		src = src / obj;
	}while(src);
	
	string str;
	for (;!s.empty();){
		int tmp = s.top();
		str = str  +  to_string(tmp);;
		s.pop();
	}
	return str;
}
int main(void){
	std::cout<<"hello world"<<std::endl;
	std::cout<<"100 -> 8 "<< oct2obj(100, 8)<<std::endl; // 144  
	return 0;
}
