/**
 * \file stat.h
 * Itt valósul meg a statisztikák tárolására alkalmas stat osztály.
 * Ebben a fájlban a függvények deklarációi szereplnek, illetve az inline tagfüggvények.
 */

#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED

#include "string5.h"

/**
* A Statisztika osztály.
* Egy játékos adatait tartalmazza a mérkőzéseket illetően.
*/
class Stat{
	//Privát adattagok
    int gyozelmek; ///< A győzelmi sorozatának száma (lehet negatív is)
    String taktika; ///< A játékos taktikája széria esetén
public:
	/**
	 * Konstruktor
	 * */
	Stat() : gyozelmek(0), taktika("") {}

    int getGyozelmek() const {return gyozelmek;}

	/**
	* getTaktika - visszaadja a játékos taktikáját
	*/
	String getTaktika() const;

	/**
	 * setStat - átállítja a statisztikát egy meglévő statisztika alapján
	 * @param s - A beállítandó statisztika
	 */
	void setStat(const Stat& s);

	/**
	 * setStat - átállítja a statisztikát egy String alapján
	 * @param str - A taktika String
	 */
	void setStat(const String& str);

	/**
	* frissit - Frissíti a játékos statisztikáját
	* @param T - milyen tárgyat használt
	* @param nyert - nyert-e a játékos
	**/
	void frissit(char T, bool nyert);
};

///<< operator kiíráshoz
std::ostream& operator<<(std::ostream& os, const Stat& s);


#endif
