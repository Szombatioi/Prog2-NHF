/**
 * \file naplo.h
 * Ebbe a fájlba kerül a statisztikákat tároló napló osztály deklarációi, inline tagfüggvényei.
 */


#ifndef NAPLO_H_INCLUDED
#define NAPLO_H_INCLUDED

#include "jatekos.hpp"

/**
* BOOL - saját logikai típus mérkőzések lezárására.
* TRUE az igaz, FALSE a hamis és DRAW a döntetlen
*/
enum BOOL {
    DRAW = -1, TRUE = 1, FALSE = 0
};


/**
* Naplo osztály - A játékosok statisztikáit tároljuk benne
*/
class Naplo{
    //Privát adattagok
    size_t size; ///< A napló maximális mérete (egyszer állítható)
    size_t n; ///< A naplóban az adattal feltöltött hely
    Jatekos** stats; ///< A statisztikákat tároló kollekció

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
	Naplo(size_t siz = 0) : size(siz), n(0) {
        stats = new Jatekos*[size]; ///< Dinamikusan lefoglaljuk a kívánt méretű helyet
	}

	///Copy ctor
	Naplo(const Naplo& naplo);

	///=operátor
    Naplo& operator=(const Naplo& naplo);

    /**
	 * load - Betölti a naplóban tárolt játékosokat a naplo.txt fájlból
	 * Ha nem létezik, üres lesz a Napló
	 * @return A sikerességtől függően igaz / hamis
	 * */
	bool load();

	/**
	 * save - Elmenti a napló adatait a naplo.txt fájlba (felülírja)
	 * Ha nem létezik a txt fájl, generál egyet.
	 * @return A sikerességtől függően igaz / hamis
	 * */
	bool save();

	/**
	* getSize - a naplóban tárolt elemeket adja vissza
	* @return n - Ahány ember benne van a naplóban
	*/
	size_t getSize() const {return n;}

	/**
	* index - egy játékos helyét adja meg a tömbben
	* Ha nincs benne, -1-gyel tér vissza
	* @param j - A keresett játékos
	*/
	size_t index(const Jatekos& j);

	/// [] operátor indexeléshez
    Jatekos* operator[](size_t i) {return stats[i];}
    /// konstans [] operátor indexeléshez
    Jatekos* const operator[](size_t i) const {return stats[i];}

	/**
	 * hozzaad - hozzáad egy új játékost a naplóhoz.
	 * Először megnézi, hogy benne van-e, ha nincs, hozzáadja, ha igen, akkor nem csinál semmit
	 * @param j A betenni kívánt játékos
	 * */
	void hozzaad(Jatekos* j);

	/**
	 * frissit - Frissíti a napló tartalmát aszerint, hogy nyert-e az adott játékos vagy sem.
	 * @param j - A frissítendő játékos
	 * @param nyert - logikai változó, azt tárolja, hogy nyert-e a játékos vagy vesztett.
	 * */
	void frissit(Jatekos* j, bool nyert);

	/**
	 * urites - Törli a napló teljes tartalmát.
	 * */
	void urites();

	/**
	 * topkiir - Kiírja a 10 legjobb játékos statisztikáját.
	 * */
	void topkiir();

	/**
	* sort - rendezi a tömböt növekvő sorrendbe
	* A top 10 kiírása előtt mindig rendez.
	* A selection sort elvén alapszik.
	*/
	void sort();

	///Destruktor
	~Naplo() { urites(); delete[] stats;}
};

#endif // DIARY_H_INCLUDED
