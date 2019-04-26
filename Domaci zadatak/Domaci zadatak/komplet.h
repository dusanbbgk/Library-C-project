#ifndef _komplet_h_
#define _komplet_h_
#include <iostream>
#include <cstring>
#include "pniz.h"
#include "delo.h"
class Komplet : public Delo
{
	PNiz<Delo*, 1> dela;
	void kopiraj(const Komplet& kom);
	void pisi(ostream& it) const
	{
		Delo::pisi(it); it << endl;
		for (int i = 0; i < dela.dohvatibrelem(); i++)
		{
			if (i == dela.dohvatibrelem() - 1)
				it << "\t" << *dela[i];
			else
				it << "\t" << *dela[i] << endl;
		}
		/*it<<dela;*/ //ISPIS NISAM VRSIO PREKO NIZA ZBOG dodatnog "\t"!
	}
public:
	explicit Komplet(const char* autor1, const char* naslov1, int kap)
		: Delo(autor1, naslov1), dela(kap) {}
	Komplet(const Komplet& kom)
		: Delo(kom), dela(kom.dela) {
		kopiraj(kom);
	}
	~Komplet();
	Komplet& operator= (const Komplet& kom)
	{
		if (this != &kom) { Delo::operator=(kom); kopiraj(kom); }
		return *this;
	}
	char vrsta() const { return 'S'; } //"S" od "SET"
	Komplet* kopija() const { return new Komplet(*this); }
	int dohvatidebljinu() const;
	Komplet& operator+= (const Delo& delo)
	{
		dela += delo.kopija();
		return *this;
	}
};
#endif