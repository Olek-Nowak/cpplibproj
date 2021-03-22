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
    plik.close();

}

template <class T>
macierz<T> macierz<T>::minor(int x, int y) {
    macierz<T> m = macierz<T>(n_-1, m_-1);
    bool inx = false, iny;
    for(int i = 0; i < n_-1; i++) {
        iny = false;
        if(i == x)
            inx = true;
        for(int j = 0; j < m_-1; j++) {
            if(j == y)
                iny = true;
            m(i, j) = tab_[i+inx][j+iny];   

        }

    }
    return m;

}

template <class T>
void macierz<T>::transpozycja() {
    T** m = new T* [m_];
    for(int i = 0; i < m_; i++)
        m[i] = new T [n_];
    for(int i = 0; i < n_; i++) {
        for(int j = 0; j < m_; j++)
            m[j][i] = tab_[i][j];

    }
    this->~macierz();
    int temp = m_;
    m_ = n_;
    n_ = temp;
    tab_ = m;

}

template <class T>
void macierz<T>::przesun_wiersz(int x, int ilosc) {
    if(x < 0 || x >= n_)
        return;
    if(ilosc < 0) {
        int l = (-1*ilosc) % m_;
        for(int i = 0; i < l; i++) {
            T temp;
            for(int j = 1; j < m_; j++) {
                temp = tab_[x][j-1];
                tab_[x][j-1] = tab_[x][j];
                tab_[x][j] = temp;

            }

        }

    }
    else {
        int l = ilosc % m_;
        for(int i = 0; i < ilosc; i++) {
            T temp;
            for(int j = m_-1; j > 0; j--) {
                temp = tab_[x][j];
                tab_[x][j] = tab_[x][j-1];
                tab_[x][j-1] = temp;

            }

        }

    }

}

template <class T>
void macierz<T>::przesun_kolumne(int y, int ilosc) {
    if(y < 0 || y >= m_)
        return;
    if(ilosc < 0) {
        int l = (-1*ilosc) % n_;
        for(int i = 0; i < -1*ilosc; i++) {
            T temp;
            for(int j = 1; j < n_; j++) {
                temp = tab_[j-1][y];
                tab_[j-1][y] = tab_[j][y];
                tab_[j][y] = temp;

            }

        }

    }
    else {
        int l = ilosc % n_;
        for(int i = 0; i < ilosc; i++) {
            T temp;
            for(int j = n_-1; j > 0; j--) {
                temp = tab_[j][y];
                tab_[j][y] = tab_[j-1][y];
                tab_[j-1][y] = temp;

            }

        }

    }

}

template class macierz<int>;
template class macierz<char>;
template class macierz<float>;
template class macierz<string>;