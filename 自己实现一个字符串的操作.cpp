/*
* 自己实现一个字符串的操作 在堆上建立
* 首先要明确字符串的有哪些功能,
*1.构造方法
*2. 字符串的长度
*3. 字符串的比较
*4. 字符串的清空
*5. 字符串的拼接
*6. 获取子串
*7. ...
*/

#include<iostream>

using std::cout;
using std::endl;

struct  MyHeapString {

public:
	MyHeapString(const char* p, int ln ) {
		// 获取一个空间
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

	// 字符串的比较
	int compare(MyHeapString s) {

		return strcmp(this->ptr, s.ptr);
	}

	// 获取一个子串
	MyHeapString subString(int pos, int len) {
		if (pos + len > this->len || pos < 0) {
			return MyHeapString("", 0);
		}
		// 生成一个空间
		char* p = (char*)calloc(sizeof(char), len);
		if (!p) {
			return  MyHeapString("",0);
		}
		for (int i = 0; i < len; i++) {
			p[i] = this->ptr[pos + i];
		}
		cout << p << endl;
		MyHeapString m(p, strlen(p));
		// 这里要释放空间
		delete p;
		p = nullptr;
		// 返回截取的子串
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