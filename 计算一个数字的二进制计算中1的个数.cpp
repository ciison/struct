
/*
* ����һ�����ֶ�����λ�� 1 �ĸ���
* 
* 1: 0001
* 2: 0010
* 
* 3: 0011
* 4: 0100
* 5: 0101
*  
* 5: 0101
* 6: 0110
*
*  ���: 
* n ������, ��ô n -1 һ����ż��(˵���Ƿϻ�), ��ô n �Ķ�����λ�� n-1 �Ķ�����λ�����һ
* n &(n-1) һ����������������λ���Ǹ� '1' ���һ���� n-1
*
* *****
* n��ż��, n & (n-1) Ҳ�ǻ���������һλ 
*/ 
#include<iostream>

using  std::cout;
using  std::endl;

int main(void) {

	cout<<"hello world"<<endl;

	// num �Ǵ��жϵ�����
	auto count_bin = [= ] ( int num ) -> decltype(num) {
		auto cnt =  0;
		while(num) {
			num = num &(num -1);
			cnt ++;
		} 
		return cnt;
	};
	
	cout<< "3 == 0b011 : "<< count_bin(3) <<endl;
	cout<< "4 == 0b100 : "<< count_bin(1) <<endl;

	return 0;
}
