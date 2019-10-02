/*
* �Լ�ʵ��һ���ַ����Ĳ��� �ڶ��Ͻ���
* ����Ҫ��ȷ�ַ���������Щ����,
*1.���췽��
*2. �ַ����ĳ���
*3. �ַ����ıȽ�
*4. �ַ��������
*5. �ַ�����ƴ��
*6. ��ȡ�Ӵ�
*7. ...
*/

#include<iostream>

using std::cout;
using std::endl;

struct  MyHeapString {

public:
	MyHeapString(const char* p, int ln ) {
		// ��ȡһ���ռ�
		this->ptr = (char*)calloc(sizeof(char), strlen(p) + 1);
		//memcpy(this->ptr, p, strlen(p));
		for (int i = 0; i < strlen(p); i++) {
			this->ptr[i] = p[i];
		}
		this->len = strlen(p);
	}
	int length() {
		return this->len;
	}
	~MyHeapString() {
		delete this->ptr;
		this->ptr = nullptr;
		this->len = 0;
	}

	void clear() {
		if (this->ptr) {
			delete this->ptr;
			this->ptr = nullptr;
			this->len = 0;
		}
	}

	// �ַ����ıȽ�
	int compare(MyHeapString s) {

		return strcmp(this->ptr, s.ptr);
	}

	// ��ȡһ���Ӵ�
	MyHeapString subString(int pos, int len) {
		if (pos + len > this->len || pos < 0) {
			return MyHeapString("", 0);
		}
		// ����һ���ռ�
		char* p = (char*)calloc(sizeof(char), len);
		if (!p) {
			return  MyHeapString("",0);
		}
		for (int i = 0; i < len; i++) {
			p[i] = this->ptr[pos + i];
		}
		cout << p << endl;
		MyHeapString m(p, strlen(p));
		// ����Ҫ�ͷſռ�
		delete p;
		p = nullptr;
		// ���ؽ�ȡ���Ӵ�
		return m;
	}
	char* ptr;
	int len;
};

int main(void) {


	MyHeapString m = MyHeapString("hello",strlen("hello"));
	//MyHeapString s = m.subString(0, 2);
	//cout << "substring:" << s.ptr << endl;
	cout << "len:" << m.length() << endl;
	return 0;
}