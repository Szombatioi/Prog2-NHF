/**
 * \file jatekos.h
 * Itt valósítjuk meg a játékos osztályt, itt a deklarációk, inline tagfüggvények vannak.
 * */

#ifndef JATEKOS_H_INCLUDED
#define JATEKOS_H_INCLUDED

#include "string5.h"
#include "targy.hpp"

/**
* A Játékos osztály.
* Egy játékos adatait tárolja (név, használt tárgy).
*/
class Jatekos{
	//Privát adattagok
	String nev; ///< A játékos neve
	Targy* targy; ///< A játékos tárgya
public:
	/**
	 * Konstruktor
	 * @param nev - A játékos neve
	 * @param *t - a tárgy, amit használ
	 * */
    Jatekos(String nev, Targy *t) : nev(nev), targy(t) {}

	/**
	 * setItem - beállítja a (már létező) játékos tárgyát
	 * @param *t - a tárgy, amit beállítunk neki
	 * */
	void setItem(Targy *t) { targy = t; }

	/**
	* getNev - Visszaadja a játékos nevét
	*/
	String getNev() const {return nev;}
	/**
	* getTargy - Visszaadja a játékos tárgyát
	*/
	targyak getTargy() const {return targy->getTargy();}

	bool operator==(const Jatekos& j) const{
        return nev==j.getNev();
	}

	///Destruktor
	~Jatekos() { delete targy; }
};

#endif // JATEKOS_H_INCLUDED
