#include<iostream>


int main(void) {
	auto is_odd = [=] ( int a )-> decltype( 1==1 ) {
		return a & 0x1;
	};
	std::cout<<is_odd(1) <<" , "<< is_odd(2) << std::endl;
	return 0 ;
} 
