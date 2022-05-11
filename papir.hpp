/**
    \file papir.h
    Ebbe a fájlba kerül a papír alosztály deklarációi, inline tagfüggvényei.
*/


#ifndef PAPIR_H_INCLUDED
#define PAPIR_H_INCLUDED

#include "string5.h"
#include "targy.hpp"

using std::cout;
using std::endl;

/**
* A Papír osztály.
* Az olló legyőzi, viszont az követ ez győzi le.
*/
class Papir : public Targy{
    targyak Counter; ///< A tárgy, ami legyőzi ezt a tárgyat
	targyak Self; ///< Hivatkozás a saját típusára, mérkőzéseknél lesz fontos
public:
	/**
	 * Konstruktor
	 * @param nev - A tárgy neve, kiírásokhoz fog kelleni
	 * */
	Papir(const String& nev) : Targy(nev), Counter(OLLO), Self(PAPIR) {}

	/**
	* getTargy - visszaadja a tárgyat
	*/
	targyak getTargy() const { return Self; }

	/**
	* getCounter - visszaadja azt a tárgyat, ami legyőzi
	*/
	targyak getCounter() const { return Counter; }
};

#endif // PAPIR_H_INCLUDED
