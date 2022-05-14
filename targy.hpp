/**
    \file targy.h
    Ebbe a fájlba kerül a tárgy ősosztály deklarációi, inline tagfüggvényei.
*/


#ifndef TARGY_HPP_INCLUDED
#define TARGY_HPP_INCLUDED

#include "string5.h"

///Ezeket a tárgyakat lehet használni, bővíthető!
enum targyak{
    KO=1, PAPIR=2, OLLO=3
};

/**
 * A Targy ősosztály. Ebből származik a Ko, Papir és Ollo osztály
 */
class Targy{
	//Privát adattagok
	String nev; ///< A tárgy neve, mérkőzések kiírásához kell
public:
	/**
	 * Konstruktor
	 * @param nev - a tárgy neve, kiírásokhoz kell majd
	 * */
	Targy(const String& nev) : nev(nev) {}

	///A saját tárgy típusát adja vissza
	virtual targyak getSelf() const = 0;

	///A tárgyat legyőző rágy típusát adja vissza
	virtual targyak getCounter() const = 0;

	///A tárgy kezdőbetűjét adja vissza
	char getBetu() const { return nev[0]; }

	///A tárgy nevét adja vissza
	String getNev() const {return nev;}

	virtual ~Targy() {}
};

#endif // TARGY_HPP_INCLUDED
