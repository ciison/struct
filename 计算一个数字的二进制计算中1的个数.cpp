
/*
* 计算一个数字二进制位中 1 的个数
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
*  如果: 
* n 是奇数, 那么 n -1 一定是偶数(说的是废话), 那么 n 的二进制位比 n-1 的二进制位后面多一
* n &(n-1) 一定会消掉最后二进制位的那个 '1' 结果一定是 n-1
*
* *****
* n是偶数, n & (n-1) 也是会消掉最后的一位 
*/ 
#include<iostream>

using  std::cout;
using  std::endl;

int main(void) {

	cout<<"hello world"<<endl;

	// num 是待判断的数字
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
