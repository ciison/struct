/******************************************************************
* ��Ŀ���� leetcode  
* https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/ 
* 
* 
* 
*******************************************************************/ 
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// ʹ��̰���㷨, �����ܵ�ʹÿһ֧�������ܶ���䱬�����ܶ������
// �����������һ���߶ε�����, �������������ص���, ���Ǳ���Ҫ�����ײ������������Ϊһ�����
// �����������û���ص���һ������, ������������

// 1. �Ը����������һ������, �����������˵��С��������
// 2. ������������, ͬʱά��һ���������, ��������Խ���ǰ�����䴩�������, �����ܵ�������������, ÿ�䴩һ������, ����һ���������(��֤���������Խ��µ�����Ҳ�䴩)
// 3. ����µ�����û�а취�䴩, ����Ҫά��һ���µ��������, 
class Solution {
public:
    // �Ƚ��������Ĵ�С
    bool static cmp(std::vector<int> &left, std::vector<int> &right) {
        return left[0]< right[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        // ���յ�һ��Ԫ��������
        std::sort(points.begin(), points.end(), cmp) ; 
        if(!(points.size() >1)){
            return points.size();
        }
        
        // ά��һ�����������, ÿ�ο��ܵ�������������
        // 
        int xstart = points[0][0]; // �����ʼ����
        int xend = points[0][1]; // �����������
        int need = 1;
        for ( int i = 1; i< points.size(); i++) {
            // �����ǰ�Ŀ�ʼ�������ǰһ�������������Ŀ�ʼҪ��, ��Ҫ����
            if (  points[i][0] <= xend) {
                xstart = points[i][0];
                // �����������Ҷ˵���ڵ�ǰ���������Ҷ˵�ʱ, ��Ҫ�������������Ҷ˵�
                if (xend > points[i][1]) {
                    xend = points[i][1];
                }
                
            }
            // ��������������ֵ�ȵ�ǰ�������СֵС, ��ʾ��ǰ�����䲻���䴩������, ��Ҫ�����µ��������
            // ͬʱ need ++ ; ����
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
