/**
    \file targy.h
    Ebbe a fájlba kerül a tárgy ősosztály deklarációi, inline tagfüggvényei.
*/


#ifndef TARGY_HPP_INCLUDED
#define TARGY_HPP_INCLUDED

#include "string5.h"

///Ezeket a tárgyakat lehet használni, bővíthető!
enum targyak{
    KO, PAPIR, OLLO
};

class Targy{
	//Privát adattagok
	String nev; ///< A tárgy neve, mérkőzések kiírásához kell
public:
	/**
	 * Konstruktor
	 * @param nev - a tárgy neve, kiírásokhoz kell majd
	 * */
	Targy(const String& nev) {}
	virtual targyak getTargy() const = 0;
	virtual targyak getCounter() const = 0;
	char getBetu() const {return nev[0];}

	virtual ~Targy() {}
};

#endif // TARGY_HPP_INCLUDED
