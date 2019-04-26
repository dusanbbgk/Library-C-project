#ifndef _greska_h_
#define _greska_h_
#include <iostream>
using namespace std;
class GIndeks {};
inline ostream& operator<< (ostream& o, const GIndeks& g)
{
	return o << "***Nedozvoljen indeks!***\n";
}
class GPrazan {};
inline ostream& operator<< (ostream& o, const GPrazan& g)
{
	return o << "***Prazno***!\n";
}
class GPun {};
inline ostream& operator<< (ostream& o, const GPun& g)
{
	return o << "***Puno!***\n";
}
class GSmanji {};
inline ostream& operator<< (ostream& o, const GSmanji& g)
{
	return o << "***Nije moguce toliko smanjiti kapacitet niza!***\n";
}
class GNemaDelo {};
inline ostream& operator<< (ostream& o, const GNemaDelo& g)
{
	return o << "***Ne postoji delo sa zadatim identifikatorom!***\n";
}
class GGreska {};
inline ostream& operator<< (ostream& o, const GGreska& g)
{
	return o << "***Doslo je do greske!***\n";
}
class GPolPuna {};
inline ostream& operator<< (ostream& o, const GPolPuna& g)
{
	return o << "***Polica je puna!***\n";
}
class GBiblPuna {};
inline ostream& operator<< (ostream& o, const GBiblPuna& g)
{
	return o << "***Biblioteka je puna!***\n";
}
#endif