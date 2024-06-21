#ifndef CD_H_
#define CD_H_

class Cd {
	private:
		char *performers;
		char *label;
		int selections;
		double playtime;
	public:
		Cd(const char * p, const char * l, int n, double x);
		Cd(const Cd & d);
		Cd();
		~Cd();
		virtual void Report() const;
		Cd & operator=(const Cd & d);
};

class Classic :public Cd 
{
	private:
		char *songname;
	public:
		Classic(const char *s, const char *p, const char *l, int n, double x);
		Classic(const Classic & d);
		Classic();
		~Classic();
		void Report() const;
		Classic & operator=(const Classic & c);
};

#endif 
