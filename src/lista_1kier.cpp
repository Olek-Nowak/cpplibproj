#include "lista_1kier.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
lista1kElem<T>::lista1kElem(T dane) {
    nast_ = nullptr;
    dane_ = dane;

}

template <class T>
lista_1kier<T>::lista_1kier() {
    glowa_ = nullptr;
    ogon_ = nullptr;
    dlugosc_ = 0;

}

template <class T>
lista_1kier<T>::lista_1kier(string sciezka) {
    glowa_ = nullptr;
    ogon_ = nullptr;
    dlugosc_ = 0;
    T dane;
    ifstream plik = ifstream(sciezka);
    if(!plik.good()) {
        cout << "Plik niedostępny.";
        return;
        
    }
    while (!plik.eof()) {
        plik >> dane;
        this->dodaj(dane);

    }
}

template <class T>
lista_1kier<T>::~lista_1kier() {
    lista1kElem<T> *temp;
    while (glowa_ != nullptr) {
        temp = glowa_;
        glowa_ = glowa_->nast_;
        delete temp;

    }
    glowa_ = nullptr;
    ogon_ = nullptr;
}

template <class T>
int lista_1kier<T>::dlugosc() {
    return dlugosc_;

}

template <class T>
void lista_1kier<T>::druk() {
    if(glowa_ == nullptr)
        cout << "Lista jest pusta.\n";
    lista1kElem<T> *temp = glowa_;
    while (temp != nullptr) {
        cout << temp->dane_ << '\n';
        temp = temp->nast_;

    }

}

template <class T>
void lista_1kier<T>::druk(string sciezka) {
    ofstream plik = ofstream(sciezka);
    if(!plik.good()) {
        cout << "Plik niedostępny.";
        return;
        
    }
    lista1kElem<T> *temp = glowa_;
    while (temp != nullptr) {
        plik << temp->dane_ << '\n';
        temp = temp->nast_;

    }

}

template <class T>
void lista_1kier<T>::dodaj(T dane) {
    dlugosc_++;
    lista1kElem<T> *n = new lista1kElem<T>(dane);
    if (ogon_ == nullptr) {
        glowa_ = n;
        ogon_ = n;

    }
    else {
        ogon_->nast_ = n;
        ogon_ = n;

    }

}

template <class T>
void lista_1kier<T>::dodaj(T dane, int pozycja) {
    if(pozycja < 0) {
        cout << "Niepoprawna pozycja elementu.\n";
        return;

    }
    else if(pozycja == 0) {
        dlugosc_++;
        lista1kElem<T>* n = new lista1kElem<T>(dane);
        n->nast_ = glowa_;
        glowa_ = n;

    }
    else {
        lista1kElem<T>* temp = glowa_;
        for (int i = 1; i < pozycja; i++) {
            if (temp == nullptr)
                return;
            temp = temp->nast_;

        }
        dlugosc_++;
        lista1kElem<T> *n = new lista1kElem<T>(dane);
        if (temp->nast_ == nullptr)
            ogon_ = n;
        lista1kElem<T> *t = temp->nast_;
        temp->nast_ = n;
        n->nast_ = t;

    }

}

template <class T>
void lista_1kier<T>::usun(T& dane) {
    if(glowa_ == nullptr)
        return;
    else if(glowa_ == ogon_) {
        dlugosc_--;
        dane = glowa_->dane_;
        delete glowa_;
        ogon_ = nullptr;
        glowa_ = nullptr;

    }
    else {
        dlugosc_--;
        lista1kElem<T> *temp = glowa_;
        while (temp->nast_ != ogon_)
            temp = temp->nast_;
        temp->nast_ = nullptr;
        dane = ogon_->dane_;
        delete ogon_;
        ogon_ = temp;

    }

}

template <class T>
void lista_1kier<T>::usun_napotkany(T dane) {
    if(glowa_->dane_ == dane) {
        dlugosc_--;
        if(glowa_ == ogon_)
            ogon_ = nullptr;
        lista1kElem<T> *temp = glowa_;
        glowa_ = temp->nast_;
        delete temp;

    }
    else {
        lista1kElem<T> *temp = glowa_;
        if (temp->nast_ == nullptr)
            return;
        while (temp->nast_->dane_ != dane) {
            if (temp->nast_ == nullptr) {
                cout << "Element o danej wartości nie istnieje.\n";
                return;

            }
            temp = temp->nast_;

        }
        dlugosc_--;
        if (temp->nast_ == ogon_)
            ogon_ = temp;
        lista1kElem<T> *t = temp->nast_;
        temp->nast_ = t->nast_;
        delete t;

    }

}

template <class T>
void lista_1kier<T>::usun(int pozycja, T& dane) {
    if(pozycja < 0) {
        cout << "Niepoprawna pozycja elementu.\n";
        return;

    }
    else if (pozycja == 0) {
        dlugosc_--;
        if (glowa_ == ogon_)
            ogon_ = nullptr;
        lista1kElem<T> *temp = glowa_;
        glowa_ = temp->nast_;
        dane = temp->dane_;
        delete temp;
        glowa_ = nullptr;

    }
    else {
        lista1kElem<T> *temp = glowa_;
        for (int i = 1; i < pozycja; i++) {
            if (temp->nast_ == nullptr) {
                cout << "Element o danej wartości nie istnieje.\n";
                return;

            }
            temp = temp->nast_;
            
        }
        dlugosc_--;
        if (temp->nast_ == ogon_)
            ogon_ = temp;
        lista1kElem<T> *t = temp->nast_;
        temp->nast_ = t->nast_;
        dane = t->dane_;
        delete t;

    }

}

template <class T>
void lista_1kier<T>::sortuj() {
    if(glowa_ == nullptr || glowa_->nast_ == nullptr)
        return;
    lista1kElem<T>* sort = glowa_;
    lista1kElem<T>* min = glowa_;
    lista1kElem<T>* t = glowa_;
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

template class lista_1kier<int>;
template class lista_1kier<char>;
template class lista_1kier<float>;