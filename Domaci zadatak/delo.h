#ifndef _delo_h_
#define _delo_h_
#include <iostream>
using namespace std;
class Delo
{
	static int posId;
	int Id;
protected:
	char *ime, *naslov;
	void kopiraj(const Delo& d);
	void brisi() { delete[] ime; delete[] naslov; }
public:
	explicit Delo(const char* ime1, const char* naslov1);
	Delo(const Delo& d) : Id(++posId) { kopiraj(d); }
	Delo& operator= (const Delo& d)
	{
		if (this != &d) { brisi(); kopiraj(d); }
		return *this;
	}
	virtual ~Delo() { brisi(); }
	const int id() const { return Id; }
	const char* dohvatiime() const { return ime; }
	const char* dohvatinaslov() const { return naslov; }
	virtual char vrsta() const = 0;
	virtual Delo* kopija() const = 0;
	virtual int dohvatidebljinu() const = 0;
protected:
	virtual void pisi(ostream& it) const
	{
		it << "\t" << vrsta() << " " << Id << ": " << ime << " - " << naslov
			<< ", debljina: " << dohvatidebljinu() << ";";
	}
	friend ostream& operator<< (ostream& it, const Delo& d)
	{
		d.pisi(it);
		return it;
	}
};
#endif