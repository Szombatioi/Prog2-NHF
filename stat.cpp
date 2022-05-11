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
