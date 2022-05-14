/**
    \file stat.cpp
    Ebbe a f�jlba ker�l a Statisztika oszt�ly tagf�ggv�nyeinek megval�s�t�sa.
*/

#include "stat.h"

/**
* frissit - Friss�ti a j�t�kos statisztik�j�t
* @param T - milyen t�rgyat haszn�lt
* @param nyert - nyert-e a j�t�kos
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
