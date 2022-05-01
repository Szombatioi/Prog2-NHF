/**
 * \file naplo.h
 * Ebbe a fájlba kerül a statisztikákat tároló napló osztály deklarációi, inline tagfüggvényei.
 */


#ifndef NAPLO_H_INCLUDED
#define NAPLO_H_INCLUDED

#include "jatekos.h"
#include "stat.h"

class Naplo{
	/**
	 * benneVan - Eldönti, hogy benne van-e egy játékos már a naplóban.
	 * Privát függvény, csak arra kell, hogy a hozzaad függvény tudjon dolgozni.
	 * @param j - A keresett játékos
	 * @return Ha benne van, igaz, ellenkező esetben hamis.
	 * */
	bool benneVan(const Jatekos& j);
public:
	/**
	 * Konstruktor
	 * @param size - Megadható a fix tömb mérete.
	 * */
	Naplo(size_t size) {}

	/**
	 * hozzaad - hozzáad egy új játékost a naplóhoz.
	 * Először megnézi, hogy benne van-e, ha nincs, hozzáadja, ha igen, akkor nem csinál semmit
	 * @param j A betenni kívánt játékos
	 * */
	void hozzaad(const Jatekos& j) {}

	/**
	 * frissit - Frissíti a napló tartalmát aszerint, hogy nyert-e az adott játékos vagy sem.
	 * @param j - A frissítendő játékos
	 * @param nyert - logikai változó, azt tárolja, hogy nyert-e a játékos vagy vesztett.
	 * */
	void frissit(const Jatekos& j, bool nyert) {}
	
	/**
	 * urites - Törli a napló teljes tartalmát.
	 * */
	void urites(){}
	
	/**
	 * topkiir - Kiírja a 10 legjobb játékos statisztikáját.
	 * */
	void topkiir(){}

	///Destruktor
	~Naplo() {urites();}
};

#endif // DIARY_H_INCLUDED
