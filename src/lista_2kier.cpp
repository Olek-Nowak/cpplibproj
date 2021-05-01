#include "lista_2kier.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
lista2kElem<T>::lista2kElem(T dane) {
    dane_ = dane;
    nast_ = nullptr;
    poprz_ = nullptr;

}

template <class T>
lista_2kier<T>::~lista_2kier() {
    lista2kElem<T>* temp;
    while(glowa_ != nullptr) {
        temp = glowa_;
        glowa_ = glowa_->nast_;
        delete temp;

    }

}

template <class T>
lista_2kier<T>::lista_2kier() {
    glowa_ = nullptr;
    ogon_ = nullptr;
    dlugosc_ = 0;

}

template <class T>
lista_2kier<T>::lista_2kier(string sciezka) {
    glowa_ = nullptr;
    ogon_ = nullptr;
    dlugosc_ = 0;
    ifstream plik = ifstream(sciezka);
    if(!plik.good())
        return;
    T dane;
    while(!plik.eof()) {
        plik >> dane;
        this->dodaj(dane);

    }

}

template <class T>
int lista_2kier<T>::dlugosc() {
    return dlugosc_;

}

template <class T>
void lista_2kier<T>::druk() {
    if(glowa_ == nullptr)
        cout << "Lista jest pusta.\n";
    else {
        lista2kElem<T>* temp = glowa_;
        while(temp != nullptr) {
            cout << temp->dane_ << '\t';
            temp = temp->nast_;

        }

    }
    
}

template <class T>
void lista_2kier<T>::druk(string sciezka) {
    ofstream plik = ofstream(sciezka);
    lista2kElem<T> *temp = glowa_;
    while (temp != nullptr) {
        plik << temp->dane_ << '\n';
        temp = temp->nast_;

    }
    
}

template <class T>
void lista_2kier<T>::dodaj(T dane) {

    
}

template <class T>
void lista_2kier<T>::dodaj(T dane, int pozycja) {

    
}

template <class T>
void lista_2kier<T>::usun() {

    
}

template <class T>
void lista_2kier<T>::usun_napotkany(T dane) {

    
}

template <class T>
T lista_2kier<T>::usun(int pozycja) {

    
}