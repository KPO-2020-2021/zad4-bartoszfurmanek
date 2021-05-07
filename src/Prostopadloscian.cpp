#include "Prostopadloscian.hh"

#define MIN_ROZNICA 0.001


Wektor3D Prostopadloscian::operator [](int Indeks)const
{
    if(Indeks >= 8)
        {
        throw std::runtime_error("Blad: Zly indeks");
        }
    
    return Wierzcholek[Indeks];
}


Wektor3D& Prostopadloscian::operator [](int Indeks)
{
    if(Indeks >= 8)
        {
        throw std::runtime_error("Blad: Zly indeks");
        }
    
    return Wierzcholek[Indeks];
}

Prostopadloscian::Prostopadloscian()
{
    for(int i=0; i<8; i++)
        {
        Wierzcholek[i]={0,0,0};
        }
}

Prostopadloscian::Prostopadloscian(const std::initializer_list<Wektor3D> &ListaElem)
{
  if(ListaElem.size() > 8)
    {
      throw std::runtime_error("Blad: Nieodpowiednia liczba parametrow");
    }
  int Indeks = -1;
  for(Wektor3D Elem_i : ListaElem)
    {
      Wierzcholek[++Indeks] = Elem_i;
    }
}

bool Prostopadloscian::operator ==(Prostopadloscian Pr)const
{
for(int i=0; i<8; i++)
    {
    if(!((*this)[i]==Pr[i]))
        {return false;}
    }
return true;
}

Prostopadloscian& Prostopadloscian::Obrot(double Kat, char Os)
{
    for(int i=0; i<8; i++)
    {
    (*this)[i] = MacierzObrotu(Kat, Os) * (*this)[i];  //Wymnożenie każdego wierzcholka przez macierz obrotu
    }
    return *this;
}

Prostopadloscian& Prostopadloscian::Translacja(Wektor3D Wektor)
{
    for(int i=0; i<8; i++)
    {
    (*this)[i] += Wektor;
    }
    return (*this);
}


void Prostopadloscian::PorownajBoki()const
{
    double bok1=(*this)[0].Odleglosc((*this)[1]);      //Obliczenie dlugosci bokow
    double bok2=(*this)[2].Odleglosc((*this)[3]);
    double bok3=(*this)[4].Odleglosc((*this)[5]);
    double bok4=(*this)[6].Odleglosc((*this)[7]);

    double bok5=(*this)[1].Odleglosc((*this)[3]);
    double bok6=(*this)[5].Odleglosc((*this)[7]);
    double bok7=(*this)[4].Odleglosc((*this)[6]);
    double bok8=(*this)[0].Odleglosc((*this)[2]);

    double bok9=(*this)[0].Odleglosc((*this)[6]);
    double bok10=(*this)[1].Odleglosc((*this)[7]);
    double bok11=(*this)[3].Odleglosc((*this)[5]);
    double bok12=(*this)[2].Odleglosc((*this)[4]);

    std::cout<< std::endl << "Poprzeczne boki sa ";                     //Analiza poprzecznych bokow
    if((abs(bok1-bok2)<=0.0001)&&(abs(bok1-bok3)<=0.0001)&&(abs(bok1-bok4)<=0.0001))
        {
        std::cout<< "rowne.";
        }
    else
        {
        std::cout<< "nierowne.";
        }
    std::cout<<std::endl;
    std::cout<< "Dlugosc pierwszego boku: " << std::setprecision(20) << bok1 << std::endl;
    std::cout<< "Dlugosc drugiego boku: " << std::setprecision(20) << bok2 << std::endl;
    std::cout<< "Dlugosc trzeciego boku: " << std::setprecision(20) << bok3 << std::endl;
    std::cout<< "Dlugosc czwartego boku: " << std::setprecision(20) << bok4 << std::endl;

    std::cout<< std::endl << "Dluzsze przeciwlegle boki sa ";           //Analiza dluzszych przeciwleglych bokow
    if((abs(bok5-bok6)<=0.0001)&&(abs(bok5-bok7)<=0.0001)&&(abs(bok5-bok8)<=0.0001))
        {
        std::cout<< "rowne.";
        }
    else
        {
        std::cout<< "nierowne.";
        }
    std::cout<<std::endl;
    std::cout<< "Dlugosc pierwszego boku: " << std::setprecision(20) << bok5 << std::endl;
    std::cout<< "Dlugosc drugiego boku: " << std::setprecision(20) << bok6 << std::endl;
    std::cout<< "Dlugosc trzeciego boku: " << std::setprecision(20) << bok7 << std::endl;
    std::cout<< "Dlugosc czwartego boku: " << std::setprecision(20) << bok8 << std::endl;

    std::cout<< std::endl << "Krotsze przeciwlegle boki sa ";           //Analiza krotszych przecwileglych bokow
    if((abs(bok9-bok10)<=0.0001)&&(abs(bok9-bok11)<=0.0001)&&(abs(bok9-bok12)<=0.0001))
        {
        std::cout<< "rowne.";
        }
    else
        {
        std::cout<< "nierowne.";
        }
    std::cout<<std::endl;
    std::cout<< "Dlugosc pierwszego boku: " << std::setprecision(20) << bok9 << std::endl;
    std::cout<< "Dlugosc drugiego boku: " << std::setprecision(20) << bok10 << std::endl;
    std::cout<< "Dlugosc trzeciego boku: " << std::setprecision(20) << bok11 << std::endl;
    std::cout<< "Dlugosc czwartego boku: " << std::setprecision(20) << bok12 << std::endl;
}

std::ostream& operator << (std::ostream &Strm, const Prostopadloscian &Pr)
{
for(int i=0; i<8; i++)
    {
    Strm << std::setw(16) << std::fixed << std::setprecision(10) << Pr[i] << std::endl;
    }
return Strm;
}