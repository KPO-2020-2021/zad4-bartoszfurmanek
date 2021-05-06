#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>

#include "Macierz.hh"

/*!
 * \brief Klasa Macierz3x3.
 *
 *  Klasa reprezentuje macierz kwadratowa 3x3. Kazda komorka tablicy
 *  reprezentuje jedna komorke macierzy, ktore indeksuje sie za pomoca
 *  operator (). Na macierzy mozna wykonywac podstawowe dzialania z
 *  arytmetyki macierzy.
 */
typedef Macierz<3>  Macierz3x3;

Macierz3x3 MacierzObrotu(double Kat, char Os);



#endif
