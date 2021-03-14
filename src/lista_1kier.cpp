#include "lista_1kier.h"
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
struct lista1kElem {
    lista1kElem(T dane) {
        nast = nullptr;
        dane_ = dane;

    }

};

template <class T>
class lista_1kier {

    lista_1kier() {
        głowa_ = nullptr;
        ogon_ = nullptr;

    }

    lista_1kier(string ścieżka) {
        głowa_ = nullptr;
        ogon_ = nullptr;
        T temp;
        ifstream plik = ifstream(ścieżka);
        while(!plik.eof()) {
            plik >> temp;
            this->dodaj(temp);

        }

    }

    ~lista_1kier() {
        lista1kElem* temp;
        while(głowa_ != nullptr) {
            temp = głowa_;
            głowa_ = głowa_->nast;
            delete temp;

        }
        głowa_ = nullptr;
        ogon_ = nullptr;

    }

    druk() {
        lista1kElem* temp = głowa_;
        while(temp != nullptr) {
            cout << temp->dane;
            temp = temp->nast;

        }

    }

    druk(string ścieżka) {
        ofstream plik = ofstream(ścieżka);
        lista1kElem* temp = głowa_;
        while(temp != nullptr) {
            plik << temp->dane;
            temp = temp->nast;

        }

    }

    dodaj(T dane) {


    }

    dodaj(T dane, int pozycja) {


    }

    usuń() {


    }

    usuń(T dane) {


    }

    usuń(int pozycja) {


    }

};