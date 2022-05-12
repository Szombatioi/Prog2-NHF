/**
* \file naplo.cpp
* Ebbe a fájlba kerül a statisztikákat tároló napló osztály tagfüggvényeinek megvalósítása.
*/

//#include <iostream>
#include "naplo.h"

/**
* benneVan - Eldönti, hogy benne van-e egy játékos már a naplóban.
* Privát függvény, csak arra kell, hogy a hozzaad() függvény tudjon dolgozni.
* @param j - A keresett játékos
* @return Ha benne van, igaz, ellenkező esetben hamis.
**/
bool Naplo::benneVan(const Jatekos& j) const{
    for(size_t i = 0; i < n; i++)
        if(j == *stats[i])
            return true;
    return false;
}

/**
 * hozzaad - hozzáad egy új játékost a naplóhoz.
 * Először megnézi, hogy benne van-e, ha nincs, hozzáadja, ha igen, akkor nem csinál semmit
 * @param j A betenni kívánt játékos
 * */
void Naplo::hozzaad(Jatekos* j){
    if(n>=size) throw "Megtelt a napló!"; // delete j
    if(!benneVan(*j))
        stats[n++] = j;
}

/**
* index - egy játékos helyét adja meg a tömbben
* Ha nincs benne, -1-gyel tér vissza
* @param j - A keresett játékos
*/
size_t Naplo::index(const Jatekos& j){
    for(size_t i = 0; i < n; i++){
        if(*stats[i] == j){
            return i;
        }
    }
    return -1;
}

/**
 * frissit - Frissíti a napló tartalmát aszerint, hogy nyert-e az adott játékos vagy sem.
 * @param j - A frissítendő játékos
 * @param nyert - logikai változó, azt tárolja, hogy nyert-e a játékos vagy vesztett.
 * */
void Naplo::frissit(Jatekos* j, bool nyert){
    if(!benneVan(*j)){
        std::cout << "NINCS BENNE??\n";
        hozzaad(j);
    }
    //j->getStat().frissit(j->getTargy()->getBetu(), nyert);
    std::cout << "Magically frissült\n";
}

/**
 * urites - Törli a napló teljes tartalmát.
 * */
void Naplo::urites(){
    for(size_t i = 0; i < n; i++)
        delete stats[i];
}

/**
* sort - növekvő sorrendbe rendezi a tömb elemeit
*/
void Naplo::sort(){
    size_t min;
    for(size_t i = 0; i < n-1; i++){
        min = i;
        for(size_t j = i+1; j < n; j++){
            if(stats[j]->getStat().getGyozelmek() < stats[min]->getStat().getGyozelmek()) min = j;
        }
        if(min != i){
            Jatekos* temp = stats[min];
            stats[min] = stats[i];
            stats[i] = temp;
        }
    }
}

/**
 * topkiir - Kiírja a 10 legjobb játékos statisztikáját növekvő sorrendben.
 * Először rendezi a listát növekvő sorrendbe a sort() függvénnyel.
 * */
void Naplo::topkiir(std::ostream& os){
    Naplo::sort();
    size_t max = (n >= 10) ? 10 : n;
    for(size_t i = 0; i < max; i++)
        os << *stats[i] << "\n";
}
