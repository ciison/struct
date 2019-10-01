#include<stdio.h>


struct linear {
	int len;
	int cap;
	int* ptr;

};

int len(linear* l) {
	return l->len;
}

int cap(linear* l) {
	return l->cap;
}

int main(void) {
	printf("hello world");
	return 0;
}