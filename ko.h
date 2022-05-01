/**
    \file ko.h
    Ebbe a fájlba kerül a kő alosztály deklarációi, inline tagfüggvényei.
*/

#ifndef KO_H_INCLUDED
#define KO_H_INCLUDED


#include "targy.h"
using std::cout;
using std::endl;

class Ko : public Targy{
	///privát adattagok
public:
	/**
	 * Konstruktor
	 * @param nev - A tárgy neve, kiírásokhoz fog kelleni
	 * */
	Ko(String nev) : Targy(nev) {}
	
	targyak getTargy() const;
	targyak getCounter() const;

	///Destruktor
	~Ko() {}
};

#endif // KO_H_INCLUDED
