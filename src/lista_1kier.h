#ifndef LISTA1K
#define LISTA1K
#include <string>

template <class T>
struct lista1kElem {
    T dane_;
    lista1kElem* nast_;
    lista1kElem(T dane);

};

/// Implementacja listy dynamicznej jednokierunkowej.

/// Standardowa dynamiczna struktura danych, alokacja i dealokacja pamięci przebiegają automatycznie.
template <class T>
class lista_1kier {
private:
    lista1kElem<T>* glowa_;
    lista1kElem<T>* ogon_;
    int dlugosc_;

public:
    ~lista_1kier();
    /// Tworzy pustą listę jednokierunkową.
    lista_1kier();
    /// Tworzy pustą listę jednokierunkową i wypełnia ją danymi z pliku.
    /// @param sciezka Lokalizacja pliku.
    lista_1kier(std::string sciezka);
    /// Znajduje długość listy.
    /// @returns Chwilowa długość listy.
    int dlugosc();
    /// Wypisuje zawartość listy do konsoli.
    void druk();
    /// Zapisuje zawartość listy do pliku.
    /// @param sciezka Lokalizacja pliku.
    void druk(std::string sciezka);
    /// Umieszcza nowy element na końcu listy.
    /// @param dane Wartość dodawanego elementu.
    void dodaj(T dane);
    /// Umieszcza nowy element na określonej pozycji.
    /// @param dane Wartość dodawanego elementu.
    /// @param pozycja Indeks pozycji, poczynając od 0.
    void dodaj(T dane, int pozycja);
    /// Usuwa ostatni element listy.
    void usun();
    /// Usuwa pierwszy napotkany element listy o danej wartości.
    /// @param dane Wartość szukanego elementu do usunięcia.
    void usun_napotkany(T dane);
    /// Usuwa element na określonej pozycji.
    /// @param pozycja Indeks pozycji, poczynając od 0.
    /// @returns Wartość usuniętego elementu.
    T usun(int pozycja);

};

#endif