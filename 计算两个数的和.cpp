// 计算两个数的和
// 
 
#include<iostream>

int main(void) {

	auto add2Sum = [=](int a, int b)->decltype (b) {

		auto sum = 0, carry = 0;

		do {

			sum = a ^ b;
			carry = (a & b) << 1;
			a = sum;
			b = carry;

		} while (b);

		return sum;
	};

	std::cout << add2Sum(1, 1) << std::endl;
	
	return 0; 
}


