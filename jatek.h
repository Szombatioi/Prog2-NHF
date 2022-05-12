/**
 * \file jatek.h
 * Itt valósul meg a mérkőzések demonstrálására használt jatek osztály.
 * Ebben a fájlban vannak a függvények deklarációi és az inline
 * függvények megvalósításai.
 * */

#ifndef JATEK_H_INCLUDED
#define JATEK_H_INCLUDED

#include "targy.hpp"
#include "naplo.h"
#include <fstream>

/**
* Jatek osztály - Magát a játék főbb vezérlési elemeit tartalmazza
*/
class Jatek{
	//Privát adattagok
	Naplo* naplo; ///< A játékosokat tartalmazó napló

	/**
	* gyoz - eldönti két tárgy közül, hogy melyik nyer.
	* Privát függvény, mivel csak a demonstrácknál kell használni.
	* @param lhs - Az egyik (bal oldali) tárgy
	* @param rhs - A másik (jobb oldali) tárgy
	*/
	BOOL gyoz(const Targy& lhs, const Targy& rhs) const;
public:
	/**
	* Konstruktor
	* @param n - A (már létrehozott) napló
	*/
	Jatek(Naplo* n) {naplo = n;}

	/**
	 * load - Betölti a naplóban tárolt játékosokat a naplo.txt fájlból
	 * Ha nem létezik, üres lesz a Napló
	 * */
	void load();

	/**
	 * save - Elmenti a napló adatait a naplo.txt fájlba (felülírja)
	 * Ha nem létezik a txt fájl, generál egyet.
	 * */
	void save();

	/**
	 * demonstrate - Demonstrál egy mérkőzést.
	 * Bekéri mindkét játékos nevét, esetlegesen felveszi őket a nyilvántartásba.
	 * Frissíti a naplót és a játékosok statisztikáit.
	 * */
	void demonstrate();
};

#endif // JATEK_H_INCLUDED
