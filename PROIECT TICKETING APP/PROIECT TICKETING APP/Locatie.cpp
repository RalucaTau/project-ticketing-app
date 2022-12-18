#include"Locatie.h"
#define _CTR_SECURE_NO_WARNING
#pragma warning (disable: 4996)

//Locatie locatie(locatie.fabricaID())

Locatie::Locatie() :idLocatie(0)
{
	nrTotalLocuri = -1;
	nrRanduri = -1;
	zona = new char[strlen("necunoscuta") + 1];
	strcpy(zona, "necunoscuta");
	vectorLocuri = nullptr;
	for (int i = 0; i < 7; i++)
		auxid[i] = 0;
}

Locatie::Locatie(int nrTotalLocuri, int nrRanduri, int* vector, const char* zona, int idLocatie) :idLocatie(idLocatie)
{ 
	if (nrRanduri > 0)
		this->nrRanduri = nrRanduri;
	else
		this->nrRanduri = 0;
	if (strlen(zona) > 3)
	{
		this->zona = new char[strlen(zona) + 1];
		strcpy(this->zona, zona);
	}
	else
	{
		this->zona = new char[strlen("Necunoscuta") + 1];
		strcpy(this->zona, "Necunoscuta");
	}
	
	if (nrTotalLocuri > 0 && vector != NULL)
	{
		this->nrTotalLocuri = nrTotalLocuri;
		this->vectorLocuri = new int[nrTotalLocuri];
		for (int i = 0; i < nrTotalLocuri; i++)
		{
			if (vector[i] >= 0)
				this->vectorLocuri[i] = vector[i];
			else
				this->vectorLocuri[i] = 0; //adica loc neocupat
		}
	}
	else
	{
		this->nrTotalLocuri = 0;
		this->vectorLocuri = nullptr;
	}

	for (int i = 0; i < 7; i++)
		auxid[i] = 0;
}

Locatie::Locatie(const Locatie& sursa): idLocatie(sursa.idLocatie)
{
		this->nrRanduri = sursa.nrRanduri;
		this->zona = new char[strlen(sursa.zona) + 1];
		strcpy(this->zona, sursa.zona);
		this->nrTotalLocuri = sursa.nrTotalLocuri;
		this->vectorLocuri = new int[sursa.nrTotalLocuri];
		for (int i = 0; i < sursa.nrTotalLocuri; i++)
		{
			if (sursa.vectorLocuri[i] >= 0)
				this->vectorLocuri[i] = sursa.vectorLocuri[i];
			else
				this->vectorLocuri[i] = 0; //adica loc neocupat
		}
		for (int i = 0; i < 7; i++)
			auxid[i] = 0;
}

Locatie::~Locatie()
{
	delete[]this->zona;
	delete[]this->vectorLocuri;
	this->vectorLocuri = nullptr;


}

Locatie& Locatie::operator=(Locatie& sursa)
{
	delete[]this->zona;
	delete[]this->vectorLocuri;
	this->vectorLocuri = nullptr;

	this->nrRanduri = sursa.nrRanduri;
	this->zona = new char[strlen(sursa.zona) + 1];
	strcpy(this->zona, sursa.zona);
	this->nrTotalLocuri = sursa.nrTotalLocuri;
	this->vectorLocuri = new int[sursa.nrTotalLocuri];
	for (int i = 0; i < sursa.nrTotalLocuri; i++)
	{
		if (sursa.vectorLocuri[i] >= 0)
			this->vectorLocuri[i] = sursa.vectorLocuri[i];
		else
			this->vectorLocuri[i] = 0; //adica loc neocupat
	}

	return *this;
}

int Locatie::getidLocatie()
{
	return idLocatie;
}

int Locatie:: getnrTotalLocuri()
{
	return this->nrTotalLocuri;
}
int Locatie::getnrRanduri()
{
	return this->nrRanduri;
}
int* Locatie::getvectorLocuri()
{
	int* newVectorLocuri = new int[this->nrTotalLocuri];
	if (this->nrTotalLocuri >= 0 && this->vectorLocuri != nullptr)
	{
		for (int i = 0; i < this->nrTotalLocuri; i++)
		{
			newVectorLocuri[i] = vectorLocuri[i];
		}
	}
	else
	{
		return nullptr;
	}
	return newVectorLocuri;
}

string Locatie::getnumeLocatie()
{
	return numeLocatie;
}

char* Locatie::getzona() {
	if (zona != nullptr) {
		char* copie = new char[strlen(zona) + 1];
		strcpy(copie, zona);
		return copie;
	}
	return nullptr; 
}

void Locatie::setvectorLocuri(int* vectorLocuri, int nrTotalLocuri)
{
	if (nrTotalLocuri > 0 && vectorLocuri != nullptr)
	{
		this->nrTotalLocuri = nrTotalLocuri;
		this->vectorLocuri = new int[nrTotalLocuri];
		for (int i = 0; i < nrTotalLocuri; i++)
		{
			this->vectorLocuri[i] = 1;
		}
	}
	else
		throw "date eronate";
}
void Locatie::setvectorLocuriCuCateUnu(int* vectorLocuri, int nrTotalLocuri, int loc)
{
	if (nrTotalLocuri > 0 && vectorLocuri != nullptr)
	{
		this->nrTotalLocuri = nrTotalLocuri;
		this->vectorLocuri = new int[nrTotalLocuri];
		this->vectorLocuri[loc] = 1;
	}
	else
		throw "date eronate";
}

