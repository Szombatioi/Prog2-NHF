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

String Stat::getTaktika() const {
    if(taktika == "") return "-";
    return taktika;
}

void Stat::setStat(const Stat& s){
    gyozelmek = s.getGyozelmek();
    taktika = s.getTaktika();
}

void Stat::setStat(const String& str){
    taktika = str;
    if(str == "-") gyozelmek = 0;
    else gyozelmek = str.size();
}

std::ostream& operator<<(std::ostream& os, const Stat& s){
    os << s.getTaktika();
    if(s.getTaktika() == "-") os << "(0)";
    else os << "(" << s.getGyozelmek() << ")";
    return os;
}
