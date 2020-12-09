#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void sito( int a, bool * tab )
{

    for( int i = 2; i * i <= a; i++ )
    if( tab[ i ] == 0 )
    for( int b = i * i; b <= a; b += 2 )
    {
        tab[ b ] = 1;
    }

}
bool trzyczyn( int liczba, bool * tab )
{
    int druga[ 4 ] { }, i = 1, c = 0;
    do
    {

        i++;


        if( tab[ i ] == 0 )
        if( liczba % i == 0 )
        {
            liczba /= i;
            if( i % 2 == 0 )
                 return false;

            for( int y = 0; y <= 3; y++ )
            if( druga[ y ] == 0 )
            {
                druga[ y ] = i;
                c++;
                break;

            }
            i = 2;
        }
    } while( liczba != 1 );

    if( c == 3 )
         return true;
    else
         return false;

}

int main()
{

    fstream plik, plik2;
    bool * tab;
    int liczba;
    plik.open( "liczby.txt", ios::in );
    plik2.open( "wyniki_liczby.txt", ios::out );
    for( int i = 1; 1 <= 1000; i++ )
    {
        plik >> liczba;
        tab = new bool[ liczba + 1 ] { };
        sito( liczba, tab );
        if( trzyczyn( liczba, tab ) )
        {
            plik2 << liczba;
        }
        delete[] tab;

    } return 0;
}
