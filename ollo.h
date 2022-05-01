/**
    \file ollo.h
    Ebbe a f�jlba ker�l az oll� aloszt�ly deklar�ci�i, inline tagf�ggv�nyei.
*/

#ifndef OLLO_H_INCLUDED
#define OLLO_H_INCLUDED

#include "string5.h"
using std::cout;
using std::endl;

class Ollo : public Targy{
	///priv�t adattagok
public:
	/**
	 * Konstruktor
	 * @param nev - A t�rgy neve, az �soszt�ly ctor-j�nak h�v�s�hoz kell
	 **/
	Ollo(const String& nev) {}

	targyak getTargy() const;
	targyak getCounter() const;

	///Destruktor
	~Ollo() {}
};

#endif // OLLO_H_INCLUDED
