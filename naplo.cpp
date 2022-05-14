/**
* \file naplo.cpp
* Ebbe a fájlba kerül a statisztikákat tároló napló osztály tagfüggvényeinek megvalósítása.
*/

#include "naplo.h"
#include <iostream>
#include <fstream>


///Copy ctor
Naplo::Naplo(const Naplo& naplo){
    stats = new Jatekos*[(size=naplo.getSize())];
    for(n = 0; n < naplo.getSize(); n++)
        stats[n] = naplo[n]->copy();
}

///=operátor
Naplo& Naplo::operator=(const Naplo& naplo){
    if(this != &naplo){
        delete[] stats;
        stats = new Jatekos*[(size = naplo.getSize())];
        for(n = 0; n < naplo.getSize(); n++)
            stats[n] = naplo[n]->copy();
    }
    return *this;
}

/**
* index - egy játékos helyét adja meg a tömbben
* Ha nincs benne, -1-gyel tér vissza
* @param j - A keresett játékos
*/
size_t Naplo::index(const Jatekos& j){
    for(size_t i = 0; i < n; i++){
        if(*stats[i] == j){
            return i; ///<Ha megegyezik a két játékos, akkor visszatér az aktuális index-szel
        }
    }
    return -1;
}

/**
 * load - Betölti a naplóban tárolt játékosokat a naplo.txt fájlból
 * Ha nem létezik, üres lesz a Napló
 * @return A sikerességtől függően igaz / hamis
 * */
bool Naplo::load(){
    std::ifstream loadFile;
    loadFile.open("naplo.txt");
    if(!loadFile.is_open()) throw "Nem letezik a naplo.txt!"; ///<Ha nem létezik a fájl, akkor kivételt dob

    size_t len;
    loadFile >> len; ///<Az első sor a játékosok számát tartalmazza
    if(len==0){
        std::cout << "Üres a fájl.\n"; ///< Üres fájl esetén nincs tömbváltoztatás
        loadFile.close();
        return false;
    }

    urites();   ///< Kiürítjük a tömböt
    delete[] stats; ///< Töröljük a tömböt
    stats = new Jatekos*[(size = len)]; ///< Új méretet foglalunk

    String nev, taktika;
    for(n = 0; n < len; n++){
        loadFile >> nev; ///< Beolvassuk a nevét
        loadFile >> taktika; ///< Beolvassuk a taktikáját
        Jatekos* tmp = new Jatekos(nev, NULL);
        stats[n] = tmp; ///< A napló megfelelő helyére betesszük a játékos pointerét
        if(taktika == "-"){
            stats[n]->setStat("");
        }
        else stats[n]->setStat(taktika); ///< Beállítjuk a taktikáját
    }
    loadFile.close();
    std::cout << "Adatok betöltve\n";
    return true;
}

/**
 * save - Elmenti a napló adatait a naplo.txt fájlba (felülírja)
 * Ha nem létezik a txt fájl, generál egyet.
 * @return A sikerességtől függően igaz / hamis
 * */
bool Naplo::save(){
    sort(); ///< Rendezzük a tömböt növekvő sorrendbe
    std::ofstream saveFile("naplo.txt");
    if(saveFile.fail()) return false;
    saveFile << n << "\n"; ///< Először a játékosok számát írjuk bele
    for(size_t i = 0; i < n; i++)
        saveFile << stats[i]->getNev() << " " << stats[i]->getStat().getTaktika() << "\n"; ///< Nev Taktika formátumban írjuk ki
    saveFile.close();
    std::cout << "Mentve\n";
    return true;
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
        Jatekos** temp = new Jatekos*[(size += 10)]; ///< 10-zel megnöveljük a napló méretét
        if(temp == NULL) throw "Nem bővíthető a napló!";
        for(size_t i = 0; i < n; i++){
            temp[i] = stats[i]; ///< Átmásoljuk az elemeket
        }
        delete[] stats; ///< A régi tömböt töröljük
        stats = temp; ///< Átállítjuk a pointert
    }
    if(!benneVan(*j)){
        stats[n++] = j; ///< Ha nincs benne a játékos és nincs tele a napló, akkor csak hozzáteszi
        std::cout << "Játékos felvéve\n";
    }
    else{
        size_t idx = index(*j);
        Stat tempStat = stats[idx]->getStat();
        delete stats[idx];
        stats[idx] = j;
        stats[idx]->setTargy(j->getTargy());
        stats[idx]->setStat(tempStat);
    }
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
    n = 0;
}

/**
* sort - rendezi a tömböt növekvő sorrendbe
* A top 10 kiírása előtt mindig rendez.
* A selection sort elvén alapszik.
*/
void Naplo::sort(){
    size_t max;
    if(n==0) return; ///< Üres tömb esetén nincs mit csinálni
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
void Naplo::topkiir(){
    if(n == 0){
        std::cout << "Nincs játékos a naplóban.\n"; ///< Ha nincs játékos a naplóban, akkor nincs értelme sort-olni vagy kiírni
        return;
    }
    sort(); ///< Rendezés
    std::cout << "A top 10 legjobb játékos:\n";
    size_t max = (n >= 10) ? 10 : n; ///< Ha nincs legalább 10 játékos, akkor csak az n méretéig megyünk el
    for(size_t i = 0; i < max; i++)
        std::cout << *stats[i] << "\n";
}
