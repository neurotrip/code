#ifndef PLORG_H_
#define PLORG_H_


class Plorg {
	private:
		static const int LEN = 19;
		char name_[LEN];
		int CI_;
	public:
		Plorg(const char *name = "Plorga", int CI = 50);
		void set_CI(int CI);
		void show();
};

#endif 
