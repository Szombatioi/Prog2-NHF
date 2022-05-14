/**
 * \file jatek.cpp
 * Itt valósulnak meg a mérkõzések demonstrálására használt jatek osztály tagfüggvényei.
 * Ebben a fájlban vannak a függvények megvalósításai.
 * */

#include "jatek.h"

/**
* gyoz - eldönti két tárgy közül, hogy melyik nyer.
* Privát függvény, mivel csak a demonstrácknál kell használni.
* @param lhs - Az egyik (bal oldali) tárgy
* @param rhs - A másik (jobb oldali) tárgy
*/
BOOL Jatek::gyoz(targyak lhs, targyak rhs) const{
    if(lhs == rhs) return DRAW; ///< Azonos tárgyak
    else if(lhs == KO && rhs == PAPIR) return FALSE; ///< KO vs. PAPIR
    else if(lhs == KO && rhs == OLLO) return TRUE; ///< KO vs. OLLO
    else if(lhs == PAPIR && rhs == OLLO) return FALSE; ///< PAPIR vs. OLLO
    else if(lhs == PAPIR && rhs == KO) return TRUE; ///< PAPIR vs. KO
    else if(lhs == OLLO && rhs == PAPIR) return TRUE; ///< OLLO vs. PAPIR
    else return FALSE; ///< OLLO vs. KO
}

/**
 * getRandomTargy - egy véletlenszerű tárgyat ad vissza, játékosoknak ezeket állítjuk be
 * @return Targy* - A véletlenszerű tárgyat adja vissza
 */
Targy* Jatek::getRandomTargy(){
    int num = rand() % 3 + 1; ///< 1 és 3 közötti számot választ
    if(num == 1) return new Ko();
    else if(num == 2) return new Papir();
    else return new Ollo();
}

/**
 * demonstrate - Demonstrál egy mérkőzést.
 * Bekéri mindkét játékos nevét, esetlegesen felveszi őket a nyilvántartásba.
 * Frissíti a naplót és a játékosok statisztikáit.
 * */
void Jatek::demonstrate(){
    ///Első játékos bekérése
    std::cout << "Első játékos: ";
    String player1, player2;
    std::cin >> player1;
    Jatekos *lhs = new Jatekos(player1, getRandomTargy());
    naplo.hozzaad(lhs); ///<Első játékos felvétele a naplóba

    ///Második játékos bekérése
    std::cout << "Második játékos: ";
    std::cin >> player2;
    if(player2 == player1) throw "Nem játszhatunk önmagunkkal!";
    Jatekos *rhs = new Jatekos(player2, getRandomTargy());
    naplo.hozzaad(rhs); ///<Második játékos felvétele a naplóba

    std::cout << lhs->getNev() << " " << lhs->getTargy()->getNev() << " vs. " << rhs->getNev() << " " << rhs->getTargy()->getNev() << std::endl; ///<Harci szöveg kiírása

    BOOL gy = gyoz(lhs->getTargy()->getSelf(), rhs->getTargy()->getSelf()); ///<Eldönti, hogy ki nyeri a mérkőzést

    ///Statisztikák frissítése
    if(gy == TRUE){
        naplo.frissit(lhs, true); ///<Ő nyert
        naplo.frissit(rhs, false); ///<Ő vesztett
        std::cout << *lhs << " nyert!\n";
    }
    else if(gy == FALSE){
        naplo.frissit(lhs, false); ///Ő vesztett
        naplo.frissit(rhs, true); ///Ő nyert
        std::cout << *rhs << " nyert!\n";
    }
    else{
        std::cout << "Nincs nyertes!\n";
    }
}

/**
 * clearConsole - A menürendszer szépsége érdekében lehetőség van tisztítani a konzolt
 */
void clearConsole(){
    #if defined(__unix__) || defined(__linux__)
    system("clear");
    #elif defined(_WIN32) || defined(_WIN64)
    system("cls");
    #endif // _WIN32
}

/**
 * menu - Kiírja a menü lehetőségeit és végre is hajtja őket
 * @param run - A főmenüben a while ciklus feltétele a run változó. Ha hamis az értéke, véget ér a program
 */
void Jatek::menu(bool& run){
    std::cout << "1. Mérkőzés levezénylése\n2. Top 10 legjobb játékos kiírása\n3. Napló ürítése\n4. Játékos felvétele\n5. Visszatöltés fájlból\n6. Mentés\n7. Képernyő tisztítása\n9. Kilépés" << std::endl;
    int valasztas; ///<Eszerint a változó szerint hajtja végre a megfelelő sorszámú utasítást
    ///Ha nem stringet ad be, akkor újra kell próbálkoznia
    while(!(std::cin >> valasztas)){
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Hibás érték! Egész számot adjon meg!\n";
    }
    std::cin.ignore(100, '\n');
    switch(valasztas){
    case 1: ///< Játék levezénylése
        demonstrate();
        break;
    case 2: ///< Top 10 legjobb játékos kiírása
        naplo.topkiir();
        break;
    case 3: ///< Napló ürítése
        naplo.urites();
        break;
    case 4: ///< Játékos felvétele
        {
            std::cout << "Játékos neve: ";
            String tempStr;
            std::cin >> tempStr;
            Jatekos *tmp = new Jatekos(tempStr, NULL); ///<Beállítjuk az új játékost
            naplo.hozzaad(tmp); ///<Felvesszük a nyilvántartásba / frissítjuk a naplót
            break;
        }
    case 5: ///< Visszatöltés fájlból
        naplo.load();
        break;
    case 6: ///< Mentés
        naplo.save();
        break;
    case 7: ///< Képernyő tisztítása
        clearConsole();
        break;
    case 9: ///< Kilépés
        run = false;
        break;
    default: ///<Ha nem 1 és 9 \ {8} számot adnak meg
        std::cout << "Hibás érték!\n";
        break;
    }
    std::cout << "----------------------\n"; ///<Az átláthatóság kedvéért..
}
