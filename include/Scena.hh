#ifndef SCENA_HH
#define SCENA_HH

#include "Prostopadloscian.hh"
#include "Macierz3x3.hh"
#include "Macierz.hh"
#include "Wektor3D.hh"
#include "Wektor.hh"

#define ROZMIAR 10

class Scena {

  Prostopadloscian Pr;              //Prostokat wzorcowy
  Wektor3D PoprzPrzesuniecie;       //Poprzednie przesuniecie
  double  PoprzKat[ROZMIAR];        //Poprzednia sekwencja obrotow (katy)
  char    PoprzOs[ROZMIAR];         //Poprzednia sekwencja obrotow (osie)

  public:

  Prostopadloscian WzorzecPr()const
  {return this->Pr;}

  Prostopadloscian&  WzorzecPr()
  {return this->Pr;}

  Wektor3D PoprzedniePrzesuniecie()const
  {return this->PoprzPrzesuniecie;}

  Wektor3D&  PoprzedniePrzesuniecie()
  {return this->PoprzPrzesuniecie;}

  double PoprzedniKat(int Indeks)const
  {if(Indeks>=ROZMIAR){throw std::runtime_error("Blad: Zly indeks");}
  return this->PoprzKat[Indeks];}

  double&  PoprzedniKat(int Indeks)
  {if(Indeks>=ROZMIAR){throw std::runtime_error("Blad: Zly indeks");}
  return this->PoprzKat[Indeks];}

  char PoprzedniaOs(int Indeks)const
  {if(Indeks>=ROZMIAR){throw std::runtime_error("Blad: Zly indeks");}
  return this->PoprzOs[Indeks];}

  char&  PoprzedniaOs(int Indeks)
  {if(Indeks>=ROZMIAR){throw std::runtime_error("Blad: Zly indeks");}
  return this->PoprzOs[Indeks];}


  Scena();

  Scena(Prostopadloscian P);

  void ZapiszPrzesuniecie(Wektor3D Przesuniecie);

  void WyzerujPrzesuniecie();

  void ZapiszObrot(double Kat, char Os, int Indeks);

  void WyczyscObroty();

  void WykonajObrot(int Indeks);

  void WykonajPrzesuniecie();

};






















#endif