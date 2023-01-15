#include "Bilet.h"
#define _CTR_SECURE_NO_WARNING
#pragma warning (disable: 4996)


static int contorBilet = 0;

static int getcontorBilet() {
	return contorBilet;
}



Plata::Plata(const char* numeParticipant, int rand, int loc, string categorie, bool locRezervat , int pret, string metodaPlata, string contBancar)
{
	setnumeParticipant(numeParticipant);
	setrand(rand);
	setloc(loc);
	setcategorie(categorie);
	setlocRezervat(locRezervat);
	this->pret = pret;
	this->metodaPlata = metodaPlata;
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

int Plata::getpret()
{
	return this->pret;
}

string Plata::getmetodaPlata()
{
	return this->metodaPlata;
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
void Bilet::setcategorie(string categorie)
{
	this->categorie = categorie;
}
void Bilet::setlocRezervat(bool locRezervat)
{
	this->locRezervat = locRezervat;
}

void Bilet::setPret(int pret)
{
	this->pret = pret;
}

void Plata::setPret(int pret)
{
	this->pret = pret;
}

void Plata::setmetodaPlata(string metodaPlata)
{
	if (metodaPlata == "cash" || metodaPlata == "card")
		this->metodaPlata = metodaPlata;
	else
		metodaPlata = "necunoscuta";
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

int Bilet::fabricaID(int idEvent, int rand, int loc)
{
	int idBilet;
	
	idBilet = idEvent * 100 + rand;
	idBilet = idBilet * 100 + loc;
	idBilet = idBilet * 10 + ((rand + loc) * 123 / 17) % 10; 
	return idBilet;
}

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

void Bilet::scriereBiletFisier(int tempID, int idEvent, int rand, int loc, string nParticipant, string numeEvent, string categorie)
{
	fstream file;
	string filename = "Bilete\\" + to_string(tempID) + ".bin";
	file.open(filename.c_str(), ios::binary | ios::out);
	if (!file.is_open())
		cout << "Eroare la deschiderea fisierului " << filename << "!" << endl;
	else
	{
		file.write(reinterpret_cast<char*>(&tempID), sizeof(tempID));
		file.write(reinterpret_cast<char*>(&idEvent), sizeof(idEvent));
		file.write(reinterpret_cast<char*>(&rand), sizeof(rand));
		file.write(reinterpret_cast<char*>(&loc), sizeof(loc));

		int length = nParticipant.length();
		file.write((char*)&length, sizeof(length));
		file.write(nParticipant.c_str(), length + 1);

		file.write((char*)&length, sizeof(length));
		file.write(categorie.c_str(), length + 1);
	}
 }

void Bilet::citesteBiletFisier(int id)
{
	int tempID=0, idEvent=0, rand=0, loc=0;
	string numeParticipant, numeEvent, categorie;
	fstream file;
	string filename = "Bilete\\" + to_string(id) + ".bin";
	
	file.open(filename, ios::in);
	if (!file.is_open())
		cout << "Eroare la deschiderea fisierului!";
	else
	{
		file.read((char*)&tempID, sizeof(tempID));
		file.read((char*)&idEvent, sizeof(idEvent));
		file.read((char*)&rand, sizeof(rand));
		file.read((char*)&loc, sizeof(loc));

		int length = 0; 
		file.read((char*)&length, sizeof(length));
		char* numeP = new char[length + 1];
		file.read(numeP, length + 1);
		numeParticipant = numeP;
		delete[] numeP;


		file.read((char*)& length, sizeof(length));
		char* numeCat = new char[length + 1];
		file.read(numeCat, length + 1);
		categorie = numeCat;
		delete[] numeCat;

	}
	cout << tempID << " " << idEvent << " " << rand << " " << loc << " " << numeParticipant << " " << categorie;

}