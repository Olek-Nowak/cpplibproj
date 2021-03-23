#ifndef DRZEWO
#define DRZEWO
#include <string>

template <class T>
struct drzewoElem {
    T dane_;
    drzewoElem<T>* mniej_;
    drzewoElem<T>* wiecej_;
    drzewoElem(T dane);
    void druk_inorder();
    void druk_inorder(std::ofstream& plik);
    void druk_drzewo(int tab);
    void skasuj();
    void dodaj(T dane);
    void usun(T dane, drzewoElem* poprzedni);

};

/// Implementacja binarnego drzewa poszukiwań.

/// Standardowa dynamiczna struktura danych, alokacja i dealokacja pamięci przebiegają automatycznie. Hierarchia elementów jest automatycznie zachowywana.
template <class T>
class drzewo {
private:
    drzewoElem<T>* korzen_;

public:
    ~drzewo();
    /// Tworzy pustą drzewo.
    drzewo();
    /// Tworzy pustą drzewo i wypełnia je elementami o danych z pliku.
    /// @param sciezka Lokalizacja pliku.
    drzewo(std::string sciezka);
    /// Wypisuje zawartość drzewa do konsoli, zachowując jego strukturę.
    void druk_drzewo();
    /// Wypisuje zawartość drzewa posortowaną rosnąco.
    void druk_inorder();
    /// Zapisuje zawartość drzewa posortowaną rosnąco do pliku.
    /// @param sciezka Lokalizacja pliku.
    void druk_inorder(std::string sciezka);
    /// Dodaje nowy element w zgodnie z zasadami binarnego drzewa poszukiwań.
    /// @param dane Wartość dodawanego elementu.
    void dodaj(T dane);
    /// Usuwa element drzewa o danej wartości.
    /// @param dane Wartość szukanego elementu do usunięcia.
    /// @warning Jeszcze nie obsługiwane!
    void usun(T dane);

};


#endif