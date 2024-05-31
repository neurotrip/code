#ifndef GOLF_H
#define GOLF_H

const int LEN = 40;

class Golf {
	private:
		char fullname_[LEN];
		int handicap_;
	public:
		Golf(const char *name, int hc);
		Golf();
		void handicap(int hc);
		void showgolf();
};

#endif

