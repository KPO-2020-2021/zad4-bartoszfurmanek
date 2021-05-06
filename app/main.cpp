// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include "exampleConfig.h"
#include "example.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"
#include "Scena.hh"



/*!
 * Funkcja służy do zapisu wspolrzednych wierzcholków prostopadlosciany do danego strumienia.
 * Pierwsze wspolrzedne zostaja zapisane ponownie, aby zachowac ciaglosc
 * przy wykonywaniu rysunku.
 * Argumenty: 
 *   StrmWy - Strumien do ktorego zostana zapisane dane.
 *   Pr - Prostopadloscianu ktorego wierzcholki maja zostac zapisane.
 * Zwraca:
 * True, jeżeli zapis uda sie pomyslnie, a w przeciwnym wypadku false.
 */
void ZapisWspolrzednychDoStrumienia(std::ostream& StrmWy, const Prostopadloscian Pr)
{
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[1] << std::endl;
  StrmWy << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[2] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[3] << std::endl;
  StrmWy << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[4] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[5] << std::endl;
  StrmWy << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[6] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[7] << std::endl;
  StrmWy << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[1] << std::endl;
}



/*!
 * Funkcja służy do zapisu wspolrzednych prostopadloscianu od pliku w celu
 * narysowania i wyswietlenia go przez gnu-plot.
 * Argumenty: 
 *   sNazwaPliku - Nazwa pliku ktory ma przechowywac informacje o wierzcholkach
 *   Pr - Prostopadloscian ktorego wierzcholki maja zostac zapisane.
 * Zwraca:
 * True, jeżeli zapis uda sie pomyslnie, a w przeciwnym wypadku false.
 */
bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, const Prostopadloscian Pr)
{
  std::ofstream  StrmPlikowy;
  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << "Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << " nie powiodla sie." << std::endl;
    return false;
  }
  ZapisWspolrzednychDoStrumienia(StrmPlikowy,Pr);
  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}



