/******************************************************************
* 题目来自 leetcode  
* https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/ 
* 
* 
* 
*******************************************************************/ 
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 使用贪心算法, 尽可能第使每一支箭尽可能多地射爆尽可能多的气球
// 把气球想象成一个线段的区间, 尽可能找区间重叠的, 但是必须要包含首部的气球射击作为一次射击
// 如果两个气球没有重叠的一个区间, 则必须射击两次

// 1. 对各个气球进行一次排序, 按照气球的左端点从小到大排序
// 2. 遍历气球数组, 同时维护一个射击区间, 在满足可以将当前气球射穿的情况下, 尽可能地射击更多的气球, 每射穿一个气球, 更新一次射击区间(保证射击区间可以将新的气球也射穿)
// 3. 如果新的气球没有办法射穿, 则需要维护一个新的射击区间, 
class Solution {
public:
    // 比较两个数的大小
    bool static cmp(std::vector<int> &left, std::vector<int> &right) {
        return left[0]< right[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        // 按照第一个元素来排序
        std::sort(points.begin(), points.end(), cmp) ; 
        if(!(points.size() >1)){
            return points.size();
        }
        
        // 维护一个射击的区间, 每次可能地射击更多的气球
        // 
        int xstart = points[0][0]; // 射击开始区间
        int xend = points[0][1]; // 最大的射击区间
        int need = 1;
        for ( int i = 1; i< points.size(); i++) {
            // 如果当前的开始的区间比前一个的射击区区间的开始要大, 则要更新
            if (  points[i][0] <= xend) {
                xstart = points[i][0];
                // 当射击区间的右端点大于当前射击区间的右端点时, 需要更新射击区间的右端点
                if (xend > points[i][1]) {
                    xend = points[i][1];
                }
                
            }
            // 如果射击区间的最大值比当前区间的最小值小, 表示当前的区间不能射穿该气球, 需要更新新的射击区间
            // 同时 need ++ ; 成立
            else if  (points[i][0] > xend) {
                xstart = points[i][0];
                xend = points[i][1];
                need ++;
            }
        }
        return need ;
    }
};

int main(void){
	cout<<"hello world"<<endl;
	vector<vector<int>> nums;
	nums.push_back(vector<int>{10,16});
	nums.push_back(vector<int>{2,8});
	nums.push_back(vector<int>{1,6});
	nums.push_back(vector<int>{7,12});
	cout<<Solution().findMinArrowShots(nums)<<endl; // 2 
	return 0;
}
