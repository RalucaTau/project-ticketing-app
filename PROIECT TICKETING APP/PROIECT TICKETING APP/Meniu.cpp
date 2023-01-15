#include "Meniu.h"

Meniu::Meniu()
{

}

Meniu::~Meniu()
{

}


void Meniu::getBileteFisier()
{
	int idBilet;
	string filename = "bilete.txt";
	fstream fisier;
	fisier.open(filename.c_str(), ios::in);
	if (!fisier.is_open())
	{
		cout << "Eroare. Nu am putut deschide fisierul bilete.txt!";
	}
	else
	{
		while (!fisier.eof())
		{
			fisier >> idBilet;
			bilete.push_back(idBilet);
		}
	}
}

void Meniu::afisareBilete()
{
	getBileteFisier();
	cout << "ID-urile biletelor disponibile:" << endl;
	for (int i = 0; i < bilete.size(); i++)
		cout << i+1 << ":" << bilete[i] << endl;
}

void Meniu::afisareClient()
{
	system("cls");
	cout << "Selectati optiunea dorita:" << endl;
	cout << "1. Cumpara bilet" << endl;
	cout << "2. Afiseaza bilete curente" << endl;
	cout << "3. Afiseaza evenimente curente" << endl;
	cout << "4. Afiseaza locatii curente" << endl;
	cout << "5. Valideaza bilet" << endl;
	cout << "6. Du-ma inapoi!" << endl;
	cin >> selectieClient;

	switch (selectieClient)
	{
	case 1:
		cumparaBilet();
		break;
	case 2:
		afisareBilete();
		break;
	case 3:
		afisareEvenimente();
		break;
	case 4:
		afisareLocatii();
		break;
	case 5:
		validareBilet();
		break;
	case 6:
		afisare();
		break;
	}
}

void Meniu::afisareAdmin()
{
	system("cls");
	cout << "Selectati optiunea dorita: " << endl;
	cout << "1. Generare eveniment nou" << endl;
	cout << "2. Generare locatie noua" << endl;
	cout << "3. Du-ma inapoi!" << endl;
	cin >> selectieAdmin;
	
	switch (selectieAdmin)
	{
	case 1:
		generareEvenimentNou();
		break;
	case 2:
		generareLocatieNoua();
		break;
	case 3:
		afisare();
		break;
	}
}

void Meniu::validareAdmin()
{
	int ok = 0;
	system("cls");
	string parolaAdmin;
	while (ok == 0)
	{
		cout << "Introduceti parola: ";
		cin >> parolaAdmin;
		if (parolaAdmin == parolaCorectaAdmin)
		{
			ok = 1;
			afisareAdmin();
		}
		else
			cout << "Parola invalida" << endl;
	}	
}

void Meniu::afisare()
{
	system("cls");
	cout << "Selectati optiunea dorita: " << endl;
	cout << "1. Administrator." << endl;
	cout << "2. Client" << endl;
	cin >> selectieUser;

	switch(selectieUser)
	{
	case 1: 
		validareAdmin();
		break;
	case 2:
		afisareClient();
		break;
	default:
		cout << "Invalid. Introduceti 1 sau 2.";
	}

}

void Meniu::argumentFisier(string filename) // Puteti rula fisier sau fisier2 pentru testing.
{
	int idBil, rand, loc, idLocatie, idEvent; 
	string numeParticipant, numeLocatie, categorie, numeEvent;
	fstream fisier;
	fisier.open(filename, ios::in);
	if (!fisier.is_open())
		cout << "eroare. Nu am putut deschide fisierul";
	else
	{
		fisier >> idBil;
		fisier >> numeParticipant;
			
		fisier >> idLocatie;
		fisier >> numeLocatie;

		fisier >> categorie;
		fisier >> rand;
		fisier >> loc;

		fisier >> idEvent;
		fisier >> numeEvent;

		cout << "ID-ul biletului: " << idBil << ", pe numele: " << numeParticipant << endl;
		cout << "ID-ul locatiei: " << idLocatie << ", " << numeLocatie << endl;
		cout << "Categoria " << categorie << ", rand " << rand << " loc " << loc << endl;
		cout << "ID-ul evenimentului: " << idEvent << ", " << numeEvent;
	}
}

