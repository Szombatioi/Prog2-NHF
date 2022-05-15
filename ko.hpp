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
	 * Eltérő nevet meg tárgy típusokat állít be, mint a Tárgy osztály más utódai
	 * */
	Ko() : Targy("Kő"), Counter(PAPIR), Self(KO) {}

	///copy függvény
	Ko* copy(){return new Ko();}

	/**
	* getTargy - visszaadja a tárgyat
	*/
	targyak getSelf() const { return Self; }

	/**
	* getCounter - visszaadja azt a tárgyat, ami legyőzi
	*/
	targyak getCounter() const { return Counter; }
};

#endif // KO_HPP_INCLUDED
