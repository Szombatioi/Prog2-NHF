/**
 * \file naplo.h
 * Ebbe a fájlba kerül a statisztikákat tároló napló osztály deklarációi, inline tagfüggvényei.
 */


#ifndef NAPLO_H_INCLUDED
#define NAPLO_H_INCLUDED

#include "jatekos.hpp"
#include "stat.h"

class Naplo{
    //Privát adattagok
    size_t size; ///< A napló maximális mérete (egyszer állítható)
    size_t n; ///< A naplóban az adattal feltöltött hely
    Stat* stats[]; ///< A statisztikákat tároló kollekció

	//TODO: stats dinamikus tömb legyen!

	/**
	 * benneVan - Eldönti, hogy benne van-e egy játékos már a naplóban.
	 * Privát függvény, csak arra kell, hogy a hozzaad() függvény tudjon dolgozni.
	 * @param j - A keresett játékos
	 * @return Ha benne van, igaz, ellenkező esetben hamis.
	 * */
	bool benneVan(const Jatekos& j) const;
public:
	/**
	 * Konstruktor
	 * @param size - Megadható a fix tömb mérete.
	 * */
	Naplo(size_t siz) : size(siz), n(0) {
        //stats = new Stat[siz]*;
	}

	/**
	 * hozzaad - hozzáad egy új játékost a naplóhoz.
	 * Először megnézi, hogy benne van-e, ha nincs, hozzáadja, ha igen, akkor nem csinál semmit
	 * @param j A betenni kívánt játékos
	 * */
	void hozzaad(const Jatekos& j);

	/**
	 * frissit - Frissíti a napló tartalmát aszerint, hogy nyert-e az adott játékos vagy sem.
	 * @param j - A frissítendő játékos
	 * @param nyert - logikai változó, azt tárolja, hogy nyert-e a játékos vagy vesztett.
	 * */
	void frissit(const Jatekos& j, bool nyert);

	/**
	 * urites - Törli a napló teljes tartalmát.
	 * */
	void urites();

	/**
	 * topkiir - Kiírja a 10 legjobb játékos statisztikáját.
	 * */
	void topkiir();

	/**
	* index - egy játékos helyét adja meg a tömbben
	* Ha nincs benne, -1-gyel tér vissza
	* @param j - A keresett játékos
	*/
    size_t index(const Jatekos& j);

	///Destruktor
	~Naplo() { urites(); /*delete[] stats;*/ }
};

/**
* Kiíratáshoz << operátor overload
*/
std::ostream& operator<<(std::ostream& os, const Stat& s);

#endif // DIARY_H_INCLUDED
