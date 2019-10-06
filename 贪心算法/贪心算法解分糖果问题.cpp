// *********************************************************************************
//  贪心法: 需要遵循某种规律, 不断贪心的选取当前最优策略的算法的设计思想
// *********************************************************************************
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 分糖果的问题
// 题目来自 leetcode https://leetcode-cn.com/problems/assign-cookies/ 分饼干的问题
// 使用的是贪心算法:
//
// 当某个孩子可以被多个饼干满足时, 是否需要优先用某个饼干满足这个孩子?
// 当某个饼干可以满足多个孩子时,  是否需要优先满足某个孩子?


// 糖果的数组: s = [ 1, 3, 6, 8, 20] , 需求因子: g = [2, 5, 9, 9, 10, 15]
// 分析题目:
// 核心的目标: 让更多的孩子得到满足, 有以下的规律:
//
// 1. 某个饼干如果不能满足某个孩子时, 则该糖果也一定不能满足需求因子更大的孩子
// : 分析:
// 糖果 1(s = 1) 不能满足孩子 1(g = 2) 即 1 < 2,, 则不能满足孩子2,  孩子3, ....
// 糖果2( s =3 ) 不能满足孩子2( g = 5) 即 3 < 5, 则不能满足孩子3 , 孩子4,....
//
// 2. 某个孩子可以用更小的糖果满足时, 则没有必要用更大的糖果来满足, 因为可以保留更多的糖果满足需求因子更大的孩子(贪心算法)
//  需要遵循某种规律, 不断贪心的选取当前最优策略的算法的设计思想 ::::: 这里的策略是, 如果可以选取小的糖果来满足当前的孩子,
//  就选取小的糖果来满足, (当前的最有策略就是能小则小)
//
// 如果孩子1( g= 2) 可以被糖果( s = 3 ) 满足, 则没有必要使用糖果3, 4, 5 来满足
// 如果孩子2 (g =5) 可以被糖果 3( s = 6 ) 满足, 则没有必要使用糖果 4, 5 来满足

// 3.....
// 孩子的需求因子更小更加容易被满足, 故优先从需求因子小的孩子尝试, 可以得到正确的结果

class Solution {
	public:
		int cookies(vector<int> &cookies, vector<int> &needs) {
			sort(cookies.begin(),cookies.end()); // 孩子的需求和饼干都做一个排序 
			sort(needs.begin(),needs.end());

			int child_full = 0 , cookie_index = 0 ;
			// 遍历条件 
			for ( ; child_full< needs.size() && cookie_index < cookies.size(); ) {
				// 如果当前孩子的需求得到满足,  
				if ( needs[child_full] <= cookies[cookie_index]) {
					child_full ++; // 满足的孩子加一 
				}
				cookie_index ++; // 每次遍历糖果都向后移动一位 
			}
			return child_full; // 返回满足孩子的需求数目 

		}
};

int main(void) {
	cout<<" hello world "<<endl;
	vector<int> child= {1,2,3,4,5,6,7};
	vector<int> cookies = {3,2,5,9};
	cout<<"child full "<< Solution().cookies(cookies,child)<<endl; 
	return 0;
}
