#pragma once
#include<iostream>
#include<string>
#include "Locatie.h"
#include<fstream>
using namespace std;

class Eveniment
{
private:
	Locatie locatie;
	const int idEveniment;
	char* tipEveniment; // gen: Film, Teatru, Meci, whatever
	string numeEveniment; //gen Thor, Franta vs Anglia, Lacul Lebedelor
	int ora,min;
	int zi, luna, an; 
	int locuriOcupate; // locurile dispovibile vor fi nrMaxLocuri-locuriOcupate
	
	

public:
	void scriereFisier(ofstream&);
	void citireFisier(ifstream&);
	Eveniment();
	Eveniment(const char*, string, int, int, int, int, int, int,const int);
	Eveniment(const Eveniment&);
	~Eveniment();
	Eveniment& operator=(const Eveniment&);
	int getidEveniment();
	char* gettipEveniment();
	string getnumeEveniment();
	int getora();
	int getmin();
	int getzi();
	int getluna();
	int getan();
	int getlocuriOcupate();
	void settipEveniment(const char*);
	void setnumeEveniment(string);
	void setora(int);
	void setmin(int min);
	void setzi(int zi);
	void setluna(int luna);
	void setan(int an);
	void setlocuriOcupate(int locuriOcupate);
	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream& in, Eveniment& sursa);
	Eveniment& operator++();
	Eveniment operator++(int);
	Eveniment operator* (int);
	bool validareOra(int, int);
	bool validareData(int, int, int);
	void verificareNrLocuri(int, int);

};