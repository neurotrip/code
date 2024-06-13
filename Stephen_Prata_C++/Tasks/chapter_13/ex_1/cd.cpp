#include "cd.h"
#include <cstring>
#include <iostream>

Cd::Cd()
{
	performers = new char [1];
	strcpy(performers, "null");
	label = new char [1];
	strcpy(label, "null");
	selections = 0;
	playtime = 0;
}

Cd::Cd(const char *p, const char *l, int s, double pl)
{
	performers = new char [strlen(p) + 1];
	strcpy(performers, p);
	label = new char [strlen(l) + 1];
	strcpy(label, l);
	selections = s;
	playtime = pl;
}

Cd::Cd(const Cd & d)
{
	performers = new char [strlen(d.performers) + 1];
	strcpy(performers, d.performers);
	label = new char [strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::~Cd()
{
	delete [] performers;
	delete [] label;
}

void Cd::Report() const 
{
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std:: endl;
}

Cd & Cd::operator=(const Cd &d)
{
	if (this == &d)
		return *this;
	delete [] performers;
	delete [] label;
	performers = new char [strlen(d.performers) + 1];
	label = new char [strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}


Classic::Classic() : Cd()
{
	songname = new char [1];
	strcpy(songname, "null");

}

Classic::Classic(const char *s, const char *p, const char *l, int x, double pl) 
: Cd(p, l, x, pl)
{
	songname = new char [strlen(s) + 1];
	strcpy(songname, s);
}

Classic::Classic(const Classic & d) : Cd(d)
{
	songname = new char[strlen(d.songname) + 1];
	strcpy(songname, d.songname);
}

Classic::~Classic()
{
	delete [] songname;
}

void Classic::Report() const 
{
	std::cout << "Songname: " << songname << std::endl;
	Cd::Report();
}

Classic & Classic::operator=(const Classic &d)
{
	if (this == &d)
		return *this;
	Cd::operator=(d);
	delete [] songname;
	songname = new char [strlen(d.songname) + 1];
	strcpy(songname, d.songname);
	return *this;
}



