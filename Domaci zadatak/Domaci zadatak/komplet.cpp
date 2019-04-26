#include "komplet.h"
void Komplet::kopiraj(const Komplet& kom)
{
	Delo::kopiraj(kom);
	for (int i = 0; i < kom.dela.dohvatibrelem(); i++)
		dela[i] = kom.dela[i]->kopija();
}
Komplet::~Komplet()
{
	for (int i = 0; i < dela.dohvatibrelem(); delete dela[i++]);
}
int Komplet::dohvatidebljinu() const
{
	int s = 0;
	for (int i = 0; i < dela.dohvatibrelem(); i++)
		s += dela[i]->dohvatidebljinu();
	return s;
}