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
            if(poprzedni->mniej_ != nullptr && poprzedni->mniej_->dane_ == dane_)
                poprzedni->mniej_ = nullptr;
            else poprzedni->wiecej_ = nullptr;
            delete this;

        }
        else if(this->mniej_ == nullptr) {
            drzewoElem<T>* temp = wiecej_;
            if(poprzedni->mniej_ != nullptr && poprzedni->mniej_->dane_ == dane_)
                poprzedni->mniej_ = temp;
            else poprzedni->wiecej_ = temp;
            delete this;

        }
        else if(this->wiecej_ == nullptr) {
            drzewoElem<T>* temp = mniej_;
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

template <class T>
int drzewoElem<T>::wysokosc() {
    if(wiecej_ != nullptr && mniej_ != nullptr)
        return mniej_->wysokosc() > wiecej_->wysokosc() ? mniej_->wysokosc() + 1 : wiecej_->wysokosc() + 1;
    else if(wiecej_ != nullptr)
        return wiecej_->wysokosc() + 1;
    else if(mniej_ != nullptr)
        return mniej_->wysokosc() + 1;
    else return 0;

}

template <class T>
int drzewoElem<T>::wielkosc() {
    if(wiecej_ != nullptr && mniej_ != nullptr)
        return mniej_->wielkosc() + wiecej_->wielkosc() + 1;
    else if(wiecej_ != nullptr)
        return wiecej_->wielkosc() + 1;
    else if(mniej_ != nullptr)
        return mniej_->wielkosc() + 1;
    else return 1;
    
}

template <class T>
void drzewoElem<T>::obrot_lewo(drzewoElem<T>* const &poprzedni) {
    drzewoElem<T>* temp = wiecej_;
    wiecej_ = temp->mniej_;
    temp->mniej_ = this;
    if(poprzedni->mniej_->dane_ == dane_)
        poprzedni->mniej_ = temp;
    else poprzedni->wiecej_ = temp;
    
}

template <class T>
void drzewoElem<T>::obrot_prawo(drzewoElem<T>* const &poprzedni) {
    drzewoElem<T>* temp = mniej_;
    mniej_ = temp->wiecej_;
    temp->wiecej_ = this;
    if(poprzedni->mniej_->dane_ == dane_)
        poprzedni->mniej_ = temp;
    else poprzedni->wiecej_ = temp;
    
}

template <class T>
drzewoElem<T>* drzewoElem<T>::obrot_korzen_lewo() {
    drzewoElem<T> *temp = wiecej_;
    wiecej_ = temp->mniej_;
    temp->mniej_ = this;
    return temp;

}

template <class T>
drzewoElem<T>* drzewoElem<T>::obrot_korzen_prawo() {
    drzewoElem<T> *temp = mniej_;
    mniej_ = temp->wiecej_;
    temp->wiecej_ = this;
    return temp;

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
        else korzen_->usun(dane, korzen_);
        if(korzen_ == nullptr)
            puste_ = true;
    
    }

}

template <class T>
int drzewo<T>::wysokosc(T dane) {
    drzewoElem<T>* temp = korzen_;
    while(temp->dane_ != dane) {
        if(temp->dane_ > dane)
            temp = temp->mniej_;
        else if(temp->dane_ < dane)
            temp = temp->wiecej_;
        else return -1;

    }
    return temp->wysokosc();

}

template <class T>
int drzewo<T>::wysokosc() {
    return korzen_->wysokosc();

}

template <class T>
int drzewo<T>::wielkosc(T dane) {
    drzewoElem<T>* temp = korzen_;
    while(temp->dane_ != dane) {
        if(temp->dane_ > dane)
            temp = temp->mniej_;
        else if(temp->dane_ < dane)
            temp = temp->wiecej_;
        else return -1;

    }
    return temp->wielkosc();

}

template <class T>
int drzewo<T>::wielkosc() {
    return korzen_->wielkosc();

}

template <class T>
void drzewo<T>::obrot_prawo(T dane) {
    if(dane == korzen_->dane_)
        korzen_ = korzen_->obrot_korzen_prawo();
    else {
        drzewoElem<T>* temp = korzen_;
        drzewoElem<T>* pop;
        while(temp->dane_ != dane) {
            pop = temp;
            if(temp->dane_ > dane)
                temp = temp->mniej_;
            else if(temp->dane_ < dane)
                temp = temp->wiecej_;
            else return;

        }
        temp->obrot_prawo(pop);

    }

}

template <class T>
void drzewo<T>::obrot_lewo(T dane) {
    if(dane == korzen_->dane_)
        korzen_ = korzen_->obrot_korzen_lewo();
    else {
        drzewoElem<T>* temp = korzen_;
        drzewoElem<T>* pop;
        while(temp->dane_ != dane) {
            pop = temp;
            if(temp->dane_ > dane)
                temp = temp->mniej_;
            else if(temp->dane_ < dane)
                temp = temp->wiecej_;
            else return;

        }
        temp->obrot_lewo(pop);

    }

}

template class drzewo<int>;
template class drzewo<char>;
template class drzewo<float>;