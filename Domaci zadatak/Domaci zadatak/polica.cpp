#include "polica.h"
Polica::~Polica()
{
	for (int i = 0; i < dela.dohvatibrelem(); delete dela[i++]);
}
PNiz<Delo*, 2> Polica::delaautora(const char* autor) const
{
	PNiz<Delo*, 2> pom;
	for (int i = 0; i < dela.dohvatibrelem(); i++)
	{
		if (strcmp(dela[i]->dohvatiime(), autor) == 0)
			pom += dela[i];
	}
	return pom;
}
Polica& Polica::isprazni()
{
	for (int i = 0; i < dela.dohvatibrelem(); delete dela[i++]);
	dela.isprazni();
	return *this;
}
int Polica::ukupnadebljina() const
{
	int deb = 0;
	for (int i = 0; i < dela.dohvatibrelem(); ++i)
		deb = deb + dela[i]->dohvatidebljinu();
	return deb;
}
Delo& Polica::operator() (int j)
{
	for (int i = 0; i < dela.dohvatibrelem(); i++)
	{
		if (j == dela[i]->id())
			return *dela(i);
	}
	throw GNemaDelo();
}