#include "Scena.hh"

#include "Macierz3x3.hh"


Scena::Scena()
{
    (*this).WzorzecPr()=Prostopadloscian({{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}});
    (*this).PoprzedniePrzesuniecie()={0,0,0};
    for(int i=0; i<ROZMIAR; i++)
        {
        (*this).PoprzedniKat(i)=0;
        (*this).PoprzedniaOs(i)='.';
        }
}

Scena::Scena(Prostopadloscian P)
{
    (*this).WzorzecPr()=P;
    (*this).PoprzedniePrzesuniecie()={0,0,0};
    for(int i=0; i<ROZMIAR; i++)
        {
        (*this).PoprzedniKat(i)=0;
        (*this).PoprzedniaOs(i)='.';
        }
}

void Scena::ZapiszPrzesuniecie(Wektor3D Przesuniecie)
{
    (*this).PoprzedniePrzesuniecie()= Przesuniecie;
}

void Scena::WyzerujPrzesuniecie()
{
    (*this).PoprzedniePrzesuniecie()= {0,0,0};
}

void Scena::ZapiszObrot(double Kat, char Os, int Indeks)
{
    (*this).PoprzedniKat(Indeks)=Kat;
    (*this).PoprzedniaOs(Indeks)=Os;
}

void Scena::WyczyscObroty()
{
    for(int i=0; i<ROZMIAR; i++)
        {
        (*this).PoprzedniKat(i)=0;
        (*this).PoprzedniaOs(i)='.';
        }
}


void Scena::WykonajObrot(int Indeks)
{
    (*this).WzorzecPr().Obrot((*this).PoprzedniKat(Indeks), (*this).PoprzedniaOs(Indeks));
}

void Scena::WykonajPrzesuniecie()
{
    (*this).WzorzecPr().Translacja((*this).PoprzedniePrzesuniecie());
}