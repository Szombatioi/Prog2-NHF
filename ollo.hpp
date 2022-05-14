/**
    \file ollo.h
    Ebbe a fájlba kerül az olló alosztály deklarációi, inline tagfüggvényei.
*/

#ifndef OLLO_HPP_INCLUDED
#define OLLO_HPP_INCLUDED

#include "targy.hpp"

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
	 * Eltérő nevet meg tárgy típusokat állít be, mint a Tárgy osztály más utódai
	 * */
	Ollo() : Targy("Olló"), Counter(KO), Self(OLLO) {}

	/**
	* getTargy - visszaadja a tárgyat
	*/
	targyak getSelf() const { return Self; }

	/**
	* getCounter - visszaadja azt a tárgyat, ami legyőzi
	*/
	targyak getCounter() const { return Counter; }
};

#endif // OLLO_HPP_INCLUDED
