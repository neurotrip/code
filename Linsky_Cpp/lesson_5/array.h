#include <stdlib.h>

#ifndef ARRAY_H_
#define ARRAY_H_
class Array {
	private:
		size_t mySize;
		int *myData;
	public:
		Array(size_t size);
		~Array();
		Array(Array &a);
		void set(int i, int val);
		int get(int i);
		size_t getSize();
		Array& operator = (Array &a);
};
#endif
