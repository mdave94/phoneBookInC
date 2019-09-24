#ifndef FAJLKEZELES_H_INCLUDED
#define FAJLKEZELES_H_INCLUDED
#include <string>
#include "lista.hpp"
#include "Bejegyzes.h"
//#include "memtrace.h"

using std::string;
class Fajlkezeles{
    string fajlnev;
public:
    Fajlkezeles(string fajlnev): fajlnev(fajlnev){}
    Lista<Bejegyzes> beolvas();
    void kiir(Lista<Bejegyzes> b);
};


#endif // FAJLKEZELES_H_INCLUDED
