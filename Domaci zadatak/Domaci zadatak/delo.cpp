#include "delo.h"
#include <cstring>
void Delo::kopiraj(const Delo& d)
{
	ime = new char[strlen(d.ime) + 1];
	strcpy(ime, d.ime);
	naslov = new char[strlen(d.naslov) + 1];
	strcpy(naslov, d.naslov);
}
Delo::Delo(const char* ime1, const char* naslov1) : Id(++posId)
{
	ime = new char[strlen(ime1) + 1];
	strcpy(ime, ime1);
	naslov = new char[strlen(naslov1) + 1];
	strcpy(naslov, naslov1);
}
int Delo::posId = 0;