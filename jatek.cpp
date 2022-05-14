/**
 * \file jatek.cpp
 * Itt val�sulnak meg a m�rk�z�sek demonstr�l�s�ra haszn�lt jatek oszt�ly tagf�ggv�nyei.
 * Ebben a f�jlban vannak a f�ggv�nyek megval�s�t�sai.
 * */

#include "jatek.h"

/**
* gyoz - eld�nti k�t t�rgy k�z�l, hogy melyik nyer.
* Priv�t f�ggv�ny, mivel csak a demonstr�ci�kn�l kell haszn�lni.
*/
BOOL Jatek::gyoz(const Targy& lhs, const Targy& rhs) const{
    if(lhs.getTargy() == rhs.getTargy()) return DRAW; ///< Azonos t�rgyak
    else if(lhs.getTargy() == KO && rhs.getTargy() == PAPIR) return FALSE; ///< KO vs. PAPIR
    else if(lhs.getTargy() == KO && rhs.getTargy() == OLLO) return TRUE; ///< KO vs. OLLO
    else if(lhs.getTargy() == PAPIR && rhs.getTargy() == OLLO) return FALSE; ///< PAPIR vs. OLLO
    else if(lhs.getTargy() == PAPIR && rhs.getTargy() == KO) return TRUE; ///< PAPIR vs. KO
    else if(lhs.getTargy() == OLLO && rhs.getTargy() == PAPIR) return TRUE; ///< OLLO vs. PAPIR
    else return FALSE; ///< OLLO vs. KO
}

/**
 * demonstrate - Demonstr�l egy m�rk�z�st.
 * Bek�ri mindk�t j�t�kos nev�t, esetlegesen felveszi �ket a nyilv�ntart�sba.
 * Friss�ti a napl�t �s a j�t�kosok statisztik�it.
 * */
void Jatek::demonstrate(){

}
