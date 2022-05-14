/**
 * \file jatekos.h
 * Itt valósítjuk meg a játékos osztályt, itt a deklarációk, inline tagfüggvények vannak.
 * */

#ifndef JATEKOS_HPP_INCLUDED
#define JATEKOS_HPP_INCLUDED

#include "string5.h"
#include "targy.hpp"
#include "stat.h"

/**
* A Játékos osztály.
* Egy játékos adatait tárolja (név, használt tárgy).
*/
class Jatekos{
	//Privát adattagok
	String nev; ///< A játékos neve
	Targy* targy; ///< A játékos tárgya
	Stat stat; ///<A játékos statisztikája;
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
	inline void setItem(Targy *t) { delete targy; targy = t; }

	/**
	* getNev - Visszaadja a játékos nevét
	*/
	String getNev() const {return nev;}

	/**
	* getTargy - Visszaadja a játékos tárgyának típusát.
	* Ez lehet KO, PAPIR vagy OLLO
	*/
	targyak getTargyType() const {return targy->getTargy();}

	/**
	* getStat - visszaadja a játékos statisztikáját
	*/
	Stat getStat() const {return stat;}

	/**
	 * getTargy - visszaadja a játékos tárgyát
	 * */
	Targy* getTargy() const {return targy;}

	void frissit(char T, bool nyert){
        stat.frissit(T, nyert);
	}

	/**
	 * A játékosok összehasonlításához == operator overload
	 * @param j A másik játékos
	 * @return igaz, ha megegyeznek, egyébként hamis
	 */
	bool operator==(const Jatekos& j) const{
        return nev==j.getNev();
	}

	///Destruktor
	~Jatekos() { delete targy; }
};

/**
* Kiíratáshoz << operátor overload
* @param os - A kiíráshoz használt stream
* @param j - A kiírandó játékos (statisztikája)
*/
inline std::ostream& operator<<(std::ostream& os, const Jatekos& j){
     return os << j.getNev() << " - " << j.getStat().getTaktika() << " (" << j.getStat().getTaktika().size() << ")";
 }

#endif // JATEKOS_HPP_INCLUDED
