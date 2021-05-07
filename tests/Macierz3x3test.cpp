#include "../tests/doctest/doctest.h"
#include "Macierz3x3.hh"


TEST_CASE("Test Macierz - macierz obortu 1"){ //x 90
    Macierz3x3 y{1,0,0,0,0,-1,0,1,0};

    Macierz3x3 x=MacierzObrotu(90, 'x');

    CHECK(x==y);
}

TEST_CASE("Test Macierz - macierz obortu 2"){//x -60
    Macierz3x3 y{1,0,0,0,0.5,sqrt(3)/2,0,-sqrt(3)/2,0.5};

    Macierz3x3 x=MacierzObrotu(-60, 'x');

    CHECK(x==y);
}

TEST_CASE("Test Macierz - macierz obortu 1"){ //y 90
    Macierz3x3 y{0,0,1,0,1,0,-1,0,0};

    Macierz3x3 x=MacierzObrotu(90, 'y');

    CHECK(x==y);
}

TEST_CASE("Test Macierz - macierz obortu 2"){//y -60
    Macierz3x3 y{0.5,0,-sqrt(3)/2,0,1,0,sqrt(3)/2,0,0.5};;

    Macierz3x3 x=MacierzObrotu(-60, 'y');

    CHECK(x==y);
}

TEST_CASE("Test Macierz - macierz obortu 1"){ //z 90
    Macierz3x3 y{0,-1,0,1,0,0,0,0,1};

    Macierz3x3 x=MacierzObrotu(90, 'z');

    CHECK(x==y);
}

TEST_CASE("Test Macierz - macierz obortu 2"){//z -60
    Macierz3x3 y{0.5,sqrt(3)/2,0,-sqrt(3)/2,0.5,0,0,0,1};

    Macierz3x3 x=MacierzObrotu(-60, 'z');

    CHECK(x==y);
}