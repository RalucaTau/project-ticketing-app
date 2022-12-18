#define _CTR_SECURE_NO_WARNING
#pragma warning (disable: 4996)
#include "Eveniment.h"


Eveniment::Eveniment() : idEveniment(0)
{
	this->tipEveniment = new char[strlen("Necunoscut") + 1];
	strcpy(this->tipEveniment, "Necunoscut");
	numeEveniment = "Necunoscut";
	ora = -1;
	min = -1;
	zi = -1;
	luna = -1;
	an = -1;
	locuriOcupate = 0;
}

Eveniment::Eveniment(const char* tipEveniment, string numeEveniment, int ora, int min, int zi, int luna, int an, int locuriOcupate,const int idEveniment) :idEveniment(idEveniment)
{
	if (strlen(tipEveniment) > 3)
	{
		this->tipEveniment = new char[strlen(tipEveniment) + 1];
		strcpy(this->tipEveniment, tipEveniment);
	}
	else
	{
		this->tipEveniment = new char[strlen("Necunoscut") + 1];
		strcpy(this->tipEveniment, "Necunoscut");
	}
	//
	if (numeEveniment.length() > 3)
		this->numeEveniment = numeEveniment;
	else
		numeEveniment = "Necunoscut";
	//
	if (ora >= 0 && ora <= 23)
		this->ora = ora;
	else
		this->ora = -1;
	//
	if (min >= 0 && min <= 59)
		this->min = min;
	else
		this->min = -1;
	//
	if (zi >= 1 && zi <= 31)
		this->zi = zi;
	else
		this->zi = -1;
	//
	if (luna >= 1 && luna <= 12)
		this->luna = luna;
	else
		this->luna = -1;
	//
	if (an >= 2022 && an <= 2025)
		this->an = an;
	else
		this->an = -1;
	//
	this->locuriOcupate = locuriOcupate;

}

Eveniment::Eveniment(const Eveniment& sursa) :idEveniment(sursa.idEveniment)
{

	this->tipEveniment = new char[strlen(sursa.tipEveniment) + 1];
	strcpy(this->tipEveniment, sursa.tipEveniment);
	this->numeEveniment = sursa.numeEveniment;
	this->ora = sursa.ora;
	this->min = sursa.min;
	this->luna = sursa.luna;
	this->an = sursa.an;
	this->locuriOcupate = sursa.locuriOcupate;
}

Eveniment::~Eveniment()
{
	delete[]this->tipEveniment;
}


Eveniment& Eveniment::operator=(const Eveniment& sursa)
{
	delete[]this->tipEveniment;
	this->tipEveniment = new char[strlen(sursa.tipEveniment) + 1];
	strcpy(this->tipEveniment, sursa.tipEveniment);
	this->numeEveniment = sursa.numeEveniment;
	this->ora = sursa.ora;
	this->min = sursa.min;
	this->luna = sursa.luna;
	this->an = sursa.an;
	this->locuriOcupate = sursa.locuriOcupate;

	return *this;
}


int Eveniment::getidEveniment()
{
	return this->idEveniment;
}

char* Eveniment::gettipEveniment()
{
	if (tipEveniment != nullptr)
	{
		char* copie = new char[strlen(tipEveniment) + 1];
		strcpy(copie, tipEveniment);
		return copie;
	}
	return nullptr;
}

string Eveniment::getnumeEveniment()
{
	return numeEveniment;
}
int Eveniment::getora()
{
	return ora;
}
int Eveniment::getmin()
{
	return min;
}

int Eveniment::getzi()
{
	return zi;
}

int Eveniment::getluna()
{
	return luna;
}

int Eveniment::getan()
{
	return an;
}

int Eveniment::getlocuriOcupate()
{
	return locuriOcupate;
}


void Eveniment::settipEveniment(const char* tipEveniment)
{
	if (strlen(tipEveniment) > 3)
	{
		this->tipEveniment = new char[strlen(tipEveniment) + 1];
		strcpy(this->tipEveniment, tipEveniment);
	}
	else
		throw "Mai introduceti odata";
}

void Eveniment::setnumeEveniment(string numeEveniment)
{
	if (numeEveniment.length() > 2)
		this->numeEveniment = numeEveniment;
	else
		throw "Mai introduceti odata";

}


void Eveniment::setora(int ora)
{
	if (ora >= 0 && ora <= 23)
		this->ora = ora;
	else
		this->ora = -1;
}



void Eveniment::setmin(int min)
{
	if (min >= 0 && min <= 59)
		this->min = min;
	else
		this->min = -1;
}
void Eveniment::setzi(int zi)
{
	if (zi >= 1 && zi <= 31)
		this->zi = zi;
	else
		this->zi = -1;
}


