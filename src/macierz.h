#ifndef MACIERZ
#define MACIERZ
#include <string>

/// Implementacja dynamicznej tablicy dwuwymiarowej.

/// Standardowa dynamiczna struktura danych, alokacja i dealokacja pamięci przebiegają automatycznie. Przeciążony operator () pozwala na dostęp do poszczególnych pól macierzy.
template <class T>
class macierz {
private:
    int n_, m_;
    T** tab_;

public:
    ~macierz();
    /// Umożliwia dostęp do wybranej komórki macierzy.
    /// Pozwala zarówno na ustawienie, jak i odczytanie wartości komórki.
    /// @param x Numer wiersza macierzy.
    /// @param y Numer kolumny macierzy.
    /// @returns Wartość wybranej komórki.
    T& operator()(int x, int y);
    /// Tworzy pustą macierz o wymiarach n x m.
    /// @param n Ilość wierszy macierzy.
    /// @param m Ilość kolumn macierzy.
    macierz(int n, int m);
    /// Tworzy pustą kwadratową macierz o wymiarach n x n.
    /// @param n Ilość wierszy i kolumn macierzy.
    macierz(int n);
    /// Tworzy macierz o wymiarach n x m oraz wypełnia ją danymi z pliku.
    /// @param sciezka Lokalizacja pliku.
    /// @param n Ilość wierszy macierzy.
    /// @param m Ilość kolumn macierzy.
    macierz(std::string sciezka, int n, int m);
    /// Wypisuje zawartość macierzy do konsoli.
    void druk();
    /// Zapisuje zawartość macierzy do pliku.
    /// @param sciezka Lokalizacja pliku.
    void druk(std::string sciezka);
    /// Tworzy kopię macierzy z wykreślonym rzędem x i kolumną y.
    /// @warning Jedynie dla macierzy kwadratowej, o wymiarach n x n.
    /// @returns Minor macierzy początkowej.
    /// @param x Numer wiersza do wykreślenia, poczynając od 0.
    /// @param y Numer kolumny do wykreślenia, poczynając od 0.
    macierz minor(int x, int y);
    /// Dokonuje transpozycji macierzy.
    /// @warning Jedynie dla macierzy kwadratowej, o wymiarach n x n.
    void transpozycja();
    /// Dokonuje przesunięcia cyklicznego wiersza macierzy.
    /// @param x Numer wiersza do przesunięcia, poczynając od 0.
    /// @param ilosc Ilość miejsc do przesunięcia, ujemna dla przesunięcia w lewo.
    void przesun_wiersz(int x, int ilosc);
    /// Dokonuje przesunięcia cyklicznego kolumny macierzy.
    /// @param y Numer kolumny do przesunięcia, poczynając od 0.
    /// @param ilosc Ilość miejsc do przesunięcia, ujemna dla przesunięcia ku górze.
    void przesun_kolumne(int y, int ilosc);

};

#endif