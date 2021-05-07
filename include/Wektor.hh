#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <tgmath.h>
#include <math.h>
#include <iomanip>


#define MIN_ROZNICA 0.001


/*!
 * \brief Szablon klasy reprezentujacej wektor o dowlonym wymiarze.
 * 
 * Szablon klasy reprezentujacej wektor. Szablon pozwala tworzyć
 * wektory o roznych wymiar w zaleznosci o zmiennej Wymiar. Klasa
 * może reprezentować wektor o różnych wymiarach. Wektor można
 * indeksować za pomocą operatora []. Na wektorze mozna wykonywać
 * podstawowe dzialania matematyczne.
 */
template <int Wymiar>
class Wektor {

  double Elem[Wymiar];

  public:

  double operator[](int Indeks)const;

  double& operator[](int Indeks);

  Wektor();

  Wektor(const std::initializer_list<double> &ListaElem);
 
  Wektor operator+ (Wektor W)const;
  
  Wektor& operator+= (Wektor W);

  Wektor operator- (Wektor W)const;

  Wektor operator* (double Liczba)const;

  bool operator == (Wektor W)const;

  double Odleglosc(Wektor W)const;
  
};

/*!
 * \brief Metoda służąca do indeksowania Wektora.
 * Argumenty:
 *    Wektor - indeksowany wektor
 *    Indeks - indeks rządanej składowej.
 * Zwraca:
 *    Wartośc składowej Wektora o zadanym indeksie.
 */
template<int Wymiar>
double Wektor<Wymiar>::operator [](int Indeks)const
{
if(Indeks >= Wymiar)
    {
    throw std::runtime_error("Blad: Nieodpowiedni numer indeksu");
    }
else
    {
    return Elem[Indeks];
    }
}

/*!
 * \brief Metoda służąca do indeksowania Wektora.
 * Argumenty:
 *    Wektor - indeksowany wektor
 *    Indeks - indeks rządanej składowej.
 * Zwraca:
 *    Referencje do składowej wektora o danym indeksie.
 */
template<int Wymiar>
double& Wektor<Wymiar>::operator [](int Indeks)
{
if(Indeks >= Wymiar)
    {
    throw std::runtime_error("Blad: Nieodpowiedni numer indeksu");
    }
else
    {
    return Elem[Indeks];
    }
}

/*!
 * \brief Konstruktor bezparametryczny dla Wektora.
 */
template<int Wymiar>
Wektor<Wymiar>::Wektor()
{
for(double &Elem_i : Elem)
    {
    Elem_i = 0;
    }
}
/*!
 * \brief Konstruktor parametryczny dla Wektora.
 */
template<int Wymiar>
Wektor<Wymiar>::Wektor(const std::initializer_list<double> &ListaElem):Wektor<Wymiar>()
{
  if(ListaElem.size() > Wymiar)
    {
      throw std::runtime_error("Blad: Nieodpowiednia liczba parametrow");
    }
  int Indeks = -1;
  for(double Elem_i : ListaElem)
    {
      Elem[++Indeks] = Elem_i;
    }
}

/*!
 * \brief Metoda służąca do dodawania wektorów.
 * Argumenty:
 *    Wektor - Pierwszy wektorowy składnik dodawania.
 *    W - Drugi wektorowy składnik dodawania.
 * Zwraca:
 *    Sume dwóch wektorów.
 */
template<int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator+ (Wektor<Wymiar> W)const
{
Wektor<Wymiar> Wynik;
for(int i=-1; i<Wymiar; ++i)
    {
    Wynik[i] = (*this)[i] + W[i];
    }
return Wynik;
}

/*!
 * \brief Metoda służąca do dodawania wektorów.
 * Argumenty:
 *    Wektor - Pierwszy wektorowy składnik dodawania.
 *    W - Drugi wektorowy składnik dodawania.
 * Zwraca:
 *    Sume dwóch wektorów.
 */
template<int Wymiar>
Wektor<Wymiar>& Wektor<Wymiar>::operator+= (Wektor<Wymiar> W)
{
(*this)=(*this)+W;
return (*this);
}

