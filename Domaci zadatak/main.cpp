#include "knjiga.h"
#include "disk.h"
#include "komplet.h"
#include "biblioteka.h"
#include "greska.h"
using namespace std;
void menu();
void main()
{
	Biblioteka bibl("Laza Kostic");
	Disk d1("Plavi Orkestar", "Suada", 60.45, 1);
	Disk d2("Crvena Jabuka", "Uzmi me", 51.40, 1);
	Knjiga k1("Haled Hoseini", "Lovac na zmajeve", 276, 3);
	Knjiga k2("Ivo Andric", "Na Drini Cuprija", 453, 3);
	Komplet kom1("Dusan Mandrapa", "Komplet", 5);
	kom1 += d2; kom1 += k2;
	bibl += d1; bibl += kom1; bibl += k1;
	while (true)
	{
		try
		{
			cout << "\n\t\t\tBiblioteka " << bibl.dohvatiime() << endl << endl;
			menu();
			int op;
			cout << "--------------> ";
			cin >> op;
			switch (op)
			{
			case 1:
			{
				cout << bibl;
				break;
			}
			case 2:
			{
				cout << "Unesite identifikator zeljenog dela: ";
				int id;
				cin >> id;
				cout << bibl.uzmidelo(id);
				break;
			}
			case 3:
			{
				char naziv[30], ime[40], kd;
				int db;
				cout << "Naziv dela: ";
				getchar();
				gets_s(naziv);
				cout << "Ime i prezime autora: ";
				gets_s(ime);
				cout << "Da li je delo knjiga (k/K) ili disk (d/D): ";
				cin >> kd;
				if (kd == 'k' || kd == 'K')
				{
					int brstr;
					cout << "Broj strana: ";
					cin >> brstr;
					cout << "Debljina: ";
					cin >> db;
					Knjiga k(ime, naziv, brstr, db);
					bibl += k;
				}
				if (kd == 'd' || kd == 'D')
				{
					double vreme;
					cout << "Vreme trajanja: ";
					cin >> vreme;
					cout << "Debljina: ";
					cin >> db;
					Disk d(ime, naziv, vreme, db);
					bibl += d;
				}
				break;
			}
			case 4:
			{
				char naziv[30], ime[40];
				int kap, brel;
				cout << "Naziv kompleta: ";
				getchar();
				gets_s(naziv);
				cout << "Ime i prezime autora: ";
				gets_s(ime);
				cout << "Kapacitet kompleta: ";
				cin >> kap;
				Komplet *kom = new Komplet(ime, naziv, kap);
				cout << "Koliko dela zelite da ubacite u komplet? ";
				cin >> brel;
				for (int i = 0; i < brel; i++)
				{
					char naz[30], autor[40], op2;
					int deb;
					cout << i + 1 << ". Delo\n";
					cout << "Naziv dela: ";
					getchar();
					gets_s(naz);
					cout << "Ime i prezime autora: ";
					gets_s(autor);
					cout << "Da li je delo knjiga (k/K) ili disk (d/D): ";
					cin >> op2;
					if (op2 == 'k' || op2 == 'K')
					{
						int brstr;
						cout << "Broj strana: ";
						cin >> brstr;
						cout << "Debljina: ";
						cin >> deb;
						Knjiga k(autor, naz, brstr, deb);
						*kom += k;
					}
					if (op2 == 'd' || op2 == 'D')
					{
						double vreme;
						cout << "Vreme trajanja: ";
						cin >> vreme;
						cout << "Debljina: ";
						cin >> deb;
						Disk d(autor, naz, vreme, deb);
						*kom += d;
					}
				}
				bibl += *kom;
				break;
			}
			case 5:
			{
				char autor[40];
				cout << "Ime i prezime autora: ";
				getchar();
				gets_s(autor);
				cout << bibl.delaautora(autor);
				break;
			}
			case 6:
			{
				char op1[3];
				cout << "Da li ste sigurni da zelite da ispraznite biblioteku (Da/Ne): ";
				cin >> op1;
				if (strcmp(op1, "Da") == 0 || strcmp(op1, "da") == 0) ~bibl;
				break;
			}
			case 7:
			{
				char naziv[30], ime[40], kd;
				int db, br;
				cout << "Naziv dela: ";
				getchar();
				gets_s(naziv);
				cout << "Ime i prezime autora: ";
				gets_s(ime);
				cout << "Da li je delo knjiga (k/K) ili disk (d/D): ";
				cin >> kd;
				if (kd == 'k' || kd == 'K')
				{
					int brstr;
					cout << "Broj strana: ";
					cin >> brstr;
					cout << "Debljina: ";
					cin >> db;
					Knjiga k(ime, naziv, brstr, db);
					cout << "Koliko primeraka: ";
					cin >> br;
					bibl.primerci_zadatogdela(br, k);
				}
				if (kd == 'd' || kd == 'D')
				{
					double vreme;
					cout << "Vreme trajanja: ";
					cin >> vreme;
					cout << "Debljina: ";
					cin >> db;
					Disk d(ime, naziv, vreme, db);
					cout << "Koliko primeraka: ";
					cin >> br;
					bibl.primerci_zadatogdela(br, d);
				}
				break;
			}
			case 8:
			{
				cout << "\n\t\tDOVIDJENJA!!!\n\n";
				exit(1);
			}
			default:
			{
				cout << "Pogresna opcija!\n";
				break;
			}
			}
		}
		catch (GIndeks g)
		{
			cout << g;
		}
		catch (GPun g)
		{
			cout << g;
		}
		catch (GPrazan g)
		{
			cout << g;
		}
		catch (GSmanji g)
		{
			cout << g;
		}
		catch (GNemaDelo g)
		{
			cout << g;
		}
		catch (GPolPuna g)
		{
			cout << g;
		}
		catch (GBiblPuna g)
		{
			cout << g;
		}
		catch (GGreska g)
		{
			cout << g;
		}
	}
}
void menu()
{
	cout << "\t****************************************************\n\n";
	cout << "\t\t1. Prikazi trenutno stanje\n"
		<< "\t\t2. Iznajmi(izbaci) delo\n"
		<< "\t\t3. Dodaj delo\n"
		<< "\t\t4. Napravi komplet delo\n"
		<< "\t\t5. Prikazi dela zadatog autora\n"
		<< "\t\t6. Isprazni biblioteku\n"
		<< "\t\t7. Nabavi odredjen br. primeraka dela\n"
		<< "\t\t8. Kraj!\n\n";
}