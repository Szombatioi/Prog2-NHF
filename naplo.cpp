/**
* \file naplo.cpp
* Ebbe a fájlba kerül a statisztikákat tároló napló osztály tagfüggvényeinek megvalósítása.
*/

#include <iostream>
#include "naplo.h"

/**
* benneVan - Eldönti, hogy benne van-e egy játékos már a naplóban.
* Privát függvény, csak arra kell, hogy a hozzaad() függvény tudjon dolgozni.
* @param j - A keresett játékos
* @return Ha benne van, igaz, ellenkezõ esetben hamis.
**/
bool Naplo::benneVan(const Jatekos& j) const{
    for(size_t i = 0; i < n; i++)
        if(j == stats[i]->getJatekos())
            return true;
    return false;
}

/**
 * hozzaad - hozzáad egy új játékost a naplóhoz.
 * Elõször megnézi, hogy benne van-e, ha nincs, hozzáadja, ha igen, akkor nem csinál semmit
 * @param j A betenni kívánt játékos
 * */
void Naplo::hozzaad(const Jatekos& j){
    if(n>=size) throw "Megtelt a napló!";
    if(!benneVan(j))
        stats[n++] = new Stat(j);
}

/**
* index - egy játékos helyét adja meg a tömbben
* Ha nincs benne, -1-gyel tér vissza
* @param j - A keresett játékos
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
 * frissit - Frissíti a napló tartalmát aszerint, hogy nyert-e az adott játékos vagy sem.
 * @param j - A frissítendõ játékos
 * @param nyert - logikai változó, azt tárolja, hogy nyert-e a játékos vagy vesztett.
 * */
void Naplo::frissit(const Jatekos& j, bool nyert){
    if(!benneVan(j)){
        hozzaad(j);
    }

}

/**
 * urites - Törli a napló teljes tartalmát.
 * */
void Naplo::urites(){
    for(size_t i = 0; i < n; i++)
        delete stats[i];
}

/**
* Kiíratáshoz << operátor overload
* @param os - A kiíráshoz használt stream
* @param s - A kiírandó statisztika
*/
std::ostream& operator<<(std::ostream& os, const Stat& s){
    return os << s.getJatekos().getNev() << " - " << s.getTaktika() << " (" << s.getTaktika().size() << ")";
}

/**
 * topkiir - Kiírja a 10 legjobb játékos statisztikáját.
 * */
void Naplo::topkiir(){
    size_t max = (n >= 10) ? 10 : n;
    for(size_t i = 0; i < max; i++)
        std::cout << stats[i] << "\n";
}
