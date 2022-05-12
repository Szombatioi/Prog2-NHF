/**
    \file ko.h
    Ebbe a fájlba kerül a kő alosztály deklarációi, inline tagfüggvényei.
*/

#ifndef KO_HPP_INCLUDED
#define KO_HPP_INCLUDED


#include "targy.hpp"

using std::cout;
using std::endl;

/**
* A Kő osztály.
* A papír legyőzi, viszont az ollót ez győzi le.
*/
class Ko : public Targy{
	targyak Counter; ///< A tárgy, ami legyőzi ezt a tárgyat
	targyak Self; ///< Hivatkozás a saját típusára, mérkőzéseknél lesz fontos
public:
	/**
	 * Konstruktor
	 * @param nev - A tárgy neve, kiírásokhoz fog kelleni
	 * */
	Ko(String nev) : Targy(nev), Counter(PAPIR), Self(KO) {}

	/**
	* getTargy - visszaadja a tárgyat
	*/
	targyak getTargy() const { return Self; }

	/**
	* getCounter - visszaadja azt a tárgyat, ami legyőzi
	*/
	targyak getCounter() const { return Counter; }

	~Ko() {}
};

#endif // KO_HPP_INCLUDED
