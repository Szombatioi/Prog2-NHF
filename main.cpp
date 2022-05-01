#include <iostream>
#include "targy.h"
#include "ko.h"
#include "jatekos.h"
#include "papir.h"
#include "string5.h"
/**
 * \file main.cpp
 * A teszteseteket itt ellenõrizzük le.
*/

using std::cout;

int main()
{
    setlocale(LC_ALL, "hun"); ///CodeBlocksnál a konzol hibásan jeleníti meg a betûket, tesztelésre javasolt a Visual Studio használata
    Jatekos j(String("Peti"), new Targy(String("Ko")));
    j.kiir();
    return 0;
}
