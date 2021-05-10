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
    drzewoElem<T>* najwiekszy();
    drzewoElem<T>* najmniejszy();
    void usun(T dane, drzewoElem* const &poprzedni);
    drzewoElem<T>* usun_korzen();
    int wysokosc();
    int wielkosc();
    void obrot_lewo(drzewoElem<T>* const &poprzedni);
    void obrot_prawo(drzewoElem<T>* const &poprzedni);
    drzewoElem<T>* obrot_korzen_lewo();
    drzewoElem<T>* obrot_korzen_prawo();

};

/// Implementacja binarnego drzewa poszukiwań.

/// Standardowa dynamiczna struktura danych, alokacja i dealokacja pamięci przebiegają automatycznie. Hierarchia elementów jest automatycznie zachowywana.
/// Implementacja wyważania rozmiaru lub wysokości drzewa ułatwiona dzięki gotowym metodom @
template <class T>
class drzewo {
private:
    drzewoElem<T>* korzen_;
    bool puste_;

public:
    ~drzewo();
    /// Tworzy puste drzewo.
    drzewo();
    /// Tworzy puste drzewo i wypełnia je elementami o danych z pliku.
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
    void usun(T dane);
    /// Znajduje wysokość poddrzewa danego elementu.
    /// @param dane Wartość elementu o szukanej wysokości.
    /// @returns Wysokość poddrzewa.
    int wysokosc(T dane);
    /// Znajduje wysokość drzewa.
    /// @returns Wysokość drzewa.
    int wysokosc();
    /// Znajduje wielkość poddrzewa danego elementu.
    /// @param dane Wartość elementu o szukanej wielkości.
    /// @returns Wielkość poddrzewa.
    int wielkosc(T dane);
    /// Znajduje wielkość drzewa.
    /// @returns Wielkość drzewa.
    int wielkosc();
    /// Wykonuje obrót w prawo drzewa względem danego elementu.
    /// @param dane Wartość obracanego elementu.
    void obrot_prawo(T dane);
    /// Wykonuje obrót w lewo drzewa względem danego elementu.
    /// @param dane Wartość obracanego elementu.
    void obrot_lewo(T dane);

};


#endif