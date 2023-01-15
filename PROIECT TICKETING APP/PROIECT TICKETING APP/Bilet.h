#pragma once
#include<iostream>
#include "Eveniment.h"
using namespace std;

class Bilet
{
private:
	Locatie locatie;
	int idBilet; 
	char* numeParticipant;
	int rand;
	int loc;
	string categorie; //adc vip/normal
	bool locRezervat = false;
	int auxid[7]={0};
	

public:
	Bilet();
	Bilet( const char*, int, int, string, bool);
	Bilet(const Bilet&);
	~Bilet();
	Bilet& operator=(Bilet&);
	int getidBilet();
	int getrand();
	int getloc();
	string getcategorie();
	bool getlocRezervat();
	char* getnumeParticipant();
	void setnumeParticipant(const char*);
	void setrand(int);
	void setloc(int);
	void setcategorie(string);
	void setlocRezervat(bool);
	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
	Bilet operator-(int);
	bool operator!();
	int fabricaID(int, int, int);
	string seteazaCategorie(string, string);
	void validareBilet();
	virtual void setPret(int);
	int pret;
	void scriereBiletFisier(int, int, int, int, string, string, string);
	void citesteBiletFisier(int id);
};

class Plata : public Bilet
{
private:
	int pret;
	string metodaPlata; //cash sau card
	const string contBancar = "RO25INGB0000999811983024";
public:
	Plata(const char*, int, int, string, bool, int, string, string);
	virtual void setPret(int pret);
	void setmetodaPlata(string metodaPlata);
	int getpret();
	string getmetodaPlata();
};