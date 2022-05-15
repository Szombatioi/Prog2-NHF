/**
    \file papir.h
    Ebbe a fájlba kerül a papír alosztály deklarációi, inline tagfüggvényei.
*/


#ifndef PAPIR_HPP_INCLUDED
#define PAPIR_HPP_INCLUDED

#include "targy.hpp"

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
	 * Eltérő nevet meg tárgy típusokat állít be, mint a Tárgy osztály más utódai
	 * */
	Papir() : Targy("Papír"), Counter(OLLO), Self(PAPIR) {}

	///copy függvény
	Papir* copy() {return new Papir();}

	/**
	* getTargy - visszaadja a tárgyat
	*/
	targyak getSelf() const { return Self; }

	/**
	* getCounter - visszaadja azt a tárgyat, ami legyőzi
	*/
	targyak getCounter() const { return Counter; }
};

#endif // PAPIR_HPP_INCLUDED
