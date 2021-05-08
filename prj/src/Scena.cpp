#include "Scena.hh"
#include "Macierz3x3.hh"

/*!
 *\file
 *\brief Definicja metod klasy Scena.
 */



/*!
 *\brief Konstruktor bezparamateryczny sceny.
 */
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

/*!
 *\brief Konstruktor paramateryczny sceny.
 * Argumenty:
 *  \param[in] P - Prostopadloscian dla ktorego ma zostac wykonana scena.
 */
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

/*!
 *\brief Metoda sluzaca do zapamietywania poprzedniego przesuniecia.
 * Argumenty:
 *  \param[in] Przesuniecia - Wektor3D Przesuniecia ktory ma zostac zapisany.
 */
void Scena::ZapiszPrzesuniecie(Wektor3D Przesuniecie)
{
    (*this).PoprzedniePrzesuniecie()= Przesuniecie;
}

/*!
 *\brief Metoda sluzaca do zerowania wektora poprzedniego przesuniecia.
 */
void Scena::WyzerujPrzesuniecie()
{
    (*this).PoprzedniePrzesuniecie()= {0,0,0};
}

/*!
 *\brief Metoda sluzaca do zapamietania poprzedniego obrotu.
 * Argumenty:
 *  \param[in] Kat - Kat obrotu, ktory ma zostac zapisany.
 *  \param[in] Os -Os obrotu, ktora ma zostac zapisana.
 *  \param[in] Indeks - Numer komorki tablic, w ktorych ma zostac zapisany dany kat oraz dana os.
 */
void Scena::ZapiszObrot(double Kat, char Os, int Indeks)
{
    (*this).PoprzedniKat(Indeks)=Kat;
    (*this).PoprzedniaOs(Indeks)=Os;
}

/*!
 *\brief Metoda sluzaca do usuniecia wszystkich zapisany osi oraz katow.
 */
void Scena::WyczyscObroty()
{
    for(int i=0; i<ROZMIAR; i++)
        {
        (*this).PoprzedniKat(i)=0;
        (*this).PoprzedniaOs(i)='.';
        }
}

/*!
 *\brief Metoda sluzaca do wykonania obrotu prostopadloscianu wzorcowego.
 * Metoda obraca prostopadloscian wzorcowy wokol danej osi oraz o zadany kat,
 * ktore sa zapamietane w komorkach tablicy o danym indeksie.
 * Argumenty:
 *  \param[in] Indeks - Indeks tablic, w ktorych sa zapamietane kat oraz os.
 */
void Scena::WykonajObrot(int Indeks)
{
    (*this).WzorzecPr().Obrot((*this).PoprzedniKat(Indeks), (*this).PoprzedniaOs(Indeks));
}
 
/*!
 *\brief Metoda sluzaca do przesuniecia wzorca prostopadloscianu o wektor poprzedniego przesuniecia.
 */
void Scena::WykonajPrzesuniecie()
{
    (*this).WzorzecPr().Translacja((*this).PoprzedniePrzesuniecie());
}