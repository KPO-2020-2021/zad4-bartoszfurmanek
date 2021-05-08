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



/*!
 *\file
 *\brief Definicja klasy Prostopadloscian.
 */

/*!
 * \brief Klasa Prostopadloscian.
 *
 * Klasa reprezentucja prostopadlocian. Jego wierzcholki sa prezentowane przez
 * tablice wektorow 3D, gdzie jeden wektor to dany wierzcholek. Prostopadloscian
 * mozna przesuwac oraz obracac, a do tego wyswietlac jego wierzcholki oraz
 * porownywac jego boki.
 */
class Prostopadloscian {

/*!
 * \brief Wierzcholki
 *
 * Atrybut modeluje 8 wierzcholkow prostopadloscianu w formie
 * tablicy z wektorami 3D.
 *
 */
  Wektor3D Wierzcholek[8];

  public:

/*!
 * \brief Indeksowanie wierzcholkow prostopadloscianu.
 */
  Wektor3D operator[](int Indeks)const;

/*!
 * \brief Indeksowanie wierzcholkow prostopadloscianu.
 */
  Wektor3D& operator[](int Indeks);

/*!
 * \brief Konstruktor bezparametryczny.
 */
  Prostopadloscian();

/*!
 * \brief Konstruktor parametryczny.
 */
  Prostopadloscian(const std::initializer_list<Wektor3D> &ListaElem);

/*!
 * \brief Przeciazenie operatora porownania dla prostopadlocianu.
 */
  bool operator ==(Prostopadloscian Pr)const;

/*!
 * \brief Metoda sluzaca do opracania prostopadloscianu o zadany kat wokol wybranej osi.
 */
  Prostopadloscian& Obrot(double Kat, char Os);

/*!
 * \brief Metoda sluzaca do przesuwania prostopadlosianu o zadany wektor.
 */
  Prostopadloscian& Translacja(Wektor3D Wektor);

/*!
 * \brief Metoda sluzaca do sprawdzania dlugosci bokow prostopadloscianu.
 */
  void PorownajBoki()const;

};

/*!
 * \brief Metoda sluzaca do przekazywania do strumienia wierzcholkow prostopadlocianu.
 */
std::ostream& operator << (std::ostream &Strm, const Prostopadloscian &Pr);



#endif
