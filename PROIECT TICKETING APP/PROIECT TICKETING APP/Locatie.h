#pragma once
#include<iostream>
using namespace std;

class Locatie
{
private:
	const int idLocatie;
	int nrTotalLocuri; 
	int nrRanduri;
	int* vectorLocuri;
	char* zona; //aici se retine doar daca mai exista si ceva extra, nu e trecuta zona "normala"
	string numeLocatie;
	int auxid[8] = {0};
public:
	Locatie();
	Locatie(int, int, int*, const char*, int);
	Locatie(const Locatie&);
	~Locatie();
	Locatie& operator=(Locatie&);
	int getidLocatie();
	int getnrTotalLocuri();
	int getnrRanduri();
	int* getvectorLocuri(); 
	char* getzona();
	string getnumeLocatie();
	void setvectorLocuri(int*, int);
	void setvectorLocuriCuCateUnu(int*, int,int);
	void setnrTotalLocuri(int);
	void setnrRanduri(int);
	void setzona(const char*);
	void setnumeLocatie(string);
	friend ostream& operator<<(ostream&, Locatie);
	friend istream& operator>>(istream&, Locatie&);
	int& operator[] (int);
	Locatie operator+ (int);
	int eliberareLocuri(int*, int);
	int fabricaID();
};
