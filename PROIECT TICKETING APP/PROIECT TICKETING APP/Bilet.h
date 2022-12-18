#pragma once
#include<iostream>
#include "Eveniment.h"
using namespace std;

class Bilet
{
private:
	Locatie locatie;
	const int idBilet; 
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
	void setcategorie(int);
	void setlocRezervat(bool);
	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
	Bilet operator-(int);
	bool operator!();
	int fabricaID();
	string seteazaCategorie(string, string);
	void validareBilet();

};
