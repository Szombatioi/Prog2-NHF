/**
 * \file jatekos.h
 * Itt valósítjuk meg a játékos osztályt, itt a deklarációk, inline tagfüggvények vannak.
 * */

#ifndef JATEKOS_HPP_INCLUDED
#define JATEKOS_HPP_INCLUDED

#include "string5.h"
#include "targy.hpp"
#include "stat.h"
#include "memtrace.h"

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
    Jatekos(const String& n, Targy *t) : nev(n), targy(t) {}

    ///Copy ctor
    Jatekos(const Jatekos& j){
        nev = j.getNev();
        targy = j.getTargy()->copy();
        stat = j.getStat();
    }

    ///copy fv, napló feltöltéshez
    Jatekos* copy() {
        return new Jatekos(*this);
    }

	/**
	 * setItem - beállítja a (már létező) játékos tárgyát
	 * @param *t - a tárgy, amit beállítunk neki
	 * */
	inline void setTargy(Targy *t) { targy = t; }

	/**
	* getNev - Visszaadja a játékos nevét
	*/
	String getNev() const {return nev;}

	/**
	* getStat - visszaadja a játékos statisztikáját
	*/
	Stat getStat() const {return stat;}

	/**
	 * setStat - Beállítja a játékos statisztikáját egy meglévő statisztika alapján
	 * @param s - A statisztika, amit beállítunk
	 */
    void setStat(const Stat& s){
        stat.setStat(s);
    }

	/**
	 * setStat - Beállítja a játékos statisztikáját egy String alapján
	 * @param str - A taktika String
	 */
    void setStat(const String& str){
        stat.setStat(str);
    }

	/**
	 * getTargy - visszaadja a játékos tárgyát
	 * */
	Targy* getTargy() const {return targy;}

	/**
	 * frissit - Frissíti a játékos statisztikáját
	 * @param T - A tárgyának betűje
	 * @param nyert - Megnyerte-e a játékos a mérkőzést
	 */
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
     return os << j.getNev() << " - " << j.getStat();
 }

#endif // JATEKOS_HPP_INCLUDED
