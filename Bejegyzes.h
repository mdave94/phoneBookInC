#ifndef TELEFONKONYV_H_INCLUDED
#define TELEFONKONYV_H_INCLUDED

#include <iostream>
//#include "memtrace.h"
using std::string;

class Bejegyzes{
    string nev;
    string becenev;
    string cim;
    string munkasz;
    string privsz;
public:
    Bejegyzes(string nev ="", string becenev ="", string cim ="", string munkasz="", string privsz =""): nev(nev), becenev(becenev), cim(cim), munkasz(munkasz), privsz(privsz){}
    void listaz(std::ostream& os) const {os << nev << std::endl << becenev << std::endl << cim << std::endl << munkasz << std::endl << privsz << std::endl;}
    bool operator<(const Bejegyzes& b) const {return nev < b.nev;}
    string getnev(){return nev;}
};


#endif // TELEFONKONYV_H_INCLUDED
