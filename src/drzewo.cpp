#include "drzewo.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Struktura kodu drzewa pozostawia sporo do życzenia, ale najłatwiejszym rozwiązaniem jest rekurencja.

template <class T>
drzewoElem<T>::drzewoElem(T dane) {
    mniej_ = nullptr;
    wiecej_ = nullptr;
    dane_ = dane;

}

template <class T>
void drzewoElem<T>::druk_inorder() {
    if(mniej_ != nullptr)
        mniej_->druk_inorder();
    cout << dane_ << '\t';
    if(wiecej_ != nullptr)
        wiecej_->druk_inorder();

}

template <class T>
void drzewoElem<T>::druk_inorder(ofstream& plik) {
    if(mniej_ != nullptr)
        mniej_->druk_inorder(plik);
    plik << dane_ << '\t';
    if(wiecej_ != nullptr)
        wiecej_->druk_inorder(plik);

}

template <class T>
void drzewoElem<T>::druk_drzewo(int tab) {
    for(int i = 0; i < tab; i++)
        cout << '\t';
    if(tab != 0)
        cout << "'-> ";
    cout << dane_ << '\n';
    if(mniej_ != nullptr)
        mniej_->druk_drzewo(tab+1);
    if(wiecej_ != nullptr)
        wiecej_->druk_drzewo(tab+1);

}

template <class T>
void drzewoElem<T>::skasuj() {
    if(mniej_ != nullptr)
        mniej_->skasuj();
    if(wiecej_ != nullptr)
        wiecej_->skasuj();
    delete this;

}

template <class T>
void drzewoElem<T>::dodaj(T dane) {
    if(mniej_ != nullptr && dane < dane_)
        mniej_->dodaj(dane);
    else if(wiecej_ != nullptr && dane > dane_)
        wiecej_->dodaj(dane);
    else if(mniej_ == nullptr && dane < dane_) {
        drzewoElem<T>* n = new drzewoElem<T>(dane);
        mniej_ = n;

    }
    else if(wiecej_ == nullptr && dane > dane_) {
        drzewoElem<T>* n = new drzewoElem<T>(dane);
        wiecej_ = n;

    }

}

template <class T>
void drzewoElem<T>::usun(T dane, drzewoElem* poprzedni) {
    if(mniej_ != nullptr && dane < dane_)
        mniej_->usun(dane, this);
    else if(wiecej_ != nullptr && dane > dane_)
        wiecej_->usun(dane, this);
    else if(dane == dane_) {
        // Usuwanie elementów drzewa obecnie nieobsługiwane - prace trwają.

    }

}



template <class T>
drzewo<T>::~drzewo() {
    korzen_->skasuj();

}

template <class T>
drzewo<T>::drzewo() {
    korzen_ = new drzewoElem<T>(NULL);

}

template <class T>
drzewo<T>::drzewo(string sciezka) {
    korzen_ = new drzewoElem<T>(NULL);
    ifstream plik = ifstream(sciezka);
    T temp;
    while(!plik.eof()) {
        plik >> temp;
        this->dodaj(temp);

    }

}

template <class T>
void drzewo<T>::druk_drzewo() {
    korzen_->druk_drzewo(0);

}

template <class T>
void drzewo<T>::druk_inorder() {
    korzen_->druk_inorder();

}

template <class T>
void drzewo<T>::druk_inorder(string sciezka) {
    ofstream plik = ofstream(sciezka);
    korzen_->druk_inorder(plik);

}

template <class T>
void drzewo<T>::dodaj(T dane) {
    if(korzen_->dane_ == NULL)
        korzen_->dane_ = dane;
    else korzen_->dodaj(dane);

}

template <class T>
void drzewo<T>::usun(T dane) {
    korzen_->usun(dane, nullptr);

}

template class drzewo<int>;
template class drzewo<char>;
template class drzewo<float>;