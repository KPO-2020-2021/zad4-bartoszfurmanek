#include "../tests/doctest/doctest.h"
#include "Prostopadloscian.hh"

TEST_CASE("Test Prostopadloscian - Konstruktor bezparametryczny"){                       
    Prostopadloscian x;

    CHECK(((x[0]==Wektor3D{0,0,0}) && (x[1]==Wektor3D{0,0,0}) && (x[2]==Wektor3D{0,0,0}) && (x[3]==Wektor3D{0,0,0}) && (x[4]==Wektor3D{0,0,0}) && (x[5]==Wektor3D{0,0,0}) && (x[6]==Wektor3D{0,0,0}) && (x[7]==Wektor3D{0,0,0})));
}

TEST_CASE("Test Prostopadloscian - indeksowanie 1"){                          
    Prostopadloscian x{{1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3}};

    CHECK((x[0]==Wektor3D{1,2,3}));
}

TEST_CASE("Test Prostopadloscian - indeksowanie 2"){                          
    Prostopadloscian x;

    x[0]={1,2,3};


    CHECK((x[0]==Wektor3D{1,2,3}));
}

TEST_CASE("Test Prostopadloscian - indeksowanie 3"){ //Zly indeks                         
    Prostopadloscian x;

    WARN_THROWS(x[8]);
}

TEST_CASE("Test Prostopadloscian - indeksowanie 3"){ //Zly indeks                         
    Prostopadloscian x;

    WARN_THROWS((x[8]={1,2,3}));
}


TEST_CASE("Test Prostopadloscian - porownanie 1"){ //Rownosc                         
    Prostopadloscian x,y;

    x[0]={1,2,3};

    y[0]={1,2,3};

    CHECK(x==y);
}

TEST_CASE("Test Prostopadloscian - porownanie 2"){ //Minimalna nierownosc                        
    Prostopadloscian x,y;

    x[0]={1.0001,2,3};

    y[0]={1,2,3};

    CHECK(x==y);
}

TEST_CASE("Test Prostopadloscian - porownanie 3"){ //Nierownosc                       
    Prostopadloscian x,y;

    x[0]={3,2,1};

    y[0]={1,2,3};

    CHECK(!(x==y));
}

TEST_CASE("Test Prostopadloscian - porownanie 4"){ //Mala nierownosc przekraczajaca granice                      
    Prostopadloscian x,y;

    x[0]={1.0011,2,3};

    y[0]={1,2,3};

    CHECK(!(x==y));
}

TEST_CASE("Test Prostopadloscian - translacja 1"){  //Wartosci dodatnie                    
    Prostopadloscian x{{-2,2,2},{2,2,2},{-2,8,2},{2,8,2},{-2,8,6},{2,8,6},{-2,2,6},{2,2,6}};

    x.Translacja({1,2,3});

    Prostopadloscian y{{-1,4,5},{3,4,5},{-1,10,5},{3,10,5},{-1,10,9},{3,10,9},{-1,4,9},{3,4,9}};

    CHECK(x==y);
}

TEST_CASE("Test Prostopadloscian - translacja 2"){  //Wartosci ujemne                   
    Prostopadloscian x{{-2,2,2},{2,2,2},{-2,8,2},{2,8,2},{-2,8,6},{2,8,6},{-2,2,6},{2,2,6}};

    x.Translacja({-1,-2,-3});

    Prostopadloscian y{{-3,0,-1},{1,0,-1},{-3,6,-1},{1,6,-1},{-3,6,3},{1,6,3},{-3,0,3},{1,0,3}};

    CHECK(x==y);
}


TEST_CASE("Test Prostopadloscian - obrot 1"){  //x 90                 
    Prostopadloscian x{{-2,2,2},{2,2,2},{-2,8,2},{2,8,2},{-2,8,6},{2,8,6},{-2,2,6},{2,2,6}};

    x.Obrot(90, 'x');

    Prostopadloscian y{{-2,-2,2},{2,-2,2},{-2,-2,8},{2,-2,8},{-2,-6,8},{2,-6,8},{-2,-6,2},{2,-6,2}};

    CHECK(x==y);
}

TEST_CASE("Test Prostopadloscian - obrot 2"){  //y 90                 
    Prostopadloscian x{{-2,2,2},{2,2,2},{-2,8,2},{2,8,2},{-2,8,6},{2,8,6},{-2,2,6},{2,2,6}};

    x.Obrot(90,'y');

    Prostopadloscian y{{2,2,2},{2,2,-2},{2,8,2},{2,8,-2},{6,8,2},{6,8,-2},{6,2,2},{6,2,-2}};

    CHECK(x==y);
}

TEST_CASE("Test Prostopadloscian - obrot 3"){  //z 90                 
    Prostopadloscian x{{-2,2,2},{2,2,2},{-2,8,2},{2,8,2},{-2,8,6},{2,8,6},{-2,2,6},{2,2,6}};

    x.Obrot(90,'z');

    Prostopadloscian y{{-2,-2,2},{-2,2,2},{-8,-2,2},{-8,2,2},{-8,-2,6},{-8,2,6},{-2,-2,6},{-2,2,6}};

    CHECK(x==y);
}