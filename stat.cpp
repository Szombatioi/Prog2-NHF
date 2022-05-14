/**
    \file stat.cpp
    Ebbe a fájlba kerül a Statisztika osztály tagfüggvényeinek megvalósítása.
*/

#include "stat.h"

/**
* frissit - Frissíti a játékos statisztikáját
* @param T - milyen tárgyat használt
* @param nyert - nyert-e a játékos
**/
void Stat::frissit(char T, bool nyert){
    if(nyert){
        gyozelmek++;
        if(taktika == "-") taktika = T;
        else taktika = taktika + T;
    }
    else{
        if(gyozelmek == 0){
            gyozelmek--;
            taktika = T;
        }
        else{
            gyozelmek = 0;
            taktika = "-";
        }
    }
}

/**
* getTaktika - visszaadja a játékos taktikáját
*/
String Stat::getTaktika() const {
    if(taktika == "") return "-"; ///< Ha nincs elmentett taktikája, akkor nem '-' jelet adunk vissza
    return taktika;
}

/**
 * setStat - átállítja a statisztikát egy meglévő statisztika alapján
 * @param s - A beállítandó statisztika
 */
void Stat::setStat(const Stat& s){
    gyozelmek = s.getGyozelmek();
    taktika = s.getTaktika();
}

/**
 * setStat - átállítja a statisztikát egy String alapján
 * @param str - A taktika String
 */
void Stat::setStat(const String& str){
    taktika = str;
    if(str == "-") gyozelmek = 0; ///<Ha nincs tárolt taktikája, akkor 0 értéket állít be
    else gyozelmek = str.size();
}

std::ostream& operator<<(std::ostream& os, const Stat& s){
    os << s.getTaktika();
    if(s.getTaktika() == "-") os << "(0)";
    else os << "(" << s.getGyozelmek() << ")";
    return os;
}
