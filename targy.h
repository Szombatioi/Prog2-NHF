/**
    \file targy.h
    Ebbe a fájlba kerül a tárgy ősosztály deklarációi, inline tagfüggvényei.
*/


#ifndef TARGY_H_INCLUDED
#define TARGY_H_INCLUDED

#include "string5.h"
using std::cout;
using std::endl;

///Ezeket a tárgyakat lehet használni, bővíthető!
enum targyak{
	KO, PAPIR, OLLO
};

class Targy{
	///Privát adattagok
public:
	/**
	 * Konstruktor
	 * @param nev - a tárgy neve, kiírásokhoz kell majd
	 * */
	Targy(const String& nev) : nev(nev) {}

	virtual targyak getTargy() const;
	virtual targyak getCounter() const;

	///Destruktor
	virtual ~Targy() {}
};

#endif // TARGY_H_INCLUDED
