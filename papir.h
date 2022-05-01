/**
    \file papir.h
    Ebbe a f�jlba ker�l a pap�r aloszt�ly deklar�ci�i, inline tagf�ggv�nyei.
*/


#ifndef PAPIR_H_INCLUDED
#define PAPIR_H_INCLUDED

#include "string5.h"
#include "targy.h"
using std::cout;
using std::endl;

class Papir : public Targy{
	///priv�t adattagok
public:
	/**
	 * Konstruktor
	 * @param nev - A t�rgy neve, az �soszt�ly ctor-j�nak h�v�s�hoz kell
	 * */
	Papir(const String& nev) : Targy(nev) {}
	
	targyak getTargy() const;
	targyak getCounter() const;

	///Destruktor
	~Papir() {}
};

#endif // PAPIR_H_INCLUDED
