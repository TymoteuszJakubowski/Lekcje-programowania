#include <iostream>
#include <fstream>

using namespace std;

int main()
{
   fstream liczby,wyniki;
      liczby.open("liczby.txt", ios::in);
      wyniki.open("wyniki.txt", ios::out | ios::trunc);
   
   int x[200],licznik=0;

   for (int i=0; i<200; i++)
   {
      liczby >> x[i];
      if (x[i]<1000) licznik++;
   }

   int nr_tab=198;
   while (x[nr_tab]==x[199])
   {
      nr_tab--;
      if (nr_tab<0) break;
   }

   wyniki << "Ilość iczb w pliku liczby.txt mniejszych od 1000: ";
   wyniki << licznik << endl;
   wyniki << "Dwie ostatnie liczby w pliku: ";
   wyniki << x[199] << ", ";

   if (nr_tab>0)
   {
      wyniki << x[nr_tab] << endl;//2. ostatnia
   }


   wyniki.close();
   liczby.close();
}