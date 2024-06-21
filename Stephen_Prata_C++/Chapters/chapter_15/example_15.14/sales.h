#ifndef SALES_H_
#define SALES_H_

#include <stdexcept>
#include <string>

class Sales {
	public:
		enum { MONTHS = 12 };
		class bad_index : public std::logic_error {
			private:
				int bi;
			public:
				explicit bad_index(int 
