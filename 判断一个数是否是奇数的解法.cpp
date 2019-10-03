// 判断一个数是否是奇数的解法,
// 利用 数的二进制的格式, 如果一个数是奇数,
// 那么二进制位的最后一位肯定是 1
// 正则, 如果一个数是偶数, 那么的二进制位的最后一位肯定是0 

#include<iostream>


int main(void) {
	
	//判断一个数是否是奇数的解法
	auto is_odd = [=] ( int a )-> decltype( 1==1 ) {
		return a & 0x1;
	};
	
	std::cout<<is_odd(1) <<" , "<< is_odd(2) << std::endl;
	
	return 0 ;
}
