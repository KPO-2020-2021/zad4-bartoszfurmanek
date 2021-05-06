#ifndef MACIERZ_HH
#define MACIERZ_HH


#include "Wektor.hh"
#include <iostream>
#include <iomanip>



/*!
 * \brief  Szablon klasy reprezentujacej macierz kwadratowa o dowolnym wymiarze
 *
 * Szablon klasy reprezentujacej macierz. Ilosc kolumn oraz wierszy, a przez to
 * ilosc elementow macierzy zalezy od zmiennej Wymiar. Macierz można indeksować za
 * pomocą operatora().Na macierzy mozna wykonywa podstawowe dzialania matematyczne.
 */
template <int Wymiar>
class Macierz{

  double Elem[Wymiar][Wymiar];
  
  public:

  double operator() (int IndeksW, int IndeksK)const;

  double& operator() (int IndeksW, int IndeksK);
 
  Macierz();

  Macierz(const std::initializer_list<double[Wymiar]> &ListaElem);

  bool operator== (Macierz M)const;
 
  Macierz operator+ (Macierz M)const;

  Macierz operator- (Macierz M)const;
  
  Macierz operator* (Macierz M)const;

  Macierz operator* (double Liczba)const;

  Wektor<Wymiar> operator* (Wektor<Wymiar> W)const;

};

/*!
 * \brief Metoda służąca do indeksowania macierzy.
 * Argumenty:
 *    Macierz - Indeksowana macierz
 *    IndeksW - Indeks wiersza.
 *    IndeksK - Indeks kolumny.
 * Zwraca:
 *    Wartośc komorki macierzy o danym indeksie.
 */
template<int Wymiar>
double Macierz<Wymiar>::operator() (int IndeksW, int IndeksK)const
{
if((IndeksW >= Wymiar) || (IndeksK >= Wymiar))
    {
    throw std::runtime_error("Blad: Nieodpowiedni numer indeksu");
    }
else
    {
    return Elem[IndeksW][IndeksK];
    }
}

/*!
 * \brief Metoda służąca do indeksowania macierzy.
 * Argumenty:
 *    Macierz - Indeksowana macierz
 *    IndeksW - Indeks wiersza.
 *    IndeksK - Indeks kolumny.
 * Zwraca:
 *    Referencja do komorki macierzy o danym indeksie.
 */
template<int Wymiar>
double& Macierz<Wymiar>::operator() (int IndeksW, int IndeksK)
{
if((IndeksW >= Wymiar) || (IndeksK >= Wymiar))
    {
    throw std::runtime_error("Blad: Nieodpowiedni numer indeksu");
    }
else
    {
    return Elem[IndeksW][IndeksK];
    }
}

/*!
 * \brief Konstruktor bezparametryczny dla macierzy.
 */
template <int Wymiar>
Macierz<Wymiar>::Macierz()
{
for(int i=0; i<Wymiar; i++)
    {
    for(int j=0; j<Wymiar; j++)
        {
        Elem[i][j]=0;
        }
    }
}

/*!
 * \brief Konstruktor parametryczny dla macierzy.
 */
/*template <int Wymiar>
Macierz<Wymiar>::Macierz(const std::initializer_list<double[Wymiar]> &ListaElem):Macierz<Wymiar>()
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
}*/


/*!
 * \brief Metoda służąca do porownywania  macierzy.
 * Argumenty:
 *    Macierz - Pierwszy macierz.
 *    M - Druga macierz.
 * Zwraca:
 *    True, jeżeli macierz są takie same, w przeciwnym wypadku False.
 */
template<int Wymiar>
bool Macierz<Wymiar>::operator== (Macierz<Wymiar> M)const
{
for(int i=0; i<Wymiar; i++)
    {
    for(int j=0; j<Wymiar; j++)
        {
        if((abs((*this)(i,j)-M(i,j)))>=MIN_ROZNICA)
        {return false;}
        }
    }
return true;
}

/*!
 * \brief Metoda służąca do dodawania macierzy.
 * Argumenty:
 *    Macierz - Pierwszy macierzowy składnik dodawania.
 *    M - Drugi macierzowy składnik dodawania.
 * Zwraca:
 *    Sume dwóch macierzy.
 */
template<int Wymiar>
Macierz<Wymiar> Macierz<Wymiar>::operator+ (Macierz<Wymiar> M)const
{
Macierz<Wymiar> Wynik;
for(int i=0; i<Wymiar; i++)
    {
    for(int j=0; j<Wymiar; j++)
        {
        Wynik(i,j) = (*this)(i,j) + M(i,j);
        }
    }
return Wynik;
}

