#ifndef _pniz_h_
#define _pniz_h_
#include "niz.h"
template <typename T, int U>
class PNiz : public Niz<T, U>
{
public:
	explicit PNiz(int kap = 5) : Niz(kap) {}
	//~PNiz () {}
	void povecaj();
	void smanji();
	PNiz& operator+= (const T& br)
	{
		if (dohvatikap() == dohvatibrelem())
			povecaj();
		n[brelem++] = br;
		return *this;
	}
	PNiz& operator+= (const PNiz& pn);
};
template <typename T, int U>
void PNiz<T, U>::povecaj()
{
	int br;
	do
	{
		cout << "Za koliko da povecam kapacitet? ";
		cin >> br;
	} while (br <= 0);
	T* pom = new T[kap += br];
	for (int i = 0; i < brelem; i++)
		pom[i] = n[i];
	n = pom;
}
template <typename T, int U>
void PNiz<T, U>::smanji()
{
	int br;
	cout << "Za koliko da smanjim kapacitet? ";
	cin >> br;
	if (br > (kap - brelem))
		throw GSmanji();
	T* pom = new T[kap -= br];
	for (int i = 0; i < brelem; i++)
		pom[i] = n[i];
	n = pom;
}
template <typename T, int U>
PNiz<T, U>& PNiz<T, U>::operator+= (const PNiz& pn)
{
	if (kap < brelem + pn.kap)
	{
		T* pom = new T[kap += pn.kap];
		for (int i = 0; i < brelem; i++)
			pom[i] = n[i];
		n = pom;
	}
	for (int i = 0; i < pn.brelem; i++)
	{
		PNiz<T, U>::operator+=(pn.n[i]);
	}
	return *this;
}
#endif