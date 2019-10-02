/*
* ���ζ��е�ʵ��
* 1: ��Ҫע��, ���������ʱ, ָ���β��ָ�벻�ܵ����ؼӼ�, ����ᵼ�� tail ��� 
* 2: ��������, �����������һ��, Ҳ���ܵ����� head ++  
*/
#include<iostream>
#include<string>
class MyCircleQueue {
	public:
		MyCircleQueue(int cap); // ����һ������Ϊ cap  �Ķ���
		virtual ~MyCircleQueue(); //
		void clear() ; // ��ն���
		bool empty(); // �����Ƿ�Ϊ��
		bool full(); // �����ж��Ƿ��Ѿ�Ϊ����
		int length(); // ���еĳ���
		bool push(int val) ; // �����
		bool pop(int &val); // ������
		void traverse(); // ��������
	private:
		int * ptr; //
		int len; // ����
		int capacity; // ����
		int head; // ��ͷ
		int tail; // ����β��
};
using namespace std;


MyCircleQueue::MyCircleQueue(int cap):head(0),tail(0),len(0),capacity(cap) {
// ���ζ��еĹ��캯��
// �����е�������ֵ������
// ��ʼ������, ���е�ͷ���Ͷ�β��ͷ��, ��Ϊ 0, ����Ϊ cap
	ptr = new int[cap] {0};

}

MyCircleQueue::~MyCircleQueue() {
	delete []ptr; // ��������Ŀռ�
	ptr =nullptr;
}

// ��ն���ֻ��Ҫ�Ѷ��е�ͷ���Ͷ��е�β������
// ���еĳ���Ҳ��Ҫ����
void MyCircleQueue::clear() {
	head = 0 ;
	tail = 0 ;
	len = 0 ;
}

// �ж϶����Ƿ�Ϊ��
bool MyCircleQueue::empty() {
	return len == 0 ?true:false;
}

// �ж϶����Ƿ��Ѿ�Ϊ��
bool  MyCircleQueue:: full() {
	return len == capacity ? true : false;
}

// ���еĳ���
int MyCircleQueue::length() {
	return len;
}

// ��Ԫ�ز������
bool MyCircleQueue::push(int val) {

// ��������Ѿ�Ϊ����, �˳�
	if(full()) {
		return false;
	}

	ptr[tail] = val;
	tail ++; // ��β����һ
	len ++; // ���еĳ��ȼ�һ
	tail %= capacity;  // ���е�β���γɻ�
	return true;
}

// Ԫ�س�����
bool MyCircleQueue:: pop(int &val) {
	if (empty()) {
		val  = -1;
		return false;
	}
	val = ptr[head];
	head ++; // ���е�ͷ����ǰ�ƶ�һ��λ��
	head %= capacity;
	len --; // ���еĳ��ȼ�һ
	return true;

}

// ��������
void MyCircleQueue::traverse() {
	cout<<"���еı���:";
	// ������Ҫ���Ƕ��еĳ��ȺͶ�ͷ��
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
	// �ڶ���Ϊ����, ������еļ��
	auto str = q.push(10) == 1 ? "����ɹ�":"�����ʧ��";
	cout<< "��ǰ�Ķ���:"<<q.full()<<" , �������: "<<str <<endl;

	// �жϵ�ǰ�Ķ����Ƿ�Ϊ��
	std::cout<<"�����ж���: "<< q.full()<<endl;
	q.traverse();

	// ���ݳ�����
	for ( int i = 0 ; i< 9 ; i++) {
		auto tmp = 0 ;
		q.pop(tmp);
		std::cout<<"������: "<<tmp<<endl;
	}

	cout<<"������֮���ٴ��ж��Ƿ��: "<<q.empty()<<endl;
	return 0;
}