/*!
 * \brief Metoda służąca do odejmowania macierzy.
 * Argumenty:
 *    Macierz - Pierwszy macierzowy składnik odejmowania.
 *    M - Drugi macierzowy składnik odejmowania.
 * Zwraca:
 *    Różnica dwóch macierzy.
 */
template<int Wymiar>
Macierz<Wymiar> Macierz<Wymiar>::operator- (Macierz<Wymiar> M)const
{
Macierz<Wymiar> Wynik;
for(int i=0; i<Wymiar; i++)
    {
    for(int j=0; j<Wymiar; j++)
        {
        Wynik(i,j) = (*this)(i,j) - M(i,j);
        }
    }
return Wynik;
}

/*!
 * \brief Metoda służąca do mnożenia macierzy.
 * Argumenty:
 *    Macierz - Pierwszy macierzowy składnik mnożenia.
 *    M - Drugi macierzowy składnik mnożenia.
 * Zwraca:
 *    Iloczyn dwóch macierzy.
 */
template<int Wymiar>
Macierz<Wymiar> Macierz<Wymiar>::operator* (Macierz<Wymiar> M)const
{
Macierz<Wymiar> Wynik;

int w,k;
for(int i=0; i<Wymiar; i++)
    {
    for(int j=0; j<Wymiar; j++)
        {
        Wynik(i,j)=0;
        w=k=0;
        while (w<Wymiar && k<Wymiar)
            {
            Wynik(i,j) += (*this)(i,k)*M(w,j);
            ++w;
            ++k;
            }
        }
    }
return Wynik;
}

/*!
 * \brief Metoda służąca do mnożenia macierzy przez skalar.
 * Argumenty:
 *    Macierz - Macierz.
 *    Liczba - Sklar.
 * Zwraca:
 *    Macierz, której każdy element został wymnożony przez skalar.
 */
template<int Wymiar>
Macierz<Wymiar> Macierz<Wymiar>::operator* (double Liczba)const
{
Macierz<Wymiar> Wynik;

for(int i=0; i<Wymiar; i++)
    {
    for(int j=0; j<Wymiar; j++)
        {
        Wynik(i,j) = (*this)(i,j)*Liczba;
        }
    }
return Wynik;
}

/*!
 * \brief Funkcja służąca do mnożenia macierzy przez skalar (Realizuje mnożenie w kolejności skalar*macierz).
 * Argumenty:
 *    M - Macierz.
 *    Liczba - Sklar.
 * Zwraca:
 *    Macierz, której każdy element został wymnożony przez skalar.
 */
template<int Wymiar>
Macierz<Wymiar> operator* (double Liczba, Macierz<Wymiar> M)
{
Macierz<Wymiar> Wynik;
for(int i=0; i<Wymiar; i++)
    {
    for(int j=0; j<Wymiar; j++)
        {
        Wynik(i,j) = M(i,j)*Liczba;
        }
    }
return Wynik;
}

/*!
 * \brief Metoda służąca do mnożenia macierzy przez wektor.
 * Argumenty:
 *    Macierz - Macierz.
 *    W - Wektor.
 * Zwraca:
 *    Wektor, będący wynikiem mnożenia macierzy przez wektor.
 */
template<int Wymiar>
Wektor<Wymiar> Macierz<Wymiar>::operator* (Wektor<Wymiar> W)const
{
Wektor<Wymiar> Wynik;

int w,k;
for(int i=0; i<Wymiar; i++)
    {
    for(int j=0; j<Wymiar; j++)
        {
        Wynik[i]=0;
        w=k=0;
        while (w<Wymiar&& k<Wymiar)
            {
            Wynik[i] += (*this)(i,k)*W[w];
            ++w;
            ++k;
            }
        }
    }
return Wynik;
}


/*!
 * \brief Funkcja służąca do przekazywania macierzy do danego strumienia.
 * Argumenty:
 *    Strm - Strumień, na który macierz ma zostać wypisany.
 *    Mac - Macierz, ktora ma zostać wypisana.
 * Zwraca:
 *    Strumień na który macierz została wypisana.
 */
template <int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm, const Macierz<Wymiar> &Mac)
{
for(int i=0; i<Wymiar; i++)
    {
    for(int j=0; j<Wymiar; j++)
        {
        Strm << std::fixed << std::setprecision(10)<< Mac(i,j);
        if(j!=(Wymiar-1))
            {
            Strm << " ";
            }
        }
    Strm << std::endl;
    }
return Strm;  
}

#endif
