#include "Bilet.h"
#define _CTR_SECURE_NO_WARNING
#pragma warning (disable: 4996)


static int contorBilet = 0;

static int getcontorBilet() {
	return contorBilet;
}


Bilet::Bilet() : idBilet(0)
{
	numeParticipant = new char[strlen("necunoscut") + 1];
	strcpy(numeParticipant, "necunoscut");
	rand = -1;
	loc = -1;
	categorie = "Normala";
	locRezervat = false;
	contorBilet++;
}

Bilet::Bilet(const char* numeParticipant, int rand, int loc, string categorie, bool locRezervat):idBilet(idBilet)
{
	contorBilet++;
	this->rand = rand;
	this->loc = loc;
	this->categorie = categorie;
	this->locRezervat = locRezervat;
	if (strlen(numeParticipant) > 2)
	{
		this->numeParticipant = new char[strlen(numeParticipant) + 1];
		strcpy(this->numeParticipant, numeParticipant);
	}
	else
	{
		this->numeParticipant = new char[strlen("necunoscut") + 1];
		strcpy(this->numeParticipant, "necunoscut");
	}

}

Bilet::Bilet(const Bilet& sursa) :idBilet(sursa.idBilet)
{
	this->rand = sursa.rand;
	this->loc = sursa.loc;
	this->categorie = sursa.categorie;
	this->locRezervat = sursa.locRezervat;
	delete[]numeParticipant;
	if (strlen(sursa.numeParticipant) > 2)
	{
		this->numeParticipant = new char[strlen(sursa.numeParticipant) + 1];
		strcpy(this->numeParticipant, sursa.numeParticipant);
	}
	else
	{
		this->numeParticipant = new char[strlen("necunoscut") + 1];
		strcpy(this->numeParticipant, "necunoscut");
	}
	contorBilet++;
}

Bilet::~Bilet()
{
	delete[] numeParticipant;
	contorBilet--;
}

Bilet& Bilet::operator=(Bilet& sursa)
{
	delete[]numeParticipant;
	this->rand = sursa.rand;
	this->loc = sursa.loc;
	this->categorie = sursa.categorie;
	this->locRezervat = sursa.locRezervat;
	delete[]numeParticipant;
	if (strlen(sursa.numeParticipant) > 2)
	{
		this->numeParticipant = new char[strlen(sursa.numeParticipant) + 1];
		strcpy(this->numeParticipant, sursa.numeParticipant);
	}
	else
	{
		this->numeParticipant = new char[strlen("necunoscut") + 1];
		strcpy(this->numeParticipant, "necunoscut");
	}
	return *this;

}

int Bilet::getidBilet()
{
	return this->idBilet;
}

int Bilet::getrand()
{
	return this->rand;
}

int Bilet::getloc()
{
	return this->loc;
}

string Bilet::getcategorie()
{
	return this->categorie;
}

bool Bilet::getlocRezervat()
{
	return this->locRezervat;
}


char* Bilet::getnumeParticipant()
{
	if (numeParticipant != nullptr)
	{
		char* copie = new char[strlen(numeParticipant) + 1];
		strcpy(copie, numeParticipant);
		return copie;
	}
	return nullptr;
}

void Bilet::setnumeParticipant(const char* numeParticipant)
{
	delete[] this->numeParticipant;
	if (strlen(numeParticipant) > 2)
	{
		this->numeParticipant = new char[strlen(numeParticipant) + 1];
		strcpy(this->numeParticipant, numeParticipant);
	}
	else
	{
		this->numeParticipant = new char[strlen("necunoscut") + 1];
		strcpy(this->numeParticipant, "necunoscut");
	}
}

void Bilet::setrand(int rand)
{
	this->rand = rand;
}

void Bilet::setloc(int loc)
{
	this->loc = loc;
}
void Bilet::setcategorie(int categorie)
{
	this->categorie = categorie;
}
void Bilet::setlocRezervat(bool locRezervat)
{
	this->locRezervat = locRezervat;
}


 ostream& operator<<(ostream& out, Bilet sursa)
{
	 out << "ID-ul biletului este: " << sursa.idBilet << endl;
	 out << "Numele participantului este: " << sursa.numeParticipant << endl;
	 out << "Randul selectat este: " << sursa.rand << endl;
	 out << "Locul selectat este: " << sursa.loc << endl;
	 out << "Categoria: " << sursa.categorie << endl;
	 out << "In momentul acutal biletul este: ";
	 if (sursa.locRezervat == false)
		 out << "disponibil";
	 else
		 out << "indisponibil";

	 return out;
}

 istream& operator>>(istream& in, Bilet& sursa)
 {
	 contorBilet++;
	 cout << "Introduceti randul biletului: " << endl;
	 in>>sursa.rand;
	 cout << "Introduceti locul biletului: " << endl;
	 in>>sursa.loc;
	 cout << "Introduceti categoria biletului " << endl;
	 if (sursa.categorie.length() > 2)
		 in >> sursa.categorie;
	 else
		 throw "Categoria a fost introdusa incorect";
	 cout << "Daca doriti sa rezervati acest bilet?" << endl;
	 cout << "true/false" << endl;
	 in>>sursa.locRezervat;
	 cout << "Introduceti numele pe care vreti sa cumparati biletul " << endl;
	 if (sursa.numeParticipant != nullptr && strlen(sursa.numeParticipant) > 2)
	 {
		 in >> sursa.numeParticipant;
	 }
	 else
	 {
		 throw "Numele e incorect introdus";
	 }
	 return in;
 }


 Bilet Bilet::operator-(int scadere)
 {
	 Bilet copie = *this;
	 copie.rand -= scadere;
	 return copie;
 }

 bool Bilet::operator!()
 {
	 return !this->locRezervat;
 }

 int Bilet::fabricaID()
 {
	 auxid[0] = this->rand % 10;
	 auxid[1] = ((this->loc % 10) * 29) % 10;
	 auxid[2] = int(numeParticipant[0]) % 10;
	 auxid[3] = int(numeParticipant[1]) % 10;
	 auxid[4] = ((int(numeParticipant[1]) % 10) * 13 + 17) % 10;
	 auxid[5] = (locatie.getidLocatie())%10;
	 int id = 0;
	 for (int i = 0; i < 6; i++)
	 {
		 id = id * 10 + auxid[i];
	 }
	 return id;
 }
 //in main va fi: Bilet bilet(bilet.fabricaID());

 string Bilet::seteazaCategorie(string categorie, string zonica)
 {
	 char* zone = locatie.getzona();
	 zonica = (char*)zone;
	 if (zonica == "Necunoscuta")
		 categorie = "Normala";
	 else
		 categorie = zonica;
	 return categorie;
 }

 void Bilet::validareBilet()
{
	 int* vLocuri;
	 int nrLocuri;

	 nrLocuri = locatie.getnrTotalLocuri();
	 vLocuri = locatie.getvectorLocuri();

	 cout << "Doriti sa achizitionati biletul de pe locul " << loc << " randul " << rand << endl;
	 cout << "Da/Nu";
	 string vote;
	 cin >> vote;
	 if (vote == "da" || vote == "Da" || vote == "dA" || vote == "DA")
		 locRezervat = true;
	 if (locRezervat = true)
		 locatie.setvectorLocuriCuCateUnu(vLocuri, nrLocuri, loc);
	
}