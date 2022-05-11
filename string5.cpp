/**
 *
 * \file string5.cpp
 * A string osztály megvalósítása saját módszerekkel.
 */

#ifdef _MSC_VER
/// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <cstring>

#ifdef MEMTRACE
#include "memtrace.h" // a standard headerek után kell lennie
#endif
#include "string5.h"


///Konstruktor karakterből
String::String(char c) {
    pData = new char[(len = 1)+1];
    pData[0] = c;
    pData[1] = 0;
}

///Konstruktor karaktertömbből
String::String(const char* str) {
    pData = new char[(len = strlen(str)) + 1];
    strncpy(pData, str, len);
    pData[len] = '\0';
}

///Másoló konstruktor, String-ből készíti
String::String(const String& str) {
    pData = new char[(len = str.len) + 1];
    strncpy(pData, str.pData, len);
    pData[len] = 0;
}


///Destruktor
    String::~String() { delete[] pData; }

///= operátor
String& String::operator=(const String& str) {
    if (this != &str) {
        if(pData != NULL) delete[] pData;
        pData = new char[(len = str.len) + 1];
        strncpy(pData, str.pData, len);
        pData[len] = 0;
    }
    return *this;
}

///[] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza
const char& String::operator[](size_t i) const {
    if(i < 0 || i >= len) throw "Indexelesi hiba!"; /// indexhiba esetén const char * kivételt dob!
    return pData[i];
}

char& String::operator[](size_t i) {
    if(i < 0 || i >= len) throw "Indexelesi hiba!";
    return pData[i];
}

///+ operátor: String-hez jobbról karaktert ad
String String::operator+(char c) const {
    char* temp = new char[len + 2];
    strncpy(temp, pData, len);
    temp[len] = c;
    temp[len+1] = 0;
    String res(temp);
    delete[] temp;
    return res;
}

///+ operátor: String-hez String-et ad (addString)
String String::operator+(const String& str) const {
    char* temp = new char[len + str.len + 1];
    strncpy(temp, pData, len);
    strncat(temp, str.pData, str.len);
    temp[len + str.len] = 0;
    String res(temp);
    delete[] temp;
    return res;
}

///char-hoz String-et ad
String operator+(char c, const String& str){
    return String(c) + str;
}


///== operator
bool String::operator==(const String& str) const{
    return strncmp(this->c_str(), str.c_str(), this->size());
}

/// << operator, ami kiír az ostream-re
std::ostream& operator<<(std::ostream& os, const String& str){
    for(size_t i = 0; i < str.size(); i++){
        os<< str[i];
    }
    return os;
}

