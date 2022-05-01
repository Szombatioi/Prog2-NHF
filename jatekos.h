/**
 * \file jatekos.h
 * Itt valósítjuk meg a játékos osztályt, itt a deklarációk, inline tagfüggvények vannak.
 * */

#ifndef JATEKOS_H_INCLUDED
#define JATEKOS_H_INCLUDED

#include "string5.h"
#include "targy.h"
using std::cout;
using std::endl;

class Jatekos{
	///Privát adattagok
public:
	/**
	 * Konstruktor
	 * @param nev - A játékos neve
	 * @param *t - a tárgy, amit használ
	 * */
       	Jatekos(String nev, Targy *t){}

	/**
	 * setItem - beállítja a (létező) játékos tárgyát
	 * @param *t - a tárgy, amit beállítunk neki
	 * */
	void setItem(Targy *t) {}

	String getNev() const;
	targyak  getTargy() const;

	///Destruktor
	~Jatekos() {}
};

#endif // JATEKOS_H_INCLUDED
