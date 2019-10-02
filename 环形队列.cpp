/*
* 环形队列的实现
* 1: 需要注意, 数据入队列时, 指向队尾的指针不能单纯地加加, 否则会导致 tail 溢出 
* 2: 出队列是, 和数据入队列一样, 也不能单纯第 head ++  
*/
#include<iostream>
#include<string>
class MyCircleQueue {
	public:
		MyCircleQueue(int cap); // 构造一个容量为 cap  的队列
		virtual ~MyCircleQueue(); //
		void clear() ; // 清空队列
		bool empty(); // 队列是否为空
		bool full(); // 队列判断是否已经为满了
		int length(); // 队列的长度
		bool push(int val) ; // 入队列
		bool pop(int &val); // 出队列
		void traverse(); // 遍历队列
	private:
		int * ptr; //
		int len; // 长度
		int capacity; // 容量
		int head; // 对头
		int tail; // 队列尾部
};
using namespace std;


MyCircleQueue::MyCircleQueue(int cap):head(0),tail(0),len(0),capacity(cap) {
// 环形队列的构造函数
// 将队列的容器赋值个容量
// 初始条件下, 队列的头部和队尾的头部, 均为 0, 容量为 cap
	ptr = new int[cap] {0};

}

MyCircleQueue::~MyCircleQueue() {
	delete []ptr; // 销毁数组的空间
	ptr =nullptr;
}

// 清空队列只需要把队列的头部和队列的尾部清零
// 队列的长度也需要清零
void MyCircleQueue::clear() {
	head = 0 ;
	tail = 0 ;
	len = 0 ;
}

// 判断队列是否为空
bool MyCircleQueue::empty() {
	return len == 0 ?true:false;
}

// 判断队列是否已经为满
bool  MyCircleQueue:: full() {
	return len == capacity ? true : false;
}

// 对列的长度
int MyCircleQueue::length() {
	return len;
}

// 将元素插入队列
bool MyCircleQueue::push(int val) {

// 如果队列已经为满了, 退出
	if(full()) {
		return false;
	}

	ptr[tail] = val;
	tail ++; // 对尾部加一
	len ++; // 队列的长度加一
	tail %= capacity;  // 队列的尾部形成环
	return true;
}

// 元素出队列
bool MyCircleQueue:: pop(int &val) {
	if (empty()) {
		val  = -1;
		return false;
	}
	val = ptr[head];
	head ++; // 队列的头部向前移动一个位置
	head %= capacity;
	len --; // 队列的长度减一
	return true;

}

// 遍历队列
void MyCircleQueue::traverse() {
	cout<<"队列的遍历:";
	// 这里需要考虑队列的长度和对头和
	for ( int i = head; i< len + head; i++) {
		std::cout<< ptr[i % capacity]<<" ";
	}
	std::cout<<endl;
}

int main(void) {
	std::cout<< "hello world";
	MyCircleQueue q(9);
	for (int i = 0 ; i< 9 ; i++) {
		std::cout<<	q.push(i) <<endl;;
	}
	// 在队列为满是, 插入队列的检测
	auto str = q.push(10) == 1 ? "插入成功":"入队列失败";
	cout<< "当前的队列:"<<q.full()<<" , 插入队列: "<<str <<endl;

	// 判断当前的队列是否为满
	std::cout<<"队列判断满: "<< q.full()<<endl;
	q.traverse();

	// 数据出队列
	for ( int i = 0 ; i< 9 ; i++) {
		auto tmp = 0 ;
		q.pop(tmp);
		std::cout<<"出队列: "<<tmp<<endl;
	}

	cout<<"出队列之后再次判断是否空: "<<q.empty()<<endl;
	return 0;
}


