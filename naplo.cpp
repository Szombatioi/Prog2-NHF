/**
* \file naplo.cpp
* Ebbe a f�jlba ker�l a statisztik�kat t�rol� napl� oszt�ly tagf�ggv�nyeinek megval�s�t�sa.
*/

#include <iostream>
#include "naplo.h"

/**
* benneVan - Eld�nti, hogy benne van-e egy j�t�kos m�r a napl�ban.
* Priv�t f�ggv�ny, csak arra kell, hogy a hozzaad() f�ggv�ny tudjon dolgozni.
* @param j - A keresett j�t�kos
* @return Ha benne van, igaz, ellenkez� esetben hamis.
**/
bool Naplo::benneVan(const Jatekos& j) const{
    for(size_t i = 0; i < n; i++)
        if(j == stats[i]->getJatekos())
            return true;
    return false;
}

/**
 * hozzaad - hozz�ad egy �j j�t�kost a napl�hoz.
 * El�sz�r megn�zi, hogy benne van-e, ha nincs, hozz�adja, ha igen, akkor nem csin�l semmit
 * @param j A betenni k�v�nt j�t�kos
 * */
void Naplo::hozzaad(const Jatekos& j){
    if(n>=size) throw "Megtelt a napl�!";
    if(!benneVan(j))
        stats[n++] = new Stat(j);
}

/**
* index - egy j�t�kos hely�t adja meg a t�mbben
* Ha nincs benne, -1-gyel t�r vissza
* @param j - A keresett j�t�kos
*/
size_t Naplo::index(const Jatekos& j){
    for(size_t i = 0; i < n; i++){
        if(stats[i]->getJatekos() == j){
            return i;
        }
    }
    return -1;
}

/**
 * frissit - Friss�ti a napl� tartalm�t aszerint, hogy nyert-e az adott j�t�kos vagy sem.
 * @param j - A friss�tend� j�t�kos
 * @param nyert - logikai v�ltoz�, azt t�rolja, hogy nyert-e a j�t�kos vagy vesztett.
 * */
void Naplo::frissit(const Jatekos& j, bool nyert){
    if(!benneVan(j)){
        hozzaad(j);
    }

}

/**
 * urites - T�rli a napl� teljes tartalm�t.
 * */
void Naplo::urites(){
    for(size_t i = 0; i < n; i++)
        delete stats[i];
}

/**
* Ki�rat�shoz << oper�tor overload
* @param os - A ki�r�shoz haszn�lt stream
* @param s - A ki�rand� statisztika
*/
std::ostream& operator<<(std::ostream& os, const Stat& s){
    return os << s.getJatekos().getNev() << " - " << s.getTaktika() << " (" << s.getTaktika().size() << ")";
}

/**
 * topkiir - Ki�rja a 10 legjobb j�t�kos statisztik�j�t.
 * */
void Naplo::topkiir(){
    size_t max = (n >= 10) ? 10 : n;
    for(size_t i = 0; i < max; i++)
        std::cout << stats[i] << "\n";
}
