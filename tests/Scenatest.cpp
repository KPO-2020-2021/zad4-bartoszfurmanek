#include "../tests/doctest/doctest.h"
#include "Scena.hh"

TEST_CASE("Test Scena - indeksowanie WzorzecPr 1"){                          
    Scena x;
    Prostopadloscian y;
    CHECK(x.WzorzecPr()==y);
}

TEST_CASE("Test Prostopadloscian - WzorzecPr 2"){                          
    Scena x;
    Prostopadloscian y{{1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3}};
    x.WzorzecPr()=y;
    CHECK(x.WzorzecPr()==y);
}

TEST_CASE("Test Scena - indeksowanie PoprzedniePrzesuniecie 1"){                          
    Scena x;
    Wektor3D y;
    CHECK(x.PoprzedniePrzesuniecie()==y);
}

TEST_CASE("Test Prostopadloscian - PoprzedniePrzesuniecie 2"){                          
    Scena x;
    Wektor3D y{1,2,3};
    x.PoprzedniePrzesuniecie()=y;
    CHECK(x.PoprzedniePrzesuniecie()==y);
}

TEST_CASE("Test Scena - indeksowanie PoprzedniKat 1"){                          
    Scena x;
    double y=0;
    CHECK(x.PoprzedniKat(0)==y);
}

TEST_CASE("Test Prostopadloscian - PoprzedniKat 2"){                          
    Scena x;
    double y=60;
    x.PoprzedniKat(0)=y;
    CHECK(x.PoprzedniKat(0)==y);
}

TEST_CASE("Test Scena - indeksowanie PoprzedniKat 3"){   //Zly indeks                       
    Scena x;
    WARN_THROWS(x.PoprzedniKat(10));
}

TEST_CASE("Test Prostopadloscian - PoprzedniKat 4"){     //Zly indeks                        
    Scena x;
    double y = 60;
    WARN_THROWS((x.PoprzedniKat(10)=y));
}

TEST_CASE("Test Scena - indeksowanie PoprzedniaOs 1"){                          
    Scena x;
    char y = '.';
    CHECK(x.PoprzedniaOs(0)==y);
}

TEST_CASE("Test Prostopadloscian - PoprzedniaOs 2"){                          
    Scena x;
    char y = '.';
    x.PoprzedniaOs(0)=y;
    CHECK(x.PoprzedniaOs(0)==y);
}

TEST_CASE("Test Scena - indeksowanie PoprzedniaOs 3"){   //Zly indeks                       
    Scena x;
    WARN_THROWS(x.PoprzedniaOs(10));
}

TEST_CASE("Test Prostopadloscian - PoprzedniaOs 4"){     //Zly indeks                        
    Scena x;
    char y = 'z';
    WARN_THROWS((x.PoprzedniaOs(10)=y));
}

TEST_CASE("Test Prostopadloscian - Zapisz przesuniecie"){                       
    Scena x;
    Wektor3D y{1,2,3};

    x.ZapiszPrzesuniecie(y);
    CHECK(x.PoprzedniePrzesuniecie()==y);

}

TEST_CASE("Test Prostopadloscian - usun przesuniecie"){                       
    Scena x;
    Wektor3D y{1,2,3};

    x.ZapiszPrzesuniecie(y);
    x.WyzerujPrzesuniecie();

    CHECK(x.PoprzedniePrzesuniecie()==Wektor3D());
}

TEST_CASE("Test Prostopadloscian - Zapisz obrot"){                       
    Scena x;
    x.ZapiszObrot(90, 'x', 1);
    CHECK((x.PoprzedniaOs(1)=='x' && x.PoprzedniKat(1)==90));

}

TEST_CASE("Test Prostopadloscian - Usun obrot"){                       
    Scena x;
    x.ZapiszObrot(90, 'x', 0);
    x.ZapiszObrot(60, 'z', 1);
    x.WyczyscObroty();
    CHECK((x.PoprzedniaOs(0)=='.' && x.PoprzedniKat(0)==0 && x.PoprzedniaOs(1)=='.' && x.PoprzedniKat(1)==0));

}

TEST_CASE("Test Prostopadloscian - Wykonaj obrot1"){                       
    Prostopadloscian y{{-2,2,2},{2,2,2},{-2,8,2},{2,8,2},{-2,8,6},{2,8,6},{-2,2,6},{2,2,6}};
    Scena x(y);

    x.ZapiszObrot(90, 'x', 0);
    x.WykonajObrot(0);

    y.Obrot(90, 'x');

    CHECK(x.WzorzecPr()==y);

}

TEST_CASE("Test Prostopadloscian - Wykonaj obrot2"){                       
    Prostopadloscian y{{-2,2,2},{2,2,2},{-2,8,2},{2,8,2},{-2,8,6},{2,8,6},{-2,2,6},{2,2,6}};
    Scena x(y);

    x.ZapiszObrot(90, 'x', 0);
    x.ZapiszObrot(60, 'z', 1);
    x.WykonajObrot(0);
    x.WykonajObrot(1);

    y.Obrot(90, 'x');
    y.Obrot(60, 'z');

    CHECK(x.WzorzecPr()==y);

}

TEST_CASE("Test Prostopadloscian - Wykonaj przesuniecie"){                       
    Prostopadloscian y{{-2,2,2},{2,2,2},{-2,8,2},{2,8,2},{-2,8,6},{2,8,6},{-2,2,6},{2,2,6}};
    Scena x(y);
    Wektor3D z{1,2,3};

    x.ZapiszPrzesuniecie(z);
    x.WykonajPrzesuniecie();

    y.Translacja(z);

    CHECK(x.WzorzecPr()==y);

}