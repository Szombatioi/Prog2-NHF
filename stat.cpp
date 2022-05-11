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
        taktika = taktika + T;
    }
    else{
        if(gyozelmek == 0){
            gyozelmek--;
            taktika = taktika + T;
        }
        else{
            gyozelmek = 0;
            taktika = "";
        }
    }
}
