/**
    \file ollo.h
    Ebbe a fájlba kerül az olló alosztály deklarációi, inline tagfüggvényei.
*/

#ifndef OLLO_H_INCLUDED
#define OLLO_H_INCLUDED

#include "string5.h"
using std::cout;
using std::endl;

class Ollo : public Targy{
	///privát adattagok
public:
	/**
	 * Konstruktor
	 * @param nev - A tárgy neve, az ¿sosztály ctor-jának hívásához kell
	 **/
	Ollo(const String& nev) {}

	targyak getTargy() const;
	targyak getCounter() const;

	///Destruktor
	~Ollo() {}
};

#endif // OLLO_H_INCLUDED
