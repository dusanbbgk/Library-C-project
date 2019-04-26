#ifndef _disk_h_
#define _disk_h_
#include "delo.h"
class Disk : public Delo
{
	double vreme;
	int debljina;
	void kopiraj(const Disk& d) { vreme = d.vreme; debljina = d.debljina; }
public:
	Disk(const char* ime1, const char* naslov1, double v, int d)
		: Delo(ime1, naslov1)
	{
		debljina = d;
		vreme = v;
	}
	Disk(const Disk& d) : Delo(d) { kopiraj(d); }
	~Disk() {}
	Disk& operator= (const Disk& d)
	{
		if (this != &d) { Delo::operator=(d); kopiraj(d); }
		return *this;
	}
	char vrsta() const { return 'D'; }
	Disk* kopija() const { return new Disk(*this); }
	int dohvatidebljinu() const { return debljina; }
	const double dohvativreme() const { return vreme; }
private:
	void pisi(ostream& it) const
	{
		Delo::pisi(it); it << " Vreme trajanja: " << vreme;
	}
};
#endif