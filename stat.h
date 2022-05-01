/**
 * \file stat.h
 * Itt valósul meg a statisztikák tárolására alkalmas stat osztály. 
 * Ebben a fájlban a függvények deklarációi szereplnek, illetve az inline tagfüggvények.
 */

#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED

#include "string5.h"
#include "jatekos.h"

using std::cout;
using std::endl;


class Stat{
	///Privát adattagok
public:
	/**
	 * Konstruktor
	 * @param j - A játékos, akinek az adatait tároljuk
	 * */
	Stat(const Jatekos& j) {}

	/**
	 * frissit - Frissíti a játékos statisztikáját
	 * @param T - milyen tárgyat használt
	 * @param nyert - nyert-e a játékos
	 * */
	void frissit(char T, bool nyert) {}

	///Destruktor
	~Stat() {}
};

#endif
