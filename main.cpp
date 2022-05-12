/**
 * \file main.cpp
 * A teszteseteket itt ellenõrizzük le.
*/
#include <iostream>
#include "gtest_lite.h"
#include "jatekos.hpp"
#include "naplo.h"
#include "ko.hpp"
#include "memtrace.h"
using namespace std;

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


//    setlocale(LC_ALL, "hun"); ///CodeBlocksnál a konzol hibásan jeleníti meg a betûket, tesztelésre javasolt a Visual Studio használata
//    try{
//        int n;
//        cin >> n;
//        switch(n){
//        case 1:
//            test1();
//            break;
//        case 2:
//            test2();
//            break;
//        case 3:
//            test3();
//            break;
//        default:
//            cout << "Hibás bemenet!";
//        }
//    } catch(std::exception& e) {cout << e.what() << endl;}
//    catch(...) {cout << "Nagy a baj" << endl;}

    try{
        Naplo n(100);
        Jatekos* p = new Jatekos(String("Peter"), new Ko("Kő"));
        n.hozzaad(p);
        n.topkiir(std::cout);
        std::cout << "Új kör\n";
        n.frissit(p, true);
        n.topkiir(std::cout);
    } catch(...){
        std::cout << "O-ó baj van\n";
    }
    return 0;
}
