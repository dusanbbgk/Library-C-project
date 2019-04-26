#include "biblioteka.h"
#include "greska.h"
Biblioteka::Biblioteka(const char* ime1, int brpol)
	: brpol(brpol), police(brpol)
{
	ime = new char[strlen(ime1) + 1];
	strcpy(ime, ime1);
	for (int i = 0; i < brpol; i++)
		police.operator+=(new Polica(i + 1));
}
void Biblioteka::brisi()
{
	for (int i = 0; i < police.dohvatibrelem(); delete police[i++]);
	delete[] ime;
}
PNiz<Delo*, 2> Biblioteka::delaautora(const char* autor) const
{
	PNiz<Delo*, 2> pom;
	for (int i = 0; i < brpol; i++)
		pom += police[i]->delaautora(autor);
	return pom;
}
Delo& Biblioteka::uzmidelo(int id)
{
	for (int i = 0; i < brpol; i++)
		return (*police[i])(id);
	throw GGreska();
}
Biblioteka& Biblioteka::operator+= (const Delo& delo)
{
	for (int i = 0; i < brpol; i++)
	{
		if (police[i]->ukupnadebljina() + delo.dohvatidebljinu() >
			police[i]->duzina())
		{
			if (i == brpol - 1) throw GBiblPuna();
			continue;
		}
		police[i]->operator+=(delo);
		break;
	}
	return *this;
}
Biblioteka& Biblioteka::operator~ ()
{
	for (int i = 0; i < police.dohvatibrelem(); i++)
		police[i]->isprazni();
	return *this;
}
void Biblioteka::primerci_zadatogdela(int br, const Delo& delo)
{
	for (int i = 0; i < br; i++)
		*this += *delo.kopija();
}
ostream& operator<< (ostream& it, const Biblioteka& bibl)
{
	/*it<<bibl.ime<<endl;*/ //PRIKAZUJE IME NA POCETKU PROGRAMA!
	it << bibl.police;
	return it;
}
