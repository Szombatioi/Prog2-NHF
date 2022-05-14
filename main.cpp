/**
 * \file main.cpp
 * A teszteseteket itt ellenõrizzük le.
*/
#include <iostream>
#include "gtest_lite.h"
#include "jatekos.hpp"
#include "naplo.h"
#include "ko.hpp"
#include "papir.hpp"
#include "ollo.hpp"
#include "memtrace.h"
#include "jatek.h"
#include <time.h>
using namespace std;

//#define MAIN
#define TESTING

/**
* test1 - betöltés fájlból
* Először egy nem létező fájlból olvasna, ekkor kivételt várunk.
* Ezután a már létező fájból olvasna, ami üres, ekkor azt várjuk, hogy hamissal térjen vissza
* Ezt követően a mentést próbáljuk meg, ekkor azt várjuk, hogy sikerüljön.
* Végül
*/
void test1(){
    Naplo n;
    Jatek jatekBetoltes(n);
    TEST(Load, "noFile"){
        EXPECT_THROW(jatekBetoltes.naplo.load(), const char*);
    } END

    TEST(Load, "fileExists"){
        std::ofstream saveFile("naplo.txt"); ///< Ezzel a sorral létrejön a fájl, még akkor is, ha ezelőtt nem létezett, viszont üres!
        saveFile.close();
        EXPECT_EQ(false, jatekBetoltes.naplo.load());
    } END

    TEST(Save, "fileExists"){
        jatekBetoltes.naplo.hozzaad(new Jatekos("Péter", NULL));
        jatekBetoltes.naplo.hozzaad(new Jatekos("András", NULL));
        jatekBetoltes.naplo.hozzaad(new Jatekos("József", NULL));
        EXPECT_EQ(true, jatekBetoltes.naplo.save());
    } END

    TEST(Load, "NormalLoad"){
        EXPECT_NO_THROW(jatekBetoltes.naplo.load());
    } END
}

/**
* test2 - Játékosok hozzáadása nyilvántartáshoz, (napló bővítése), napló ürítése és a legjobbak kiírása.
* Először egy nem létező játékost ad hozzá, ekkor azt várjuk, hogy sikerüljön, a program azt írja ki, hogy "Játékos felvéve".
* Ezután egy már létező játékos ad hozzá, ekkor nem várunk semmit.
* Ezt követően kiírjuk a top 10 (vagy annál kevesebb) legjobb játékost.
* Végül ürítjük a naplót, majd ezt követően az ismételt kiírásnál azt várjuk, hogy azt írja ki a program, hogy "Nincs játékos a naplóban"
* FIGYELEM: Ez a teszteset nem a gtest_lite-val fut.
*/
void test2(){
    Naplo n;
    n.hozzaad(new Jatekos("Németh Orsolya", NULL)); ///< "Játékos felvéve"
    n.hozzaad(new Jatekos("Németh Orsolya", NULL)); ///< Nincs kiírás, mert már létező játékos
    n.topkiir();
    n.urites();
    n.topkiir();
}

/**
* test3 - egy mérkőzés levezénylése
* Először ugyanazt a játékost adjuk meg mindkétszer a játékosok bekérésénél, itt kivételt várunk.
* Ezután ha nem érkezik kivétel (itt már különböző játékosokat adunk meg!), akkor jól levezényelt egy mérkőzést és jól frissítette a naplót
*/
void test3(){
    Naplo n;
    Jatek jatek(n);
    TEST(Demonstrate, SamePerson) {
        std::cout << "FIGYELEM: Ugyanazt a nevet adja meg mindkét játékosnál!\n";
        EXPECT_THROW(jatek.demonstrate(), const char*);
    } END

    TEST(Demonstrate, GoodVersion){
        EXPECT_NO_THROW(jatek.demonstrate());
    } END
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "hun"); ///CodeBlocksnál a konzol hibásan jeleníti meg a betűket, tesztelésre javasolt a Visual Studio használata vagy esetleg a Linuxon való futtatás
    #ifdef TESTING
    try{
        test1();
        test2();
        test3();
    } catch(std::exception& e) {cout << e.what() << endl;}
    catch(...) {cout << "Nagy a baj" << endl;}
    #endif // TEST

    #ifdef MAIN
    bool run = true;
    Naplo n(1);
    Jatek jatek(n);
    while(run){
        jatek.menu(run);
    }
    #endif // MAIN
    return 0;
}
