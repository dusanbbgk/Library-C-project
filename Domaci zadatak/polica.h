#ifndef _polica_h_
#define _polica_h_
#include <iostream>
#include "niz.h"
#include "pniz.h"
#include "delo.h"
#include "greska.h"
#include <cstring>
using namespace std;
class Polica
{
	int rbr;
	double duz;
	PNiz<Delo*, 1> dela;
	void kopiraj(const Polica& pol) {}
	Polica(const Polica& pol) {}
	Polica& operator= (const Polica& pol) {}
public:
	Polica(int rbr, int kap = 5, double duz = 20)
		: rbr(rbr), dela(kap), duz(duz) {}
	~Polica();
	Polica& operator+= (const Delo& delo)
	{
		if (duz < ukupnadebljina() + delo.dohvatidebljinu())
			throw GPolPuna();
		dela += delo.kopija();
		return *this;
	}
	Delo& operator() (int j);
	Polica& isprazni();
	double duzina() const { return duz; }
	int ukupnadebljina() const;
	PNiz<Delo*, 2> delaautora(const char* autor) const;
	friend ostream& operator<< (ostream& it, const Polica& pol)
	{
		it << "Redni br.: " << pol.rbr << ". " << "duzina: " << pol.duz
			<< " broj dela: " << pol.dela.dohvatibrelem()
			<< " ukupna debljina: " << pol.ukupnadebljina() << endl
			<< pol.dela;
		return it;
	}
};
#endif