int main()
{
  Prostopadloscian      Pr{{-20,20,20},{20,20,20},{-20,80,20},{20,80,20},{-20,80,60},{20,80,60},{-20,20,60},{20,20,60}};    
  PzG::LaczeDoGNUPlota  Lacze;      //Zmienna do operowania na gnuplocie
  char                  Opcja;      //Zmienna przechowujaca informacje o wybranej opcji w menu
  double                Kat;        //Kat obrotu prostopadloscianu  
  char                  Os;         //Os obrotu
  int                   Powtorzenia =1; //Liczba powtorzen obrotow
  int                   i, j, k;//Ilosc powtorzen obrotu prostopadloscianu oraz indeks pomocniczny
  Wektor3D              Przesuniecie;//Wektor przesuniecia prostopadloscianu
  Macierz3x3            MacierzObr; //Macierz obrotu
  Scena                 Sc(Pr);     //Struktura zapamietujaca prostopadloscian oraz jego obroty i przesuniecia
  int                   KoniecPetli;
  

  Lacze.DodajNazwePliku("Prostopadloscian.dat",PzG::RR_Ciagly,2);     //Podlaczenie pliku, w ktorym beda zapisywane wspolrzedne do rysowania
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.UstawZakresY(-155,155);
  Lacze.UstawZakresX(-155,155);
  Lacze.UstawZakresZ(-155,155);

  Pr.PorownajBoki();

  std::cout<< std::endl;                                       //Wyswietlenie menu programu
  std::cout<< "o - obrot prostopadloscianu o zadana sekwencje rotacji" << std::endl;
  std::cout<< "t - powtorzenie poprzedniej sekwencji rotacji" << std::endl;
  std::cout<< "r - wyswietlenie macierzy rotacji" << std::endl;
  std::cout<< "p - przesuniecie prostopadloscianu o zadany wektor" << std::endl;
  std::cout<< "P - powtorzenie przesuniecia o zadany wektor" << std::endl;
  std::cout<< "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
  std::cout<< "b - porowanie bokow prostopadloscianu" << std::endl;
  std::cout<< "m - wyswietlenie menu" << std::endl;
  std::cout<< "k - koniec programu" << std::endl;
  std::cout<< std::endl;

  while(1)
    {
    std::cout<< "Wybrana opcja: ";
    std::cin>> Opcja;
    switch(Opcja)
        {
        case 'o':    //Wybor obortu prostopadloscianu
            {
            std::cout << "Podaj sekwencje obrotow (max. 10 obrotow): "<<std::endl;          //Wczytywanie danych i zapisywanie ich do struktury
            k=0;
            KoniecPetli=0;
            Sc.WyczyscObroty();
            while((k<10) && !KoniecPetli)                  //Zrobic to przez zmienna koniec petli
                {
                std::cin >> Os;
                if((Os!='x') && (Os!='y') && (Os!='z') && (Os!='.'))
                    {
                    std::cin.ignore(100000,'\n');
                    std::cout<< "Nieznana opcja. Dozwolne opcje: x, y, z lub . (Koniec wczytywania). Sprobuj ponownie" << std::endl;
                    }
                else
                    {
                    if(Os=='.')
                        {
                        KoniecPetli=1;
                        }
                    else
                        {
                        std::cin >> Kat;
                        }
                    std::cin.ignore(100000,'\n');
                    Sc.ZapiszObrot(Kat, Os, k);
                    ++k;
                    }
                }

            std::cout << "Podaj ilosc powtorzen obrotu: ";
            std::cin >> Powtorzenia;
            std::cin.ignore(100000,'\n');


            if (!ZapisWspolrzednychDoPliku("Prostopadloscian.dat",Pr))
                {
                return 1;
                }
            Lacze.Rysuj();                        //Rysunek pierwotnej pozycji prostopadloscianu

            for(i=0; i<Powtorzenia; i++)
                {
                k=0;
                while((k<10) && (Sc.PoprzedniaOs(k)!='.'))
                    {
                    for(j=0; j<30; j++)               //Petla do wykonywania animacji ruchu (50FPS)
                        {
                        Pr.Obrot(MacierzObrotu((Sc.PoprzedniKat(k))/30, Sc.PoprzedniaOs(k)));             //Obrot prostopadloscianu
                        usleep(33333);
                        if (!ZapisWspolrzednychDoPliku("Prostopadloscian.dat",Pr))
                            {
                            return 1;
                            }
                        Lacze.Rysuj();                //Rysowanie prostokata
                        }
                    Sc.WykonajObrot(k);               //Wykonanie obrotu wzorca bez animacji (mniejsza kumulacja bledow)
                    Pr = Sc.WzorzecPr();              //Zastapienie prostopadloscianu prostopadloscianem wzorcowym
                    ++k;             
                    }
                }

            Pr.PorownajBoki();                           //Porownanie dlugosci bokow prostopadloscianu

            std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
            std::cin.ignore(100000,'\n');
            

            break;
            }
        case 't':    //Wybor poprzedniego obrotu
            {
            
            if(Sc.PoprzedniaOs(0)=='.')
                {
                std::cout << "Brak poprzedniej kombinacji obrotow" << std::endl;
                break;
                }


            if (!ZapisWspolrzednychDoPliku("Prostopadloscian.dat",Pr))
                {
                return 1;
                }
            Lacze.Rysuj();                        //Rysunek pierwotnej pozycji prostopadloscianu

            for(i=0; i<Powtorzenia; i++)
                {
                k=0;
                while((k<10) && (Sc.PoprzedniaOs(k)!='.'))
                    {
                    for(j=0; j<30; j++)               //Petla do wykonywania animacji ruchu (30FPS)
                        {
                        Pr.Obrot(MacierzObrotu((Sc.PoprzedniKat(k))/30, Sc.PoprzedniaOs(k)));             //Obrot prostopadloscianu
                        usleep(33333);
                        if (!ZapisWspolrzednychDoPliku("Prostopadloscian.dat",Pr))
                            {
                            return 1;
                            }
                        Lacze.Rysuj();                //Rysowanie prostokata
                        }
                    Sc.WykonajObrot(k);               //Wykonanie obrotu wzorca bez animacji (mniejsza kumulacja bledow)
                    Pr = Sc.WzorzecPr();              //Zastapienie prostopadloscianu prostopadloscianem wzorcowym
                    ++k;             
                    }
                }

            Pr.PorownajBoki();                           //Porownanie dlugosci bokow prostopadloscianu

            std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
            std::cin.ignore(100000,'\n');
            

            break;
            }
        
        case 'r':   //Wyswietlenie macierzy rotacji
            {
            std::cout <<std::endl << "Podaj os obrotu (x, y, z) oraz kat obrotu" <<std::endl;
            KoniecPetli=0;
            while(!KoniecPetli)
                {
                std::cin >> Os;
                if((Os!='x') && (Os!='y') && (Os!='z'))
                    {
                    std::cin.ignore(100000,'\n');
                    std::cout<< "Nieznana os. Mozliwe opcje to: x, y lub z. Sprobuj ponownie"<< std::endl;
                    }
                else
                    {
                    std::cin >> Kat;
                    std::cin.ignore(100000,'\n');
                    std::cout<< std::endl << MacierzObrotu(Kat, Os)<< std::endl;
                    KoniecPetli=1;
                    }
                }
            break;
            }
        case 'p':     //Przesuniecie prostopadloscianu
            {
            Sc.WyzerujPrzesuniecie();
            std::cout << "Podaj wektor przesuniecia: ";
            std::cin >> Przesuniecie;
            std::cin.ignore(100000,'\n');
            Sc.ZapiszPrzesuniecie(Przesuniecie);

            if (!ZapisWspolrzednychDoPliku("Prostopadloscian.dat",Pr))
                {
                return 1;
                }
            Lacze.Rysuj();                                    //Rysunek pierwotnej pozycji prostopadloscianu

            for(j=0; j<30; j++)                               //Petla do wykonywania animacji ruchu (30FPS)
                {
                Pr.Translacja(Przesuniecie*0.0333);             //Przesuniecie prostopadloscianu o zadany wektor
                    usleep(33333);
                    if (!ZapisWspolrzednychDoPliku("Prostopadloscian.dat",Pr))
                        {
                        return 1;
                        }
                    Lacze.Rysuj();                            //Rysowanie prostopadloscianu                  
                }

            Sc.WykonajPrzesuniecie();                         //Wykonanie przesuniecia na wzorcu prostopadloscianu
            Pr = Sc.WzorzecPr();                              //Zastapienie prostopadloscianu prostopadloscianem wzorcowym (z mniejsza iloscia kumulacji bledow)

            std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
            std::cin.ignore(100000,'\n');

            break;
            }
        case 'P':   //Powotrzenie poprzedniego przesuniecia
            {
            
            if (!ZapisWspolrzednychDoPliku("Prostopadloscian.dat",Pr))
                {
                return 1;
                }
            Lacze.Rysuj();                                    //Rysunek pierwotnej pozycji prostopadloscianu

            for(j=0; j<30; j++)                               //Petla do wykonywania animacji ruchu (30FPS)
                {
                Pr.Translacja(Sc.PoprzedniePrzesuniecie()*0.0333);             //Przesuniecie prostopadloscianu o zadany wektor
                    usleep(33333);
                    if (!ZapisWspolrzednychDoPliku("Prostopadloscian.dat",Pr))
                        {
                        return 1;
                        }
                    Lacze.Rysuj();                            //Rysowanie prostopadloscianu                  
                }

            Sc.WykonajPrzesuniecie();                         //Wykonanie przesuniecia na wzorcu prostopadloscianu
            Pr = Sc.WzorzecPr();                              //Zastapienie prostopadloscianu prostopadloscianem wzorcowym (z mniejsza iloscia kumulacji bledow)

            std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
            std::cin.ignore(100000,'\n');

            break;
            }    
        case 'w':       //Wyswietlenie wspolrzednych
            {
            std::cout<< std::endl<< Pr<< std::endl;
            break;
            }
        case 'b':       //Porownanie bokow
            {
            Pr.PorownajBoki(); 
            break;
            }
        case 'm':       //Wyswietlenie menu programu
            {
            std::cout<< std::endl;                                       
            std::cout<< "o - obrot prostopadloscianu o zadana sekwencje rotacji" << std::endl;
            std::cout<< "t - powtorzenie poprzedniej sekwencji rotacji" << std::endl;
            std::cout<< "r - wyswietlenie macierzy rotacji" << std::endl;
            std::cout<< "p - przesuniecie prostopadloscianu o zadany wektor" << std::endl;
            std::cout<< "P - powtorzenie przesuniecia o zadany wektor" << std::endl;
            std::cout<< "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
            std::cout<< "b - porowanie bokow prostopadloscianu" << std::endl;
            std::cout<< "m - wyswietlenie menu" << std::endl;
            std::cout<< "k - koniec programu" << std::endl;
            std::cout<< std::endl;
            break;
            }
        case 'k':       //Koniec programu
            {
            std::cout<< std::endl << "KONIEC PROGRAMU" << std::endl;
            return 0;
            }
        default:        //Wybor zlej opcji
            {
            std::cout<< std::endl<< "Blad wyboru opcji, sprobuj ponownie"<< std::endl;
            }
        }
    }
}
