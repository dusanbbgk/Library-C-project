#ifndef _knjiga_h_
#define _knjiga_h_
#include "delo.h"
class Knjiga : public Delo
{
	int brstr, debljina;
	void kopiraj(const Knjiga& k)
	{
		brstr = k.brstr; debljina = k.debljina;
	}
public:
	Knjiga(const char* ime1, const char* naslov1, int b, int d)
		: Delo(ime1, naslov1)
	{
		brstr = b; debljina = d;
	}
	Knjiga(const Knjiga& k) : Delo(k) { kopiraj(k); }
	~Knjiga() {}
	Knjiga& operator= (const Knjiga& k)
	{
		if (this != &k) { Delo::operator=(k); kopiraj(k); }
		return *this;
	}
	const int dohvatibrstr() const { return brstr; }
	int dohvatidebljinu() const { return debljina; }
	char vrsta() const { return 'K'; }
	Knjiga* kopija() const { return new Knjiga(*this); }
private:
	void pisi(ostream& it) const
	{
		Delo::pisi(it); it << " br. strana:  " << brstr;
	}
};
#endif