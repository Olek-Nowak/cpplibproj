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
        cout << '\n';

    }
    
}

template <class T>
void lista_2kier<T>::druk(string sciezka) {
    ofstream plik = ofstream(sciezka);
    lista2kElem<T>* temp = glowa_;
    while (temp != nullptr) {
        plik << temp->dane_ << '\n';
        temp = temp->nast_;

    }
    
}

template <class T>
void lista_2kier<T>::dodaj(T dane) {
    dlugosc_++;
    lista2kElem<T>* n = new lista2kElem<T>(dane);
    if(ogon_ == nullptr) {
        glowa_ = n;
        ogon_ = n;

    }
    else {
        ogon_->nast_ = n;
        n->poprz_ = ogon_;
        ogon_ = n;

    }
    
}

template <class T>
void lista_2kier<T>::dodaj(T dane, int pozycja) {
    if(pozycja < 0)
        return;
    else if(pozycja == 0) {
        dlugosc_++;
        lista2kElem<T>* n = new lista2kElem<T>(dane);
        n->nast_ = glowa_;
        glowa_->poprz_ = n;
        glowa_ = n;

    }
    else {
        lista2kElem<T>* temp = glowa_;
        for(int i = 1; i < pozycja; i++) {
            if(temp == nullptr)
                return;
            temp = temp->nast_;

        }
        dlugosc_++;
        lista2kElem<T>* n = new lista2kElem<T>(dane);
        if(temp->nast_ == nullptr)
            ogon_ = n;
        n->poprz_ = temp;
        n->nast_ = temp->nast_;
        n->nast_->poprz_ = n;
        temp->nast_ = n;

    }
    
}

template <class T>
void lista_2kier<T>::usun() {
    if(ogon_ == nullptr)
        return;
    else {
        dlugosc_--;
        if(ogon_->poprz_ == nullptr) {
            glowa_ = nullptr;
            delete ogon_;
            ogon_ = nullptr;

        }
        else {
            lista2kElem<T>* temp = ogon_->poprz_;
            delete ogon_;
            ogon_ = temp;
            ogon_->nast_ = nullptr;

        }

    }
    
}

template <class T>
void lista_2kier<T>::usun_napotkany(T dane) {
    if(glowa_ == nullptr)
        return;
    lista2kElem<T>* temp = glowa_;
    while(temp->dane_ != dane) {
        if(temp->nast_ == nullptr)
            return;
        temp = temp->nast_;

    }
    dlugosc_--;
    if(temp->poprz_ == nullptr)
        glowa_ = temp->nast_;
    else
        temp->poprz_->nast_ = temp->nast_;
    if(temp->nast_ == nullptr)
        ogon_ = temp->poprz_;
    else
        temp->nast_->poprz_ = temp->poprz_;
    delete temp;
    
}

template <class T>
T lista_2kier<T>::usun(int pozycja) {
    if(pozycja < 0)
        return NULL;
    else if(pozycja == 0) {
        dlugosc_--;
        if(glowa_->nast_ == nullptr)
            ogon_ = nullptr;
        lista2kElem<T>* temp = glowa_;
        glowa_ = temp->nast_;
        glowa_->poprz_ = nullptr;
        T wynik = temp->dane_;
        delete temp;
        return wynik;

    }
    else {
        lista2kElem<T>* temp = glowa_;
        for(int i = 0; i < pozycja; i++) {
            if(temp == nullptr)
                return NULL;
            temp = temp->nast_;

        }
        dlugosc_--;
        if(temp->poprz_ == nullptr)
            glowa_ = temp->nast_;
        if(temp->nast_ == nullptr)
            ogon_ = temp->poprz_;
        temp->nast_->poprz_ = temp->poprz_;
        temp->poprz_->nast_ = temp->nast_;
        T wynik = temp->dane_;
        delete temp;
        return wynik;

    }

}

template <class T>
void lista_2kier<T>::sortuj() {
    if(glowa_ == nullptr || glowa_->nast_ == nullptr)
        return;
    lista2kElem<T>* sort = glowa_;
    lista2kElem<T>* min = glowa_;
    lista2kElem<T>* t = glowa_;
    T temp;
    while(sort != nullptr) {
        min = sort;
        t = sort;
        while(t != nullptr) {
            if(t->dane_ < min->dane_)
                min = t;
            t = t->nast_;

        }
        temp = sort->dane_;
        sort->dane_ = min->dane_;
        min->dane_ = temp;
        sort = sort->nast_;

    }

}

template class lista_2kier<int>;
template class lista_2kier<char>;
template class lista_2kier<float>;