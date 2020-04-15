#include <iostream>
#include <vector>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct uczen
{
        string imie, nazwisko;
        int numer;
};

class klasa
{
                vector <struct uczen> spis;

        public:
                void wprowadz();
                void wypisz();
                void zapiszDoPliku(const char *);
                void wczytajZPliku(const char *);
};

void klasa::wprowadz()
{
        int iloscUczniow;
        struct uczen wprowadzany;
        cout << "Ilosc uczniow: ";
        cin  >> iloscUczniow;
        for (int i=0; i<iloscUczniow; i++)
        {
                cout << "Nr Imie Nazwisko: ";
                cin >> wprowadzany.numer
                        >> wprowadzany.imie
                        >> wprowadzany.nazwisko;
                spis.push_back(wprowadzany); //TU WSTAW do tablicy nowy rekord
        }
}


void klasa::wypisz()
{
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                cout << it->numer << " "
                         << it->imie << " "
                         << it->nazwisko << "\n";
        }
}



void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it) // iterator to zmienna która przebiega ca³¹ tablicê
        {
                plik << it->numer << " "
                         << it->imie << " "
                         << it->nazwisko << "\n";
        }
        plik.close();
}

void klasa::wczytajZPliku(const char *nazwa)
{
		ifstream plik2;
		string napis, imie, nazwisko;
		int numer;
		plik2.open("c:\\nazwa.txt", ios::in);
		if(plik2.good())
			while(!plik2.eof())
			{
				plik2>>imie;
				plik2>>nazwisko;
				plik2>>numer;
				cout<<napis;
				cout<<endl;
			}
			plik2.close();
}



int main(int argc, char** argv) {
        klasa TI;
        TI.wprowadz();
        TI.wypisz();
        TI.zapiszDoPliku("c:\\a.txt");
	TI.wczytajZPliku("c:\\nazwa.txt");
        return 0;
}
