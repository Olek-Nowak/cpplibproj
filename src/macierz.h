#ifndef MACIERZ
#define MACIERZ
#include <string>

/// Implementacja dynamicznej tablicy dwuwymiarowej.

/// Standardowa dynamiczna struktura danych, alokacja i dealokacja pamięci przebiegają automatycznie.
template <class T>
class macierz {
private:
    int n_, m_;
    T** tab_;

public:
    ~macierz();
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
    macierz(std::string sciezka, int n, int m);
    /// Wypisuje zawartość macierzy do konsoli.
    void druk();
    /// Zapisuje zawartość macierzy do pliku.
    /// @param sciezka Lokalizacja pliku.
    void druk(std::string sciezka);
    /// Dokonuje transpozycji macierzy.
    /// @warning Jedynie dla macierzy kwadratowej, o wymiarach n x n.
    void transpozycja();
    /// Dokonuje obrócenia macierzy.
    /// @warning Jedynie dla macierzy kwadratowej, o wymiarach n x n.
    void obrot();
    /// Oblicza wartość wyznacznika macierzy.
    /// @warning Jedynie dla macierzy kwadratowej, o wymiarach n x n.
    /// @returns Wartość wyznacznika, NULL dla macierzy prostokątnej.
    int wyznacznik();

};

#endif