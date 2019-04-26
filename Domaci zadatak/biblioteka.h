#ifndef _biblioteka_h_
#define _biblioteka_h_
#include "polica.h"
class Biblioteka
{
	char* ime;
	int brpol;
	Niz<Polica*, 1> police;
	void kopiraj(const Biblioteka& bibl) {}
	Biblioteka(const Biblioteka& bibl) {}
	Biblioteka& operator= (const Biblioteka& bibl) {}
	void brisi();
public:
	Biblioteka(const char* ime1, int brpol = 3);
	~Biblioteka() { brisi(); }
	int dohvatibrpol() const { return brpol; }
	Polica& operator[] (int j)
	{
		if (j > brpol)
			throw GIndeks();
		return *police[j - 1];
	}
	const Polica& operator[] (int j) const
	{
		if (j > brpol)
			throw GIndeks();
		return *police[j - 1];
	}
	Biblioteka& operator~ ();
	char* dohvatiime() const { return ime; }
	PNiz<Delo*, 2> delaautora(const char* autor) const;
	Delo& uzmidelo(int id);
	void primerci_zadatogdela(int br, const Delo& delo);
	Biblioteka& operator+= (const Delo& delo);
	friend ostream& operator<< (ostream& it, const Biblioteka& bibl);
};
#endif