void Eveniment::setluna(int luna)
{
	if (luna >= 1 && luna <= 12)
		this->luna = luna;
	else
		this->luna = -1;
}
void Eveniment::setan(int an)
{
	if (luna >= 1 && luna <= 12)
		this->luna = luna;
	else
		this->luna = -1;
}

void Eveniment::setlocuriOcupate(int locuriOcupate)
{
	this->locuriOcupate = locuriOcupate;
}



ostream& operator<<(ostream& out, Eveniment sursa)
{
	out << "ID-ul evenimentului este: " << sursa.idEveniment<<endl;
	out << "Tipul evenimentului este: " << sursa.tipEveniment<<endl;
	out << "Numele evenimentului este: " << sursa.numeEveniment<<endl;
	out << "Data evenimentului este: " << sursa.zi << "." << sursa.luna << "." << sursa.an << endl;
	out << "Ora la care are loc evenimentul este: " << sursa.ora << ":" << sursa.min;
	out << "Evenimentul are " << sursa.locuriOcupate << " locuri ocupate deja";

	return out;
}


istream& operator>>(istream& in, Eveniment& sursa)
{
	cout << "Introduceti tipul evenimentului" << endl;
	cout << "adica daca e film, teatru, fotbal, etc" << endl;
	if (strlen(sursa.tipEveniment) > 2)
		in >> sursa.tipEveniment;
	else
		throw "Ati introdus un tip invalid :(";
	//
	cout << "Cum se numeste evenimentul" << endl;
	cout << "ex:'UK vs Franta', 'Thor-razbunarea zeilor'"<<endl;
	if (sursa.numeEveniment.length() > 2)
		in >> sursa.numeEveniment;
	else
		throw "Ati introdus un eveniment care nu exista :(";
	//
	cout << "Introduceti ziua in care are loc evenimentul" << endl;
	if (sursa.zi >= 0 && sursa.zi <= 23)
		in>>sursa.zi;
	else
		sursa.zi = -1;
	//
	cout << "Introduceti luna in care are loc evenimentul" << endl;
	if (sursa.luna >= 1 && sursa.luna <= 31)
		in >> sursa.luna;
	else
		sursa.luna = -1;
	//
	cout << "Introduceti anul in care are loc evenimentul" << endl;
	if (sursa.an >= 2022 && sursa.an <= 2025)
		in>>sursa.an;
	else
		sursa.an = -1;
	//
	cout << "Introduceti ora in care are loc evenimentul" << endl;
	if (sursa.ora >= 0 && sursa.ora <= 23)
		in>>sursa.ora;
	else
		sursa.ora = -1;
	//
	cout << "Introduceti minutul in care are loc evenimentul" << endl;
	if (sursa.min >= 0 && sursa.min <= 59)
		in>>sursa.min;
	else
		sursa.min = -1;
	cout << "Introduceti cate locuri sunt ocupate" << endl;
	cout << "Daca nu stiti introduceti -1" << endl;
	if (sursa.locuriOcupate >= 0)
		in >> sursa.locuriOcupate;
	else
		sursa.locuriOcupate = -1;

	return in;
}


//OPERATOR ++ PRE
Eveniment& Eveniment::operator++()
{
	this->locuriOcupate++;
	return *this; 
}


//OPERATOR ++ POST
Eveniment Eveniment:: operator++(int)
{
	Eveniment copie = *this;
	this->locuriOcupate++;
	return copie;
}


Eveniment Eveniment::operator* (int inmultire)
{
	Eveniment copie = *this;
	copie.locuriOcupate *= inmultire;
	return copie;
}

bool Eveniment::validareOra(int ora, int min)
{
	bool valid = true;
	if (ora < 0 || ora>23)
		valid = false;
	if (min < 0 || min>59)
		valid = false;
	return valid;
}


bool Eveniment::validareData(int zi, int luna, int an)
{
	bool valid = true;
	if (zi < 1 || zi>31)
		valid = false;
	if (luna < 1 || luna>12)
		valid = false;
	if (an < 2022 || an>2025)
		valid = false;

	return valid;
}

void Eveniment::verificareNrLocuri(int locuriOcupate, int nrTotal)
{
	nrTotal = locatie.getnrTotalLocuri();
	if (locuriOcupate < nrTotal)
		cout << "Locatia inca are locuri disponibile!" << endl;
	else if (locuriOcupate == nrTotal)
		cout << "Biletele s-au epuizat!" << endl;
	else if (locuriOcupate > nrTotal)
		cout << "Atentie! S-au vandut mai multe bilete decat este posibil!" << endl;

}