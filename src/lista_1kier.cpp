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

}

template <class T>
lista_1kier<T>::lista_1kier(string sciezka) {
    glowa_ = nullptr;
    ogon_ = nullptr;
    T temp;
    ifstream plik = ifstream(sciezka);
    while (!plik.eof()) {
        plik >> temp;
        this->dodaj(temp);

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
int lista_1kier<T>::druk() {
    if (glowa_ == nullptr)
        cout << "Lista jest pusta.\n";
    lista1kElem<T> *temp = glowa_;
    while (temp != nullptr) {
        cout << temp->dane_ << '\n';
        temp = temp->nast_;

    }
    return 0;

}

template <class T>
int lista_1kier<T>::druk(string sciezka) {
    ofstream plik = ofstream(sciezka);
    lista1kElem<T> *temp = glowa_;
    while (temp != nullptr) {
        plik << temp->dane_ << '\n';
        temp = temp->nast_;

    }
    return 0;

}

template <class T>
int lista_1kier<T>::dodaj(T dane) {
    lista1kElem<T> *n = new lista1kElem<T>(dane);
    if (glowa_ == nullptr) {
        glowa_ = n;
        ogon_ = n;

    }
    else {
        ogon_->nast_ = n;
        ogon_ = n;

    }
    return 0;

}

template <class T>
int lista_1kier<T>::dodaj(T dane, int pozycja) {
    if (pozycja < 0)
        return -2;
    else if (pozycja == 0) {
        lista1kElem<T> *n = new lista1kElem<T>(dane);
        n->nast_ = glowa_;
        glowa_ = n;

    }
    else {
        lista1kElem<T> *temp = glowa_;
        for (int i = 1; i < pozycja; i++) {
            if (temp == nullptr)
                return -1;
            temp = temp->nast_;

        }
        lista1kElem<T> *n = new lista1kElem<T>(dane);
        if (temp->nast_ == nullptr)
            ogon_ = n;
        lista1kElem<T> *t = temp->nast_;
        temp->nast_ = n;
        n->nast_ = t;

    }
    return 0;

}

template <class T>
int lista_1kier<T>::usun() {
    if (glowa_ == nullptr)
        return -1;
    else if (glowa_ == ogon_) {
        delete glowa_;
        ogon_ = nullptr;
        glowa_ = nullptr;

    }
    else {
        lista1kElem<T> *temp = glowa_;
        while (temp->nast_ != ogon_)
            temp = temp->nast_;
        temp->nast_ = nullptr;
        delete ogon_;
        ogon_ = temp;

    }
    return 0;

}

template <class T>
int lista_1kier<T>::usun_napotkany(T dane) {
    if (glowa_->dane_ == dane) {
        if (glowa_ == ogon_)
            ogon_ = nullptr;
        lista1kElem<T> *temp = glowa_;
        glowa_ = temp->nast_;
        delete temp;
        glowa_ = nullptr;

    }
    else {
        lista1kElem<T> *temp = glowa_;
        if (temp->nast_ == nullptr)
            return -1;
        while (temp->nast_->dane_ != dane) {
            if (temp->nast_ == nullptr)
                return -1;
            temp = temp->nast_;

        }
        if (temp->nast_ == ogon_)
            ogon_ = temp;
        lista1kElem<T> *t = temp->nast_;
        temp->nast_ = t->nast_;
        delete t;

    }
    return 0;

}

template <class T>
T lista_1kier<T>::usun(int pozycja) {
    if (pozycja < 0)
        return NULL;
    else if (pozycja == 0) {
        if (glowa_ == ogon_)
            ogon_ = nullptr;
        lista1kElem<T> *temp = glowa_;
        glowa_ = temp->nast_;
        delete temp;
        glowa_ = nullptr;

    }
    else {
        lista1kElem<T> *temp = glowa_;
        for (int i = 1; i < pozycja; i++) {
            if (temp->nast_ == nullptr)
                return NULL;
            temp = temp->nast_;
            
        }
        if (temp->nast_ == ogon_)
            ogon_ = temp;
        lista1kElem<T> *t = temp->nast_;
        temp->nast_ = t->nast_;
        T wynik = t->dane_;
        delete t;
        return wynik;

    }

}

template class lista_1kier<int>;
template class lista_1kier<char>;
template class lista_1kier<float>;
template class lista_1kier<string>;