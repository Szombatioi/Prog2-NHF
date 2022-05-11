/**
 * \file stat.h
 * Itt valósul meg a statisztikák tárolására alkalmas stat osztály.
 * Ebben a fájlban a függvények deklarációi szereplnek, illetve az inline tagfüggvények.
 */

#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED

#include "string5.h"
#include "jatekos.h"

/**
* A Statisztika osztály.
* Egy játékos adatait tartalmazza a mérkőzéseket illetően.
*/
class Stat{
	//Privát adattagok
    Jatekos jatekos; ///< A játékos, akinek az adatait tárolja.
    int gyozelmek; ///< A győzelmi sorozatának száma (lehet negatív is)
    String taktika; ///< A játékos taktikája széria esetén
public:
	/**
	 * Konstruktor
	 * @param j - A játékos, akinek az adatait tároljuk
	 * */
	Stat(const Jatekos& j) : jatekos(j), gyozelmek(0), taktika("") {}

    //int getGyozelmek() const {return gyozelmek;}
    String getTaktika() const {return taktika;}
    Jatekos getJatekos() const {return jatekos;}

	/**
	 * frissit - Frissíti a játékos statisztikáját
	 * @param T - milyen tárgyat használt
	 * @param nyert - nyert-e a játékos
	 * */
	void frissit(char T, bool nyert);
};

#endif
