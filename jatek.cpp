/**
 * \file jatek.cpp
 * Itt valósulnak meg a mérkõzések demonstrálására használt jatek osztály tagfüggvényei.
 * Ebben a fájlban vannak a függvények megvalósításai.
 * */

#include "jatek.h"

/**
* gyoz - eldönti két tárgy közül, hogy melyik nyer.
* Privát függvény, mivel csak a demonstrációknál kell használni.
*/
BOOL Jatek::gyoz(const Targy& lhs, const Targy& rhs) const{
    if(lhs.getTargy() == rhs.getTargy()) return DRAW; ///< Azonos tárgyak
    else if(lhs.getTargy() == KO && rhs.getTargy() == PAPIR) return FALSE; ///< KO vs. PAPIR
    else if(lhs.getTargy() == KO && rhs.getTargy() == OLLO) return TRUE; ///< KO vs. OLLO
    else if(lhs.getTargy() == PAPIR && rhs.getTargy() == OLLO) return FALSE; ///< PAPIR vs. OLLO
    else if(lhs.getTargy() == PAPIR && rhs.getTargy() == KO) return TRUE; ///< PAPIR vs. KO
    else if(lhs.getTargy() == OLLO && rhs.getTargy() == PAPIR) return TRUE; ///< OLLO vs. PAPIR
    else return FALSE; ///< OLLO vs. KO
}

/**
 * demonstrate - Demonstrál egy mérkõzést.
 * Bekéri mindkét játékos nevét, esetlegesen felveszi õket a nyilvántartásba.
 * Frissíti a naplót és a játékosok statisztikáit.
 * */
void Jatek::demonstrate(){

}
