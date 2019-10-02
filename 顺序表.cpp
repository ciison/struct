/*
* 实现一个顺序表, 
* 功能: 实现顺序表的初始化, 长度, 插入, 清空 
*/
#include<iostream>
using std::cout;
using  std::endl;
class sequelist {
	public:
		sequelist(int cap):capacity(cap),len(0) {
			// 生成 cap 个空间的数据
			ptr = new int[cap] {0};
		}
		~sequelist() {
			delete [] ptr;
			ptr = nullptr;
		}

		// 清空线性表
		void clear() {
			this ->len = 0 ;
		}
		// 顺序表的长度
		int inline length() {
			return this->len;
		}

		// 判断是否为空
		bool inline empty() {
			return len == 0 ? true : false;
		}
		// 判断是否已经为满
		bool inline  full () {
			return this ->capacity == 0 ? true: false;
		}
		// 在对应的位置插入数据
		bool inline  insert(int pos, int val ) {
			// 如果插入的位置大于长度, 直接返回
			if ( pos > this -> len ) {
				return false;
			}
			// 长度已经 和容量相等就返回了
			if (this ->len  == this->capacity ) {
				return false;
			}
			// 将 pos 之后的元素向后移动一位
			for ( int i = 0 ; i< this -> len - pos ; i ++) {
				ptr[len  - i +1] = ptr[len - i];
			}
			// 在对应的位置赋值操作
			ptr[pos] = val;
			// 数据的长度加一
			this->len ++;
		}
		// 遍历线性表
		void inline  traverse() {
			std::cout<<"遍历:";
			for(auto i = 0 ; i< this -> len ; i++) {
				cout<< ptr[i] << " ";
			}
			cout<<endl;
		}
	private:
		int len;  // 长度
		int *ptr; // 数据域
		int capacity; // 容量域
};


int main(void) {
	cout<<"hello world"<<endl;
	sequelist list(5);
	list.insert(0,2);
	list.insert(1,1);
	list.insert(1,67890); // 在第二个位置插入
	list.insert(3,3);
	list.insert(4,4);
	list.insert(5,5);
	list.traverse();
	cout<<"length" << list.length()<<endl;
	list.clear(); 
	list.traverse();
	cout<<"length" << list.length() <<endl;
}
