#include <iostream>
#include "targy.h"
#include "ko.h"
#include "jatekos.h"
#include "papir.h"
#include "string5.h"
/**
 * \file main.cpp
 * A teszteseteket itt ellen�rizz�k le.
*/

using std::cout;

int main()
{
    setlocale(LC_ALL, "hun"); ///CodeBlocksn�l a konzol hib�san jelen�ti meg a bet�ket, tesztel�sre javasolt a Visual Studio haszn�lata
    Jatekos j(String("Peti"), new Targy(String("Ko")));
    j.kiir();
    return 0;
}
