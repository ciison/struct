/*
* ʵ��һ��˳���, 
* ����: ʵ��˳���ĳ�ʼ��, ����, ����, ��� 
*/
#include<iostream>
using std::cout;
using  std::endl;
class sequelist {
	public:
		sequelist(int cap):capacity(cap),len(0) {
			// ���� cap ���ռ������
			ptr = new int[cap] {0};
		}
		~sequelist() {
			delete [] ptr;
			ptr = nullptr;
		}

		// ������Ա�
		void clear() {
			this ->len = 0 ;
		}
		// ˳���ĳ���
		int inline length() {
			return this->len;
		}

		// �ж��Ƿ�Ϊ��
		bool inline empty() {
			return len == 0 ? true : false;
		}
		// �ж��Ƿ��Ѿ�Ϊ��
		bool inline  full () {
			return this ->capacity == 0 ? true: false;
		}
		// �ڶ�Ӧ��λ�ò�������
		bool inline  insert(int pos, int val ) {
			// ��������λ�ô��ڳ���, ֱ�ӷ���
			if ( pos > this -> len ) {
				return false;
			}
			// �����Ѿ� ��������Ⱦͷ�����
			if (this ->len  == this->capacity ) {
				return false;
			}
			// �� pos ֮���Ԫ������ƶ�һλ
			for ( int i = 0 ; i< this -> len - pos ; i ++) {
				ptr[len  - i +1] = ptr[len - i];
			}
			// �ڶ�Ӧ��λ�ø�ֵ����
			ptr[pos] = val;
			// ���ݵĳ��ȼ�һ
			this->len ++;
		}
		// �������Ա�
		void inline  traverse() {
			std::cout<<"����:";
			for(auto i = 0 ; i< this -> len ; i++) {
				cout<< ptr[i] << " ";
			}
			cout<<endl;
		}
	private:
		int len;  // ����
		int *ptr; // ������
		int capacity; // ������
};


int main(void) {
	cout<<"hello world"<<endl;
	sequelist list(5);
	list.insert(0,2);
	list.insert(1,1);
	list.insert(1,67890); // �ڵڶ���λ�ò���
	list.insert(3,3);
	list.insert(4,4);
	list.insert(5,5);
	list.traverse();
	cout<<"length" << list.length()<<endl;
	list.clear(); 
	list.traverse();
	cout<<"length" << list.length() <<endl;
}
