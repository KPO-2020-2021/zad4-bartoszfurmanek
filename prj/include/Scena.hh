#ifndef SCENA_HH
#define SCENA_HH

#include "Prostopadloscian.hh"
#include "Macierz3x3.hh"
#include "Macierz.hh"
#include "Wektor3D.hh"
#include "Wektor.hh"

#define ROZMIAR 10


/*!
 *\file
 *\brief Definicja klasy Scena.
 */

/*!
 * \brief Klasa Scena.
 *
 * Klasa reprezentuje scene. Klasa ma za zadanie zapamietywanie prostopadloscianu jako
 * prostopadloscian wzorcowy, oraz jego poprzedniego przesuniecia i jego poprzednich obrotow.
 * Odpowiednie metody pozwalaja na zapisywanie i usuwanie informacji o poprzednich przesunieciach
 * i obrotach oraz pozwalaja na wykonywanie ich na prostopadlosciaie wzorcowym.
 */
class Scena {

/*!
 * \brief Prostopadlocian wzorcowy.
 *
 * Atrybut modeluje kopie danego prostopadloscianu. Jest o zmienna klasy Prostopadloscian.
 * Podstawowa wartoscia tego atrybutu jest Prostopadloscian o wierzcholkach skladajacych 
 * sie z wektorow [0,0,0]
 */
  Prostopadloscian Pr;

/*!
 * \brief Poprzednie Przesuniecie.
 *
 * Atrybut sluzy do pamietania poprzedniego przesuniecia danego prostopadloscianu.
 * Jest on zmienna klasy Wektor3D. Podstawowa wartoscia tego atrybutu jest wektor
 * [0,0,0]
 */            
  Wektor3D PoprzPrzesuniecie;

/*!
 * \brief Poprzednie Katy obrotu
 *
 * Atrybut sluzy do pamietania sekwencji poprzednich kat obrotow prostopadloscianu.
 * Ilosc zapamietywanych katow zalezy od stalej ROZMIAR. Podstawowa wartoscia tego
 * atrybuty jest tablica zawierajaca wartosci 0.
 */
  double  PoprzKat[ROZMIAR];

/*!
 * \brief Poprzednie Osie obrotu
 *
 * Atrybut sluzy do pamietania sekwencji poprzednich osi obrotow prostopadloscianu.
 * Ilosc zapamietywanych osi zalezy od stalej ROZMIAR. Podstawowa wartoscia tego
 * atrybuty jest tablica zawierajaca znaki '.' .
 */
  char    PoprzOs[ROZMIAR];         

  public:

/*!
 * \brief Metoda służąca do uzyskiwania prostopadloscianu wzorcowego.
 * Zwraca:
 *   \retval Prostopadloscian wzorcowy.
 */
  Prostopadloscian WzorzecPr()const
  {return this->Pr;}

/*!
 * \brief Metoda służąca do uzyskiwania prostopadloscianu wzorcowego.
 * Zwraca:
 *   \retval Referencja do prostopadlocianu wzorcowego.
 */
  Prostopadloscian&  WzorzecPr()
  {return this->Pr;}

/*!
 * \brief Metoda służąca do uzyskiwania poprzedniego przesuniecia.
 * Zwraca:
 *   \retval Poprzednie przesuniecie.
 */
  Wektor3D PoprzedniePrzesuniecie()const
  {return this->PoprzPrzesuniecie;}

/*!
 * \brief Metoda służąca do uzyskiwania poprzedniego przesuniecia.
 * Zwraca:
 *   \retval Referencja do poprzedniego przesuniecia.
 */
  Wektor3D&  PoprzedniePrzesuniecie()
  {return this->PoprzPrzesuniecie;}

/*!
 * \brief Metoda służąca do uzyskiwania poprzedniego katu obrotu.
 * Argumenty:
 *  \param[in] Indeks - Indeks rzadnego katu obrotu.
 * Zwraca:
 *   \retval Poprzedni kat obrotu.
 */
  double PoprzedniKat(int Indeks)const
  {if(Indeks>=ROZMIAR){throw std::runtime_error("Blad: Zly indeks");}
  return this->PoprzKat[Indeks];}

/*!
 * \brief Metoda służąca do uzyskiwania poprzedniego katu obrotu.
 * Argumenty:
 *  \param[in] Indeks - Indeks rzadnego katu obrotu.
 * Zwraca:
 *   \retval Referencja do poprzedniego katu obrotu.
 */
  double&  PoprzedniKat(int Indeks)
  {if(Indeks>=ROZMIAR){throw std::runtime_error("Blad: Zly indeks");}
  return this->PoprzKat[Indeks];}

/*!
 * \brief Metoda służąca do uzyskiwania poprzedniej osi obrotu.
 * Argumenty:
 *  \param[in] Indeks - Indeks rzadnej osi obrotu.
 * Zwraca:
 *   \retval Poprzednia os obortu.
 */
  char PoprzedniaOs(int Indeks)const
  {if(Indeks>=ROZMIAR){throw std::runtime_error("Blad: Zly indeks");}
  return this->PoprzOs[Indeks];}

/*!
 * \brief Metoda służąca do uzyskiwania poprzedniej osi obrotu.
 * Argumenty:
 *  \param[in] Indeks - Indeks rzadnej osi obrotu.
 * Zwraca:
 *   \retval Referencja do poprzedniej osi obrotu.
 */
  char&  PoprzedniaOs(int Indeks)
  {if(Indeks>=ROZMIAR){throw std::runtime_error("Blad: Zly indeks");}
  return this->PoprzOs[Indeks];}

/*!
 * \brief Konstruktor bezparametryczny.
 */
  Scena();

/*!
 * \brief Konstruktor parametryczny.
 */
  Scena(Prostopadloscian P);

/*!
 * \brief Metoda sluzaca do zapamietywania poprzedniego przesuniecia.
 */
  void ZapiszPrzesuniecie(Wektor3D Przesuniecie);

/*!
 * \brief Metoda sluzaca do zerowania poprzedniego przesuniecia.
 */
  void WyzerujPrzesuniecie();

/*!
 * \brief Metoda sluzaca do zapisania danego obrotu na pozycje o zadanym indeksie.
 */
  void ZapiszObrot(double Kat, char Os, int Indeks);

/*!
 * \brief Metoda sluzaca do usuwania wczesniej zapamietanych obrotow
 */
  void WyczyscObroty();

/*!
 * \brief Metoda sluzaca do obrocania prostopadlocianu wzorcowego wg. obrotu zapamietanego
 * na pozycji o zadanym indeksie.
 */
  void WykonajObrot(int Indeks);

/*!
 * \brief Metoda sluzaca do przesuniecia prostopadlocianu wzorcowego o poprzednio zapisany wektor przesuniecia.
 */
  void WykonajPrzesuniecie();

};






















#endif