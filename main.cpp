#include <iostream>
#include "lista.hpp"
#include "bejegyzes.h"
#include "fajlkezeles.h"
#include <sstream>
//#include "memtrace.h"

using namespace std;

Bejegyzes adatfelvesz(std::ostream& os, std::istream& is){
    string nev, becenev, cim, munkasz, privsz;
    os << "Add meg a nevet: ";
    is >> nev;
    os << endl << "Add meg a becenevet: ";
    is >> becenev;
    os << endl << "Add meg a cimet: ";
    is >> cim;
    os << endl << "Add meg a munkahelyi telefonszamot: ";
    is >> munkasz;
    os << endl << "Add meg a privat szamot: ";
    is >> privsz;
    os << endl;

    Bejegyzes uj(nev, becenev, cim, munkasz, privsz);
    return uj;

}

void torol(Lista<Bejegyzes>& telefonkonyv){
    cout << "Add meg a nevet: " << endl;
    std::string nev;
    cin >> nev;
    Lista<Bejegyzes>::iterator i;
    try{
    for(i = telefonkonyv.begin(); i != telefonkonyv.end() && (*i).getnev() != nev; i++);
    if(i != telefonkonyv.end())
        telefonkonyv.torol(*i);
    else
        cout << "Nincs ilyen bejegyzes." << endl;
    }
    catch(std::out_of_range e){
        cout << "valami baj van. " << e.what() << endl;
    }

}

bool menu(Lista<Bejegyzes>& telefonkonyv, std::ostream& os, std::istream& is){
    os << "Valassz a lehetosegek kozul: " << endl;
    os << "1: Telefonkonyv listazasa" << endl;
    os << "2: Adatok felvetele" << endl;
    os << "3: Adatok torlese" << endl;
    os << "4: Kilepes, adatok mentese" << endl;

    Lista<Bejegyzes>::iterator i;

    char c;
    is >> c;

      switch (c){
        case '1':
            try{
                for(i = telefonkonyv.begin(); i != telefonkonyv.end(); i++){
                        i->listaz(os);
                        os << endl;
                }
            }
            catch(std::out_of_range e){
                os << "valami baj van. " << e.what() << endl;
            }
                    break;

        case '2': os << "Adja meg az adatokat: " << endl;
                    telefonkonyv.beszur(adatfelvesz(os, is));
                    break;

        case '3': torol(telefonkonyv);
                    break;

        case '4': return false;

        default: os<< "Kerlek 1-4 kozotti szamokat irj" << endl;

    }

    return true;

}

int main()
{
    Fajlkezeles fajlkezeles("telefonkonyv.txt");
    Lista<Bejegyzes> telefonkonyv = fajlkezeles.beolvas();
    std::stringstream sso, ssi;

   ssi <<  endl << endl << endl << 5  << 1 << 2 << endl << "p" << endl <<"p"  << endl << "p" << endl << "p" <<  endl <<"p" << 4 << 4 << 4;
  //  ssi << 1;

    while(menu(telefonkonyv, cout, ssi));

    fajlkezeles.kiir(telefonkonyv);


    return 0;
}