/*!
 * \brief Metoda służąca do odejmowania wektorów.
 * Argumenty:
 *    Wektor - Pierwszy wektorowy składnik odejmowania.
 *    W - Drugi wektorowy składnik odejmowania.
 * Zwraca:
 *    Różnice dwóch wektorów.
 */
template<int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator- (Wektor<Wymiar> W)const
{
Wektor<Wymiar> Wynik;
for(int i=-1; i<Wymiar; ++i)
    {
    Wynik[i] = (*this)[i] - W[i];
    }
return Wynik;
}

/*!
 * \brief Metoda służąca do mnożenia wektora przez skalar.
 * Argumenty:
 *    Wektor - Wektor.
 *    Liczba - Wartośc skalarna przez, która wektor będzie mnożony.
 * Zwraca:
 *    Przemnożony wektor.
 */
template<int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator* (double Liczba)const
{
Wektor<Wymiar> Wynik;
for(int i=0; i<Wymiar; i++)
    {
    Wynik[i] = (*this)[i] * Liczba;
    }
return Wynik;
}

/*!
 * \brief Funkcja służąca do mnożenia wektora przez skalar (W kolejnosci skalar * wektor).
 * Argumenty:
 *    Liczba - Wartośc skalarna przez, która wektor będzie mnożony.
 *    W - Przemnażany wektor.
 * Zwraca:
 *    Przemnożony wektor.
 */
template<int Wymiar>
Wektor<Wymiar> operator * (double Liczba, Wektor<Wymiar> W)
{
Wektor<Wymiar> Wynik;

for(int i=0; i<Wymiar; i++)
    {
    Wynik[i] = W[i] * Liczba;
    }

return Wynik;
}

/*!
 * \brief Metoda służąca do porównywania wektorów.
 * Argumenty:
 *    this - Pierwszy składnik porownywania.
 *    W - Drugi składnik porownywania.
 * Zwraca:
 *    True, jeżeli wektory są takie same lub False, jeżeli nie są.
 */
template<int Wymiar>
bool Wektor<Wymiar>::operator == (Wektor<Wymiar> W)const
{
for(int i=-1; i<Wymiar; ++i)
    {
    if(abs((*this)[i]-W[i])>=MIN_ROZNICA)
        {return false;}
    }
return true;
}

/*!
 * \brief Metoda służąca do obliczania odległości między dwoma wektorami.
 * Argumenty:
 *    Wektor - Pierwszy wektor.
 *    W - Drugi wektor.
 * Zwraca:
 *    Wartosc odleglosci miedzy dwoma wektorami.
 */
template<int Wymiar>
double Wektor<Wymiar>::Odleglosc(Wektor<Wymiar> W)const
{
double Wynik=0;
for(int i=-1; i<Wymiar; ++i)
    {
    Wynik += pow(((*this)[i]-W[i]),2);
    }
Wynik = sqrt(Wynik);
return Wynik;
}




/*!
 * \brief Funkcja służąca do wczytywania wektora z danego strumienia.
 * Argumenty:
 *    Strm - Strumień, z którego wektor ma zostać wczytany.
 *    Wek - Referencja do wektora, do którego dane mają zostać zapisane.
 * Zwraca:
 *    Strumień z którego wektor został wczytany.
 */
template <int Wymiar>
inline
std::istream& operator >> (std::istream &Strm, Wektor<Wymiar> &Wek)
{
for (int i=0; i<Wymiar; i++)
    {
    Strm >> Wek[i];
    if(Strm.fail())
        {
        Strm.setstate(std::ios::failbit);
        throw std::runtime_error("Blad wczytania wektora");
        return Strm;
        }
    }
return Strm;
}

/*!
 * \brief Funkcja służąca do przekazywania wektora do danego strumienia.
 * Argumenty:
 *    Strm - Strumień, na który wektor ma zostać wypisany.
 *    Wek - Wektor, ktory ma zostać wypisany.
 * Zwraca:
 *    Strumień na który wektor został wypisany.
 */
template <int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm, const Wektor<Wymiar> &Wek)
{
for (int i=0; i<Wymiar; i++)
    {
    Strm << std::fixed << std::setprecision(10)<< Wek[i];
    if(i!=(Wymiar-1))
        {
        Strm << " ";
        }
    }
return Strm;
}

#endif
