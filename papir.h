/**
    \file papir.h
    Ebbe a fájlba kerül a papír alosztály deklarációi, inline tagfüggvényei.
*/


#ifndef PAPIR_H_INCLUDED
#define PAPIR_H_INCLUDED

#include "string5.h"
#include "targy.h"
using std::cout;
using std::endl;

class Papir : public Targy{
	///privát adattagok
public:
	/**
	 * Konstruktor
	 * @param nev - A tárgy neve, az ¿sosztály ctor-jának hívásához kell
	 * */
	Papir(const String& nev) : Targy(nev) {}
	
	targyak getTargy() const;
	targyak getCounter() const;

	///Destruktor
	~Papir() {}
};

#endif // PAPIR_H_INCLUDED
