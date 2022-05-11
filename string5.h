#ifndef STRING_H
#define STRING_H
/**
 * \file string5.h
 *
 * Ez a fájl tartalmazza a
 *   - String osztály deklarációját
 *   - az inline függvényeket.
 */

#include <iostream>

#ifndef MEMTRACE
#error "definialja projekt szinten a MEMTARCE makrot!"
#endif // MEMTRACE

/**
 * A String osztály.
 * A 'pData'-ban vannak a karakterek (a lezáró nullával együtt), 'len' a hossza.
 * A hosszba nem számít bele a lezáró nulla.
 */
class String {
    char *pData;        ///< pointer az adatra
    size_t len;         ///< hossz lezáró nulla nélkül
public:
    /// Paraméter nélküli konstruktor:
    String() :pData(), len(0) {}

    /// Sztring hosszát adja vissza.
    /// @return sztring tényleges hossza (lezáró nulla nélkül).
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pointer a tárolt, vagy azzal azonos tartalmú nullával lezárt sztring-re.
    const char* c_str() const { return pData;}

    ///Ctor
    String(char c);
    ///Ctor
    String(const char* str);
    ///Copy
    String(const String& str);
    ///operator=
    String& operator=(const String& str);
    ///+ operator
    String operator+(char c) const;
    ///+ operator
    String operator+(const String& str) const;
    ///[] operator
    const char& operator[](size_t i) const;
    ///[] operator
    char& operator[](size_t i);
    ///== operator
    bool operator==(const String& str) const;
    ///Dtor
    ~String();

};

///char + str
String operator+(char c, const String& str);
///<< operator
std::ostream& operator<<(std::ostream& os, const String& str);
///>> operator
std::istream& operator>>(std::istream& is, String& s0);
#endif
