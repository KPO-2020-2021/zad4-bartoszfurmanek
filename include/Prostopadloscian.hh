#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Wektor3D.hh"
#include "Wektor.hh"
#include "Macierz3x3.hh"
#include "Macierz.hh"
#include <tgmath.h>
#include <math.h>
#include <iomanip>



/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostopadloscian {
  
  Wektor3D Wierzcholek[8];

  public:

  Wektor3D operator[](int Indeks)const;

  Wektor3D& operator[](int Indeks);

  Prostopadloscian();

  Prostopadloscian(const std::initializer_list<Wektor3D> &ListaElem);

  bool operator ==(Prostopadloscian Pr)const;

  Prostopadloscian& Obrot(double Kat, char Os);

  Prostopadloscian& Translacja(Wektor3D Wektor);

  void PorownajBoki()const;

  friend std::ostream& operator << (std::ostream &Strm, const Prostopadloscian &Pr);
};

std::ostream& operator << (std::ostream &Strm, const Prostopadloscian &Pr);



#endif
