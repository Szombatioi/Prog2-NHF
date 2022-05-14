/**
* \file naplo.cpp
* Ebbe a fájlba kerül a statisztikákat tároló napló osztály tagfüggvényeinek megvalósítása.
*/

#include "naplo.h"
#include <iostream>
#include <fstream>

/**
 * load - Betölti a naplóban tárolt játékosokat a naplo.txt fájlból
 * Ha nem létezik, üres lesz a Napló
 * */
void Naplo::load(){
    std::ifstream loadFile("naplo.txt");
    if(loadFile.fail()) throw "Nem letezik a naplo.txt!";
    loadFile.close();
}

/**
 * save - Elmenti a napló adatait a naplo.txt fájlba (felülírja)
 * Ha nem létezik a txt fájl, generál egyet.
 * */
void Naplo::save(){
    std::ofstream saveFile("naplo.txt");
    saveFile << n << "\n";
    for(size_t i = 0; i < n; i++)
        saveFile << *stats[i] << "\n";
    saveFile.close();
}


/**
* benneVan - Eldönti, hogy benne van-e egy játékos már a naplóban.
* Privát függvény, csak arra kell, hogy a hozzaad() függvény tudjon dolgozni.
* @param j - A keresett játékos
* @return Ha benne van, igaz, ellenkező esetben hamis.
**/
bool Naplo::benneVan(const Jatekos& j) const{
    for(size_t i = 0; i < n; i++){
        if(j == *stats[i]){
            return true;    ///< Ha a napló valamelyik eleme megegyezik ezzel a játékossal, akkor benne van
        }
    }

    return false;
}

/**
 * hozzaad - hozzáad egy új játékost a naplóhoz.
 * Először megnézi, hogy benne van-e, ha nincs, hozzáadja, ha igen, akkor nem csinál semmit
 * @param j A betenni kívánt játékos
 * */
void Naplo::hozzaad(Jatekos* j){
    if(n>=size){ ///< Ha megtelik a napló...
        Jatekos** temp = new Jatekos*[(size+=10)]; ///< 10-zel megnöveljük a napló méretét
        for(size_t i = 0; i < n; i++){
            temp[i] = stats[i]; ///< Átmásoljuk az elemeket
        }
        delete[] stats; ///< A régi tömböt töröljük
        stats = temp; ///< Átállítjuk a pointert
    }
    if(!benneVan(*j))
        stats[n++] = j; ///< Ha nincs benne a játékos és nincs tele a napló, akkor csak hozzáteszi

}

/**
 * frissit - Frissíti a napló tartalmát aszerint, hogy nyert-e az adott játékos vagy sem.
 * @param j - A frissítendő játékos
 * @param nyert - logikai változó, azt tárolja, hogy nyert-e a játékos vagy vesztett.
 * */
void Naplo::frissit(Jatekos* j, bool nyert){
    if(!benneVan(*j)){
        hozzaad(j); ///< Ha nincs benne a játékos, akkor hozzáveszi
    }
    j->frissit(j->getTargy()->getBetu(), nyert);    ///< Frissíti a statisztikát
}

/**
 * urites - Törli a napló teljes tartalmát.
 * */
void Naplo::urites(){
    for(size_t i = 0; i < n; i++)
        delete stats[i];
}

/**
* sort - rendezi a tömböt növekvő sorrendbe
* A top 10 kiírása előtt mindig rendez.
* A selection sort elvén alapszik.
*/
void Naplo::sort(){
    size_t max;
    for(size_t i = 0; i < n-1; i++){
        max = i;
        for(size_t j = i+1; j < n; j++){
            if(stats[j]->getStat().getGyozelmek() > stats[max]->getStat().getGyozelmek()) max = j;
        }
        if(max != i){
            Jatekos* temp = stats[max];
            stats[max] = stats[i];
            stats[i] = temp;
        }
    }
}

/**
 * topkiir - Kiírja a 10 legjobb játékos statisztikáját növekvő sorrendben.
 * Először rendezi a listát növekvő sorrendbe a sort() függvénnyel.
 * @param os - A stream, amire ki akarunk írni
 * */
void Naplo::topkiir(std::ostream& os){
    sort(); ///< Rendezés
    os << "A top 10 legjobb játékos:\n";
    size_t max = (n >= 10) ? 10 : n;
    for(size_t i = 0; i < max; i++)
        os << *stats[i] << "\n";
}
