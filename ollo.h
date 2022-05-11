/**
    \file ollo.h
    Ebbe a fájlba kerül az olló alosztály deklarációi, inline tagfüggvényei.
*/

#ifndef OLLO_H_INCLUDED
#define OLLO_H_INCLUDED

#include "string5.h"
using std::cout;
using std::endl;

/**
* Az Olló osztály.
* A kő legyőzi, viszont a papírt ez győzi le.
*/
class Ollo : public Targy{
    targyak Counter; ///< A tárgy, ami legyőzi ezt a tárgyat
	targyak Self; ///< Hivatkozás a saját típusára, mérkőzéseknél lesz fontos
public:
	/**
	 * Konstruktor
	 * @param nev - A tárgy neve, kiírásokhoz fog kelleni
	 **/
	Ollo(const String& nev) : Targy(nev), Counter(KO), Self(OLLO) {}

	/**
	* getTargy - visszaadja a tárgyat
	*/
	targyak getTargy() const { return Self; }

	/**
	* getCounter - visszaadja azt a tárgyat, ami legyőzi
	*/
	targyak getCounter() const { return Counter; }
};

#endif // OLLO_H_INCLUDED
