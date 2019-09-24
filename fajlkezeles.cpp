#include "fajlkezeles.h"
#include <fstream>
#include <iostream>
//#include "memtrace.h"

using namespace std;

Lista<Bejegyzes> Fajlkezeles::beolvas(){
    ifstream file;
    file.open(fajlnev.c_str(), ios::in);
    string nev, becenev, cim, munkasz, privsz;
    Lista<Bejegyzes> uj;
    //cin.ignore();

    while(
        std::getline(file, nev) &&
        std::getline(file, becenev) &&
        std::getline(file, cim) &&
        std::getline(file, munkasz) &&
        std::getline(file, privsz)
    )
        uj.beszur(Bejegyzes(nev, becenev, cim, munkasz, privsz));

    file.close();

    return uj;

}

void Fajlkezeles::kiir(Lista<Bejegyzes> b){
    ofstream file;
    file.open(fajlnev.c_str(), ios::out | ios::trunc);
    try{
    for(Lista<Bejegyzes>::iterator i = b.begin(); i != b.end(); i++)
        i->listaz(file);
    }
    catch(std::out_of_range e){
        cout << "valami baj van. " << e.what() << endl;
    }


    file.close();
}
