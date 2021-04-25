#include "drzewo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

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
        mniej_->druk_drzewo(tab + 1);
    if(wiecej_ != nullptr)
        wiecej_->druk_drzewo(tab + 1);

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
    else cout << "Wartosc " << dane << " jest juz zawarta w drzewie\n";

}

template <class T>
drzewoElem<T>* drzewoElem<T>::najwiekszy() {
    if(wiecej_ == nullptr)
        return this;
    else return wiecej_->najwiekszy();

}

template <class T>
drzewoElem<T>* drzewoElem<T>::najmniejszy() {
    if(mniej_ == nullptr)
        return this;
    else return mniej_->najmniejszy();

}

template <class T>
void drzewoElem<T>::usun(T dane, drzewoElem<T>* const &poprzedni) {
    if(mniej_ != nullptr && dane < dane_)
        mniej_->usun(dane, this);
    else if(wiecej_ != nullptr && dane > dane_)
        wiecej_->usun(dane, this);
    else if(dane == dane_) {
        if(this->mniej_ == nullptr && this->wiecej_ == nullptr) {
            cout << '\n' << poprzedni->dane_ << '\n';
            if(poprzedni->mniej_ != nullptr && poprzedni->mniej_->dane_ == dane_)
                poprzedni->mniej_ = nullptr;
            else poprzedni->wiecej_ = nullptr;
            delete this;

        }
        else if(this->mniej_ == nullptr) { //problem
            drzewoElem<T>* temp = wiecej_->najmniejszy();
            /*mniej_ = temp->wiecej_;
            dane_ = temp->dane_;
            temp->wiecej_ = nullptr;
            wiecej_->usun(dane_, this);
            */
            if(poprzedni->mniej_ != nullptr && poprzedni->mniej_->dane_ == dane_)
                poprzedni->mniej_ = temp;
            else poprzedni->wiecej_ = temp;
            delete this;

        }
        else if(this->wiecej_ == nullptr) { //problem
            drzewoElem<T>* temp = mniej_->najwiekszy();
            /*wiecej_ = temp->mniej_;
            dane_ = temp->dane_;
            temp->mniej_ = nullptr;
            mniej_->usun(dane_, this);
            */
            if(poprzedni->mniej_ != nullptr && poprzedni->mniej_->dane_ == dane_)
                poprzedni->mniej_ = temp;
            else poprzedni->wiecej_ = temp;
            delete this;

        }
        else {
            bool mniej = int(rand() % 2);
            if(mniej) {
                drzewoElem<T>* temp = mniej_->najwiekszy();
                dane_ = temp->dane_;
                mniej_->usun(dane_, this);

            }
            else {
                drzewoElem<T>* temp = wiecej_->najmniejszy();
                dane_ = temp->dane_;
                wiecej_->usun(dane_, this);

            }

        }

    }
    else
        cout << "Wartosc " << dane << " nie istnieje\n";

}

template <class T>
drzewoElem<T>* drzewoElem<T>::usun_korzen() {
    if(mniej_ == nullptr && wiecej_ == nullptr) {
        delete this;
        return nullptr;

    }
    else if(this->mniej_ == nullptr) {
        drzewoElem<T>* temp = wiecej_->najmniejszy();
        temp->mniej_ = wiecej_;
        delete this;
        return temp;

    }
    else if(this->wiecej_ == nullptr) {
        drzewoElem<T>* temp = mniej_->najwiekszy();
        temp->wiecej_ = mniej_;
        delete this;
        return temp;
        
    }
    else {
        bool mniej = int(rand() % 2);
        if(mniej) {
            drzewoElem<T>* temp = mniej_->najwiekszy();
            dane_ = temp->dane_;
            mniej_->usun(temp->dane_, this);
            return temp;

        }
        else {
            drzewoElem<T>* temp = wiecej_->najmniejszy();
            dane_ = temp->dane_;
            wiecej_->usun(temp->dane_, this);
            return temp;

        }
            
    }

}

// ------------------------

template <class T>
drzewo<T>::~drzewo() {
    korzen_->skasuj();

}

template <class T>
drzewo<T>::drzewo() {
    srand(time(NULL));
    korzen_ = new drzewoElem<T>(NULL);
    puste_ = true;

}

template <class T>
drzewo<T>::drzewo(string sciezka) {
    srand(time(NULL));
    korzen_ = new drzewoElem<T>(NULL);
    puste_ = true;
    ifstream plik = ifstream(sciezka);
    T temp;
    while(!plik.eof()) {
        plik >> temp;
        this->dodaj(temp);

    }

}

template <class T>
void drzewo<T>::druk_drzewo() {
    if(korzen_ == nullptr && puste_)
        cout << "Drzewo jest puste\n";
    else korzen_->druk_drzewo(0);

}

template <class T>
void drzewo<T>::druk_inorder() {
    if(korzen_ == nullptr && puste_)
        cout << "Drzewo jest puste\n";
    else korzen_->druk_inorder();

}

template <class T>
void drzewo<T>::druk_inorder(string sciezka) {
    if(korzen_ == nullptr && puste_)
        return;
    ofstream plik = ofstream(sciezka);
    korzen_->druk_inorder(plik);

}

template <class T>
void drzewo<T>::dodaj(T dane) {
    if(korzen_ == nullptr) {
        korzen_ = new drzewoElem<T>(NULL);
        puste_ = true;

    }
    if(puste_) {
        korzen_->dane_ = dane;
        puste_ = false;

    }
    else korzen_->dodaj(dane);

}

template <class T>
void drzewo<T>::usun(T dane) {
    if(korzen_ == nullptr || puste_)
        cout << "Drzewo jest puste\n";
    else {
        if(dane == korzen_->dane_)
            korzen_ = korzen_->usun_korzen();
        else korzen_->usun(dane, nullptr);
        if(korzen_ == nullptr)
            puste_ = true;
    
    }

}

template class drzewo<int>;
template class drzewo<char>;
template class drzewo<float>;