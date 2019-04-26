#ifndef _niz_h_
#define _niz_h_
#include "greska.h"
template <typename T, int U>
class Niz
{
protected:
	T* n;
	int brelem, kap;
	void kopiraj(const Niz& n1);
public:
	explicit Niz(int kap = 5) : kap(kap) { n = new T[kap]; brelem = 0; }
	Niz(const Niz& n1) { kopiraj(n1); }
	virtual ~Niz() { delete[] n; }
	Niz& operator= (const Niz& n1)
	{
		if (this != &n1) { brisi(); kopiraj(n1); }
		return *this;
	}
	const int dohvatikap() const { return kap; }
	const int dohvatibrelem() const { return brelem; }
	virtual Niz& operator+= (const T& br)
	{
		if (dohvatikap() == dohvatibrelem())
			throw GPun();
		n[brelem++] = br;
		return *this;
	}
	T& operator[] (const int i)
	{
		if (i < 0 || i >= brelem)
			throw GIndeks();
		return n[i];
	}
	const T& operator[] (const int i) const
	{
		if (i < 0 || i >= brelem)
			throw GIndeks();
		return n[i];
	}
	T operator() (int j)
	{
		if (brelem == 0)
			throw GPrazan();
		else if (j<0 || j>brelem)
			throw GIndeks();
		T br = n[j];
		for (int i = j; i < brelem; i++)
			n[i] = n[i + 1];
		--brelem;
		return br;
	}
	void isprazni() { brelem = 0; }
	template <typename T, int U>
	friend ostream& operator<< (ostream& it, const Niz<T, U>& n1);
};
template <typename T, int U>
void Niz<T, U>::kopiraj(const Niz& n1)
{
	n = new T[kap = n1.kap];
	brelem = n1.brelem;
	for (int i = 0; i < brelem; i++)
		n[i] = n1.n[i];
}
template <typename T, int U>
ostream& operator<< (ostream& it, const Niz<T, U>& n1)
{
	for (int i = 0; i < n1.brelem; i++)
	{
		/*if(U==0)
			it<<n1.n[i]<<endl;         //NESTO NIJE DOBRO!!!
		else*/
		it << *n1.n[i] << endl;
	}
	return it;
}
#endif
