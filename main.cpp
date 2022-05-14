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
using namespace std;

#define MAIN
//#define TESTING

/**
* test1 - betöltés fájlból
* Először egy nem létező fájlból olvasna, ekkor false értéket várunk.
* Ezután a megfelelő fájból olvasna, ekkor azt várjuk, hogy sikerüljön.
*/
void test1(){
//    Jatek jatekBetoltes;
//    TEST(Load, "noFile"){
//        EXPECT_THROW(jatekBetoltes.load("random.txt"), std::exception);
//    } END

//    TEST(Load, "fileExists"){
//        EXPECT_NO_THROW(jatekBetoltes.load("naplo.txt"));
//    } END
}

/**
* test2 - Játékosok hozzáadása nyilvántartáshoz.
* Először egy nem létező játékost ad hozzá, ekkor azt várjuk, hogy sikerüljön.
* Ezután egy már létező játékos ad hozzá, ekkor kivételt várunk.
* Végül azt várjuk, hogy túlindexelés miatt kivételt dobjon.
*/
void test2(){
//    Naplo n(2);
//    TEST(AddPlayer, "newPlayer"){
//        Targy *t = new Ko("Kő");
//        EXPECT_NO_THROW(n.hozzaad(new Jatekos(String("Peter"), t)));
//        delete t;
//    } END
//
//    TEST(AddPlayer, "existingPlayer"){
//        Targy *t = new Ko("Kő");
//        EXPECT_THROW(n.hozzaad(new Jatekos(String("Peter"), t)), std::exception);
//        delete t;
//    } END
//
//    TEST(AddPlayer, "outOfRange"){
//        Targy *t = new Papir("Papír");
//        ///Ő még beleférhet
//        n.hozzaad(new Jatekos(String("Andras"), t));
//        ///Ő már viszont nem
//        EXPECT_THROW(n.hozzaad(new Jatekos(String("Jozsef"), t)), std::out_of_range);
//        delete t;
//    } END
}

/**
* test3 - egy mérkőzés levezénylése
* Ha nem érkezik kivétel, akkor jól levezényelt egy mérkőzést és jól frissítette a naplót
*/
void test3(){
//    Jatek j;
//    j.load("naplo.txt");
//    j.demonstrate();
//    j.save("naplo.txt");
}

int main()
{
    #ifdef TESTING
    setlocale(LC_ALL, "hun"); ///CodeBlocksnál a konzol hibásan jeleníti meg a betűket, tesztelésre javasolt a Visual Studio használata
    try{
        int n;
        cout << "Adja meg a teszteset számát: (1,2,3) ";
        cin >> n;
        switch(n){
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        case 3:
            test3();
            break;
        default:
            cout << "Hibás bemenet!";
        }
    } catch(std::exception& e) {cout << e.what() << endl;}
    catch(...) {cout << "Nagy a baj" << endl;}
    #endif // TEST

    #ifdef MAIN
    try{
        Naplo n(1);
        Jatekos *p1 = new Jatekos("Peter", new Ko());
        Jatekos *p2 = new Jatekos("Andras", new Papir());
        Jatekos *p3 = new Jatekos("Jozsef", new Ollo());
        n.hozzaad(p1);
        n.hozzaad(p2);
        n.hozzaad(p3);
        n.frissit(p1, true);
        n.frissit(p1, false);
        n.frissit(p1, true);
        p1->setItem(new Papir());
        n.frissit(p1, true);
        n.frissit(p1, true);
        std::cout << n.getSize(); //3 a bővítés miatt
        Jatek jatek(&n);
        jatek.save();
    }catch(const char* s) {
        std::cout << s << std::endl;
    }
    catch(...){
        std::cout << "Error??" << "\n";
    }
    #endif // MAIN
    return 0;
}