void Meniu::getLocatiiFisier()
{
	int idLocatie;
	string filename = "locatii.txt";
	fstream fisier;
	fisier.open(filename.c_str(), ios::in);
	if (!fisier.is_open())
		cout << "Eroare. Nu am putut deschide fisierul locatii.txt";
	else
	{
		while (!fisier.eof())
		{
			fisier >> idLocatie;
			locatii.push_back(idLocatie);
		}
	}
}

void Meniu::validareBilet()
{
	bool ok = 0;
	int idBiletFisier;
	afisareBilete();
	cout << endl;
	int idEvent, rand, loc;
	cout << "Introduceti ID evenimentului ";
	cin >> idEvent;
	cout << "Introduceti rand ";
	cin >> rand;
	cout << "Introduceti loc ";
	cin >> loc;
	int idBilet = bilet.fabricaID(idEvent, rand, loc);
	fstream file;
	string filename = "bilete.txt";
	cout << idBilet;
	file.open(filename, ios::in);
	if (!file.is_open())
		cout << "Nu am putut deschide bilete.txt";
	else
	{
		while (!file.eof())
		{
			file >> idBiletFisier;
			idBilete.push_back(idBiletFisier);
		}
	}
	for (int i = 0; i < idBilete.size(); i++)
		if (idBilet == idBilete[i])
			ok = 1;
	if (ok == 1)
		cout << " - Bilet valid!" << endl;
	else
		cout << " - Bilet invalid" << endl;

}


bool Meniu::verificaBilet(int idEvent, int rand, int loc)
{
	bool ok = 1;
	int idev, r, l;
	fstream file;
	file.open("bilete.txt", ios::in);
	if (!file.is_open())
		cout << "Nu am putut deschide bilete.txt";
	else
	{
		while (!file.eof())
		{
			file >> idev;
			file >> r;
			file >> l;

			if (r == rand && l == loc && idev == idEvent)
				ok = 0;
		}
		
	}
	return ok;
}

void Meniu::cumparaBilet()
{
	int idEvent, rand, loc;
	cout << "Introduceti id-ul evenimentului: ";
	cin >> idEvent;
	cout << "Introudceti randul: ";
	cin >> rand;
	cout << "Introduceti locul: ";
	cin >> loc;
	if (!verificaBilet(idEvent, rand, loc))
		cout << "Locul este deja ocupat";
	else
	{
		fstream fisier;
		string filename = "locuri_ocupate.txt";
		fisier.open(filename, ios::out | ios::app);
		fisier << idEvent << " " << rand << " " << loc;

		int idBilet = bilet.fabricaID(idEvent, rand, loc);
		string numeParticipant, numeEvent, categorie;
		cout << "Introduceti numele participantului ";
		cin >> numeParticipant;

		cout << "Introduceti numele evenimentului ";
		cin >> numeEvent;

		cout << "Introduceti categoria ";
		cin >> categorie;

		bilet.scriereBiletFisier(idBilet, idEvent, rand, loc, numeParticipant, numeEvent, categorie);

		cout << "idBilet " << idBilet << " idEvent " << idEvent << " rand " << rand << " loc " << loc << endl << " numeParticipant " << numeParticipant;
		cout << " numeEvent " << numeEvent << " categorie " << categorie;

		fstream fisier3;
		fisier3.open("bilete.txt", ios::out);
		fisier3 << idBilet << endl;
	}

}

void Meniu::generareLocatieNoua()
{
	int idLocatie;
	cout << "Introduceti ID-ul locatiei ";
	cin >> idLocatie;
	string filename = "locatii.txt";
	fstream fisier1, fisier2;
	fisier1.open(filename, ios::out | ios::app);
	if (!fisier1.is_open())
		cout << "Eroare la deschiderea fisierului locatii.txt";
	else
		fisier1 << idLocatie << endl;
	
	int nrTotalLocuri, nrRanduri;
	string numeLocatie;
	
	cout << "Introduceti numele locatiei ";
	cin.get();
	getline(cin, numeLocatie);

	cout << "Introduceti numarul total de locuri ";
	cin >> nrTotalLocuri;

	cout << "Introduceti numarul de randuri ";
	cin >> nrRanduri;

	string filename2 = "Locatii\\" + to_string(idLocatie) + ".txt";
	fisier2.open(filename2, ios::out);
	if (!fisier2.is_open())
		cout << "Eroare la deschiderea fisierului " << filename2 << endl;
	else
		fisier2 << idLocatie << endl << numeLocatie << endl << nrTotalLocuri << endl << nrRanduri;
}

