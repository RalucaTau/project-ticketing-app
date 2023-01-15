#include<iostream>
#include<string>
#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"
#define _CTR_SECURE_NO_WARNING
#pragma warning (disable: 4996)

#include "Meniu.h"

using namespace std;

int main(int argc, char *argv[]) 
{
	
	Meniu meniu;
	if (argc == 1) 
		meniu.afisare();
	else if(argc == 2)
	{
		if (argv[1] == "meniu")
			meniu.afisare();
		else
		{
			string filename = argv[1];
			meniu.argumentFisier(filename);			
		}
	}
	
	
	return 0;
}

