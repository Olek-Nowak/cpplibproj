#include "kolejka.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
kolejka<T>::~kolejka() {
    delete[] tablica_;

}

template <class T>
kolejka<T>::kolejka(int dlugosc) {
    if(dlugosc > 0) {
        dlugosc_ = dlugosc;
        tablica_ = new T [dlugosc];
        zapis_ = 0;
        odczyt_ = 0;
        pusta_ = true;
        
    }
    
}

template <class T>
kolejka<T>::kolejka(int dlugosc, string sciezka) {
    if(dlugosc > 0) {
        dlugosc_ = dlugosc;
        tablica_ = new T [dlugosc];
        zapis_ = 0;
        odczyt_ = 0;
        pusta_ = true;
        T temp;
        ifstream plik = ifstream(sciezka);
        if(!plik.good()) {
            cout << "Plik niedostępny.";
            return;

        }
        for(int i = 0; i < dlugosc; i++) {
            if(plik.eof())
                return;
            plik >> temp;
            kolejkuj(temp);

        }

    }

}

template <class T>
void kolejka<T>::druk(string sciezka) {
    if(pusta_)
        return;
    ofstream plik = ofstream(sciezka);
    if(!plik.good()) {
        cout << "Plik niedostępny.";
        return;
        
    }
    for(int i = 0; i < dlugosc_; i++)
        plik << tablica_[i] << '\n';
    plik << "zapis: " << zapis_ << '\n';
    plik << "odczyt: " << odczyt_ << '\n';
    plik.close();

}

template <class T>
void kolejka<T>::podglad(T& dane) {
    if(!pusta_)
        dane = tablica_[odczyt_];
    else
        cout << "Kolejka jest pusta\n";
    
}

template <class T>
void kolejka<T>::kolejkuj(T dane) {
    if(zapis_ == odczyt_ && !pusta_)
        cout << "Przekroczono maksymalna dlugosc kolejki\n";
    else {
        tablica_[zapis_] = dane;
        zapis_++;
        if(zapis_ > dlugosc_ - 1)
            zapis_ = 0;
        pusta_ = false;

    }
    
}

template <class T>
void kolejka<T>::dekolejkuj(T& dane) {
    if(pusta_)
        cout << "Kolejka jest pusta\n";
    else {
        dane = tablica_[odczyt_];
        odczyt_++;
        if(odczyt_ > dlugosc_ - 1)
            odczyt_ = 0;
        if(zapis_ == odczyt_)
            pusta_ = true;

    }
    
}

template class kolejka<int>;
template class kolejka<char>;
template class kolejka<float>;
template class kolejka<string>;