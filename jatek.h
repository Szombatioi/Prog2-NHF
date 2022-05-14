/**
 * \file jatek.h
 * Itt valósul meg a mérkőzések demonstrálására használt jatek osztály.
 * Ebben a fájlban vannak a függvények deklarációi és az inline
 * függvények megvalósításai.
 * */

#ifndef JATEK_H_INCLUDED
#define JATEK_H_INCLUDED

#include "targy.hpp"
#include "ko.hpp"
#include "papir.hpp"
#include "ollo.hpp"
#include "naplo.h"
#include <fstream>

/**
* Jatek osztály - Magát a játék főbb vezérlési elemeit tartalmazza
*/
class Jatek{
	/**
	* gyoz - eldönti két tárgy közül, hogy melyik nyer.
	* Privát függvény, mivel csak a demonstrácknál kell használni.
	* @param lhs - Az egyik (bal oldali) tárgy
	* @param rhs - A másik (jobb oldali) tárgy
	*/
	BOOL gyoz(targyak lhs, targyak rhs) const;
public:
    Naplo &naplo; ///< A játékosokat tartalmazó napló
	/**
	* Konstruktor
	* @param n - A (már létrehozott) napló
	*/
	Jatek(Naplo& n) : naplo(n) {}

	Targy* getRandomTargy();

	/**
	 * demonstrate - Demonstrál egy mérkőzést.
	 * Bekéri mindkét játékos nevét, esetlegesen felveszi őket a nyilvántartásba.
	 * Frissíti a naplót és a játékosok statisztikáit.
	 * */
	void demonstrate();

	void menu(bool& run);
};

#endif // JATEK_H_INCLUDED