void Locatie::setnrTotalLocuri(int nrTotalLocuri)
{
	if(nrTotalLocuri > 0)
		this->nrTotalLocuri = nrTotalLocuri;
	else
		this->nrTotalLocuri = 0;
}


void Locatie::setnrRanduri(int nrRanduri)
{
	if (nrRanduri > 0)
		this->nrRanduri = nrRanduri;
	else
		nrRanduri = 0;
}


void Locatie::setzona(const char* zona)
{
	if (zona != nullptr && strlen(zona) > 2)
	{
		if (this->zona != nullptr)
			delete[] this->zona;
		this->zona = new char[strlen(zona) + 1];
		strcpy(this->zona, zona);
	}
}


void Locatie::setnumeLocatie(string numeLocatie)
{
	if (numeLocatie.length() > 3)
		this->numeLocatie = numeLocatie;
	else
		this->numeLocatie = "Necunoscut";
}

ostream& operator<<(ostream& out, Locatie sursa)
{
	out << "ID-ul locatiei este: " << sursa.idLocatie << endl;
	out << "Numarul total de locuri este: " << sursa.nrTotalLocuri << endl;
	out << "Numarul total de randuri este: " << sursa.nrRanduri<<endl;
	out << "Numele locatiei este "<<sursa.numeLocatie<<endl;
	out << "Locurile disponibile, egale cu 0, si cele ocupate, egale cu 1, sunt: " << endl;
	for (int i = 0; i < sursa.nrTotalLocuri; i++)
	{
		out << "Locul " << i + 1 << " -> " << sursa.vectorLocuri[i]<<endl;
	}
	out << "Zona aleasa este: " << sursa.zona << endl;
	return out;
}

istream& operator>>(istream& in, Locatie& sursa)
{
	/*cout << "Introduceti ID-ul locatiei " << endl;
	int id;
	in >> id;
	sursa.setnrRanduri(id);*/
	///
	cout << "Introduceti numarul total de locuri " << endl;
	if (sursa.nrTotalLocuri > 10)
		in >> sursa.nrTotalLocuri;
	else
		throw "Prea putine locuri, n-are cum! Mai incercati <3";
	///
	cout << "Introduceti numarul de randuri" << endl;	 //vip, pe langa cele normale poate sa mai aiba ori tribuna, ori loja; Normalul exista deja, asta e pt extra
	if (sursa.nrRanduri > 3)
		in >> sursa.nrRanduri;
	else
		throw "Prea putine randuri, n-are cum! Mai incercati <3" ;
	///
	cout << "Daca vreti sa introduceti manual toate locurile ocupate/neocupate, apasati tasta 1, apoi enter"<<endl;
	cout << "Daca nu, apasati tasta 0, apoi enter" << endl;
	int aux;
	in >> aux;
	if (aux == 1)
	{
		cout << "Introduceti locurile care sunt ocupate " << endl;
		for (int i = 0; i < sursa.nrTotalLocuri; i++)
		{
			cout << "Locul" << i + 1;
			in >> sursa.vectorLocuri[i];
			cout << endl;
		}
		
	}
	else
		throw "Nu se poate inca altfel, trebuia sa introduceti manual csf, #naspa" ;
	///

	cout << "Introduceti numele locatiei " << endl;
	if (sursa.numeLocatie.length() > 2)
		in >> sursa.numeLocatie;
	else
		throw "Locatia nu are suficiente caractere, mai incercati ";

	///
	cout << "Ce fel de zona extra exista la aceasta locatie?" << endl; 
	cout << "de exemplu: VIP, loja, tribuna, etc" << endl;
	in >> sursa.zona;

	return in;
}

int& Locatie::operator[] (int index)
{
	if (index >= 0 && index < this->nrTotalLocuri) 
		return this->vectorLocuri[index];
	else
		throw "eroare";
}
	

Locatie Locatie::operator+ (int marire)
{
	Locatie copie = *this;
	copie.nrTotalLocuri += marire;
	return copie;
}



int Locatie::eliberareLocuri(int* vectorLocuri, int nrTotalLocuri)
{
	for (int i = 0; i < nrTotalLocuri; i++)
	{
		vectorLocuri[i] = 0;
	}
	return* vectorLocuri;
}
//const int idLocatie;
//int nrTotalLocuri;
//int nrRanduri;
//int* vectorLocuri;
//char* zona; //aici se retine doar daca mai exista si ceva extra, nu e trecuta zona "normala"
//string numeLocatie;
//int auxid[7];

int Locatie::fabricaID()
{
	auxid[0] = this->nrTotalLocuri % 10;
	auxid[1] = this->nrRanduri % 10;
	int nr = 0;
	int copie;
	copie = nrTotalLocuri;
	while (copie != 0)
	{
		nr++;
		copie = copie / 10;
	}
	auxid[2] = nr;
	copie = nrRanduri;
	nr = 0;
	while (copie != 0)
	{
		nr++;
		copie = copie / 10;
	}
	auxid[3] = nr;
	auxid[4] = nrTotalLocuri / 10;
	auxid[5] = nrRanduri / 10;
	auxid[6] = int(zona[0]) % 10;
	int id = 0;
	for (int i = 0; i < 7; i++)
	{
		id = id * 10 + auxid[i];
	}
	return id;
}