void Meniu::afisareLocatii()
{
	getLocatiiFisier();
	cout << "ID-uri locatii curente:" << endl;
	for (int i = 0; i < locatii.size(); i++)
		cout <<  i+1 << " " << locatii[i] << endl;
	
	//Nu merge sa citeasca numele :(
	/*int choice;
	cin >> choice;
	fstream fisier;
	string filename = "Locatii\\" + to_string(locatii[choice - 1]) + ".txt";
	int idLocatie=0, nrTotalLocuri=0, nrRanduri=0;
	string numeLocatie;

	fisier.open(filename, ios::in);
	if (!fisier.is_open())
		cout << "Eroare la deschiderea fisierului" << filename;
	else
	{
		fisier >> idLocatie;
		fisier >> noskipws >> numeLocatie;
		fisier >> nrTotalLocuri >> nrRanduri;
	}
		

	cout << "ID locatie " << idLocatie << endl;
	cout << "Nume locatie " << numeLocatie << endl;
	cout << "Numar total locuri" << nrTotalLocuri << endl;
	cout << "Numar randuri" << nrRanduri << endl;*/

}

void Meniu::generareEvenimentNou()
{
	int idEveniment;
	string tipEveniment;
	string numeEveniment;
	int ora, min, zi, luna, an;
	int locuriOcupate;

	fstream file1, file2;
	string filename = "evenimente.txt";
	

	cout << "Introduceti ID-ul evenimentului ";
	cin >> idEveniment;

	string filename2 = "Evenimente\\" + to_string(idEveniment) + ".txt";

	file1.open(filename, ios::out | ios::app);
	if (!file1.is_open())
		cout << "Eroare la deschiderea fisierului evenimente.txt";
	else
		file1 << idEveniment << endl;

	cout << "Introduceti tipul evenimentului "; 
	cin >> tipEveniment;

	cout << "Introduceti numele evenimentului ";
	cin >> numeEveniment;

	cout << "Introduceti ora ";
	cin >> ora;

	cout << "Introduceti minutul ";
	cin >> min;

	cout << "Introduceti data (zi) ";
	cin >> zi;

	cout << "Introduceti data (luna) ";
	cin >> luna;

	cout << "Introduceti data (anul) ";
	cin >> an;

	cout << "Introduceti numarul de locuri ocupate ";
	cin >> locuriOcupate;

	file2.open(filename2, ios::out);
	if (!file2.is_open())
		cout << "Eroare la deschiderea fisierului" << filename2;
	else
	{
		file2 << idEveniment << " " << numeEveniment << " " << tipEveniment << " " << zi << " " << luna << " " << an;
		file2 << " " << ora << " " << min << " " << locuriOcupate;
	}
}

void Meniu::getEvenimenteFisier()
{
	int idEvent;
	string filename = "evenimente.txt";
	fstream fisier;
	fisier.open(filename, ios::in);
	if (!fisier.is_open())
		cout << "Eroare. Nu am putut deschide fisierul evenimente.txt!";
	else
	{
		while (!fisier.eof())
		{
			fisier >> idEvent;
			evenimente.push_back(idEvent);
		}
	}
}

void Meniu::afisareEvenimente()
{
	getEvenimenteFisier();
	cout << "ID-urile evenimentelor disponibile:" << endl;
	for (int i = 0; i < evenimente.size(); i++)
		cout << i+1 << ":" << evenimente[i] << endl;
	int choice;
	cin >> choice;
	fstream fisier;
	string filename = "Evenimente\\" + to_string(evenimente[choice - 1]) + ".txt";

	int idEveniment = 0;
	string tipEveniment;
	string numeEveniment;
	int ora=0, min=0, zi=0, luna=0, an=0;
	int locuriOcupate=0;
	fisier.open(filename, ios::in);
	if (!fisier.is_open())
		cout << "Eroare la deschiderea fisierului " << filename;
	else
		fisier >> idEveniment >> numeEveniment >> tipEveniment >> zi >> luna >> an >> ora >> min >> locuriOcupate;

	cout << endl;
	system("cls");
	cout << "ID eveniment " << idEveniment << endl;
	cout << "Nume eveniment " << numeEveniment << endl;
	cout << "Tip eveniment " << tipEveniment << endl;
	cout << "Data " << zi << "-" << luna << "-" << an << endl;
	cout << "Ora " << ora << ":" << min << endl;
}
