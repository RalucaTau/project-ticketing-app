#pragma once
#include "Bilet.h"
#include <vector>
#include <iostream>
using namespace std;

class Meniu
{
private:
	void getEvenimenteFisier();
	void getBileteFisier();
	void getLocatiiFisier();

	void validareBilet();
	

	void generareEvenimentNou();
	void afisareEvenimente();
	
	
	void afisareClient();
	
	void afisareAdmin();
	void validareAdmin();


	void generareLocatieNoua();
	void afisareLocatii();


	int selectieUser=0, selectieAdmin=0, selectieClient=0, idEveniment=0;
	string parolaCorectaAdmin = "admin";
	
	vector<int> evenimente;
	vector<int> bilete;
	vector<int> locatii;
	vector<int> idOcupate, randOcupate, locOcupate;

	vector<int> idBilete;

	Bilet bilet;
public:
	Meniu();
	~Meniu();
	bool verificaBilet(int, int, int);
	void afisareBilete();
	void cumparaBilet();

	void afisare();
	void argumentFisier(string filename);
	
};