/**
 * \file jatek.h
 * Itt valósul meg a mérkőzések demonstrálására használt jatek osztály.
 * Ebben a fájlban vannak a függvények deklarációi és az inline
 * függvények megvalósításai.
 * */

#ifndef JATEK_H_INCLUDED
#define JATEK_H_INCLUDED

class Game{
	///Privát adattagok
	bool gyoz(const Targy& lhs, const Targy& rhs) const;
public:
	///Konstruktor - Ez hozza létre a naplót
	Jatek() {}

	/**
	 * load - Betölti a naplóban tárolt játékosokat a naplo.txt fájlból
	 * Ha nem létezik, üres lesz a Napló
	 * */
	void load() {}

	/**
	 * save - Elmenti a napló adatait a naplo.txt fájlba (felülírja)
	 * Ha nem létezik a txt fájl, generál egyet.
	 * */
	void save() {}

	/**
	 * demonstrate - Demonstrál egy mérkőzést.
	 * Bekéri mindkét játékos nevét, esetlegesen felveszi őket a nyilvántartásba.
	 * Frissíti a naplót és a játékosok statisztikáit.
	 * */
	void demonstrate() {}
};

#endif // JATEK_H_INCLUDED
