#include "macierz.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <class T>
T& macierz<T>::operator()(int x, int y) {
    if(x >= 0 && x < n_ && y >=0 && y < m_)
        return tab_[x][y];

}

template <class T>
macierz<T>::~macierz() {
    for(int i = 0; i < n_; i++)
        delete[] tab_[i];
    delete[] tab_;
    tab_ = nullptr;

}

template <class T>
macierz<T>::macierz(int n, int m) {
    tab_ = new T* [n];
    for(int i = 0; i < n; i++)
        tab_[i] = new T [m];
    n_ = n;
    m_ = m;

}

template <class T>
macierz<T>::macierz(int n) {
    tab_ = new T* [n];
    for(int i = 0; i < n; i++)
        tab_[i] = new T [n];
    n_ = n;
    m_ = n;

}

template <class T>
macierz<T>::macierz(string sciezka, int n, int m) {
    tab_ = new T* [n];
    for(int i = 0; i < n; i++)
        tab_[i] = new T [m];
    n_ = n;
    m_ = m;
    T temp;
    ifstream plik = ifstream(sciezka);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(plik.eof())
                return;
            plik >> temp;
            tab_[i][j] = temp;

        }

}

template <class T>
void macierz<T>::druk() {
    for(int i = 0; i < n_; i++) {
        for(int j = 0; j < m_; j++)
            cout << tab_[i][j] << '\t';
        cout << '\n';

    }

}

template <class T>
void macierz<T>::druk(string sciezka) {
    ofstream plik = ofstream(sciezka);
    for(int i = 0; i < n_; i++) {
        for(int j = 0; j < m_; j++)
            plik << tab_[i][j] << '\t';
        plik << '\n';

    }

}

template <class T>
void macierz<T>::transpozycja() {


}

template <class T>
void macierz<T>::obrot() {


}

template <class T>
int macierz<T>::wyznacznik() {


}

template class macierz<int>;
template class macierz<char>;
template class macierz<float>;
template class macierz<string>;